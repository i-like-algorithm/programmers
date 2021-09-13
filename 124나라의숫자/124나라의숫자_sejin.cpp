#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    string num = "0124";
    
    while (n)
    {
        if (n % 3 != 0)
        {
            answer += num[n % 3];
            n /= 3;
        }
        else
        {
            answer += "4";
            n = n / 3 - 1;
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
