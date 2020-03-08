# pragma optimize("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <stdio.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define ADD3(a,b) ((a<<3)+(a<<1)+(b&0b1111))
#define MUL(a,b) ((a)*(b))
int fRI(){
    int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = ADD3(r,N); N = gc();
    }while(0x30<=N&&N<=0x3A);
    return r;
}
void fWI(int n,int a){
    int c = 0, r = 0;
    pc('#');
    while(!(n%10)) {c++; n/=10;}
    while(n) {r = ADD3(r,n%10); n/=10;}
    while(r) {pc(r%10|0b110000); r/=10;}
    while(c--) pc(0x30); pc(32);
    c = 0;
    if(!a) {pc(0x30); pc(0x0A); return ;}
    while(!(a%10)) {c++; a/=10;}
    while(a) {r = ADD3(r,a%10); a/=10;}
    while(r) {pc(r%10|0b110000); r/=10;}
    while(c--) pc(0x30); pc(0x0A);
}
int main(void){
    register int N, tc = 1, T=fRI(),ans, p, n, s, in, de;
    while(T--){
        N=fRI(); n=fRI(); p=fRI();
        in = de = s = ans = 0;
        n<p ? in++ : s++;
        for(register int i = 2 ; i < N ; i++) {
            n = fRI();
            if(s){
                if(p>n) de++;
                else ans += (MUL(in,de)), de = s = 0, in = 1;
            }
            else{
                if(p<n) in++;
                else s = 1, de++;
            }
            n ^= p; p ^= n;
        }
        if(in&&de) ans +=(MUL(in,de));
        fWI(tc++,ans);
    }
    return 0;
}
