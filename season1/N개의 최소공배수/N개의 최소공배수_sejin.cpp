#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (1) {
        int reminder = a % b;
        if (reminder == 0)
            return (b);
        a = b;
        b = reminder;    
    }
}

int solution(vector<int> arr) {
    int answer = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        answer = answer * arr[i] / gcd(answer, arr[i]);
    }
    return answer;
}
