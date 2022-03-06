#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iostream>
using namespace std;
    void set_index(vector<string> &s_tmp, int i, int j, int &z)
    {
        if(s_tmp[i][j] == 'S')
            return ;
        else if(s_tmp[i][j] == 'L')
        {
            z--;
            if(z < 0) z = 3;
        }
        else if(s_tmp[i][j] == 'R')
        {
            z++;
            if(z > 3) z = 0;
        }
        return ;
    }

    void dfs(int i, int j, int z, int &cnt, vector<vector<vector<int>>> &a_data, vector<string> &s_tmp, vector<int> &answer)
    {
        if (a_data[i][j][z] == 1)
        {
            if(cnt != 0)
                answer.push_back(cnt);
            cnt = 0;
            
            return ;
        }
        
        if(z == 0)
        {
            a_data[i][j][z] = 1;
            if (i - 1 < 0)
                i = a_data.size();
            set_index(s_tmp, i - 1, j, z); // SRL에 따른 z값 변화
            cnt++;
            dfs(i - 1, j, z, cnt, a_data, s_tmp, answer);

        }
        else if(z == 1)
        {
            a_data[i][j][z] = 1;
            if (j + 1 >= a_data[i].size())
                j = -1;
            set_index(s_tmp, i, j + 1, z); // SRL에 따른 z값 변화
            cnt++;
            dfs(i , j + 1, z, cnt, a_data, s_tmp, answer);
            
        }
        
        else if(z == 2)
        {
            a_data[i][j][z] = 1;
            if (i + 1 >= a_data.size())
                i = -1;
            set_index(s_tmp, i + 1, j, z); // SRL에 따른 z값 변화
            cnt++;
            dfs(i + 1, j, z, cnt, a_data, s_tmp, answer);
            
        }
        else if(z == 3)
        {
            a_data[i][j][z] = 1;
            if (j - 1 < 0)
                j = a_data[i].size();
            set_index(s_tmp, i, j - 1, z); // SRL에 따른 z값 변화
            cnt++;
            dfs(i , j - 1, z, cnt, a_data, s_tmp, answer);
            
        }
        return ;
    }

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    vector<vector<vector<int>>> a_data;
    vector<vector<int>> arr;
    vector<string> s_data;
    string s_tmp = "";
    vector<int> tmp (4, 0);
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size(); j++)
        {
            if(isalpha(grid[i][j]))
            {
                s_tmp += grid[i][j];
                arr.push_back(tmp);
            }
            if(j == grid[i].size() - 1)
            {
                s_data.push_back(s_tmp);
                a_data.push_back(arr);
                s_tmp = "";
                arr.clear();
            }
        }
    }

    int cnt = 0;
    //a_data[i][j][z]중 z가 0일떄 위, 1일때 오른쪽, 2일때 아래, 3일때 왼쪽 표현
    for(int i = 0; i < a_data.size(); i++)
    {
        for(int j = 0; j < a_data[i].size(); j++)
        {
            for(int z = 0; z < 4; z++)
            {
                dfs(i, j, z, cnt, a_data, s_data, answer);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
