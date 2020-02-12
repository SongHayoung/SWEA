#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, N, answer;
	string s;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> s;
		answer = 0;
		switch (N) {
		case 2:
			cout << "#" << test_case << " 0\n";
			break;
		default:
			for (int i = 0; i<s.length(); i++)
				answer += s[i] - 48;
			cout << "#" << test_case << " " << (answer % (N - 1)) << endl;
			break;
		}
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
