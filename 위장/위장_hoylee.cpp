#include <string>
#include <vector>
#include <map>
#include<iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    map<string, int> m;
    bool answer = true;
    
    for(int i = 0; i < phone_book.size(); i++)
        m.insert({ phone_book[i], 1 });
    for(int i = 0; i < phone_book.size(); i++)
    {
        m.erase(phone_book[i]);
        for (int z= 1; z <= phone_book[i].size(); z++)
            if (m.find(phone_book[i].substr(0, z)) != m.end())
                return false;
        m.insert({phone_book[i], 1});
    }
    return true;
}
