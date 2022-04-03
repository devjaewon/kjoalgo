#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    // 완료일 기준으로 계산
    // 첫번째 작업부터 하나씩 꺼내면서 prev max < next 이면 끊고
    // prev >= next 이면 기다렸다가 max 값보다 < next 인 시점에 끊기

    vector<int> completes;
    for (int i = 0; i < progresses.size(); ++i) {
        int progress = progresses[i];
        int speed = speeds[i];

        completes.push_back(ceil((100 - progress) / (float)speed));
    }

    int pivot = 0;
    int p_max = 0;
    for (int complete : completes) {
        if (pivot == 0) {
            pivot = 1;
            p_max = complete;
            continue;
        }

        if (complete > p_max) {
            answer.push_back(pivot);
            pivot = 1;
            p_max = complete;
            continue;
        }

        pivot++;
        p_max = max(p_max, complete);
    }

    if (pivot > 0) {
        answer.push_back(pivot);
    }

    return answer;
}
