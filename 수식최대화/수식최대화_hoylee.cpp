#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <cstdlib>
using namespace std;
void dfs2(string order,int o_index, deque<long long> arr1, deque<char> arr2, long long &answer )
{
    deque <long long> tmp1;
    deque <char> tmp2;
    long long int temp = 0;
    int flag =0;
    if(o_index == 3)
    {
        if(answer < abs(arr1.front())) answer = abs(arr1.front());
        return;
    }
    tmp1.push_back(arr1.front());
    arr1.pop_front();
    while (!arr1.empty())
    {
        flag = 0;
        if(arr2.front() != order[o_index])
        {
            tmp2.push_back(arr2.front());
            tmp1.push_back(arr1.front());
            arr2.pop_front();
            arr1.pop_front();
            flag =1;
        }
        else if(order[o_index] == '*')
            temp = tmp1.back() * arr1.front();

        else if(order[o_index] == '+')
            temp = tmp1.back() + arr1.front();

        else if(order[o_index] == '-')
            temp = tmp1.back() - arr1.front();
        if(flag == 0)
        {
            arr1.pop_front();
            arr2.pop_front();
            tmp1.pop_back();
            tmp1.push_back(temp);
        }
    }
    dfs2(order, o_index + 1, tmp1, tmp2, answer);
}

void dfs(long long &answer, char *a_operator, int deep, string order, deque<long long> &arr1, deque<char> &arr2)
{
    char tmp;
    
    if (deep == 3)
    {
        dfs2(order, 0 , arr1, arr2, answer);
        std::cout << std::endl;
    }

    for(int i = 0; i < 3; i++)
    {
        if (a_operator[i] != 'x')
        {
            tmp = a_operator[i];
            a_operator[i] = 'x';
            dfs(answer , a_operator, deep + 1, order + tmp, arr1, arr2);
            a_operator[i] = tmp;
        }
    }
}
long long solution(string expression) {
    long long answer = 0;
    char a_operator[3] = {'*', '+', '-'};
    deque<long long> arr1;
    deque<char> arr2;
    string tmp = "";
    
    for(int i = 0; i < expression.size(); i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
            tmp += expression[i];
        else{
            arr1.push_back(stol(tmp));
            arr2.push_back(expression[i]);
            tmp = "";
        }       
    }
    if(tmp != "") arr1.push_back(stol(tmp));
    dfs(answer, a_operator, 0, "", arr1, arr2);
    return answer;
}
