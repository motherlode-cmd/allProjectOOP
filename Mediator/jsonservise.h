#ifndef JSONSERVISE_H
#define JSONSERVISE_H
#include <map>
#include <string>

class JsonServise
{
public:
    JsonServise();
    std::map <std::string, std::string> parseData(const std::string fileName);
private:
    std::string readJson(const std::string fileName);
};

#endif // JSONSERVISE_H
