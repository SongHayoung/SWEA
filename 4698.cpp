#include <iostream>
#include <vector>
using namespace std;
#define MAXNUM 1000000
vector<bool> is_Prime(500001,true);
int answer, D;
inline bool is_Special(int n){
    do{
        if((n%10)==D)
            return true;
        n/=10;
    }while(n);
    return false;
}
int main(int argc, char** argv){
    int T, test_case;
    int A,B;
    is_Prime[0] = false;
    for(int i=3; i*i<=MAXNUM;i+=2){
        if(is_Prime[i>>1]){
            for(int j = i*i; j<=MAXNUM; j += (i<<1))
                is_Prime[j>>1] = false;
        }
    }
    cin>>T;
    for(test_case=1;test_case<=T;test_case++){
        cin>>D>>A>>B;
        answer = (D==2&&A<=2) ? 1 : 0;
        if((A&1)==0)
            A^=1;
        for(int i=A;i<=B;i+=2){
            if(is_Prime[i>>1]&&is_Special(i)){
                ++answer;
            }
        }
        cout<<"#"<<test_case<<" "<<answer<<endl;
    }
}
