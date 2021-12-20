#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int make_combination_and_find(vector<map<long long, int>> &dp, int &zz, int &number, long long &cop, int &cnt)
{
    for(auto it2 = std::begin(dp[zz]); it2!=std::end(dp[zz]); ++it2)
    {
        for (auto it = std::begin(dp[cnt - zz]); it!=std::end(dp[cnt - zz]); ++it)
        {
            if((*it2).first != 0 && (*it).first != 0 ){
                if((*it).first * (*it2).first == number || (*it).first / (*it2).first == number || (*it).first + (*it2).first == number || (*it).first - (*it2).first == number || cop == number || (*it2).first / (*it).first == number  || (*it2).first -  (*it).first == number )
                {
                    return cnt + 2;
                }
                dp[cnt + 1][(*it).first * (*it2).first]++;
                dp[cnt + 1][(*it).first + (*it2).first]++;
                dp[cnt + 1][(*it).first / (*it2).first]++;
                dp[cnt + 1][(*it).first - (*it2).first]++;
                dp[cnt + 1][(*it2).first / (*it).first]++;
                dp[cnt + 1][(*it2).first - (*it).first]++;
                dp[cnt + 1][cop]++;
            }
        }
    }
    return -1;
}

int solution(int N, int number) {
    int answer = -1;
    vector<map<long long, int>> dp(10);
    dp[0][N] ++;
    int cnt = 0;
    long long cop = N;
    if(N == number)
        return 1;
    while(cnt != 9)
    {
        for(int zz = 0; zz <= cnt / 2; zz++)
        {       
            // cnt 4를 만들때 0,4  1,3   2,2 가 필요해서 사용
            std::cout << zz << " " << cnt - zz << "   ";
            cop = cop * 10 + N; // ex 5, 55 , 555, 5555;
            answer = make_combination_and_find(dp, zz, number, cop, cnt);
            if(answer != -1)
                return answer;
        }
        std::cout << std::endl;
        cnt++;
    }
    return answer;
}
