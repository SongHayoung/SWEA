#include <stdio.h>
#define MOD 1000000007
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
char buf[10001];
int main(int argc, char** argv){
    register int tc=1, T=fRI(),len=0,DP[7];
    for(;tc<=T;) {
        DP[0] = DP[1] = DP[2] = DP[3] = DP[4] = DP[5] = DP[6] = 0;
        do{
            buf[len++]=gc();
        }while('A'<=buf[len-1]&&buf[len-1]<='Z');
        len--;
        pc(0x23); fWI(tc++); pc(0x20);
        while(len){
            switch(buf[--len]){
                case 'G': DP[6]++; break;
                case 'N': DP[5] = (DP[5]+DP[6])%MOD; break;
                case 'U': DP[4] = (DP[4]+DP[5])%MOD; break;
                case 'S': DP[3] = (DP[3]+DP[4])%MOD; DP[0] = (DP[0] + DP[1])%MOD; break;
                case 'M': DP[2] = (DP[2]+DP[3])%MOD; break;
                case 'A': DP[1] = (DP[1]+DP[2])%MOD; break;
                default: break;
            }
        }
        fWI(DP[0]); pc(0x0A);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
