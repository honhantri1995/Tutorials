/**
 * @attention Copyright (c) 2023 by LG electronics co, Ltd. All rights reserved.
 *   This program or software including the accompanying associated documentation ("Software") is
 *   the proprietary software of LG Electronics Inc.  and or its licensors, and may only be used,
 *   duplicated, modified or distributed pursuant to the terms and conditions of a separate written license agreement
 *   between you and LG Electronics Inc. ("Authorized License").
 *   Except as set forth in an Authorized License, LG Electronics Inc. grants no license (express or implied), rights to use,
 *   or waiver of any kind with respect to the Software, and LG Electronics Inc. expressly reserves all rights in
 *   and to the Software and all intellectual property therein.
 *   If you have no Authorized License, then you have no rights to use the Software in any ways,
 *   and should immediately notify LG Electronics Inc. and discontinue all use of the Software.
 */

// #include <Log.h>
#include <regex>
#include <algorithm>

#include "JsonParser.hpp"

#define LOGE(...) printf(__VA_ARGS__)
#define LOGD(...) printf(__VA_ARGS__)

std::mutex g_jsonFileMutex;

/**
 * @brief Construct a new Json Parser object
 * @param filePath : Path of JSON file
 */
JsonParser::JsonParser(std::string filePath) :
    m_filePath(filePath),
    m_jsonRoot(nullptr)
{
    // Read file and load JSON objects
    readFile();

    // Set double format (max 10 digits for each double number)
    // Note: This step is required to prevent garbage digits. E.g.: Value to be set is 511.2, but value in JSON file after written is 511.19999999999999
    //       With this function, value in JSON file will be 511.2 (exactly what we set to)
    (void)json_c_set_serialization_double_format("%.10g", JSON_C_OPTION_THREAD);
}

/**
 * @brief Destroy the Json Parser object
 */
JsonParser::~JsonParser()
{
    // Free memory and close file
    if (m_jsonRoot != nullptr) {
        if (json_object_put(m_jsonRoot) < 1) {
            LOGE("[%s]: %s, Failed to free all JSON objects in file: %s. Error: %s\n", MODULE_NAME, __FUNCTION__, m_filePath.c_str(),
                json_util_get_last_err());
        }
        m_jsonRoot = nullptr;
    }
}

/**
 * @brief Read JSON file
 * @return true if success, false if failure
 */
bool JsonParser::readFile()
{
    LOGD("[%s]: %s\n", MODULE_NAME, __FUNCTION__);

    std::lock_guard<std::mutex> lock(g_jsonFileMutex);

    m_jsonRoot = json_object_from_file(m_filePath.c_str());

    if (m_jsonRoot == nullptr) {
        LOGE("[%s]: %s, Failed to read file %s. Error: %s\n", MODULE_NAME, __FUNCTION__, m_filePath.c_str(), json_util_get_last_err());
        return false;
    }

    return true;
}

/**
 * @brief Write JSON file
 * @return true if success, false if failure
 */
bool JsonParser::writeFile()
{
    LOGD("[%s]: %s\n", MODULE_NAME, __FUNCTION__);

    if (m_jsonRoot == nullptr) {
        LOGE("[%s]: %s, Failed to write file %s because Json Root is null\n", MODULE_NAME, __FUNCTION__, m_filePath.c_str());
        return false;
    }

    std::lock_guard<std::mutex> lock(g_jsonFileMutex);

    int ret = json_object_to_file_ext(m_filePath.c_str(),
                                      m_jsonRoot,
                                      JSON_C_TO_STRING_NOSLASHESCAPE | JSON_C_TO_STRING_PRETTY | JSON_C_TO_STRING_SPACED);
    if (ret < 0) {
        LOGE("[%s]: %s, Failed to write file %s. Error: %s\n", MODULE_NAME, __FUNCTION__, m_filePath.c_str(), json_util_get_last_err());
        return false;
    }

    return true;
}

/**
 * @brief Get property value based on the given key
 * @note The returned value is always a string regarding of its real data type. So, client might need to convert data type manually.
 * @param key : Property key whose its value will be get
 * @return Property value to get
 */
