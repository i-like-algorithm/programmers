#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(string name) {
    int answer = 0;
    int s_index = 0;
    int left = 0;
    string w_name;
    for(int i = 0; i < name.size(); i++)
        w_name += "A";

    for(int i = 0; i <= floor((double)name.size() / (double)2); i++)
    {
        if(s_index <= i)
            left = name.size() + s_index-i;
        else left = s_index - i;
        if( name[(s_index + i) % name.size()] != w_name[(s_index+i)%name.size()] || name[left] != w_name[left])
        {
            if(name[(s_index + i) % name.size()] != w_name[(s_index+i)%name.size()])
                s_index = (s_index + i) % name.size();
            else s_index = left;
            if(i != 0)
                answer += i;
            int mov_count = (name[s_index] > w_name[s_index]) ? name[s_index] - w_name[s_index]  : w_name[s_index] - name[s_index];
            answer += (26 - mov_count > mov_count) ? mov_count : 26 - mov_count;    
            w_name[s_index] = name[s_index];
            i = 0;
        }
    }
    return answer;
}
