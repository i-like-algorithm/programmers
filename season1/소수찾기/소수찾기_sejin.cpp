#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

set<int> my_set;

bool find_primenum(int num) {
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int conv_int(vector<char> perm) {
    int result = 0;
    
    for (int i = 0; i < perm.size(); i++) {
        result = result * 10 + perm[i] - '0';
    }
    return (result);
}

void repeatPermutation(vector<pair<char, bool>> check, vector<char> perm, int depth) {
    if (depth == perm.size()) {
        my_set.insert(conv_int(perm));
        return ;
    }
    
    for (int i = 0; i < check.size(); i++) {
        if (check[i].second == true)
            continue;
        else {
            check[i].second = true;
            perm[depth] = check[i].first;
            repeatPermutation(check, perm, depth + 1);
            check[i].second = false;
        }
    }
}

void make_permutation(string numbers, int cnt) {
    vector<char> perm(cnt);
    vector<pair<char, bool>> check;
    for (auto &el : numbers) {
        check.push_back(pair<char, bool>(el, false));
    }
    repeatPermutation(check, perm, 0);  
}

int solution(string numbers) {
    int answer = 0;
    
    for (int i = numbers.size(); i > 0; i--) {
        make_permutation(numbers, i);    
    }
    
    for (auto it = my_set.begin(); it != my_set.end(); it++) {
        if (find_primenum(*it)) {
            answer++;
        }
    }
    
    return answer;
}
