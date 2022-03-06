#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int str_dump(string A, string B)
{
    int cnt = 0;

    for(int i = 0; i < B.size(); i++)
    {
        if(A[i] != B[i])
        {
            cnt++;
            if(cnt == 3)
                break;
        }
    }
    return cnt;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    long long num;
    string bit_num;
    map<long long, string> m;

    bit_num ="";
    for(int i = 0; i < numbers.size(); i++)
    {
        bit_num ="";
        num = numbers[i];
        // if(num % 2 == 1)
        // {}
        if(m[num] == "")
        {
            while(num != 0)
            {
                char tmp = (num % 2) + '0';
                bit_num = bit_num + tmp;
                num /= 2;
            }
            m[numbers[i]] = bit_num;
        }
        else
            bit_num = m[num];
        long long cnt = 1;
        while(1)
        {
            if(m[numbers[i] + cnt] == "")
            {
                for(int j = 0; j < bit_num.size(); j++)
                {
                    if(bit_num[j] == '0')
                    {
                        bit_num[j] = '1';
                        break;
                    }
                    else if(bit_num[j] == '1')
                    {
                        bit_num[j] = '0';
                        if(j == bit_num.size() - 1)
                        {
                            bit_num = bit_num + '1';
                            break;
                        }
                    }
                }
                m[numbers[i] + cnt] = bit_num;
            }
            else
                bit_num = m[numbers[i] + cnt];
            cnt++;
            if(2 >= str_dump(m[numbers[i]], bit_num))
                break;
        }
        answer.push_back(numbers[i]+cnt - 1);
    }
    
    return answer;
}
