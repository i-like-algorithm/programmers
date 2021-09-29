class Solution {
    public String solution(String s) {
        String answer = "";
        int flag = 1;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                answer += s.charAt(i);
                flag = 1;
            } else {
                if (flag == 1 && (s.charAt(i) >= 'a' && s.charAt(i) <= 'z')) {
                    answer += Character.toUpperCase(s.charAt(i));
                } else if (flag == 0 && (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z')) {
                    answer += Character.toLowerCase(s.charAt(i));
                } else {
                    answer += s.charAt(i);
                }
                flag = 0;
            }
        }
        return answer;
    }
}