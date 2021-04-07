#include "z_function.hpp"

int main() {
    std::string text = "mamamaymake";
    std::string pattern = "mama";
    std::string str = pattern+"%"+text;
    std::vector<int> ans = z_function(str);
    checkTheResultVec(ans);
}
