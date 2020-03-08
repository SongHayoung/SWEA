#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define ADD3(a,b) ((a<<3)+(a<<1)+(b&0b1111))
char buf[20000][51];
int compare(const void *A, const void *B){
    int lenA = strlen((char*)A);
    int lenB = strlen((char*)B);
    if(lenA==lenB)
        return (strcmp((char*)A,(char*)B));
    return lenA > lenB;
}
int fRI(){
    int N = gc(), r = 0;
    for(;'0'>N||N>'9';N=gc());
    do{
        r = ADD3(r,N); N = gc();
    }while(48<=N&&N<=57);
    return r;
}
int fWI(int n){
    int c = 0, r = 0;
    pc('#');
    while(!(n%10)) {c++; n/=10;}
    while(n) {r = ADD3(r,n%10); n/=10;}
    while(r) {pc(r%10|0b110000); r/=10;}
    while(c--) pc(0x30);
    pc(0x0A);
}
int main(void){
    register int N, tc = 1, T=fRI(), len;
    for(;tc<=T;tc++){
        N=fRI();
        for(register int i = 0 ; i < N ; i++)
            scanf("%s",buf[i]);
        qsort(buf,N,sizeof(buf[0]),compare);
        fWI(tc);
        len = 0;
        while(buf[0][len]!=NULL) pc(buf[0][len++]);
        pc(0x0A);
        for(register int i = 1; i < N; i++)
            if(strcmp(buf[i-1],buf[i])){
                len = 0;
                while(buf[i][len]!=NULL) pc(buf[i][len++]);
                pc(0x0A);
            }
    }
    return 0;
}
