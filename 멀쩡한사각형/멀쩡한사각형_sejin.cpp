#include <cmath>
#include <iostream>

using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    
    for (int i = 1; i < w; i++) {
        answer += floor(((double)h * i) / w);
    }
    
    return answer * 2;
}
