#include <stdio.h>
#define pc(x) putchar_unlocked(x)
#define gc() getchar_unlocked()
int readINT(){
    int N = gc(),ret = 0;
    do{
        ret = (ret<<3) + (ret<<1) + N - '0';    N=gc();
    }while('0'<=N&&N<='9');
    return ret;
}
void writeInt (int N){
    int rev=N, count = 0;
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}
int main(int argc, char** argv){
    int T, N, A, B,letter[101], letters[1001] = {0, };
    T=readINT();
    register int checked, get, time, limit, tc;
    for(tc=1;tc<=T;tc++){
        N=readINT(); A=readINT(); B=readINT();
        pc('#'); writeInt(tc);
        for(int i=1;i<=N;i++) {
            letter[i] = readINT();
            letters[letter[i]]^=1;
        }
        checked = 1;
        get = 0;
        for(time=1;time<=letter[N];time++){
            if(letters[time])    {get++; letters[time]^=1;}
            if(get==A||time-letter[checked]==B){
                limit = checked + ((get+1)>>1);
                for(;checked<limit;checked++)   {pc(' ');writeInt(time);}
                get = get - ((get+1)>>1);
            }
        }
        while(get){
            if(time-letter[checked]==B){
                limit = checked + ((get+1)>>1);
                for(;checked<limit;checked++)    {pc(' ');writeInt(time);}
                get = get - ((get+1)>>1);
            }
            time++;
        }
        pc('\n');
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
