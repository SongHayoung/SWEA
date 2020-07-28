#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define gc() getchar_unlocked()
inline void fastreadINT_byReference(int &ret){
    int N = gc(), flag = 1;
    for(;N<'0'||N>'9';N=gc())
        if(N=='-'){
            flag=-1;    N=gc(); break;
        }
    ret = 0;
    do{
        ret = (ret<<3) + (ret<<1) + (N & 0b1111);    N=gc();
    }while('0'<=N&&N<='9');
    ret *= flag;
}
int main() {
    int tc = 1, T = 10, dump;
    vector<int> vec = vector<int>(100);
    while(T--) {
        fastreadINT_byReference(dump);
        for(int i = 0; i < 100; ++i)
            fastreadINT_byReference(vec[i]);

        while(dump--) {
            --(*max_element(vec.begin(), vec.end()));
            ++(*min_element(vec.begin(), vec.end()));
        }
        printf("#%d %d\n",tc++, *max_element(vec.begin(), vec.end()) - *min_element(vec.begin(), vec.end()));
    }
}
