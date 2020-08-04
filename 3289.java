import java.io.*;

public class Solution {
    public static int n, m, T, tc = 1, i, a, b;
    public static int[] g = new int[1000001];
    public static Reader r = new Reader();
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws Exception {
        T = r.nextInt();
        while (T--!=0) {
            n = r.nextInt();
            m = r.nextInt();
            bw.write("#" + tc++ + " " );
            for(i = 1; i <= n; ++i)
                g[i] = i;
            for(i = 0; i < m; ++i) {
                switch (r.nextInt()) {
                    case 0:
                        a = getG(r.nextInt());
                        b = getG(r.nextInt());
                        g[a] = g[b] = Math.min(a,b);
                        break;
                    case 1:
                        a = getG(r.nextInt());
                        b = getG(r.nextInt());
                        if(a==b) bw.write('1');
                        else bw.write('0');
                        break;
                    default: break;
                }

            }
            bw.write("\n");
        }
        bw.flush();
    }
    public static int getG(int n) {
        return n == g[n] ? n : getG(g[n]);
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
