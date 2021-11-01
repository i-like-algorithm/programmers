#include <string>
#include <vector>
#include <iostream>
using namespace std;

void dfs(int &flag, vector<string> &places, int j, int z, int deep, int *arr)
{

    if (deep == 2)
        return ;
    
    if(arr[0] == j-1 && arr[1] == z) ;
    else if(j - 1 >= 0 && places[j - 1][z] == 'P')
        flag = -1;
    else if(j - 1 >= 0 && places[j - 1][z] == 'O')
        dfs(flag, places, j - 1, z, deep + 1, arr);
    
    if(arr[0] == j+1 && arr[1] == z) ;
    else if(j + 1 < places.size() && places[j + 1][z] == 'P')
        flag = -1;
    else if(j + 1 < places.size() && places[j + 1][z] == 'O')
        dfs(flag, places, j + 1, z, deep + 1, arr);
    
    if(arr[0] == j && arr[1] == z - 1) ;
    else if(z - 1 >= 0 && places[j][z - 1] == 'P')
        flag = -1;
    else if(z - 1 >= 0 && places[j][z - 1] == 'O')
        dfs(flag, places, j, z - 1, deep + 1, arr);
       
    if(arr[0] == j && arr[1] == z + 1) ;
    else if(z + 1 < places[0].size() && places[j][z + 1] == 'P')
        flag = -1;
    else if(z + 1 < places[0].size() && places[j][z + 1] == 'O')
        dfs(flag, places, j, z + 1, deep + 1, arr);

    return ;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int flag = 0;
    int arr[2];
    for (int i = 0; i < places.size(); i++)
    {
        flag = 0;
        for(int j = 0; j < places[i].size() && flag != -1; j++)
        {
            for(int z = 0; z < places[i][j].size() && flag != -1; z++)
            {
                arr[0] = j;
                arr[1] = z;
                if(places[i][j][z] == 'P')
                    dfs(flag, places[i], j, z, 0, arr);
            }
        }
        if (flag == - 1)
            answer.push_back(0);
        else answer.push_back(1);
    }
    return answer;
}
