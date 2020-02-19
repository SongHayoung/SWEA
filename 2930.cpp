#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char** argv) {
    register int i, j;
    int TC, repeat, num;
    char cmd;
    scanf("%d",&TC);
    getchar();
    for (i = 1; i<=TC; i++) {
        scanf("%d",&repeat);
        getchar();
        printf("#%d ",i);
        priority_queue<int, vector<int>, less<int>> pq;
        for(j=0;j<repeat;j++){
            cmd=getchar();
            getchar();
            switch (cmd){
                case '1':
                    scanf("%d",&num);
                    getchar();
                    pq.push(num);
                    break;
                case '2':
                    if(pq.empty()){
                        printf("-1 ");
                    }
                    else{
                        printf("%d ",pq.top());
                        pq.pop();
                    }
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }
}
