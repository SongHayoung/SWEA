#include<iostream>
#include <vector>
#include <queue>
using namespace std;
class atom {
public:
    int energy;
    int way;
    int x;
    int y;
    bool dead;
    atom(int _x, int _y ,int e, int w, bool d) : x(_x), y(_y), energy(e), way(w) , dead(d){
    }
};

int main(int argc, char** argv)
{
    int test_case;
    int T;
    int N, x, y, energy, way,answer;
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        vector<atom> atoms;
        vector<int> colision;
        vector<vector<int>> MAP(2001, vector<int>(2001, 0));
        queue<pair<int, int>> boom;
        atoms.push_back(atom(0, 0, 0, 0, false));
        answer = 0;
        int value;
        for (int j = 1; j <= N; j++) {
            cin >> x >> y >> way >> energy;
            x += 1000; y = 1000 - y;
            MAP[y][x] = j;
            atoms.push_back(atom(x, y, energy, way, false));
        }
        for (int k = 0; k <= 2001; k++) {
            bool flag=true;
            for (int j = 1; j <= N; j++) {
                if (atoms[j].dead)
                    continue;
                flag = false;
                int _x = atoms[j].x + dx[atoms[j].way];
                int _y = atoms[j].y + dy[atoms[j].way];
                if (0 <= _x && _x <= 2000 && 0 <= _y && _y <= 2000) {
                    if (MAP[_y][_x] !=0)
                        if (atoms[j].way + atoms[MAP[_y][_x]].way == 1 || atoms[j].way + atoms[MAP[_y][_x]].way == 5) {
                            atoms[j].dead = true;
                            atoms[MAP[_y][_x]].dead = true;
                            colision.push_back(j);
                            colision.push_back(MAP[_y][_x]);
                            MAP[_y][_x] = 0;
                            MAP[atoms[j].y][atoms[j].x] = 0;
                        }
                }
            }
            for(int j=1;j<=N;j++){
                if (atoms[j].dead)
                    continue;
                if (MAP[atoms[j].y][atoms[j].x] == j)
                    MAP[atoms[j].y][atoms[j].x] = 0;
                atoms[j].x = atoms[j].x + dx[atoms[j].way];
                atoms[j].y = atoms[j].y + dy[atoms[j].way];
                if (0 > atoms[j].x || atoms[j].x > 2000 || 0 > atoms[j].y || atoms[j].y > 2000) {
                    atoms[j].dead = true;
                }
                if (atoms[j].dead)
                    continue;
                value = MAP[atoms[j].y][atoms[j].x];
                if (value == 1234) {
                    colision.push_back(j);
                    atoms[j].dead = true;
                }
                else if (value == 0 || value > j) {
                    MAP[atoms[j].y][atoms[j].x] = j;
                }
                else {
                    if (value < j) {
                        colision.push_back(MAP[atoms[j].y][atoms[j].x]);
                        colision.push_back(j);
                        atoms[MAP[atoms[j].y][atoms[j].x]].dead = true;
                        atoms[j].dead = true;
                        MAP[atoms[j].y][atoms[j].x] = 1234;   //colision
                        boom.push(make_pair(atoms[j].y, atoms[j].x));
                    }
                }
            }
            if (flag)
                break;
            while (!boom.empty()) {
                MAP[boom.front().first][boom.front().second] = 0;
                boom.pop();
            }
        }
        for (int j = 0; j < colision.size(); j++)
            answer += atoms[colision[j]].energy;

        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