std::string JsonParser::getValue(std::vector<std::string> key)
{
    LOGD("[%s]: %s\n", MODULE_NAME, __FUNCTION__);

    std::string value;

    if (m_jsonRoot == nullptr) {
        LOGE("[%s]: %s, Failed to get value by key because JsonRoot is null. File: %s\n", MODULE_NAME, __FUNCTION__, m_filePath.c_str());
        return value;
    }

    // Check whether inputed key is provided
    uint32_t keySize = key.size();
    if (keySize <= 0) {
        LOGE("[%s]: %s, Failed to get value because key was not provided. File: %s\n", MODULE_NAME, __FUNCTION__, m_filePath.c_str());
        return value;
    }

    json_object* tmpJsonRoot = m_jsonRoot;

    for (size_t i = 0; i < keySize; i++) {
        const char* pKey = key[i].c_str();

        json_object* jsonObj = NULL;
        (void)json_object_object_get_ex(tmpJsonRoot, pKey, &jsonObj);
        if (jsonObj == NULL) {
            LOGE("[%s]: %s, Failed to get value by key because JsonObject is null. File: %s\n", MODULE_NAME, __FUNCTION__, m_filePath.c_str());
            return value;
        }

        // If reaching the leaf property, get its value in string
        if (i == keySize - 1) {
            value = getStringFromJsonObj(jsonObj);
        }

        // Change temporary root to the next object
        tmpJsonRoot = jsonObj;
    }

    return value;
}

/**
 * @brief Update property value based on a given key to JSON file
 * @note The inputed value is always a string regarding of its real data type. The func will convert string to real data type when writing to JSON file.
 * @param key : Property key to be updated
 * @param value : Property value to be updated
 * @param isCreatePropertyIfNotExist [optional] : Whether to create new property if the given key doesn't exist
 * @param valueType [optional] : Specify the data type of property value to be created. Used only when isCreatePropertyIfNotExist is true.
 * @return true if success, false if failure
 */
bool JsonParser::setValue(std::vector<std::string> key, std::string value, bool isCreatePropertyIfNotExist, enum JSON_VALUE_TYPE valueType)
{
    LOGD("[%s]: %s\n", MODULE_NAME, __FUNCTION__);

    if (m_jsonRoot == nullptr) {
        LOGE("[%s]: %s, Failed to update value by key because JsonRoot is null. File: %s\n", MODULE_NAME, __FUNCTION__, m_filePath.c_str());
        return false;
    }

    // Check whether inputed key is provided
    uint32_t keySize = key.size();
    if (keySize <= 0) {
        LOGE("[%s]: %s, Failed to update value because key was not provided. File: %s\n", MODULE_NAME, __FUNCTION__, m_filePath.c_str());
        return false;
    }

    json_object* tmpJsonObj = m_jsonRoot;

    for (size_t i = 0; i < keySize; i++) {
        const char* pKey = key[i].c_str();

        json_object* jsonObj = NULL;
        (void)json_object_object_get_ex(tmpJsonObj, pKey, &jsonObj);

        if (isCreatePropertyIfNotExist == false) {
            if (jsonObj == NULL) {
                LOGE("[%s]: %s, Failed to update value by key because property doesn't exist. File: %s\n. Make sure the inputed key is valid", MODULE_NAME, __FUNCTION__, m_filePath.c_str());
                return false;
            }
        }
        else {
            // If the property doesn't exist, create a new one
            if (jsonObj == NULL) {
                // First, create the non-leaf property(s) if needed
                if (i < keySize - 1) {
                    jsonObj = createNewProperty(tmpJsonObj, pKey, JSON_VALUE_TYPE::OBJECT);
                }
                // Finally, create the leaf property
                else {
                    jsonObj = createNewProperty(tmpJsonObj, pKey, valueType);
                }

                if (jsonObj == NULL) {
                    LOGE("[%s]: %s, Failed to update value by key because failed to create property. File: %s\n", MODULE_NAME, __FUNCTION__, m_filePath.c_str());
                    return false;
                }
            }
        }

        // If reaching the leaf property, set its value
        if (i == keySize - 1) {
            if (jsonObj != NULL) {
                setStringToJsonObj(jsonObj, value);
            }
        }

        // Change temporary object to the next object
        tmpJsonObj = jsonObj;
    }

    // Update file in disk
    (void)writeFile();

    return true;
}

/**
 * @brief Get property value with its real data type from JSON object, then convert the value to string
 * @param jsonObj : JSON object whose value is get
 * @return Property value in string
 */
