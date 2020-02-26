#include <stdio.h>
#include <memory.h>
char board[1000][1001];
int black_col[1000], black_row[1000];
int main(int argc, char** argv){
    int tc, T, N,row,col,answer;
    scanf("%d",&T);
    for(tc=1;tc<=T;tc++){
        scanf("%d",&N);
        memset(black_row,0,sizeof(black_row));
        memset(black_col,0,sizeof(black_col));
        for(row=0;row<N;row++){
            scanf("%s",board[row]);
            for(col=0;col<N;col++){
                if(board[row][col]=='B') {
                    black_col[row]++;
                    black_row[col]++;
                }
            }
        }
        answer = 0;
        for(row=0;row<N;row++){
            for(col=0;col<N;col++){
                if(board[row][col]=='B'&&(black_row[col]+black_col[row]-1)&1)
                    ++answer;
                else if(board[row][col]=='W'&&(black_row[col]+black_col[row])&1)
                    ++answer;
            }
        }
        printf("#%d %d\n",tc,answer);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
