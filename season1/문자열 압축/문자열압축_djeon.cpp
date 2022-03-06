#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string s) {
    queue<string> q;
    string top;
    string new_string;
    int answer = s.length();
    int index;
    int flag;
    int num = 1;
    
    // 압축 단위 1~s.length() / 2 순환
    for (int i = 1; i <= s.length() / 2; i++) {
        index = 0;
        // 압축 단위만큼 잘라서 queue에 저장
        while (1) {
            if (index >= s.length()) {
                break ;
            }
            q.push(s.substr(index, i));
            index += i;
        }
        flag = 0;
        new_string = "";
        // queue의 앞에서부터 차례대로 pop해나가면서 비교
        while (1) {
            if (flag == 0) {
                top = q.front();
                q.pop();
                flag = 1;
            }
            if (q.empty() != 1 && top != q.front()) {
                flag = 0;
                if (num > 1) {
                    new_string += (to_string(num) + top);
                    num = 1;
                } else {
                    new_string += top;
                }
            } else if (q.empty() != 1) {
                num++;
                q.pop();
            }
            if (q.empty() == 1){
                if (num > 1) {
                    new_string += (to_string(num) + top);
                    num = 1;
                } else {
                    new_string += top;
                }
                break ;
            }
        }
        // 새롭게 만든 string의 길이가 answer보다 짧을 경우, answer값 갱신
        if (answer > new_string.length()) {
            answer = new_string.length();
        }
    }
    return answer;
}