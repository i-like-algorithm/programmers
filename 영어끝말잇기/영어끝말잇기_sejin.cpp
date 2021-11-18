#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    map<string, int> word_chk;
    
    for (int i = 0; i < words.size(); i++) {
        if (word_chk[words[i]] || (i > 0 && words[i - 1].back() != words[i].front())) {
            if ((i + 1) % n) {
                answer[0] = (i + 1) % n;
                answer[1] = (i + 1) / n + 1;
            }
            else {
                answer[0] = n;
                answer[1] = (i + 1) / n;
            }
            break;
        }
        else {
            word_chk[words[i]]++;
        }
    }
    
    return answer;
}
