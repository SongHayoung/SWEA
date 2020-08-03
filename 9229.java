import java.io.*;
import java.util.*;

public class Solution {
    public static int m, n, ans, i, T, tc = 1;
    public static int[] snacks = new int[1000];
    public static Reader r = new Reader();
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws Exception {
        T = r.nextInt();
        while (T-- != 0) {
            n = r.nextInt();
            m = r.nextInt();

            for(i = 0, ans = -1; i < n; ++i)
                snacks[i] = r.nextInt();

            Arrays.sort(snacks, 0, n);
            if(snacks[0] + snacks[1] <= m)
                for (i =  1; i < n && snacks[i] <= m; ++i)
                    ans = Math.max(ans, snacks[i] + binarySearch(m - snacks[i], i));

            bw.write("#" + tc++ + " " + ans + "\n");
        }
        bw.flush();
    }

    static int binarySearch(int target, int r) {
        int l = 0, m, ret = -987654321;
        while(l < r) {
            m = (l+r)>>1;
            if(snacks[m] == target) return target;
            if(snacks[m] < target) {
                l = m + 1;
                ret = Math.max(ret, snacks[m]);
            }
            else r = m;
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
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            do {
                ret = (ret<<3) + (ret<<1)  + (c & 0b1111);
            } while ((c = read()) >= '0' && c <= '9');

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
