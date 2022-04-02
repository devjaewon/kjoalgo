#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * @brief 
 * 마라톤 경기
 * 완주하지 못한 참여자 찾기
 */
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> checker;
    
    for (string person : participant) {
        if (checker.count(person)) {
            checker[person]++;
        } else {
            checker[person] = 1;
        }
    }
    
    for (string person : completion) {
        if (checker[person] > 1) {
            checker[person]--;
        } else {
            checker.erase(person);
        }
    }
    
    answer = checker.begin()->first;
    
    return answer;
}