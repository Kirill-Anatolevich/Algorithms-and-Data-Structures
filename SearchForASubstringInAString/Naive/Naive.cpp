#include <bits/stdc++.h>
#include "additional_function.hpp"
/*
 * The function Naive returns indexes of pattern occurrence
 */

static std::vector<int> Naive(std::string text, std::string pattern) {
    int textSize = text.size();
    int patternSize = pattern.size();
    std::vector<int> ans;
    for (int i = 0; i < textSize - patternSize + 1; ++i) {
        for (int j = 0; j < patternSize; ++j) {
            if (text[i + j] == pattern[j]) {
                if (j == patternSize -1) {
                    ans.push_back(i);
                }
                continue;
            }
            else {
                break;
            }
        }
    }
    checkTheResultVec(ans);
    return ans;
}

int main() {
    std::string text = "abaaababaaba";
    std::string pattern = "aba";
    std::vector<int> res = Naive(text, pattern);
    checkTheResultVec(res);
}
