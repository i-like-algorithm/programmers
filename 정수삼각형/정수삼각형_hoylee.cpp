#include <string>
#include <vector>
#include <iostream>
using namespace std;
void     Make_max_triangle(vector<vector<int>> &triangle, int &answer)
{
    for(int i = 0; i < triangle.size() - 1; i++)
    {
        for(int j = 0; j < triangle[i].size(); j++)
        {
            if(j == triangle[i].size() - 1 || triangle[i][j] > triangle[i][j + 1])
                triangle[i + 1][j+1] = triangle[i + 1][j+1] + triangle[i][j];
            if(j == 0 || triangle[i][j] > triangle[i][j - 1])
                triangle[i + 1][j] = triangle[i + 1][j] + triangle[i][j];
        }
    }
}
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int triangle_size = triangle.size();
    Make_max_triangle(triangle, answer);
    for(int i = 0; i < triangle[triangle_size - 1].size(); i++)
        if(answer < triangle[triangle_size - 1][i])
            answer = triangle[triangle_size - 1][i];
    return answer;
}
