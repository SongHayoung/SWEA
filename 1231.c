#include <stdio.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
int e;
char buf[101];
int fRI(){
    register int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = (r<<3) + (r<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return r;
}
void inorderCC(int n){
    if((n<<1) <= e) inorderCC(n<<1);
    pc(buf[n]);
    if((n<<1)+1 <= e) inorderCC((n<<1)+1);
}
int main(void){
    register int T = 10,  tc = 0, i;
    while(T--){
        e = fRI();
        for(i=1;i<=e;++i) {
            fRI();
            buf[i] = gc();
            if((i<<1) <= e) fRI();
            if((i<<1)+1 <= e) fRI();
        };
        printf("#%d ",++tc);
        inorderCC(1);
        pc('\n');
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
