#include <iostream>
using namespace std;
int main(void)
{
    int tc;
    cin >> tc;
    int t2, m2;
    int at, am;
    bool flag;
    for (int i = 1; i <= tc; i++) {
        cin >> at >> am >> t2 >> m2;
        flag = false;
        am += m2;
        if (am >= 60) {
            flag = true;
            am -= 60;
        }
        at += t2;
        if (flag)
            ++at;
        if (at >= 13)
            at -= 12;
        cout << "#" << i << " " << at << " " << am << endl;
    }
}
