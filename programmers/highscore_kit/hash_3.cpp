#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector< vector<string> > clothes) {
    unordered_map<string, int> clothes_count;

    for (auto pair : clothes) {
        string category = pair[1];

        clothes_count[category]++;
    }

    int ret = 1;
    for (auto& it : clothes_count) {
        ret *= (it.second + 1);
    }
    
    return ret - 1;
}
