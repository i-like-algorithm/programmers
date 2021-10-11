#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> m_map;
    
    for (int i = 0; i < clothes.size(); i++) {
        m_map[clothes[i][1]]++;
    }
    
    for (auto it = m_map.begin(); it != m_map.end(); it++) {
        answer *= (it->second + 1);
    }
    
    return answer - 1;
}
