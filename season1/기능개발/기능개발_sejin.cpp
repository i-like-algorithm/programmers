#include <string>
#include <vector>

using namespace std;

int work_day(int progress, int speed) {
    int day = (100 - progress) / speed;
    if ((100 - progress) % speed)
        day++;
    return (day);
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day;
    int cnt;
    for (int i = 0; i < progresses.size();) {
        day = work_day(progresses[i], speeds[i]);
        cnt = 1;
        for (int j = i + 1; j < progresses.size(); j++) {
            if (work_day(progresses[j], speeds[j]) > day)
                break;
            cnt++;
        }
        answer.push_back(cnt);
        i += cnt;
    }
    return answer;
}
