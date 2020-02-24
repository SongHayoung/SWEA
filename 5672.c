#include <stdio.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
char birds[2000];
int ret , flag, n;
int fastReadINT(){
    ret = 0, flag = 1, n = gc();
    for(;'0'>n||n>'9';n=gc()){
        if(n=='-'){
            flag = -1; n=gc(); break;
        }
    }
    do{
        ret = (ret<<3) + (ret<<1) + (n & 0b1111); n = gc();
    }while('0'<=n&&n<='9');
    return ret*flag;
}
void fastWriteANSWER(int N){
    pc('#');
    if (n == 0) { pc('0'); pc('\n'); return ;}
    if (n<0) { n = -n; pc('-');}
    flag = 0, ret = n = N;
    while ((ret % 10) == 0) { flag++; ret /= 10;}
    ret = 0;
    while (N != 0) { ret = (ret<<3) + (ret<<1) + N % 10; N /= 10;}
    while (ret != 0) { pc(ret % 10 + '0'); ret /= 10;}
    while (flag--) pc('0');
    pc(' ');
}
int main(int argc, char** argv){
    register int tc, T, N, front, back, cmp_front, cmp_back;
    T = fastReadINT();
    for(tc = 1; tc <= T; tc++){
        N = fastReadINT();
        back = front = 0;
        while(back<N){
            birds[back] = gc();
            if('A'<=birds[back] && birds[back]<='Z')
                back++;
        }
        back -= 1;
        fastWriteANSWER(tc);
        while(front!=back){
            if(birds[front]==birds[back]){
                cmp_front = front + 1;
                cmp_back = back - 1;
                while(birds[cmp_front]==birds[cmp_back]&&cmp_front<=cmp_back) {
                    cmp_front++;
                    cmp_back--;
                }
                if(birds[cmp_front]>birds[cmp_back]){
                    pc(birds[back--]);
                }
                else
                    pc(birds[front++]);
            }
            else if(birds[front]>birds[back])
                pc(birds[back--]);
            else
                pc(birds[front++]);
        }
        pc(birds[front]);
        pc('\n');
        
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
