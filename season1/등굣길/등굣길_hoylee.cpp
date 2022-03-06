#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> public_visit(n, vector<int>(m, 0));
    // map<pair<int,int>, int> p_map;
    // for(int i = 0; i < puddles.size(); i++)
    //     p_map[{puddles[i][1] - 1, puddles[i][0] - 1}] = 1;
    for(int i = 0; i < puddles.size(); i++)
    {
        public_visit[puddles[i][1] - 1][puddles[i][0] - 1] = -1;
    }
    public_visit[0][0] = 1;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            //끝 부분 처리
            if(i == n -1 && j == m - 1 || public_visit[i][j] == 0 || public_visit[i][j] == -1)
                ;
            else if(j == m - 1 || i == n - 1)
            {
                if(j == m - 1 && public_visit[i + 1][j] != -1)
                    public_visit[i + 1][j] = (public_visit[i][j] + public_visit[i + 1][j] ) % 1000000007 ;
                else if(i == n - 1 && public_visit[i][j + 1] != -1)
                    public_visit[i][j + 1] = (public_visit[i][j] + public_visit[i][j + 1] ) % 1000000007 ;
            }
            else
            {
                if(public_visit[i + 1][j] != -1 )
                    public_visit[i + 1][j] = (public_visit[i][j] + public_visit[i + 1][j] ) % 1000000007 ;
                if(public_visit[i][j + 1] != -1 )
                    public_visit[i][j + 1] = (public_visit[i][j] + public_visit[i][j + 1] ) % 1000000007 ;
            }
            
        }
    }
    // for(int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         std::cout << public_visit[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    return answer = public_visit[n - 1][m - 1] % 1000000007 ;
}
