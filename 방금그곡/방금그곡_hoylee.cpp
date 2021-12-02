#include <string>
#include <vector>
#include<sstream>
#include <iostream>
using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    vector<vector<string>> split_m_info(musicinfos.size());
    vector<int> play_length (musicinfos.size(), 0);
    int find_music_length = 0;
    
    for(int i = 0; i < musicinfos.size(); i++)
    {
        int string_index = 0;
        istringstream ss(musicinfos[i]);
        string stringBuffer;
        stringBuffer = "";
        while (getline(ss, stringBuffer, ','))
        {
            if(string_index == 0)
            {
                play_length[i] -= (stoi(stringBuffer.substr(0, 2)) * 60);
                play_length[i] -= stoi(stringBuffer.substr(3, 2));
            }
            else if(string_index == 1)
            {
                play_length[i] += stoi(stringBuffer.substr(0, 2)) * 60;
                play_length[i] += stoi(stringBuffer.substr(3, 2));
            }
            split_m_info[i].push_back(stringBuffer);
            string_index++;
        }
        
        for(int zz = 0 ; zz < split_m_info[i].size(); zz++)
            std::cout << split_m_info[i][zz]<< " ";
        std::cout << endl;
        if (find_music_length  < play_length[i])
        {
            string music_data = "";
            int m_length = split_m_info[i][3].size();
            int shap_plus = 0;
            for(int j = 0; j < play_length[i] + shap_plus; j++){
                music_data += split_m_info[i][3][j % m_length];
                if(split_m_info[i][3][(j + 1) % m_length] == '#')
                    shap_plus++;
            }

            size_t music_find_i = 0;
            while((music_find_i = music_data.find(m , music_find_i)) != std::string::npos)
            { // 재대로 된거 찾을떄 까지 계속 find~!!
                if(music_data[music_find_i + m.size()] != '#')
                    break;
                music_find_i++;
            }
            if(music_find_i != std::string::npos)
            {
                find_music_length = play_length[i];
                answer = split_m_info[i][2];
            }
        }
    }

    return answer;
}
