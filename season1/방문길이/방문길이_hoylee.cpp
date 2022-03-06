#include <map>
#include <string>
#include <iostream>
using namespace std;

void move_index(int &x, int &y, string &dirs, int &answer, int i)
{
    if((x == -5 && dirs[i] == 'U') || (x == 5 && dirs[i] == 'D') || (y == -5 && dirs[i] == 'L') || (y == 5 && dirs[i] == 'R'))
    {
        answer--;
    }
    else if(dirs[i] == 'U')
    {
        x--;
    }
    else if(dirs[i] == 'D')
        x++;
    else if(dirs[i] == 'R')
        y++;
    else if(dirs[i] == 'L')
        y--;
}

int solution(string dirs) {
    int answer = 0;
    int x = 0; 
    int y = 0;
    answer = dirs.size();
    string start_index = "";
    string end_index = "";
    map<string, int> visit_check;
  0001  
    for(int i = 0; i < dirs.size(); i++)
    {
        start_index = ("" + to_string(x)) + (to_string(y));
        move_index(x, y, dirs, answer, i);
        end_index = ("" + to_string(x)) + to_string(y);
        if(start_index != end_index && (visit_check[start_index + end_index] != 0 || visit_check[end_index + start_index] != 0))
            answer--;
        visit_check[start_index + end_index]++;
        visit_check[end_index + start_index]++;
    }
    return answer;
}
