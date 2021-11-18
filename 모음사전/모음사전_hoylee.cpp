#include <string>
#include <vector>

using namespace std;

void dfs(string tmp, int deepth, string &word, int &answer, vector<string> &alpha, int &flag)
{
    if(tmp == word)
    {
        flag = 1;
        return ;
    }
    
    if(deepth == 5)
        return ;
    //tmp == AAAA; 
    for(int i = 0;  i < 5 && flag == 0; i++)
    {
        answer++;
        dfs(tmp + alpha[i],deepth + 1, word, answer, alpha, flag);
    }
}

int solution(string word) {
    int answer = 0;
    vector <string> alpha = {"A", "E", "I", "O", "U"};
    int flag = 0;
    dfs("", 0, word, answer, alpha, flag);

    return answer;
}
