import java.io.*;

public class Solution {
    static int[][] map = new int[1000][1000];
    static int[][] dp = new int[1000][1000];
    static int[] dy = {-1,0,1,0};
    static int[] dx = {0,1,0,-1};
    static int N;
    public static void main(String[] args) throws IOException {
        Reader r = new Reader();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = r.nextInt(), tc = 1;
        while(T-- != 0) {
            N = r.nextInt();
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j) {
                    map[i][j] = r.nextInt();
                    dp[i][j] = -1;
                }
            int ans = -1, num = -1;
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j){
                    dp[i][j] = f(i, j);
                    if(dp[i][j] > ans || (dp[i][j] == ans && map[i][j] < num)) {
                        ans = dp[i][j];
                        num = map[i][j];
                    }
                }
            bw.write("#" + tc++ + " " + num + " " + (ans + 1) + "\n");
        }
        bw.flush();
    }
    static int f(int y, int x) {
        if(dp[y][x] != -1) return dp[y][x];
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<= nx && nx < N && 0 <= ny && ny < N && map[ny][nx] == map[y][x] + 1){
                return (dp[y][x] = f(ny, nx))+ 1;
            }
        }
        return dp[y][x] = 0;
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
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = (ret<<3) + (ret<<1)  + (c & 0b1111);
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
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
