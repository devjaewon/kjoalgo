#include <string>
#include <vector>

using namespace std;

int find_high_priority(vector<int> priorities) {
    if (priorities.size() <= 1) return -1;
    
    int target_priority = priorities[0];
    for (int i = 1; i < priorities.size(); ++i) {
        if (priorities[i] > target_priority) {
            return i;
        }
    }
    
    return -1;
}

void shift(vector<int>* priorities, vector<int>* idxes) {
    int p = priorities->at(0);
    int idx = idxes->at(0);

    priorities->erase(priorities->begin());
    idxes->erase(idxes->begin());

    priorities->push_back(p);
    idxes->push_back(idx);
}

int solution(vector<int> priorities, int location) {
    // idx 큐도 추가로 하나 생성
    vector<int> idxes;
    for (int i = 0; i < priorities.size(); ++i) idxes.push_back(i);
    
    // 후순위에 더 우선순위 작업이 있는지 확인
    int order = 0;
    while (priorities.size() > 0) {
        // 우선순위 높은 작업이 있다면 대기열 마지막으로 이동
        if (find_high_priority(priorities) > 0) {
            shift(&priorities, &idxes);
        } else {
            int loc = idxes[0];
            // 우선순위 작업처리 (큐에서 제거)
            priorities.erase(priorities.begin());
            idxes.erase(idxes.begin());

            // idx 와 확인하고자 하는 location 이 같다면 return
            order++;
            if (loc == location) {
                return order;
            }
        }
    }
    
    return order;
}