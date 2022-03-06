#include <string>
#include <vector>
#include <iostream>
using namespace std;

void color_visit_table(vector<vector<int>> &visit_table, int &n, int &deep, int &i, int flag)
{
    int table_column = 1;
    for(int table_row = deep + 1; table_row < n; table_row++)
    {
        if(i - table_column >= 0 && i + table_column < n)
        {
            visit_table[table_row][i - table_column] += flag;
            visit_table[table_row][i + table_column] += flag;
        }
        else if(i - table_column >= 0)
            visit_table[table_row][i - table_column] += flag;
        else if(i + table_column < n)
            visit_table[table_row][i + table_column] += flag;
        visit_table[table_row][i] += flag;
        table_column++;
    }
}
void dfs(vector<vector<int>> visit_table, int &answer, int &n, int deep)
{
    if(deep == n)
    {
        answer++;
        return ;
    }
    for(int i = 0; i < n; i++)
    {
        if(visit_table[deep][i] == 0)
        {
            color_visit_table(visit_table, n, deep, i, 1);
            dfs(visit_table, answer, n, deep + 1);
            color_visit_table(visit_table, n, deep, i, -1);
        }
    }
}

int solution(int n) {
    int answer = 0;
    vector<vector<int>> visit_table(n, vector<int>(n,0));
    
    dfs(visit_table, answer, n, 0);
    return answer;
}
