#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> all_data;
    vector<int> tmp;
    int max = 0; 
    
    for(int i = 0; i < n; i++)
    {
        max += i + 1;
        // tmp.assign(i + 1, 0);
        // all_data.push_back(tmp);
        all_data.push_back(vector<int> (i+1, 0));
        //all_data.emplace_back(i+1, 0); //위 처럼 굳이 vector tmp 를 만들지 않고, emplace를 쓰면 바로 만들어 줌.
    }

    for(int i = 0; i < n; i++)
    {
        all_data[i][0] = i + 1;
        all_data[n - 1][i] = i + n;
    }
    int push_data = all_data[n - 1][n - 1];
    int flag = 0; // 0 위, 1 아래, 2 오른쪽
    int x = n - 1, y = n - 1;
    while(max > push_data)
    {
        if(flag == 0 && all_data[x - 1][y - 1] == 0)
        {
            all_data[x - 1][y - 1] = ++push_data;
            x--; y--;
        }
        
        else if(flag == 1 && all_data[x + 1][y] == 0)
        {
            all_data[x + 1][y] = ++push_data;
            x++;
        }
        
        else if(flag == 2 && all_data[x][y + 1] == 0)
        {
            all_data[x][y + 1] = ++push_data;
            y++;
        }
        else if( flag == 0 )
            flag = 1;
        else if (flag == 1)
            flag = 2;
        else if (flag == 2)
            flag = 0;
        
    }
    
    for(int i = 0; i < all_data.size(); i++)
        for(int j = 0; j < all_data[i].size(); j++)
            answer.push_back(all_data[i][j]);

    return answer;
}
