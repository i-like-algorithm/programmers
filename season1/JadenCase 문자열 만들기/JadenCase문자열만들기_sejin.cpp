#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool newWord = true;
    
    for (int i = 0; i < s.size(); i++) {
        if (newWord && s[i] != ' ') {
            if (isalpha(s[i]))
                s[i] = toupper(s[i]);
            newWord = false;
        }
        else {
            if (s[i] == ' ')
                newWord = true;
            else if (isalpha(s[i]))
                s[i] = tolower(s[i]);
        }
    }
    
//     bool space = true;
    
//     for (auto &el : s) {
//         el = tolower(el);
//     }
    
//     for (auto &el : s) {
//         if (space && isalpha(el)) {
//             el = toupper(el);
//         }
//         space = false;
//         if (el == ' ')
//             space = true;
//     }
    return s;
}
