#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

bool cache_hit(list<string> &cache, const string &target) {
    auto it = find(cache.begin(), cache.end(), target);
    if (it != cache.end()) {
        cache.erase(it);
        return (true);
    }
    return (false);
}

string tolowerstr(const string str) {
    string result;
    
    for (int i = 0; i < str.size(); i++) {
        result += tolower(str[i]);
    }
    return result;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> cache;
    
    for (auto &el : cities) {
        el = tolowerstr(el);
    }
    
    for (int i = 0; i < cities.size(); i++) {
        if (cacheSize == 0)
            answer += 5;
        else { 
            if (cache_hit(cache, cities[i]))
                answer++;
            else
                answer += 5;
            if (cache.size() == cacheSize)
                cache.pop_front();
            cache.push_back(cities[i]);
        }
    }
    return answer;
}
