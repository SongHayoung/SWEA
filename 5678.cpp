#include<iostream>
#include <algorithm>
using namespace std;
int Palindrome(string &s){
    int ret = 1;
    int len;
    for(int i=0;i<s.length()-1;i++){
        len = 0;
        while((i-len-1)>=0&&(i+len+1<s.length()) && s[i-len-1]==s[i+len+1])   ++len;
        ret = ret > (len<<1)+1 ? ret : (len<<1)+1;
        
        if(s[i]!=s[i+1])
            continue;
        len = 1;
        while((i-len)>=0&&(i+len+1<s.length()) && s[i-len]==s[i+1+len]) ++len;
        ret = ret > len<<1 ? ret : len<<1;
    }
    return ret;
}
int main(int argc, char** argv){
    register int test_case;
    int T;
    scanf("%d",&T);
    string str;
    for(test_case = 1; test_case<=T; test_case++){
        cin>>str;
        printf("#%d %d\n",test_case,Palindrome(str));
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
