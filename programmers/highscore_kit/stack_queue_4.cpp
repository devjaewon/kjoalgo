#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int len = prices.size();

    for (int i = 0; i < len; ++i) {
        int price = prices[i];
        int ret = 0;

        for (int j = i + 1; j < len; ++j) {
            if (prices[j] >= price) {
                ret++;
            } else {
                ret++;
                break;
            }
        }

        answer.push_back(ret);
    }

    return answer;
}
