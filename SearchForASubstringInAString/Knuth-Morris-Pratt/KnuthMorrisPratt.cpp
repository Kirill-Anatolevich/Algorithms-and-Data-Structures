#include <bits/stdc++.h>
#include "prefix_function.hpp"

std::vector<int> KnuthMorrisPratt(std::string text, std::string pattern, std::vector<int> prefix) {
    int i = 0;
    int j = 0;
    int textSize = (int)text.size();
    int patternSize = (int)pattern.size();
    std::vector<int> ans;
    while (i <= textSize - (patternSize - j)) {
        while (j <= patternSize - 1 && pattern[j] == text[i]) {
            ++i;
            ++j;
        }
        if (j == patternSize) {
            ans.push_back(i - patternSize);
        }
        if (j == 0) {
            ++i;
        }
        j = prefix[j - 1];
    }
    return ans;
}
        

int main() {
    std::string text = "ababababaabab";
    std::string pattern = "ababa";
    std::vector<int> prefix;
    prefix = PrefixFunction(pattern);
    checkTheResultVec(prefix);
    std::vector<int> ans = KnuthMorrisPratt(text, pattern, prefix);
    checkTheResultVec(ans);
}
