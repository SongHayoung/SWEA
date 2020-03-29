#include <stdio.h>
#include <string.h>
char buf[1002];
int main(void) {
    int T, tc = 0, ans, cur, len;
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%s",buf);
        cur = buf[0]&0b1111;
        len = strlen(buf);
        for(int i = 1; i < len; ++i){
            if(!(buf[i]&0b1111)) continue;
            if(cur<i)  ans += i-cur, cur = i + (buf[i]&0b1111);
            else cur += (buf[i]&0b1111);
        }
        printf("#%d %d\n",++tc,ans);
    }
    return 0;
}
