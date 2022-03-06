import java.util.Queue;
import java.util.PriorityQueue;
import java.util.LinkedList;
import java.util.Collections;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 1;
        int curLocation = location;
        Queue<Integer> queue = new LinkedList<>();
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(Collections.reverseOrder());
        
        for (int i = 0; i < priorities.length; i++) {
            queue.add(priorities[i]);
            priorityQueue.add(priorities[i]);
        }
        
        while (true) {
            if (queue.peek() == priorityQueue.peek()) {
                if (curLocation == 0) {
                    break ;
                } else {
                    curLocation--;   
                }
                queue.remove();
                priorityQueue.remove();
                answer++;
            } else {
                queue.add(queue.peek());
                queue.remove();
                if (curLocation == 0) {
                    curLocation = queue.size() - 1;
                } else {
                    curLocation--;   
                }
            }
        }
        
        return answer;
    }
}