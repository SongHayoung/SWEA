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
/* Trie Algorithm Runtime Error(Memory Issue)
#include <iostream>
#include <memory.h>
using namespace std;
#define Alpha 26
inline int get_Index(char c);
inline bool is_Alpha(char c);
struct Trie{
    Trie *next[Alpha];
    bool is_Finish;
    Trie() : is_Finish(false){
        memset(next,0,sizeof(next));
    }
    ~Trie(){
        for(int i=0;i < Alpha; i++)
            if(next[i]!=0)
                delete next[i];
    }
    void insert(const char *key){
        if(is_Alpha(*key)){
            if(next[get_Index(*key)]==0)
                next[get_Index(*key)] = new Trie();
            next[get_Index(*key)]->insert(key+1);
        }
        else
            is_Finish = true;
    }
    bool is_Same(const char *key){
        if(is_Alpha(*key)){
            if(next[get_Index(*key)]==0)
                return false;
            return next[get_Index(*key)]->is_Same(key+1);
        }
        return is_Finish;
    }
};
inline int get_Index(char c){
    return c-'a';
}
inline bool is_Alpha(char c){
    return 'a'<=c&&c<='z';
}
int main(int argc, char** argv)
{
    int T, N, M;
    register char c[51];
    register int i, test_case, answer;
    scanf("%d",&T);
    Trie *root;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        root = new Trie();
        answer = 0;
        scanf("%d %d",&N,&M);
        for(i=0;i<N;i++) {
            scanf("%s",&c);
            root->insert(c);
        }
        for(i=0;i<M;i++) {
            scanf("%s",&c);
            if(root->is_Same(c))
                ++answer;
        }
        printf("#%d %d\n",test_case,answer);
        delete root;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
*/
