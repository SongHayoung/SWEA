#include <iostream>
using namespace std;
int main(int argc, char** argv){
    int T, test_case;
    unsigned long long A,B,N,R,C;
    unsigned long long answer;
    cin>>T;
    for(test_case=1;test_case<=T;test_case++){
        cin>>N>>A>>B;
        answer = -1;
        for(R=N;R>=1;R--)
            for(C=1;R*C<=N&&C<=R;C++)
                answer = (answer > A*(R-C)+ B*(N-R*C))&&A*(R-C)+ B*(N-R*C)>=0 ? A*(R-C)+ B*(N-R*C) : answer;
        
        cout<<"#"<<test_case<<" "<<answer<<endl;
    }
}
