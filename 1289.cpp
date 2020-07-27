#include <iostream>
using namespace std;
int main() {
    int tc = 1, T;
    char c, prev;
    scanf("%d",&T);
    getchar_unlocked();
    while(T--) {
        prev = c = getchar_unlocked();
        int ans = 1;
        bool flag = c == '0' ? false : true;
        for(c = getchar_unlocked(); c == '1' || c == '0' ; prev = c, c = getchar_unlocked()) {
            if(flag && prev != c) ++ans;
            if(c == '1') flag = true;
        }
        printf("#%d %d\n",tc++, ans);
    }
}
