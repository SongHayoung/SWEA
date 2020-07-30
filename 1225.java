import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Solution {
    public static Queue<Integer> q = new LinkedList<>();
    public static void main(String[] args) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = 10, tc = 1;
        while(T-- != 0){
            bf.readLine();
            StringTokenizer st = new StringTokenizer(bf.readLine());
            for(int i = 0; i < 8; ++i) {
                q.add(fastParseInt(st.nextToken()));
            }
            boolean flag = true;
            while(flag) {
                for(int i = 1; flag && i <=5; ++i){
                    int n = q.remove() - i;
                    if(n <= 0) {
                        q.add(0);
                        flag = false;
                    } else {
                        q.add(n);
                    }
                }
            }
            bw.write("#" + tc ++ + " ");
            for(int i = 0; i < 8; ++i)
                bw.write(q.remove() + " ");
            bw.write("\n");
        }
        bw.flush();
    }
    public static int fastParseInt(String str){
        int ret = 0;
        for(int i = 0; i < str.length(); ++i)
            ret = (ret<<3) + (ret<<1) + (str.charAt(i) & 0b1111);
        return ret;
    }

}
