#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool check(vector<char> &character, string condition, char compare) {
    int address1 = find(character.begin(), character.end(), condition[0]) - character.begin();
    int address2 = find(character.begin(), character.end(), condition[2]) - character.begin();
    int gap = abs(address2 - address1);
    
    if (compare == '=') {
        if (gap == condition[4] - '0' + 1)
            return true;
    }
    else if (compare == '<') {
        if (gap < condition[4] - '0' + 1)
            return true;
    }
    else if (compare == '>') {
        if (gap > condition[4] - '0' + 1)
            return true;
    }
    return false;
}

int solution(int n, vector<string> data) {
    vector<char> character = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    int answer = 0;
    bool flag;
    do {
        flag = true;
        for (int i = 0; i < n; i++) {
            flag = check(character, data[i], data[i][3]);
            if (flag == false)
                break ;
        }
        if (flag == true)
            answer++;
    } while (next_permutation(character.begin(), character.end()));
    return answer;
}