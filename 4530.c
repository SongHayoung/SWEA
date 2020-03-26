#include <stdio.h>
long long A, B;
long long  f(long long A){
    long long ret = 0;
    long long pow = 1;
    while(A){
        ret += (A%10)>4 ? ((A%10)-1)*pow : (A%10)*pow;
        A *= 0.1;
        pow *= 9;
    }
    return ret;
}
int main(void) {
    int T, tc = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%llu %llu",&A,&B);
        printf("#%d %llu\n",++tc,B<0 ? f(-A) - f(-B) : A<0 ? f(-A) + f(B) - 1 : f(B) - f(A));
    }
    return 0;
}
