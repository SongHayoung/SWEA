#include <stdio.h>
#define pc(x) putchar_unlocked(x)
#define gc() getchar_unlocked()
#define A pc('A'),pc('l'),pc('i'),pc('c'),pc('e'),pc('\n')
#define B pc('B'),pc('o'),pc('b'),pc('\n')
#define ll long long
ll fWL(){
    ll r = 0, N = gc();
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = (r<<3) + (r<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return r;
}
void fWA(int t){
    int r = 0, c = 0;
    pc('#');
    while(!(t%10)) {c++; t/=10;}
    while(t) {r = (r<<3) + (r<<1) + t%10; t/=10;}
    while(r) {pc(r%10|0b110000); r/=10;}
    while(c--) {pc(0x30);} pc(32);
}
int main(int argc, char** argv){
    register int  tc=1, T = fWL();
    ll N, min, cmp;
    while(T--){
        min = 2; cmp = 4;
        N = fWL();
        fWA(tc++);
        if(!(N^1)) B;
        else{
            while(1){
                if(min<=N&&N<min+cmp) {A; break;}
                min += cmp;
                if(min<=N&&N<min+cmp) {B; break;}
                min += cmp;
                cmp<<=2;
            }
        }
    }
}
