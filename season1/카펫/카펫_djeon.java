class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = {0, 0};
        int vertical;
        int horizon;
        
        for (int i = 1; i * i <= yellow; i++) {
            if (yellow % i == 0) {
                vertical = i;
                horizon = yellow / vertical;
                if (((vertical + 2) * (horizon + 2)) - yellow == brown) {
                    answer[0] = horizon + 2;
                    answer[1] = vertical + 2;
                    break ;
                }
            }
        }
        return answer;
    }
}