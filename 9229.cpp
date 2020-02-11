#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> weight;
int N,M;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int TC;
    cin>>TC;
    for(int i=1;i<=TC;i++){
        int ans=-1;
        cin>>N>>M;
        weight.clear();
        weight.resize(N);
        for(int j=0;j<N;j++)
            cin>>weight[j];
        sort(weight.begin(),weight.end());
        for(int j=N-1;j>=0;j--){
            if(weight[j]>M)
                continue;
            for(int k=j-1;k>=0;k--){
                if((weight[j]+weight[k])>M)
                    continue;
                ans=max(ans,weight[k]+weight[j]);
                break;
            }
        }
        cout<<"#"<<i<<" "<<ans<<endl;
    }
}
