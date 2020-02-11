#include<iostream>

using namespace std;
void solution(int n) {
    bool flag = false;
    int N = n;
    do {
        if (N % 10 == 3 || N % 10 == 6 || N % 10 == 9) {
            cout << "-";
            flag = true;
        }
        N /= 10;
    } while (N);
    if (!flag) {
        cout << n;
        return;
    }
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case < T; ++test_case)
    {
        solution(test_case);
        cout << " ";
    }
    solution(T);
    return 0;
}
