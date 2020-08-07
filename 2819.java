import java.io.*;
import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class Solution {
    static Set<Integer>[][][] dp = new Set[4][4][7];
    static int[][] map = new int[4][4];
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {-1, 0, 1, 0};
    static int TC, t, ans;
    static Reader r = new Reader();
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        TC = r.nextInt();
        for(int i =  0; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                for(int k = 0; k < 7; ++k)
                    dp[i][j][k] = new HashSet<>();
        while(TC--!=0){
            for(int i = 0; i < 4; ++i)
                for(int j = 0; j < 4; ++j){
                    map[i][j] = r.nextInt();
                    for(int k = 0; k < 7; ++k)
                        dp[i][j][k].clear();
                }

            ans = 0;

            for(int i = 0; i < 4; ++i)
                for(int j = 0; j < 4; ++j) {
                    ans += solution(i, j, map[i][j], 0);
                }
            bw.write("#" + ++t + " " + ans + "\n");
        }
        bw.flush();
    }
    static int solution(int y, int x, int val, int c){
        if(dp[y][x][c].contains(val))
            return 0;
        if(c == 6) {
            for(int i = 0; i < 4; ++i)
                for(int j = 0; j < 4; ++j)
                    dp[i][j][c].add(val);
            return 1;
        }
        dp[y][x][c].add(val);
        int ret = 0;
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < 4 && 0 <= ny && ny < 4)
                ret += solution(ny, nx, val * 10 + map[ny][nx], c + 1);
        }
        return ret;
    }

    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public int nextInt() throws IOException {
            int ret = 0, flag = 1;
            byte c = read();
            if(c == '-') {
                flag = -1;
                c = read();
            }
            do {
                ret = (ret<<3) + (ret<<1) + (c & 0b1111);
            }  while ((c = read()) >= '0' && c <= '9');

            return ret * flag;
        }
        public String readLine() throws IOException {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1)
            {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }


        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
    }
}
