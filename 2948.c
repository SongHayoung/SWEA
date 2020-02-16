#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char** argv)
{
    int T, N, M;
    register char c[51];
    register int i, test_case, answer;
    vector<string> g1, g2;
    vector<string>::iterator it1, it2;
    g1.reserve(100000);
    g2.reserve(100000);
    scanf("%d",&T);
    for(test_case = 1; test_case <= T; ++test_case)
    {
        g1.clear();
        g2.clear();
        answer = 0;
        scanf("%d %d",&N,&M);
        for(i=0;i<N;i++) {
            scanf("%s",&c);
            g1.push_back(string(c));
        }
        for(i=0;i<M;i++) {
            scanf("%s",&c);
            g2.push_back(string(c));
        }
        sort(g1.begin(),g1.end());
        sort(g2.begin(),g2.end());
        it1 = g1.begin(); it2 = g2.begin();
        while(it1!=g1.end()&&it2!=g2.end()){
            if(*it1==*it2){
                ++it1; ++it2; ++answer;
            }
            else if(*it1>*it2)
                ++it2;
            else
                ++it1;
        }
        printf("#%d %d\n",test_case,answer);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
