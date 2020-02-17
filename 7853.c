#include <stdio.h>
#define MOD 1000000007
int main(void){
    register int test_case, idx, i;
    register long answer;
    int T;
    char c[1001];
    scanf("%d",&T);
    getchar();
    for(test_case = 1; test_case<=T; test_case++){
        idx = 0;
        answer = 1;
        do {
            c[idx++] = getchar();
        }while('a'<=c[idx-1]&&c[idx-1]<='z');
        answer *= c[0]!=c[1]&&c[idx-2]!=c[idx-3] ? 4 : c[0]==c[1]&&c[idx-2]==c[idx-3] ? 1 : 2;
        for(i=1;i<idx-2;i++)
            answer = c[i-1]!=c[i]&&c[i-1]!=c[i+1]&&c[i]!=c[i+1] ? answer*3%MOD : c[i-1]==c[i]&&c[i]==c[i+1] ? answer*1%MOD : answer*2%MOD;
        
        printf("#%d %d\n",test_case,answer%MOD);
    }
    return 0;
}
