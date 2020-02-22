#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(int argc, char** argv)
{
    int test_case,N,num,H,answer;
    int T;
    vector<int> Nums;
    Nums.reserve(500000);
    scanf("%d",&T);
    for(test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d",&N);
        Nums.clear();
        for(int i=0;i<N;i++){
            scanf("%d",&num);
            Nums.push_back(num);
        }
        sort(Nums.begin(),Nums.end());
        auto it = Nums.begin();
        answer = 0;
        for(H = 0; H <= Nums[N-1]; H++){
            answer = (N-(it-Nums.begin())) >= H ? H : answer;
            if(*it==H){
                while(*it==H)   ++it;
            }
            if((N-(it-Nums.begin())) < H)
                break;
        }
        printf("#%d %d\n",test_case,answer);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
