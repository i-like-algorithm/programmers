import java.util.Queue;
import java.util.LinkedList;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int[] curDistance = new int[truck_weights.length];
        Queue<Integer> bridge = new LinkedList<>();
        int answer = 0;
        int sum = 0;
        int index = 0;
        int minIndex = 0;
        for (int i = 0; i < curDistance.length; i++) {
            curDistance[i] = 0;
        }
        while (true) {
            // 다리 위의 트럭 대수, 무게를 고려하여 다음 트럭을 다리 위에 올릴지 판단
            if (index < truck_weights.length
                && bridge.size() < bridge_length
                && sum + truck_weights[index] <= weight)
            {
                bridge.add(truck_weights[index]);
                sum += truck_weights[index];
                index++;
            }
            // 다리 위 트럭들의 현재 거리를 1씩 증가
            for (int i = minIndex; i < minIndex + bridge.size(); i++) {
                curDistance[i]++;
            }
            // 다리 위의 트럭이 다리를 모두 지나면, bridge 큐에서 트럭 제거
            if (curDistance[minIndex] >= bridge_length) {
                bridge.remove();
                sum -= truck_weights[minIndex];
                minIndex++;
            }
            // 시간 추가
            answer++;
            // 트럭이 다 지나가고 다리 위에 트럭이 없을 때, 프로그램 종료
            if (index == truck_weights.length && bridge.size() == 0) {
                break ;
            }
        }
        answer++;
        return answer;
    }
}