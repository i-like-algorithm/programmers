#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer(n, s / n);
    int Remainder = s % n;
    
    if(answer[0] == 0)
        return {-1};
    
    int i = n - 1;
    for(int Remainder = s % n; Remainder != 0; Remainder--)
    {
        answer[i]++;
        i--;
    }
    return answer;
}
