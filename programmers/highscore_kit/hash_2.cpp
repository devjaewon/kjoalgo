#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string a, string b) {
    return a < b;
}

bool check_include(string short_str, string long_str) {
    for (int i = 0; i < short_str.length(); ++i) {
        if (short_str[i] != long_str[i]) {
            return false;
        }
    }

    return true;
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), compare);

    int size = phone_book.size();

    for (int i = 0; i < size - 1; ++i) {
        if (check_include(phone_book[i], phone_book[i + 1])) {
            return false;
        }
    }

    return true;
}
