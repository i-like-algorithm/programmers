class Solution {
    public int[][] solution(int[][] arr1, int[][] arr2) {
        int[][] answer = new int[arr1.length][arr2[0].length];
        int sum;
        for (int i = 0; i < arr1.length; i++) {
            for (int j = 0; j < arr2[0].length; j++) {
                sum = 0;
                for (int z = 0; z < arr1[i].length; z++) {
                    sum += (arr1[i][z] * arr2[z][j]);
                }
                answer[i][j] = sum;
            }
        }
        return answer;
    }
}