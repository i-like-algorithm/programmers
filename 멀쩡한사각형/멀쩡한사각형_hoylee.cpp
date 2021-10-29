#include <cmath>
#include <iostream>
using namespace std;

long long solution(int w, int h) {
    long long answer = (long long)w * (long long)h;
//    double a = (double)w / (double)h;
    long long tmp = 0;
    for(long long i = 1; i <= h; i++)
        tmp += ceil(i * (double)w / (double)h) - floor((long long)(i - 1) * (double)w / (double)h);
    return answer - tmp;
}
// 22번쨰 줄 처럼, 미리 w/h를 하면 정확도가 떨어질수 있다. 
// 정확도를 좀더 높여주기위해, w * i를해서 큰수를 나눈뒤에 /h 나누셈을 해주면 더 정확해진다.
// 25번쨰 줄에 answer -=으로 바로 뺴주면 틀리게 나온다. 
// 이유를 모르겠다.
