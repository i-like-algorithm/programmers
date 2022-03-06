#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int c_size = citations.size();
    
    sort(citations.begin(), citations.end());
    //0, 1, 3, 5 ,6,
    if (c_size < citations[0])
        return c_size;
    for (int z = 10000; z >= 0; z--)
    {
        for (int i = 0; i < c_size; i++)
        {
            if (citations[c_size - 1 - i] == z)
            {
                if(i + 1 >= z && c_size - 1 - i <= z)
                    return z;
                else break;
            }
            else if (citations[c_size - 1 - i] < z)
            {
                if(i >= z && c_size - 1 - i <= z)
                    return z;
                else break;
            }

        }
    }
    return answer;
}
