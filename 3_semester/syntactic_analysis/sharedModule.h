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
#include <unordered_set>
#include <map>
#include <unordered_map>

#define excep(msg) std::exception(msg)

using str = std::string;

template<class T = int>
using uMapVar = std::unordered_map<str, T>;

using uMapChI = std::unordered_map<char, int>;
using li = long int;
using ld = long double;
using ui = unsigned int;
using ss = std::stringstream;
using sCh = std::set<char>;

#endif //INFORMATICS_SHAREDMODULE_H
