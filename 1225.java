import java.io.*;
import java.util.*;

public class Solution {
    public static int[] arr = new int[8];

    public static void main(String[] args) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = 10, tc = 1, minVal;
        while (T-- != 0) {
            bf.readLine();
            minVal = Integer.MAX_VALUE;
            StringTokenizer st = new StringTokenizer(bf.readLine());
            for (int i = 0; i < 8; ++i) {
                minVal = Math.min(minVal, (arr[i] = fastParseInt(st.nextToken())));
            }
            minVal = minVal - (minVal % 15) - 15;
            for (int i = 0; i < 8; ++i) {
                arr[i] -= minVal;
            }
            boolean flag = true;
            int idx = 0;
            while (flag) {
                for (int i = 1; flag && i <= 5; ++i, idx = (idx + 1) % 8) {
                    arr[idx] -= i;
                    if (arr[idx] <= 0) {
                        flag = false;
                        arr[idx] = 0;
                    }
                }
            }
            bw.write("#" + tc++ + " ");
            for (int i = 0; i < 8; ++i, idx = (idx + 1) % 8)
                bw.write(arr[idx] + " ");
            bw.write("\n");
        }
        bw.flush();
    }

    public static int fastParseInt(String str) {
        int ret = 0;
        for (int i = 0; i < str.length(); ++i)
            ret = (ret << 3) + (ret << 1) + (str.charAt(i) & 0b1111);
        return ret;
    }
}
