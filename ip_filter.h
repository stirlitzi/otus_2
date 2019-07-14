#pragma once
#include <vector>
#include <string>
#include <set>

using namespace std;
struct Ip {
    int first_oct;
    int second_oct;
    int third_oct;
    int last_oct;


};

vector<string> split(const string &str, char d);
bool operator<(const Ip &lhs, const Ip &rhs);
Ip SplitBy(string_view s, char sep);
ostream &operator<<(ostream &os, const Ip &ip);
stringstream filter(multiset<Ip> &ip_pool, int ip_find1, int ip_find2);