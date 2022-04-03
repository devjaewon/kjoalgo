#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare(unordered_map<string, int> prev, unordered_map<string, int> next) {
    return prev["play"] > next["play"];
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    // 1. 장르별 재생횟수, 고유 아이디별 재생횟수 측정
    // { [장르]: Array<{ id: int, play: int }> }
    // { [장르]: int }
    unordered_map<string, vector<unordered_map<string, int>>> counts;
    unordered_map<string, int> total_counts;

    for (int id = 0; id < genres.size(); ++id) {
        string genre = genres[id];
        unordered_map<string, int> element;

        element["id"] = id;
        element["play"] = plays[id];
        counts[genre].push_back(element);
    }

    for (auto& it : counts) {
        string genre = it.first;
        vector<unordered_map<string, int>> elements = it.second;
        int sum = 0;

        sort(elements.begin(), elements.end(), compare);

        for (auto &element : elements) {
            sum += element["play"];
        }
        counts[genre] = elements;
        total_counts[genre] = sum;
    }


    // 2. 장르 순서 측정.
    // [장르, 장르, 장르]
    vector<string> genre_orders;
    for (auto& it : counts) {
        genre_orders.push_back(it.first);
    }

    function<bool(string, string)> lamda = [&](string a, string b) {
        return total_counts[a] > total_counts[b];
    };

    sort(genre_orders.begin(), genre_orders.end(), lamda);

    // 3. 장르 배열 => 공유아이디 배열
    vector<int> id_orders;

    for (auto genre : genre_orders) {
        auto elements = counts[genre];
        int size = elements.size();

        for (int i = 0; i < 2; ++i) {
            if (i > size - 1) {
                break;
            }

            id_orders.push_back(elements[i]["id"]);
        }
    }

    return id_orders;
}
