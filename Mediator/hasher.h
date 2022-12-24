#ifndef HASHER_H
#define HASHER_H

#include <vector>
#include <string>
class Hasher
{
public:
    Hasher() = default;
    bool check_hash(std::vector<std::string> words);
    long long writeHash(std::string filename);
    long long hash(std::string s);
};

#endif // HASHER_H
