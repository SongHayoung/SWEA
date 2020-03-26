#include <stdio.h>
#include <memory.h>
#define gc() getchar_unlocked()
int topni[4][8];
int fRI(){
    register int N=gc(),ret = 0, flag = 1;
    for(;N<48||N>57;N=gc()){
        if(N=='-'){
            flag = -1; N = gc(); break;
        }
    }
    do{
        ret = (ret<<3) + (ret<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return ret*flag;
}
void DFS(int t, int d, int s){
    if(!s){
        if(t!=3&&topni[t][2]!=topni[t+1][6]) DFS(t+1,-d,1);
        if(t&&topni[t][6]!=topni[t-1][2]) DFS(t-1,-d,-1);
        if(d==1){
            int temp = topni[t][7];
            for(int i = 7; i > 0; --i)
                topni[t][i] = topni[t][i-1];
            topni[t][0] = temp;
        }
        else{
            int temp = topni[t][0];
            for(int i = 0; i < 7; ++i)
                topni[t][i] = topni[t][i+1];
            topni[t][7] = temp;
        }
    }
    else if(s==1){
        if(t!=3&&topni[t][2]!=topni[t+1][6]) DFS(t+1,-d,1);
        if(d==1){
            int temp = topni[t][7];
            for(int i = 7; i > 0; --i)
                topni[t][i] = topni[t][i-1];
            topni[t][0] = temp;
        }
        else{
            int temp = topni[t][0];
            for(int i = 0; i < 7; ++i)
                topni[t][i] = topni[t][i+1];
            topni[t][7] = temp;
        }
    }
    else{
        if(t&&topni[t][6]!=topni[t-1][2]) DFS(t-1,-d,-1);
        if(d==1){
            int temp = topni[t][7];
            for(int i = 7; i > 0; --i)
                topni[t][i] = topni[t][i-1];
            topni[t][0] = temp;
        }
        else{
            int temp = topni[t][0];
            for(int i = 0; i < 7; ++i)
                topni[t][i] = topni[t][i+1];
            topni[t][7] = temp;
        }
    }
}
int main(void) {
    register int N, tc = 0, T = fRI(), i, j, t, d;
    while (T--) {
        N = fRI();
        for(i=0;i<4;++i)
            for(j=0;j<8;++j)
                topni[i][j] = fRI();
        while(N--){
            t = fRI(); d = fRI();
            DFS(t-1,d,0);
        }
        printf("#%d %d\n",++tc,topni[0][0]+(topni[1][0]<<1)+(topni[2][0]<<2)+(topni[3][0]<<3));
    }
}
