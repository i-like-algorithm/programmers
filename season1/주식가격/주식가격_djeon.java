class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        int numMore;
        
        for (int i = 0; i < prices.length - 1; i++) {
            numMore = 0;
            for (int j = i + 1; j < prices.length; j++) {
                numMore++;
                if (prices[i] > prices[j]) {
                    break ;
                }
            }
            answer[i] = numMore;
        }
        return answer;
    }
}