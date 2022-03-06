#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<string> board) {
    vector < vector <pair<char, int>> > v(m,vector <pair<char, int>>(n,{0,0}));
    vector < vector <pair<char, int>> > v2(m,vector <pair<char, int>>(n,{'!',0}));
    int answer = 0;
    char charic[8] =  {'R', 'M', 'A', 'F', 'N', 'T', 'J', 'C'};
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            v[i][j].first = board[i][j];

    int flag = 0;
    vector<int> v2_index(n);

    while(1)
    {
        flag = 0;
        for(int j = 0; j < n; j++)
        {
            for(int i = m - 1; i >= 0; i--)   
            {
                if((i > 0 && j < n - 1) && (v[i][j].first != '!' && v[i][j].first == v[i - 1][j].first && v[i][j].first == v[i][j + 1].first && v[i][j].first == v[i - 1][j + 1].first))
                {
                    v[i][j].second = 1;
                    v[i - 1][j].second = 1;
                    v[i][j + 1].second = 1;
                    v[i - 1][j + 1].second = 1;
                    flag = 1;
                }
                if(v[i][j].first != '!' && v[i][j].second == 0)
                {
                    v2[m - 1 - v2_index[j]][j] = {v[i][j].first ,0};
                    v2_index[j]++;
                }
            }
        }
        v = v2;
        v2_index.assign(n,0);
        for(int z= 0; z < v2.size(); z++)        
            v2[z].assign(n,{'!', 0});
        if (flag == 0) break;
    }
    for(int i =0 ; i < m; i++)
        for (int j = 0; j < n; j ++)
            if(v[i][j].first == '!')
                answer++;
    
    return answer;
}
