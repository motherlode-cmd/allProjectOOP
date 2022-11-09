#include "jsonservise.h"
#include <fstream>
#include <iostream>
#include <sstream>
JsonServise::JsonServise()
{}

std::string JsonServise::readJson(const std::string fileName)
{
    std::ifstream input(fileName);
    std::stringstream buffer;
    buffer<<input.rdbuf();
    return buffer.str();
}

std::map<std::string, std::string> JsonServise::parseData(const std::string fileName)
{
    std::string data = readJson(fileName);
    std::map<std::string, std::string> curr;
    int i = data.find('{');
    int j = data.find('}');
    data = data.substr(i + 2, j - i - 2);
    while(data.length() != 0) {
        std::string key;
        std::string val;
        std::string tmp;
        if((int)data.find(',') != -1) {
            tmp = data.substr(0, data.find(','));
            data = data.substr(data.find(',') + 1);
        } else {
            tmp = data;
            data = "";
        }
        tmp = tmp.substr(tmp.find('"') + 1);
        key = tmp.substr(0, tmp.find('"'));
        tmp = tmp.substr(tmp.find('"') + 1);
        tmp = tmp.substr(tmp.find('"') + 1);
        val = tmp.substr(0, tmp.find('"'));
        curr[key] = val;
    }
    return curr;
}
