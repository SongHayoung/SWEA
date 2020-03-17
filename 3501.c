#include <stdio.h>
#include <memory.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
int a[100000];
int r[100000];
int fRI(){
    register int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = (r<<3) + (r<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return r;
}
int gcd(int a, int b){
    if(!b) return a;
    return gcd(b,a%b);
}
int main(void){
    register int tc = 1, T = fRI(), p, q , g, m, idx, f;
    while(T--) {
        p = fRI(); q = fRI();
        g = gcd(p,q);
        p /= g; q /= g;
        m = p/q;
        printf("#%d %d",tc++,m);
        if(m) p = p-m*q;
        if(p){
            pc('.');
            idx = 1; f = 0;
            while(!f){
                p = (p<<3) + (p<<1);
                m = p/q;
                p = p-m*q;
                if(!r[p]) r[p]=idx;
                else if(a[r[p]]!=m) {f = r[p]+1; a[idx++] = m;}
                else f = r[p];
                a[idx++] = m;
                if(!p) { f = -1; break;}
            }
            if(f>0){
                for(int i = 1; i < f; i++)
                    pc(a[i]|0b110000);
                pc('(');
                for(int i = f; i < idx-1; i++)
                    pc(a[i]|0b110000);
                pc(')');
            }
            else{
                for(int i = 1; i <= idx-1; i++)
                    pc(a[i]|0b110000);
            }
            if(T) memset(r,0,sizeof(int)*q);
        }
        pc('\n');
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
