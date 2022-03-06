#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int go_dungeons(const vector<vector<int>> &dungeons, int k) {
    int cnt = 0;

    for (int i = 0; i < dungeons.size(); i++) {
        if (k < dungeons[i][0]) {
            break;
        }
        else {
            k -= dungeons[i][1];
            cnt++;
        }
    }

    return (cnt);
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    int cur_cnt = 0;

    sort(dungeons.begin(), dungeons.end());
    do {
        cur_cnt = go_dungeons(dungeons, k);
        if (cur_cnt > answer)
            answer = cur_cnt;
    } while(next_permutation(dungeons.begin(), dungeons.end()));


    return answer;
}
