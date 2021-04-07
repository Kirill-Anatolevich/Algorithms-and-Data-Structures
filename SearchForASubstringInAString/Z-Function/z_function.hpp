#include <bits/stdc++.h>
#include "/home/spiridonovk/UsefulPrograms/additional_function.hpp"

std::vector<int> z_function (std::string str) {
    int strSize = (int)str.size();
    std::vector<int> z(strSize);
    for (int i = 1, l = 0, r = 0; i < strSize; ++i) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < strSize && str[z[i]] == str[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] -1 > r) {
            l = i;
            r = i + z[i] -1;
        }
    }
    return z;
}
