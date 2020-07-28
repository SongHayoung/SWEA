
import java.util.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        int tc = 1, T, N, dir, x, y, n, ny, nx;
        int[] dx = {0,1,0,-1};
        int[] dy = {-1,0,1,0};
        T = scanner.nextInt();
        while(T-- != 0) {
            N = scanner.nextInt();
            int[][] map = new int[N][N];
            for(int[] row : map)
                Arrays.fill(row, -1);
            dir = 1; n = 1;
            y = 0; x = 0;
            while(true) {
                map[y][x] = n++;
                ny = y + dy[dir];
                nx = x + dx[dir];
                if(0 <= nx && nx < N && 0 <= ny && ny < N && map[ny][nx] == -1) {
                    y = ny;
                    x = nx;
                }
                else{
                    dir = (++dir) % 4;
                    y = y + dy[dir];
                    x = x + dx[dir];
                    if(0 > x || x >= N || 0 > y || y >= N || map[y][x] != -1)
                        break;
                }
            }

            System.out.println("#" + tc++);
            for(int[] row : map) {
                for (int val : row)
                    System.out.print(val + " ");
                System.out.println();
            }
        }
    }
}
