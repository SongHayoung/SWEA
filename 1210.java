
import java.util.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        int tc = 1, T = 10, y, x, dir;
        int[] dx = {0, 1, 0, -1};
        int[] dy = {-1, 0, 1, 0};
        int[][] map = new int[100][100];
        while(T-- != 0) {
            y = dir = 99;
            tc = scanner.nextInt();
            for(int i = 0; i < 100; ++i)
                for(int j = 0; j < 100; ++j)
                    map[i][j] = scanner.nextInt();

            for(x = 0; map[99][x] != 2; ++x);

            for(;y != 0;) {
                if((dir == 1 || dir == 3) && 0 <= x + dx[dir] && x + dx[dir] < 99 && map[y][x + dx[dir]] == 1) {
                    x = x + dx[dir];
                }
                else if(0 != x && map[y][x - 1] != 0 && dir != 1){
                    x = x - 1;
                    dir = 3;
                }
                else if(99 != x && map[y][x + 1] != 0 && dir != 3){
                    x = x + 1;
                    dir = 1;
                }
                else if(map[y - 1][x] == 1) {
                    y = y - 1;
                    dir = -1;
                }
            }
            System.out.println("#" + tc + " " + x);
        }
    }
}
