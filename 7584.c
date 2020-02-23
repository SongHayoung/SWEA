#include <stdio.h>
//2020.02.17 기준 1등
int main(void){
    register int test_case;
    int T;
    long long N;
    scanf("%d",&T);
    for(test_case = 1; test_case<=T; test_case++){
        scanf("%lld",&N);
        while(~N&1)
            N>>=1;
        printf("#%d %d\n",test_case, ~(~(N-1)>>1)&1);
    }
    return 0;
}
/* SAME CODE
 #include <string>
 #include <iostream>
 using namespace std;
 int main(void){
 int test_case, T;
 long long N;
 scanf("%d",&T);
 for(test_case = 1; test_case<=T; test_case++){
 scanf("%lld",&N);
 while((N%2)==0)
 N>>=1;
 if((N-1)/2%2==0)
 printf("#%d 0\n",test_case);
 else
 printf("#%d 1\n",test_case);
 } 
 return 0;
 }
 */
