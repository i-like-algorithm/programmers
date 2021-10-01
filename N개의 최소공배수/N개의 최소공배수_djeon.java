class Solution {
    public int solution(int[] arr) {
        int answer = 0;
        int max = max(arr);
        int index = 1;
        int compare;
        int flag = 0;
        
        while (flag == 0) {
            compare = max * index++;
            flag = 1;
            for (int i = 0; i < arr.length; i++) {
                if (compare % arr[i] != 0) {
                    flag = 0;
                    break ;
                }
            }
            if (flag == 1) {
                answer = compare;
                break ;
            }
        }
        return answer;
    }
    
    private int max(int[] arr) {
        int result = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > result)
                result = arr[i];
        }
        return result;
    }
}