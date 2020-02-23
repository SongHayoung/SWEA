#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define FIR(x) fastreadINT_byReference(x)
#define FIV() fastreadINT_byValue()
#define gc() getchar_unlocked()

inline void fastreadINT_byReference(int &ret){
    int N = gc(), flag = 1;
    for(;N<'0'||N>'9';N=gc())
        if(N=='-'){
            flag=-1;    N=gc(); break;
        }
    ret = 0;
    do{
        ret = (ret<<3) + (ret<<1) + (N & 0b1111);    N=gc();
    }while('0'<=N&&N<='9');
    ret *= flag;
}

int fastreadINT_byValue(){
    int N = gc(), ret = 0, flag = 1;
    for(;N<'0'||N>'9';N=gc())
        if(N=='-'){
            flag=-1;    N=gc(); break;
        }
    do{
        ret = (ret<<3) + (ret<<1) + (N & 0b1111);    N=gc();
    }while('0'<=N&&N<='9');
    return ret*flag;
}

long long solutions(int &m,vector<long long> &times){
    sort(times.begin(),times.end());
    long long left = 1, answer, mid, sum;
    long long right = answer = times.back()*m;
    while(left+1<right){
        mid = (left+right)>>1;
        sum = 0;
        for(auto it : times)
            sum += (mid / it);
        
        if(sum>=m)  {answer = min(answer,mid); right = mid;}
        else        left = mid;
    }
    return answer;
}
int main(int argc, char** argv){
    int tc, T, N, M;
    vector<long long> times;
    times.reserve(100001);
    FIR(T);
    for(tc = 1; tc <= T; tc++){
        FIR(N); FIR(M);
        times.clear();
        for(int i = 0; i < N; i++)
            times.push_back((long long)FIV());
        printf("#%d %ld\n",tc,solutions(M,times));
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
