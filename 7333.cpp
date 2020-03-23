#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(int argc, char** argv)
{
    int test_case,N,num,multi,answer;
    int T;
    vector<int> Boxes;
    Boxes.reserve(100);
    scanf("%d",&T);
    for(test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d",&N);
        Boxes.clear();
        answer = 0;
        for(int i=0;i<N;i++){
            scanf("%d",&num);
            Boxes.push_back(num);
        }
        sort(Boxes.begin(),Boxes.end());
        auto it_front = Boxes.begin();
        auto it_end = Boxes.end()-1;
        while(it_end>=it_front){
            if(it_end==it_front){
                if(*it_end>=50)
                    ++answer;
                break;
            }
            multi = 1;
            while(((*it_end)*multi)<50){
                ++multi; ++it_front;
                if(it_front>it_end){
                    --answer;
                    break;
                }
            }
            --it_end;
            ++answer;
        }
        printf("#%d %d\n",test_case,answer);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
