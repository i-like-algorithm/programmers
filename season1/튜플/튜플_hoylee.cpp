#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> arr;
    vector<int> tmp;
    string num_tmp = "";
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
            num_tmp += s[i];
        else if ((s[i] == ',' || s[i] == '}') && num_tmp != "")
        {
            tmp.push_back(stoi(num_tmp));
            num_tmp = "";
            if(s[i] == '}')
            {
                arr.push_back(tmp);
                tmp.clear();
            }
        }
    }
    sort(arr.begin(), arr.end(), compare);
    for(int i = 0; i < arr.size(); i++)
        sort(arr[i].begin(), arr[i].end());
    answer.push_back(arr[0][0]);
    for(int i = 1; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[i].size(); j++)
        {
            if (j == arr[i].size() - 1)
                answer.push_back(arr[i][j]);
            else if(arr[i][j] != arr[i - 1][j])
            {
                answer.push_back(arr[i][j]);
                break;
            }
        }
    }
    return answer;
}
