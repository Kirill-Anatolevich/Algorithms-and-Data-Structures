#include <bits/stdc++.h>
#include "additional_function.hpp"

void InsertionSort(std::vector<int>& vec) {
    int vectorSize = vec.size();
    int key;
    int j;
    for (int i = 1; i < vectorSize; ++i) {
        key = vec[i];
        j = i - 1;
        while (j >= 0 && key < vec[j]) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j+1] = key;
    }
}

int main() {
    std::vector<int> vec;
    vec = {10, 48, 90, 5, 3 -8, 9, 51, 21, 96};
    checkTheResultVec(vec);
    InsertionSort(vec);
    checkTheResultVec(vec);
    return 0;
}
