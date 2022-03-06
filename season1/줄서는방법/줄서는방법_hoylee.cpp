#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long pector(int &n)
{
    long long tmp =1;
    for(long long i = 0; i < n; i++)
    {
        tmp = tmp * (i + 1);
    }
    return tmp;
}

void find_digit_number(vector<int> &answer, long long &k, int &n, vector<int> &people_num)
{
    k--;
    long long tmp;
    while((--n) > 0 && k >= 0)
    {
        tmp = pector(n);
        answer.push_back(people_num[k/tmp]);
        people_num.erase(people_num.begin() + (k / tmp));
        if (k == 0) break;
        k = k % tmp;
    }
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> people_num(n);
    for(int i = 0; i < n; i++)
        people_num[i] = i + 1;
    
    find_digit_number(answer, k, n, people_num);

    for(int i = 0; i < people_num.size(); i++)
        answer.push_back(people_num[i]);
    return answer;
}
