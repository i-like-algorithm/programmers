#include <string>
#include <vector>

using namespace std;

void dfs(const int &n, long long make_retangle, long long &answer)
{
    if(make_retangle > n)
        return;
    else if(make_retangle == n)
    {
        answer++;
        return;
    }
    dfs(n, make_retangle + 1, answer);
    dfs(n, make_retangle + 2, answer);
    return ;
}

int solution(int n) {
    int answer = 0;
    long long tmp = 0;
    dfs(n, 0, tmp);

//     n --;
//     n --;
//     long long first = 1;
//     long long second = 2;

//     while(n-- > 0)
//     {
//         tmp = first + second % 1000000007;
//         first = second;
//         second = tmp;
//     }
    answer = (tmp % 1000000007);
    return answer;
}
