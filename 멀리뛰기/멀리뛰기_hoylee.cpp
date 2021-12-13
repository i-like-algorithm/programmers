#include <string>
#include <vector>

using namespace std;

void dfs(int &n , int deep, long long &answer)
{
    if(n < deep)
        return;
    else if(n == deep)
    {
        answer++;
        return ;
    }
    
    dfs(n, deep + 1, answer);
    dfs(n, deep + 2, answer);
    return ;
}

long long solution(int n) {
    long long answer = 1;
    
    int pre_number = 1;
    answer = 1;
    while(--n)
    {
        int tmp = answer;
        answer = (answer + pre_number) % 1234567;
        pre_number = tmp;
    }
    //dfs(n, 0, answer);
    return answer;
}
