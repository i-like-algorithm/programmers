#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map <string, int>m;
    m[words[0]] = 1;
    for(int i = 1; i < words.size(); i++)
    {
        if(words[i][0] != words[i - 1][words[i-1].size()-1] || m[words[i]] != 0)
            return {i % n + 1, i / n + 1};
        m[words[i]]++;
    }
    return {0,0};
}
