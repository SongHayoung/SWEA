#include <stdio.h>
#include <memory.h>
#define gc() getchar_unlocked()
int fRI(){
    register int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = (r<<3) + (r<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return r;
}
int main(void){
    register int T = fRI(),  tc = 0, i,idx, flag;
    char buf[11], c;
    while(T--){
        i = idx = flag = 0;
        memset(buf,0,sizeof(buf));
        for(;'A'>buf[i]||buf[i]>'Z';buf[i]=gc());
        do{
            buf[++i] = gc();
        }while('A'<=buf[i]&&buf[i]<='Z');
        do{
            c = gc();
            if(!flag)
                switch(c){
                    case 'B': if(buf[idx]!='B') flag = 1;
                        break;
                    case 'A':
                    case 'D':
                    case 'O':
                    case 'P':
                    case 'Q':
                    case 'R': if(!(buf[idx]=='A'||buf[idx]=='D'||buf[idx]=='O'||buf[idx]=='P'||buf[idx]=='Q'||buf[idx]=='R')) flag = 1;
                        break;
                    default: if(buf[idx]=='A'||buf[idx]=='D'||buf[idx]=='O'||buf[idx]=='P'||buf[idx]=='Q'||buf[idx]=='R'||buf[idx]=='B') flag = 1;
                        break;
                }
            ++idx;
        }while('A'<=c&&c<='Z');
        flag ||idx-1!=i? printf("#%d DIFF\n",++tc) : printf("#%d SAME\n",++tc);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
