//
// Created by aminjonshermatov on 9/24/2021.
//

#ifndef INFORMATICS_SHAREDMODULE_H
#define INFORMATICS_SHAREDMODULE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <unordered_map>

#define excep(msg) std::exception(msg)

using str = std::string;

template<class T = int>
using mapVar = std::map<str, T>;

using mapChI = std::unordered_map<char, int>;
using li = long int;
using ld = long double;
using ui = unsigned int;
using ss = std::stringstream;
using sCh = std::set<char>;

#endif //INFORMATICS_SHAREDMODULE_H
