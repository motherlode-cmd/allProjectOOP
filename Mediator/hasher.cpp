#include "hasher.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

bool Hasher::check_hash(std::vector<std::string> words)
{
    long long h = 0;
    for(size_t i = 0; i < words.size() - 1; i++)
        h += hash(words[i]);
    return std::to_string(h) == words[words.size() - 1];
}

long long Hasher::writeHash(std::string filename)
{
    std::ifstream inf;
    inf.open(filename,  std::ios::binary);
    try {
        std::vector <std::string> words;
        std::string s;
        if(inf.is_open()) {
            while(inf>>s) {
                words.push_back(s);
            }
            long long h = 0;
            for(size_t i = 0; i < words.size(); i++)
                h += hash(words[i]);
            inf.close();
            return h;
        } else {
            throw(inf.is_open());
        }
    } catch(bool is) {
        std::cout<<"Can't open file"<<std::endl;
        return 0l;
    }
}

long long Hasher::hash(std::string s)
{
    long long h = 0;
    for(size_t i = 0; i < s.length(); i++) {
        h += (int)s[i] * pow(2, i);
    }
    return h;
}
