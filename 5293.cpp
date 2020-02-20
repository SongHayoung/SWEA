#include <iostream>
#include <string>
#include <vector>
using namespace std;
int A, B, C, D;
vector< vector<vector<vector<vector<string> > > > > DP(21,
        vector<vector<vector<vector<string> > > >(21,
        vector<vector<vector<string> > >(21,
        vector<vector<string> > (21,
        vector<string>(2)))));
void make_str(string s, int a, int b, int c, int d, int last){
    DP[a][b][c][d][last]=s;
    switch(s[s.length()-1]){
        case '0' :
            if(a<20&&DP[a+1][b][c][d][0].empty())
                make_str(s + '0',a + 1, b, c, d,0);
            if(b<20&&DP[a][b+1][c][d][1].empty())
                make_str(s + '1', a, b + 1, c, d,1);
            break;
        case '1' :
            if(c<20&&DP[a][b][c+1][d][0].empty())
                make_str(s + '0', a, b, c + 1, d,0);
            if(d<20&&DP[a][b][c][d+1][1].empty())
                make_str(s + '1', a, b, c, d + 1,1);
            break;
        default:
            break;
    }
}
int main(int argc, char** argv) {
    register int i;
    int TC;
    scanf("%d",&TC);
    make_str("0",0,0,0,0,0);
    make_str("1",0,0,0,0,1);
    for (i = 1; i<=TC; i++) {
        scanf("%d %d %d %d",&A,&B,&C,&D);
        DP[A][B][C][D][0].empty() ? (DP[A][B][C][D][1].empty() ? printf("#%d impossible\n",i) :
                                     printf("#%d %s\n",i,DP[A][B][C][D][1].c_str())) :
                                     printf("#%d %s\n",i,DP[A][B][C][D][0].c_str());
    }
}
