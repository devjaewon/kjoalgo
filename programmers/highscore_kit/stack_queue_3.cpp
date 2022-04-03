#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    vector<int> onbridges;
    vector<int> positions;
    vector<int> completes;
    int total = truck_weights.size();
    int t = 0;
    
    auto get_current_weight = [&]() {
        int sum = 0;
        for (int w : onbridges) sum += w;
        
        return sum;
    };
    
    auto move = [&]() {
        int dest = positions.size();
        
        for (int i = 0; i < dest; ++i) {
            if (positions[i] < bridge_length - 1) { // 움직일 수 있음
                positions[i]++;
                continue;
            }
            
            completes.push_back(1);
            onbridges.erase(onbridges.begin() + i);
            positions.erase(positions.begin() + i);
            i--;
            dest--;
        }
    };
    
    auto come = [&]() {
        if (truck_weights.size() <= 0) return;
        
        int current_count = onbridges.size();
        int max_count = bridge_length;
        
        if (max_count <= current_count) return;
        
        int current_weight = get_current_weight();
        int max_weight = weight;
        int next_weight = truck_weights[0];
        
        if (current_weight + next_weight > max_weight) return;
        
        truck_weights.erase(truck_weights.begin());
        onbridges.push_back(next_weight);
        positions.push_back(0);
    };
    
    while (completes.size() < total) {
        move();
        come();
        t++;
    }
    
    return t;
}
