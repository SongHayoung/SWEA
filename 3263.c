#include <stdio.h>
#include <memory.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
int fastreadINT_byValue(){
    int N = gc(), ret = 0;
    do{
        ret = (ret<<3) + (ret<<1) + (N & 0b1111);    N=gc();
    }while('0'<=N&&N<='9');
    return ret;
}

void writeFASTINT(int tc, int answer){
    pc('#');
    int ret = 0, count = 0;
    while((tc%10)==0) { count++; tc/=10;}
    while(tc)   {ret = (ret<<3)+(ret<<1)+tc%10; tc/=10;}
    while(ret)  {pc(ret%10+'0'); ret/=10;}
    while(count--) pc('0');
    ret = count = 0;
    pc(' ');
    if(answer==0)   {   pc('0'); pc('\n');   return;}
    while((answer%10)==0) { count++; answer/=10;}
    while(answer)   {ret = (ret<<3)+(ret<<1)+answer%10; answer/=10;}
    while(ret)  {pc(ret%10+'0'); ret/=10;}
    while(count--) pc('0');
    pc('\n');
}
int main(int argc, char** argv){
    register int tc, i, N, n, T, answer;
    int DP[100001];
    T = fastreadINT_byValue();
    for(tc = 1; tc <= T; tc++){
        N = fastreadINT_byValue();
        answer = 0;
        memset(DP,0,sizeof(DP));
        for(i=1;i<=N;i++){
            n = fastreadINT_byValue();
            DP[n] = DP[n-1]+1;
            answer = answer > DP[n] ? answer : DP[n];
        }
        writeFASTINT(tc,N-answer);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
