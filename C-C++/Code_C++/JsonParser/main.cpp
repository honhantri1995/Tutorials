#include "JsonParser.hpp"
#include <iostream>
using namespace std;

#define JSON_FILE_PATH  "mock.json"

int main()
{
    JsonParser parser(JSON_FILE_PATH);

    // Normal cases
    string data;
    // data = parser.getValue({"info", "infoId"});
    // cout << "data: " << data << endl;

    // data = parser.getValue({"disable"});
    // cout << "data: " << data << endl;

    // data = parser.getValue({"enable", "xyz"});
    // cout << "data: " << data << endl;

    // data = parser.getValue({"infod"});
    // cout << "data: " << data << endl;

    // data = parser.getValue({"info", "infoDetails", "abc"});
    // cout << "data: " << data << endl;

    // parser.setValue({"info", "infoDetails", "abc"}, "false");

    // data = parser.getValue({"info", "infoDetails", "abc"});
    // cout << "data: " << data << endl;

    // parser.setValue({"info", "infoDetails", "abc"}, "false");

    // parser.setValue({"info", "infoId"}, "123123123123");

    // parser.setValue({"infod"}, std::to_string(511.22200));

    // parser.setValue({"abc"}, "true", true, JSON_VALUE_TYPE::STRING); 

    // parser.setValue({"info", "infoDetails", "mnc"}, std::to_string(1), true, JSON_VALUE_TYPE::DOUBLE); 

    // parser.setValue({"info", "infoDetails", "moreDetails", "xyz"}, std::to_string(1), true, JSON_VALUE_TYPE::DOUBLE); 

    // Abnormal cases
    // data = parser.getValue({"info", "abc"});
    // cout << "data: " << data << endl;

    // data = parser.getValue({"info"});
    // cout << "data: " << data << endl;

    // data = parser.getValue({"notexist"});
    // cout << "data: " << data << endl;

    // parser.setValue({"set", "abc"}, "true", true, JSON_VALUE_TYPE::STRING); // key "set" is primitive

    // Exceptions
    // parser.setValue({"infod"}, "true", true, JSON_VALUE_TYPE::STRING);  // infod is a int, not a string

    parser.getValueDataType("1.2");
    parser.getValueDataType("12");

    return 0;
}