std::string JsonParser::getStringFromJsonObj(json_object* jsonObj)
{
    LOGD("[%s]: %s\n", MODULE_NAME, __FUNCTION__);

    std::string value;
    try {
        json_type objType = json_object_get_type(jsonObj);

        switch(objType) {
            case json_type_string: {
                const char* tmpVal = json_object_get_string(jsonObj);
                value = std::string(tmpVal);
                LOGD("[%s]: %s, String value: %s\n", MODULE_NAME, __FUNCTION__, tmpVal);
            }
                break;
            case json_type_int: {
                int32_t ival = json_object_get_int(jsonObj);
                value = std::to_string(ival);
                LOGD("[%s]: %s, Int value: %d\n", MODULE_NAME, __FUNCTION__, ival);
            }
                break;
            case json_type_double: {
                double dval = json_object_get_double(jsonObj);
                value = std::to_string(dval);
                LOGD("[%s]: %s, Double value: %lf\n", MODULE_NAME, __FUNCTION__, dval);
            }
                break;
            case json_type_boolean: {
                json_bool bval = static_cast<uint8_t>(json_object_get_boolean(jsonObj));
                value = (bval == 1) ? "true" : "false";
                LOGD("[%s]: %s, Bool value: %d\n", MODULE_NAME, __FUNCTION__, bval);
            }
                break;
            default:
                LOGE("[%s]: %s, Object type is not a primitive type: %d\n", MODULE_NAME, __FUNCTION__, static_cast<int32_t>(objType));
                break;
        }
    }
    catch(const std::invalid_argument& e) {
        LOGE("[%s]: %s, Exception std::invalid_argument: %s\n", MODULE_NAME, __FUNCTION__, e.what());
    }
    catch(const std::out_of_range& e) {
        LOGE("[%s]: %s, Exception std::out_of_range: %s\n", MODULE_NAME, __FUNCTION__, e.what());
    }
    catch(const std::exception& e) {
        LOGE("[%s]: %s, Exception: %s\n", MODULE_NAME, __FUNCTION__, e.what());
    }
    catch(...) {
        LOGE("[%s]: %s, Exception\n", MODULE_NAME, __FUNCTION__);
    }

    return value;
}

/**
 * @brief Set property value to JSON object
 * @param jsonObj : JSON object whose value is get
 * @param value : Property value to be set. Note: The value string will converted to the real data type of the property
 */
void JsonParser::setStringToJsonObj(json_object* jsonObj, std::string value)
{
    LOGD("[%s]: %s\n", MODULE_NAME, __FUNCTION__);

    try {
        json_type objType = json_object_get_type(jsonObj);

        switch(objType) {
            case json_type_string:
                (void)json_object_set_string(jsonObj, value.c_str());
                LOGD("[%s]: %s, String value: %s\n", MODULE_NAME, __FUNCTION__, value.c_str());
                break;
            case json_type_int: {
                int64_t ival = static_cast<int64_t>(std::stol(value));
                (void)json_object_set_int64(jsonObj, ival);
                LOGD("[%s]: %s, Int value: %ld\n", MODULE_NAME, __FUNCTION__, ival);
            }
                break;
            case json_type_double: {
                double dval = static_cast<double>(std::stod(value));
                (void)json_object_set_double(jsonObj, dval);
                LOGD("[%s]: %s, Double value: %lf\n", MODULE_NAME, __FUNCTION__, dval);
            }
                break;
            case json_type_boolean: {
                json_bool bval = 0;
                if (value == "true" || value == "1") {
                    bval = 1;
                }
                else if (value == "false" || value == "0") {
                    bval = 0;
                }
                else {
                    LOGE("[%s]: %s, Invalid bool value: %s\n", MODULE_NAME, __FUNCTION__, value.c_str());
                    break;
                }
                (void)json_object_set_boolean(jsonObj, bval);
                LOGD("[%s]: %s, Bool value: %s\n", MODULE_NAME, __FUNCTION__, value.c_str());
            }
                break;
            default:
                LOGE("[%s]: %s, Object type is not a primitive type: %d\n", MODULE_NAME, __FUNCTION__, static_cast<int32_t>(objType));
                break;
        }
    }
    catch(const std::invalid_argument& e) {
        LOGE("[%s]: %s, Exception std::invalid_argument: %s\n", MODULE_NAME, __FUNCTION__, e.what());
    }
    catch(const std::out_of_range& e) {
        LOGE("[%s]: %s, Exception std::out_of_range: %s\n", MODULE_NAME, __FUNCTION__, e.what());
    }
    catch(const std::exception& e) {
        LOGE("[%s]: %s, Exception: %s\n", MODULE_NAME, __FUNCTION__, e.what());
    }
    catch(...) {
        LOGE("[%s]: %s, Exception\n", MODULE_NAME, __FUNCTION__);
    }
}

/**
 * @brief Create new property
 * @param parentJsonObj : The object which holds the property
 * @param key : Property key to be created
 * @param valueType : Data type of property value to be created
 * @return Object of the new property
 */
