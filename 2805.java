import java.io.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int tc = 1, T, N, ans, i;
        String str;
        T = Integer.parseInt(br.readLine());
        while(T-- != 0) {
            N = Integer.parseInt(br.readLine());
            i = ans = 0;
            do{
                str = br.readLine();
                for(int j = Math.abs(N / 2 - i);
                    i < N / 2 ? j <= N / 2 + i : j < N + N / 2 - i; ++j)
                    ans += str.charAt(j) & 0b1111;
            }while(++i < N);
            bw.write("#" + tc++ + " " + ans + "\n");
        }
        bw.flush();
    }
}
