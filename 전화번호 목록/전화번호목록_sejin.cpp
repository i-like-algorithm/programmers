#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return (a.size() < b.size());
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end(), cmp);
    
    map<string, int> my_map;
    
    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = 0; j < phone_book[i].size(); j++) {
            if (my_map[phone_book[i].substr(0, j + 1)])
                return false;
        }
        my_map[phone_book[i]] = 1;
    }
    return true;
}
