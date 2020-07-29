import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    public static void main(String[] args) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        boolean shootFlag, tankFlag;
        int tc = 1, T = customParseInt(bf.readLine()), y, x, N, ny, nx;
        int[] dx = {0,1,0,-1};
        int[] dy = {-1,0,1,0};
        String[] map = new String[20];
        String cmd;
        while(T-- != 0) {
            StringTokenizer st = new StringTokenizer(bf.readLine());
            y = customParseInt(st.nextToken());
            x = customParseInt(st.nextToken());
            for(int i = 0; i < y; ++i)
                map[i] = bf.readLine();
            N = customParseInt(bf.readLine());
            tank t = new tank();
            tankFlag = true;
            for(int i = 0; tankFlag && i < y; ++i)
                for(int j = 0; tankFlag && j < x; ++j)
                    switch (map[i].charAt(j)){
                        case '<': t.y = i; t.x = j; t.dir = 3; map[i] = map[i].replace('<', '.'); tankFlag = false; break;
                        case '^': t.y = i; t.x = j; t.dir = 0; map[i] = map[i].replace('^', '.'); tankFlag = false; break;
                        case '>': t.y = i; t.x = j; t.dir = 1; map[i] = map[i].replace('>', '.'); tankFlag = false; break;
                        case 'v': t.y = i; t.x = j; t.dir = 2; map[i] = map[i].replace('v', '.'); tankFlag = false; break;
                        default: break;
                    }
            cmd = bf.readLine();
            for(int i = 0; i < N; ++i){
                switch (cmd.charAt(i)){
                    case 'U':
                        t.dir = 0;
                        ny = t.y + dy[t.dir];
                        nx = t.x + dx[t.dir];
                        if(0 <= nx && nx < x && 0 <= ny && ny < y && map[ny].charAt(nx) == '.'){
                            t.y = ny;
                            t.x = nx;
                        }
                        break;
                    case 'D':
                        t.dir = 2;
                        ny = t.y + dy[t.dir];
                        nx = t.x + dx[t.dir];
                        if(0 <= nx && nx < x && 0 <= ny && ny < y && map[ny].charAt(nx) == '.'){
                            t.y = ny;
                            t.x = nx;
                        }
                        break;
                    case 'L':
                        t.dir = 3;
                        ny = t.y + dy[t.dir];
                        nx = t.x + dx[t.dir];
                        if(0 <= nx && nx < x && 0 <= ny && ny < y && map[ny].charAt(nx) == '.'){
                            t.y = ny;
                            t.x = nx;
                        }
                        break;
                    case 'R':
                        t.dir = 1;
                        ny = t.y + dy[t.dir];
                        nx = t.x + dx[t.dir];
                        if(0 <= nx && nx < x && 0 <= ny && ny < y && map[ny].charAt(nx) == '.'){
                            t.y = ny;
                            t.x = nx;
                        }
                        break;
                    case 'S':
                        ny = t.y + dy[t.dir];
                        nx = t.x + dx[t.dir];
                        shootFlag = true;
                        while (0 <= nx && nx < x && 0 <= ny && ny < y && shootFlag){
                            switch (map[ny].charAt(nx)) {
                                case '*':
                                    StringBuilder sb = new StringBuilder(map[ny]);
                                    sb.setCharAt(nx, '.');
                                    map[ny] = sb.toString();
                                    shootFlag = false;
                                    break;
                                case '#': shootFlag = false; break;
                                default: break;
                            }
                            ny += dy[t.dir];
                            nx += dx[t.dir];
                        }
                    default: break;
                }
            }
            System.out.print("#" + tc++ + " ");
            StringBuilder sb = new StringBuilder(map[t.y]);
            sb.setCharAt(t.x, t.dir == 0 ? '^' :
                    t.dir == 1 ? '>' : t.dir == 2 ? 'v' : '<');
            map[t.y] = sb.toString();
            for(int i = 0; i < y; ++i)
                System.out.println(map[i]);
        }
    }
    static public int customParseInt(String val) {
        int ret = 0, flag = val.charAt(0) == '-' ? -1 : 1;
        for(int i = val.charAt(0) == '-' ? 1 : 0; i < val.length(); ++i)
            ret = (ret<<3) + (ret<<1) + (val.charAt(i) & 0b1111);
        return ret * flag;
    }
    public static class tank{
        public int y;
        public int x;
        public int dir;
    }
}
