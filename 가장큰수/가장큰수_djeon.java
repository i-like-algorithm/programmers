import java.util.Arrays;
import java.util.Comparator;

class CustomComparator implements Comparator<Integer> {
    @Override
    public int compare(Integer a, Integer b) {
        int x = Integer.parseInt(a.toString() + b.toString());
        int y = Integer.parseInt(b.toString() + a.toString());
        return (y - x);
    }
}

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        Integer numbersInteger[] = Arrays.stream(numbers).boxed().toArray(Integer[]::new); 
        Arrays.sort(numbersInteger, new CustomComparator());
        if (numbersInteger[0] == 0) {
            return "0";
        }
        for (int i = 0; i < numbersInteger.length; i++) {
            answer += numbersInteger[i].toString();
        }
        return answer;
    }
}