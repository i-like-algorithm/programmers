import java.util.PriorityQueue;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        int first;
        int second;
        int value;
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();
        
        for (int i = 0; i < scoville.length; i++) {
            priorityQueue.add(scoville[i]);
        }
        
        while (true) {
            first = priorityQueue.poll();
            if (first >= K) {
                break ;
            }
            second = priorityQueue.poll();
            value = first + (second * 2);
            answer++;
            priorityQueue.add(value);
            if (priorityQueue.size() < 2 && priorityQueue.peek() < K) {
                return -1;
            }
        }
        
        return answer;
    }
}