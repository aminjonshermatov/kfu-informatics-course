//
// Created by aminjonshermatov on 9/23/2021.
//

#ifndef INFORMATICS_GLOBALS_H
#define INFORMATICS_GLOBALS_H

#include <bits/stdc++.h>

#define mk(a, b) std::make_pair(a, b)
#define findAll(store, el) std::find((store).begin(), (store).end(), el)
#define exp(msg) std::runtime_error(msg)

using pii = std::pair<int, int>;
using str = std::string;
using li = long int;

template<typename T = str>
using v = std::vector<T>;

using um_ii = std::unordered_map<int, v<int>>;
using um_sii = std::unordered_map<str, um_ii>;

template <typename T>
using mP = std::map<int, T*>;

using ss = std::stringstream;

#endif //INFORMATICS_GLOBALS_H
