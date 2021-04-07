#include "additional_function.hpp"

std::vector<double> BucketSort(std::vector<double> &vec) {
    int vecSize = (int)vec.size();
    std::vector<std::vector<double>> newVec(vecSize);
    std::vector<double> ans;
    for (int i = 0; i < vecSize; ++i) {
        int a = (int)vecSize*vec[i];
        newVec[(int)vecSize*vec[i]].push_back(vec[i]);
    }
    for (int i = 0; i < vecSize; ++i) {
        if (newVec[i].size() != 0) {
            std::sort(newVec[i].begin(), newVec[i].end());
        }
    }
    for (int i = 0; i < vecSize; ++i) {
        for (int j = 0; j < newVec[i].size(); ++j) {
            ans.push_back(newVec[i][j]);
        }
    }
    return ans;
}

int main() {
    std::vector<double> vec = {0.9,0.7, 0.1,0.3,0.4,0.6,0.7,0.1, 0.2, 0.3};
    checkTheResultVec(vec);
    std::vector<double> ans = BucketSort(vec);
    checkTheResultVec(ans);
}
