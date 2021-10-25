#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

void DFS(vector<string> &data, int &answer, vector <char> character, int deepth, string make_value)
{
    int distance = 0;
    if(deepth == 8)
    {
        for(int i = 0; i < data.size(); i++)
        {
            distance = (int)make_value.find(data[i][0]) - (int)make_value.find(data[i][2]);
            if(data[i][3] == '>' && abs(distance) - 1 <= (data[i][4] - '0'))
                return;
            else if (data[i][3] == '<' && abs(distance) - 1 >= (data[i][4] - '0'))
                return;
            else if(data[i][3] == '=' && abs(distance) - 1 != data[i][4] - '0') // data[i][4] - '0' 이거 대신에 처음에 0 을넣었는데 실패나옴. 왜안되나요?...
                return ;
        }
        answer++;
        return ;
    }
    for(int i = 0; i < character.size(); i++)
    {
        if(character[i] != 0)
        {
            char tmp = character[i];
            character[i] = 0;
            DFS(data, answer, character, deepth + 1, make_value + tmp);
            character[i] = tmp;
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    int deepth = 0;
    string make_value;
    vector<char> character = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    DFS(data, answer, character, deepth, make_value);
    return answer;
}
