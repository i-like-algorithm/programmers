#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int weight_sum = 0;
    deque<int> bridge(bridge_length, 0);
    deque<int> trucks(truck_weights.begin(), truck_weights.end());
    

    while (weight_sum || trucks.size()) {
        if (trucks.size()) {
            weight_sum -= bridge[0];
            bridge.pop_front();
            if (weight_sum + trucks[0] <= weight) {
                weight_sum += trucks[0];
                bridge.push_back(trucks[0]);
                trucks.pop_front();
            }
            else
                bridge.push_back(0);
        }
        else {
            weight_sum -= bridge[0];
            bridge.pop_front();
            bridge.push_back(0);
        }
        answer++;
    }
    return answer;
}
