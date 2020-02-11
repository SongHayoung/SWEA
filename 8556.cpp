#include <iostream>
#include <memory.h>
using namespace std;
bool NorW[20];//north == true, west = false;
int cnt;
char c;
void solution(){
    memset(NorW,false,sizeof(NorW));
    cnt = 0;
    while(1){
        c=getchar();
        if(c=='\n')
            break;
        getchar();getchar();getchar();
        if(c=='n'){
            getchar();
            NorW[cnt] = true;
        }
        ++cnt;
    }
    long long answer = 0;
    long long div = 1<<cnt-1;
    long long multi = 1<<cnt-2;
    if(!NorW[cnt-1])
        answer = 90 * div;
    for(int i = cnt-2; i>=0; i--){
        if(NorW[i])
            answer = answer - 90*multi;
        else
            answer = answer + 90*multi;
        multi>>=1;
    }
    if(answer<0)
        answer *= -1;
    if(answer%div==0){
        cout<<answer/div<<endl;
        return ;
    }
    div>>=1;
    while(1){
        if(answer%div==0){
            cout<<answer/div<<"/"<<((1<<cnt-1)/div)<<endl;
            return ;
        }
        div>>=1;
    }
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    getchar();
    for(test_case = 1; test_case <= T; ++test_case){
        cout<<"#"<<test_case<<" ";
        solution();
    }
    return 0;
}
