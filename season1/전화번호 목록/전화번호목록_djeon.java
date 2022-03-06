import java.util.HashMap;
import java.util.Map;
import java.util.Arrays;
import java.util.Comparator;

class CustomComparator implements Comparator<String> {
    @Override
    public int compare(String a, String b) {
        return (a.length() - b.length());
    }
}

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        String compareString;
        Map<String, Integer> map = new HashMap();
        
        Arrays.sort(phone_book, new CustomComparator());
        map.put(phone_book[0], 1);
        
        for (int i = 1; i < phone_book.length; i++) {
            compareString = "";
            for (int j = 0; j < phone_book[i - 1].length(); j++) {
                compareString += phone_book[i].charAt(j);
                if (map.containsKey(compareString)) {
                    return false;
                }
            }
            map.put(phone_book[i], 1);
        }
        return answer;
    }
}