import java.util.Arrays;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        int weight;
        int minIndex = 0;
        int maxIndex = people.length - 1;
        Arrays.sort(people);
        while (maxIndex > -1 && people[maxIndex] != 0) {
            weight = people[maxIndex];
            people[maxIndex] = 0;
            if (!(people[minIndex] == 0 || people[minIndex] == '\0'
                || weight + people[minIndex] > limit)) {
                weight += people[minIndex];
                people[minIndex] = 0;
                minIndex++;
            }
            maxIndex--;
            answer++;
        }
        return answer;
    }
}