#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(string a, string b){
    string aa;
    string bb;
    
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] >= '0' && a[i] <= '9')
            break;
        aa += tolower(a[i]);    
    }
    for(int i = 0; i < b.size(); i++)
    {
        if(b[i] >= '0' && b[i] <= '9')
            break;
        bb += tolower(b[i]);
    }
    if(aa < bb)
        return 1;
    return 0;
}

bool s_compare(int start_index, int now_index, vector<string> files)
{
    for(int i = 0 ; i < files[now_index].size(); i++)
    {
        if((files[start_index][i] >= '0' && files[start_index][i] <= '9') && (files[now_index][i] >= '0' && files[now_index][i] <= '9'))
            return 1;
        else if (tolower(files[now_index][i]) != tolower(files[start_index][i]))
        {
            return 0;
        }
    }
    return 1;
}

bool compare2(string a, string b)
{
    int i;
    string aa;
    string bb;
    for (i= 0; i < a.size(); i++)
        if(a[i] >= '0' && a[i] <= '9')
            break;
    for(int j  = i; j < a.size(); j++)
    {
        if(a[j] >= '0' && a[j] <= '9')
            aa +=  a[j];
        else break;
    }
    for(int j  = i; j < b.size(); j++)
    {
        if(b[j] >= '0' && b[j] <= '9')
            bb += b[j];
        else break;
    }
    if(stoi(aa) < stoi(bb))
        return 1;
    else return 0;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    stable_sort(files.begin(), files.end(), compare);
    int start_index = 0;
    int i;
    
    for(i = 1 ; i < files.size(); i++)
    {
        if(s_compare(start_index, i, files) == 1)
            ;
        else
        {
            stable_sort(files.begin() + start_index, files.begin() + i , compare2);
            start_index = i;
        }
    }
    stable_sort(files.begin() + start_index, files.begin() + i , compare2);
    // sort의 경우 00 이나 0 이런식으로 같은 값들을 정렬할떄 불안정하게 정렬됨. 그래서 stable_sort를 사용.
    return answer = files;
}
