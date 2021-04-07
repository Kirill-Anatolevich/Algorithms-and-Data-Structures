#pragma once
#include <bits/stdc++.h>
#include "/home/spiridonovk/UsefulPrograms/additional_function.hpp"

static std::vector<int> PrefixFunction(std::string pattern) {
    int patternSize = (int) pattern.length();
    std::vector<int> prefix(patternSize);
    prefix[0] = 0;
    char x;
    int v;
    for (int i = 1; i < patternSize; ++i) {
        x = pattern[i];
        v = prefix[i - 1] - 1;
        while (v != -1 && pattern[v+1] != x) {
            v = prefix[v] - 1;
        }
        if (pattern[v + 1] == x) {
            prefix[i] = prefix[i - 1] + 1;
        }
        else {
            prefix[i] = 0;
        }
    }
    return prefix;
}
