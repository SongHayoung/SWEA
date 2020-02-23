#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int main(int argc, char** argv){
    int test_case;
    int T, N, cnt;
    bool alphas[26];
    string str;
    char c;
    scanf("%d",&T);
    for(test_case = 1; test_case <= T; ++test_case){
        scanf("%d",&N);
        vector<vector<string>> students(21,vector<string>());
        getchar();
        for(int i = 0; i<N; i++){
            str.clear();
            while(1){
                c=getchar();
                if(c==' '||('A'<=c&&c<='Z'))
                    str += c;
                else
                    break;
            }
            cnt = 0;
            memset(alphas,false,sizeof(alphas));
            for(int j=0;j<str.length();j++){
                if('A'<=str[j]&&str[j]<='Z'&&!alphas[str[j]-'A']){
                    alphas[str[j]-'A'] = true; ++cnt;
                }
            }
            students[cnt].push_back(str);
        }
        for(int i=20; i>=0; i--){
            if(students[i].size()!=0){
                sort(students[i].begin(),students[i].end());
                printf("#%d %s\n",test_case,students[i][0].c_str());
                break;
            }
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
