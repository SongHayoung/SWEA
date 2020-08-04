import java.io.*;
import java.util.*;

public class Solution {
    public static int n, s, tc = 1, ans, prevans, size, i;
    public static LinkedList<Integer>[] g = new LinkedList[101];
    public static boolean[] v = new boolean[101];
    public static Queue<Integer> q = new LinkedList<>();
    public static Reader r = new Reader();
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws Exception {
        for(int i = 1; i <= 100; ++i)
            g[i] = new LinkedList<>();
        while (tc != 11) {
            for(int i = 1; i <= 100; ++i) {
                g[i].clear();
                v[i] = false;
            }
            n = r.nextInt()>>1;
            s = r.nextInt();
            q.add(s);
            v[s] = true;
            ans = s;

            for(i = 0; i < n; ++i)
                g[r.nextInt()].addLast(r.nextInt());

            while(!q.isEmpty()) {
                size = q.size();
                prevans = ans;
                ans = -1;
                for(i = 0; i < size; ++i) {
                    int node = q.poll();
                    for (int val : g[node]) {
                        if (v[val]) continue;
                        v[val] = true;
                        ans = Math.max(ans, val);
                        q.add(val);
                    }
                }
            }
            ans = prevans;
            bw.write("#" + tc++ + " " + ans + "\n");
        }
        bw.flush();
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
