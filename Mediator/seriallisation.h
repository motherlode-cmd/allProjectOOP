#ifndef SERIALLISATION_H
#define SERIALLISATION_H
#include <algorithm>
#include <iostream>
#include <fstream>
#include "Exeptions/exeptionfield.h"
#include "dataparser.h"
#include <vector>
#include "math.h"
#include <algorithm>
#include "hasher.h"
#include "./Exeptions/myexeption.h"
#include "./Exeptions/exeptionfile.h"
template <typename ... Game>
class Seriallisation
{
public:
    Seriallisation(){}
    void load(std::string fileName, int & level, Field & field, Player * player) {
        std::ifstream is;
        is.open(fileName, std::ios::binary);
        if(!is.is_open())throw(ExeptionFile(fileName));
        std::vector <std::string> ans;
        std::string s;
        while(is>>s) {
            ans.push_back(s);
        }
        is.close();
        DataParser().parseField(ans, level, field, player);
    }

    void write(std::string fileName, int level, Game& ... args) {
        std::ofstream os;
        os.open(fileName, std::ios::binary);
        if(!os.is_open())throw(ExeptionFile(fileName));
        os<<level<<'\n';
        (os<<...<<args.toString());
        os.flush();
        os.close();
        os.open(fileName, std::ios::app);
        os<<Hasher().writeHash(fileName);
        os.flush();
        os.close();
    }

};

#endif // SERIALLISATION_H
