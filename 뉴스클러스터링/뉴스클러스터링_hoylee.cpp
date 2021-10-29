#include <string>
#include <cctype>
#include <iostream>
#include <map>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map <string, int> m;
    map <string, int> m2;
    map <string, int> make_union;
    map <string, int> make_intersection;
    
    string r_str1, r_str2 = {"", ""};
    for(int i = 0; i < str1.size(); i++)
    {
        if(isalpha(str1[i]) != 0)
            r_str1 += toupper(str1[i]);
        else r_str1 +=" ";
    }   
    for(int i = 0; i< str2.size(); i++)
    {
        if(isalpha(str2[i]) != 0)
            r_str2 += toupper(str2[i]);
        else r_str2 += " ";
    }

    //substr은 더 느리지 않을까?
    string tmp = "";
    for(int i = 0; i < r_str1.size() - 1; i++)
    {
        if(r_str1[i + 1] == ' ')
            i++;
        else if(r_str1[i] != ' ')
        {
        tmp += r_str1[i];
        tmp += r_str1[i + 1];
        m[tmp]++;
        tmp = "";
        }
    }
    for(int i = 0; i< r_str2.size() - 1; i++)
    {
        if(r_str2[i + 1] == ' ')
            i++;
        else if(r_str2[i] != ' ')
        {
        tmp += r_str2[i];
        tmp += r_str2[i + 1];
        m2[tmp]++;
        tmp = "";
        }
    }
        
    for(auto iter = m.begin(); iter != m.end(); iter++)
    {
        make_union[iter->first] = iter->second;
        make_intersection[iter->first] = -1 * iter->second;
    }
    for(auto iter = m2.begin(); iter != m2.end(); iter++)
    {
        if(make_union[iter->first] != 0)
            make_union[iter->first] = max(make_union[iter->first], iter->second);
        else make_union[iter->first] = iter->second;
        if(make_intersection[iter->first] != 0)
            make_intersection[iter->first] = min(make_intersection[iter->first] * - 1, iter->second);
    }
    
    long long int union_value = 0; 
    for(auto iter = make_union.begin(); iter != make_union.end(); iter++)
        union_value += iter->second;
    long long int intersection_value = 0;
    for(auto iter = make_intersection.begin(); iter != make_intersection.end(); iter++)
        if(iter->second > 0) intersection_value += iter->second;
    if(union_value == 0)
        return 65536;
    answer = (65536 *  intersection_value) / union_value;

    return answer;
}
