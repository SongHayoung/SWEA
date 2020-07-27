import java.util.Scanner;

public class Solution {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int tc = 1;
        int T;
        String input;
        T = sc.nextInt();
        while(T-- != 0) {
            input = sc.next();
            int ans = 1;
            boolean flag = false;
            for(int i = 0; i < input.length() - 1; ++i) {
                if(input.charAt(i) == '1')
                    flag = true;
                if (flag) {
                    if(input.charAt(i) != input.charAt(i + 1)) ++ans;
                }
            }
            System.out.println("#" + tc++ + " " + ans);
        }

    }
}
