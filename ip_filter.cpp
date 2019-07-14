#include <tuple>
#include "ip_filter.h"
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "stdlib.h"
//#include "gtest/gtest.h"
#include <sstream>

using namespace std;

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
vector<string> split(const string &str, char d) {
    vector<string> r;

    string::size_type start = 0;
    string::size_type stop = str.find_first_of(d);
    while (stop != string::npos) {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}



bool operator<(const Ip &lhs, const Ip &rhs) {
    return tie(lhs.first_oct, lhs.second_oct, lhs.third_oct, lhs.last_oct) <
           tie(rhs.first_oct, rhs.second_oct, rhs.third_oct, rhs.last_oct);
}


Ip SplitBy(string_view s, char sep) {
    vector<int> result;
//string_view result;
    while (!s.empty()) {
        size_t pos = s.find(sep);
        result.push_back(atoi(s.substr(0, pos).data()));
        s.remove_prefix(pos != s.npos ? pos + 1 : s.size());
    }
    return {result.at(0), result.at(1), result.at(2), result.at(3)};
}


ostream &operator<<(ostream &os, const Ip &ip) {
    os << ip.first_oct << "." << ip.second_oct << "." << ip.third_oct << "." << ip.last_oct << endl;

    return os;
}



stringstream filter(multiset<Ip> &ip_pool, int ip_find1, int ip_find2) {
    stringstream ss;
    if (ip_find1 == 0 && ip_find2 == 0) {
        for (auto it = ip_pool.rbegin(); it != ip_pool.rend(); ++it) {
//            cout << *it;
            ss << *it;
        }
        return ss;
    }
    auto it = ip_pool.rbegin();
    while ((it != ip_pool.rend())) {
        if (it->first_oct == ip_find1 && (ip_find1 == 1 && ip_find2 == 0)) {
//            cout << *it;
            ss << *it;
        } else if (it->first_oct == 46 && it->second_oct == 70 && (ip_find1 == 46 && ip_find2 == 70)) {
            cout << *it;
            ss << *it;
        } else if ((it->first_oct == 46 || it->second_oct == 46 || it->third_oct == 46 || it->last_oct == 46) &&
                   (ip_find1 == 46 && ip_find2 == 0)) {
//            cout << *it;
            ss << *it;
        }
        ++it;
    }
    return ss;
}

