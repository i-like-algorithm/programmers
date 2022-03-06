import java.util.Stack;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        Stack<Integer> stack = new Stack<>();
        int num = 1;
        int passDay;
        if ((100 - progresses[0]) % speeds[0] == 0)
            passDay = (100 - progresses[0]) / speeds[0];
        else
            passDay = ((100 - progresses[0]) / speeds[0]) + 1;
        
        for (int i = 1; i < progresses.length; i++) {
            if (passDay * speeds[i] >= 100 - progresses[i]) {
                num++;
            } else {
                stack.push(num);
                num = 1;
                if ((100 - progresses[i]) % speeds[i] == 0)
                    passDay = (100 - progresses[i]) / speeds[i];
                else
                    passDay = ((100 - progresses[i]) / speeds[i]) + 1;
            }
        }
        stack.push(num);
        answer = convertIntArray(stack);
        
        return answer;
    }
    
    private int[] convertIntArray(Stack<Integer> stack) {
        int[] result = new int[stack.size()];
        
        for (int i = stack.size() - 1; i >= 0; i--) {
            result[i] = stack.peek();
            stack.pop();
        }
            
        return result;
    }
}