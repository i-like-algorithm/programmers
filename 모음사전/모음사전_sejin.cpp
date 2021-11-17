#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void repeatPermutation(const string &alpha, int length, vector<string> &words, string &token) {
    if (length == token.size()) {
        words.push_back(token);
        return ;
    }

    for (int i = 0; i < alpha.size(); i++) {
        token[length] = alpha[i];
        repeatPermutation(alpha, length + 1, words, token);
    }
}

int solution(string word) {
    int answer = 0;
    vector<string> words;
    string alpha = "AEIOU";

    for (int i = 1; i <= 5; i++) {
        string token(i, ' ');
        repeatPermutation(alpha, 0, words, token);
    }
    for (auto &el : words) {
        for (auto &el2 : el) {
            cout << el2 << ", " ;
        }
        cout << endl;
    }
    sort(words.begin(), words.end());
    auto it = find(words.begin(), words.end(), word);

    return (it - words.begin() + 1);
}
