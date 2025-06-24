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

#ifndef JSONPARSER_HPP
#define JSONPARSER_HPP

#include <unistd.h>
#include <string>
#include <vector>
#include <mutex>
#include <json-c/json.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "v2xmgr"

#ifdef MODULE_NAME
#undef MODULE_NAME
#endif
#define MODULE_NAME "V2xJsonParser"

enum class JSON_VALUE_TYPE
{
    STRING,
    INT,
    DOUBLE,
    BOOL,
    OBJECT,
    UNKNOWN
};

class JsonParser
{
    public:
        JsonParser(std::string filePath);
        ~JsonParser();

        bool readFile();
        bool writeFile();

        std::string getValue(std::vector<std::string> key);
        bool setValue(std::vector<std::string> key, std::string value, bool isCreatePropertyIfNotExist = false, enum JSON_VALUE_TYPE valueType = JSON_VALUE_TYPE::STRING);

        JSON_VALUE_TYPE getValueDataType(std::string value);

    private:
        std::string getStringFromJsonObj(json_object* jsonObj);
        void setStringToJsonObj(json_object* jsonObj, std::string value);

        json_object* createNewProperty(json_object* parentJsonObj, const char* key, enum JSON_VALUE_TYPE valueType);

    private:
        std::string m_filePath;
        json_object* m_jsonRoot;
};

#endif  // JSONPARSER_HPP
