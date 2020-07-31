import java.io.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        Reader r = new Reader();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int[] arr = new int[1<<7];
        int T = 10, tc = 1, index, ans;
        String cmd;
        while(T-- != 0) {
            r.readLine();
            cmd = r.readLine();
            for(int i = index = ans = 0; i < cmd.length(); ++i) {
                switch (cmd.charAt(i)) {
                    case '+': ans += arr[index - 1]; arr[index++] = cmd.charAt(i++ + 1) & 0b1111; break;
                    case '*': arr[index - 1] = arr[index - 1] * (cmd.charAt(i++ + 1) & 0b1111); break;
                    default: arr[index++] = cmd.charAt(i) & 0b1111; break;
                }
            }
            bw.write("#" + tc++ + " " + (ans + arr[index - 1]) + "\n");
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
        public String readLine() throws IOException {
            byte[] buf = new byte[1<<8];
            int cnt = 0, c;
            while ((c = read()) != -1) {
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
