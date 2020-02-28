#include <stdio.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
long fRL(){
    long ret = 0, N = gc();
    do{
        ret = (ret<<3) + (ret<<1) + (N&0b1111); N = gc();
    }while('0'<=N&&N<='9');
    return ret;
}
void fWL(long N){
    long r = 0, c = 0;
    while(!(N%10))  {c++; N/=10;}
    while(N)        {r = (r<<3) + (r<<1) + N%10; N/=10;}
    while(r)        {pc(r%10 + 48); r/=10;}
    while(c--)      {pc(48);}
    return ;
}
int main(int argc, char** argv){
    register long N,A,B;
    register int T=fRL(),tc=1;
    for(;tc<=T;tc++) {
        N = fRL(); A = fRL(); B = fRL();
        pc(35);    fWL(tc);    pc(32);
        if(A>B)         pc(48);
        else if(!(N^1)){
            if(A^B)    pc(48);
            else        pc(49);
        }
        else            fWL((N-2)*(B-A)+1);
        pc(10);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
