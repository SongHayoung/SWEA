#include <stdio.h>
#include <memory.h>

using namespace std;
int Tests[2001];
bool isSolved[2001][2001];
int Solved[2001];
int scores[2001];
void solution(int tc){
    int N,T,P;
    char score;
    scanf("%d%d%d",&N,&T,&P);
    getchar();
    memset(Tests,0,sizeof(Tests));
    memset(isSolved,false,sizeof(isSolved));
    memset(Solved,0,sizeof(Solved));
    for(int i=1;i<=N;i++){
        for(int j=0;j<T;j++){
            score = getchar();
            getchar();
            if(score=='0'){
                ++Tests[j];
            }else{
                isSolved[i][j]=true;
                ++Solved[i];
            }
        }
    }

    memset(scores,0,sizeof(scores));
    for(int i=0;i<T;i++){
        if(isSolved[P][i])
            scores[P] += Tests[i];
    }
    int standard_score = scores[P];
    int standard_solved = Solved[P];
    int rank = 1;
    for(int i=1;i<=N;i++){
        if(i==P)
            continue;
        for(int j=0;j<T;j++) {
            if (isSolved[i][j]) {
                scores[i] += Tests[j];
            }
        }
        if(scores[i]>standard_score)
            ++rank;
        else if(scores[i]==standard_score){
            if(Solved[i]>standard_solved)
                ++rank;
            else if(Solved[i]==standard_solved)
                if(i<P)
                    ++rank;
        }
    }
    printf("#%d %d %d\n",tc,standard_score,rank);
    return ;
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    scanf("%d",&T);
    for(test_case = 1; test_case <= T; ++test_case){
        solution(test_case);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
