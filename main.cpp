#include "ip_filter.h"
#include <iostream>
#include <sstream>
using namespace std;


int main(int argc, char const *argv[]) {

       try {
        multiset<Ip> ip_pool;
        for (string line; getline(std::cin, line);) {
            if (line.empty()) {
                break;
            }
            ip_pool.insert(SplitBy(string_view(line), '.'));
        }

        // TODO reverse lexicographically sort
           {
               stringstream ss;
               ss = filter(ip_pool, 0, 0);
               cout << ss.str();
           }

        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output
           {
               stringstream ss;
               ss = filter(ip_pool, 1, 0);
               cout << ss.str();
           }
        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
           {
               stringstream ss;
               ss = filter(ip_pool, 46, 70);
               cout << ss.str();
           }
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
           {
               stringstream ss;
               ss = filter(ip_pool, 46, 0);
               cout << ss.str();
           }


    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
