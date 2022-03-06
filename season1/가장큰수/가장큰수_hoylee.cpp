#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int custom_func(string A, string B) {
    if((A + B) > (B + A) )
        return 1;
    else return 0;
}


string solution(vector<int> numbers) {
    string answer = "";
    vector <string> s_numbers;
    
    for(int i = 0; i < numbers.size(); i++)
        s_numbers.push_back(to_string(numbers[i]));
    sort(s_numbers.begin(),s_numbers.end(),custom_func); 
    if (s_numbers[0] == "0")
        return "0";
    for (int i = 0; i < numbers.size(); i++)
        answer += s_numbers[i];

    return answer;
}	
