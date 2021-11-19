#include <string>
#include <vector>
#include <iostream>
#include <map>
//#include <pair>
using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    double x_denominator; //분모
    double x_molecule;  // 분자
    double y_denominator; //분모
    double y_molecule;  // 분자
    
    double x;
    double y;
    
    int x_max = -2147483648;
    int x_min = 2147483647;
    int y_min = 2147483647;
    int y_max = -2147483648;
    
    map<pair<int,int>, int> m_data;
    //vector<pair<int,int>> a_data;

    for(int i = 0; i < line.size() - 1; i++)
    {
        for(int j = i + 1; j < line.size(); j++)
        {
            x_denominator = (long long)line[i][0] * line[j][1] - (long long)line[i][1] * line[j][0];
            x_molecule = (long long)line[i][1] * line[j][2] - (long long)line[i][2] * line[j][1];
            
            y_denominator = line[i][0] * line[j][1] - line[i][1] * line[j][0];
            y_molecule = line[i][2] * line[j][0] - line[i][0] * line[j][2];
            
            if(x_denominator != 0)
            {
                x = x_molecule / x_denominator;
                y = y_molecule / y_denominator;
            }
            if(x_denominator != 0 && x - (int)x == 0 && y - (int)y == 0)
            { 
                if(x_min > x)
                    x_min = x;
                if(x_max < x)
                    x_max = x;
                
                if(y_min > y)
                    y_min = y;
                if(y_max < y)
                    y_max = y;
                m_data[{(int)x,(int)y}]++;
            }
        }
    }
    string tmp ="";
    for(; y_min <= y_max; y_max--)
    {
        tmp = "";
        for(int x_min_tmp = x_min; x_min_tmp <= x_max; x_min_tmp++)
        {
            if(m_data[{x_min_tmp, y_max}] != 0)
                tmp += "*";
            else tmp += ".";
        }
        answer.push_back(tmp);
    }
    return answer;
}
