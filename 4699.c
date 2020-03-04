#include <stdio.h>

#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
int fRI(){
    int N=gc(),ret = 0;
    for(;N<48||N>57;N=gc());
    do{
        ret = (ret<<3) + (ret<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return ret;
}
void fWI(int n){
    int r = 0, c = 0;
    if(!n) {pc(0x30); return ;}
    while(!(n%10)) {c++; n/=10;}
    while(n){r=(r<<3)+(r<<1)+n%10; n/=10;}
    while(r){pc(r%10|0b110000); r/=10;}
    while(c--) pc(0x30);
}

char buf[2001];
int DP[2001][2001] = {0, }, price[27];
int main(int argc, char** argv){
    register int L, K, tc=1, T, temp;
    T=fRI();
    for(;tc<=T;tc++){
        L=fRI(); K=fRI();
        temp = 0;
        do{
            buf[temp++]=gc();
        }while('a'<=buf[temp-1]&&buf[temp-1]<='z');
        for(register int i = 0; i < K; i++){
            price[i]=fRI(); temp=fRI();
            price[i] = price[i] > temp ? temp : price[i];
        }
        for (register int i = 0; i < L; i++) {
            DP[i][i] = 0;
            for (register int j = i+1; j < L; j++)
                DP[i][j] = 987654321;
        }
        for(register int diff = 1; diff < L; diff++)
            for(register int pos = 0; pos < L-diff; pos++){
                if(!(buf[pos]^buf[pos+diff])) DP[pos][pos+diff] = DP[pos+1][pos+diff-1];
                else DP[pos][pos+diff] = DP[pos+1][pos+diff]+price[buf[pos]-'a'] > DP[pos][pos+diff-1]+price[buf[pos+diff]-'a'] ?
                    DP[pos][pos+diff-1]+price[buf[pos+diff]-'a'] : DP[pos+1][pos+diff]+price[buf[pos]-'a'];
            }
        pc('#');fWI(tc);pc(' ');fWI(DP[0][L-1]);pc('\n');
    }
    return 0;
}
