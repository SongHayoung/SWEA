
import java.util.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        int tc = 1, T = 10, dump;
        while(T-- != 0) {
            dump = scanner.nextInt();
            List<Integer> map = new ArrayList<>();
            for(int i = 0; i < 100; ++i) {
                map.add(scanner.nextInt());
            }
            while(dump-- != 0) {
                int max = Collections.max(map);
                int min = Collections.min(map);
                boolean minFlag = false, maxFlag = false;
                int index = 0;
                for(int val : map) {
                    if(maxFlag && minFlag) break;
                    if(!maxFlag && val == max) {
                        map.set(index, val - 1);
                        maxFlag = true;
                    }
                    if(!minFlag && val == min) {
                        map.set(index, val + 1);
                        minFlag = true;
                    }
                    ++index;
                }
            }
            System.out.println("#" + tc++ + " " + (Collections.max(map) - Collections.min(map)));
        }
    }
}