json_object* JsonParser::createNewProperty(json_object* parentJsonObj, const char* key, enum JSON_VALUE_TYPE valueType)
{
    LOGD("[%s]: %s\n", MODULE_NAME, __FUNCTION__);
    json_object* newObj = NULL;

    if (parentJsonObj == NULL) {
        LOGE("[%s]: %s, Failed to create a new property without a parent property or a root. File: %s\n", MODULE_NAME, __FUNCTION__, m_filePath.c_str());
        return newObj;
    }
    else {
        // It's impossible to add new properties inside a property of primitive type
        if (json_object_get_type(parentJsonObj) != json_type_object) {
            LOGE("[%s]: %s, Failed to create a new property inside a property of primitive type. File: %s\n", MODULE_NAME, __FUNCTION__, m_filePath.c_str());
            return newObj;
        }
    }

    // If the property already exists, don't need to create it
    json_object* jsonObj = NULL;
    (void)json_object_object_get_ex(parentJsonObj, key, &jsonObj);
    if (jsonObj != NULL) {
        LOGE("[%s]: %s, Failed to create a new property because it already exists. File: %s\n", MODULE_NAME, __FUNCTION__, m_filePath.c_str());
        return newObj;
    }

    switch (valueType) {
        case JSON_VALUE_TYPE::OBJECT:
            newObj = json_object_new_object();
            break;
        case JSON_VALUE_TYPE::STRING:
            newObj = json_object_new_string("");
            break;
        case JSON_VALUE_TYPE::DOUBLE:
            newObj = json_object_new_double(0.0);
            break;
        case JSON_VALUE_TYPE::INT:
            newObj = json_object_new_int64(0);
            break;
        case JSON_VALUE_TYPE::BOOL:
            newObj = json_object_new_boolean(false);
            break;
        default:
            LOGE("[%s]: %s, Unknown JSON value type (%d). File: %s\n", MODULE_NAME, __FUNCTION__, static_cast<int32_t>(valueType), m_filePath.c_str());
            break;
    }

    if (newObj == NULL) {
        LOGE("[%s]: %s, Failed to create a new property. File: %s\n", MODULE_NAME, __FUNCTION__, m_filePath.c_str());
        return newObj;
    }

    int32_t ret = json_object_object_add(parentJsonObj, key, newObj);
    if (ret < 0) {
        LOGE("[%s]: %s, Failed to add new property. File: %s\n", MODULE_NAME, __FUNCTION__, m_filePath.c_str());
        return newObj;
    }

    return newObj;
}

/**
 * @brief Get real data type of the value from its given string
 * @param value : Value string
 * @return Real data type 
 */
JSON_VALUE_TYPE JsonParser::getValueDataType(std::string value)
{
    LOGD("[%s]: %s\n", MODULE_NAME, __FUNCTION__);

    // Is value empty?
    if (value.empty()) {
        LOGE("[%s]: %s, Value is an empty string. File: %s\n", MODULE_NAME, __FUNCTION__, m_filePath.c_str());
        return JSON_VALUE_TYPE::UNKNOWN;
    }

    // Does value contain only whitespace?
    if (std::all_of(value.begin(), value.end(), isspace)) {
        LOGE("[%s]: %s, Value contains only whitespace. File: %s\n", MODULE_NAME, __FUNCTION__, m_filePath.c_str());
        return JSON_VALUE_TYPE::UNKNOWN;
    }

    // Is value a bool string?
    if ((value == "true") || (value == "false")) {
        LOGD("[%s]: %s, Value is a boolean\n", MODULE_NAME, __FUNCTION__);
        return JSON_VALUE_TYPE::BOOL;
    }

    try {
        // Is value a double string?
        std::regex doubleRegex(R"(^-?\d+\.\d+$)");
        if (std::regex_match(value, doubleRegex) == true) {
            LOGD("[%s]: %s, Value is a double\n", MODULE_NAME, __FUNCTION__);
            return JSON_VALUE_TYPE::DOUBLE;
        }

        // Is value an integer string?
        std::regex intRegex(R"(^-?\d+$)");
        if (std::regex_match(value, intRegex) == true) {
            LOGD("[%s]: %s, Value is an integer\n", MODULE_NAME, __FUNCTION__);
            return JSON_VALUE_TYPE::INT;
        }
    }
    catch (const std::regex_error& e) {
        LOGE("[%s]: %s, Exception std::regex_error: %s\n", MODULE_NAME, __FUNCTION__, e.what());
        return JSON_VALUE_TYPE::UNKNOWN;
    }
    catch (...) {
        LOGE("[%s]: %s, Exception\n", MODULE_NAME, __FUNCTION__);
        return JSON_VALUE_TYPE::UNKNOWN;
    }

    // If value is not bool, not integer, not double, keep it as string
    LOGD("[%s]: %s, Value is a string\n", MODULE_NAME, __FUNCTION__);
    return JSON_VALUE_TYPE::STRING;
}