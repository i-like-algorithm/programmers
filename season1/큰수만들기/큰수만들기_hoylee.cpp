#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int start_index = 0;
    for (int i = 0; i < k; i++)
    {
        for(int j = start_index; j < number.size(); j++ )
        {
            if(j != number.size() - 1 && number[j] < number[j + 1])
            {
                number = number.substr(0, j) + number.substr(j + 1, number.size() - j - 1);
                break;
            }
            else if(j == number.size() - 1)
                number = number.substr(0, number.size() - 1);
            start_index = (j == 0) ? 0 : j - 1;
        }
    }
    return answer  = number;
}

