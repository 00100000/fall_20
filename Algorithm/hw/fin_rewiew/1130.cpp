#include <cstdio>
#include <queue>
using namespace std;

int n, m, t;
int sy, sx;
int go[5][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {0, 0}};
int map[105][105];
int enpos[1005][105][105];
int enemy[10005][3];
int n_enemy;

int inq(int t, int y, int x);
void deq(int in, int &t, int &y, int &x);

int main(){
    // input
    scanf("%d%d%d", &n, &m, &t);
    n_enemy = 0;
    int in;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &in);
            if(in == 0) map[i][j] = 0;
            else if(in == 3) map[i][j] = 3;
            else{
                map[i][j] = 1;
                if(in == 2){
                    sy = i;
                    sx = j;
                }
                else if(in >= 4 && in <= 7){
                    enemy[n_enemy][0] = i;
                    enemy[n_enemy][1] = j;
                    enemy[n_enemy][2] = in % 4;
                    n_enemy ++;
                }
            }
        }
    }

    // enemy
    int y, x;
    for(int i = 0; i <= t; i++){
        for(int j = 0; j < n_enemy; j++)
            enpos[i][enemy[j][0]][enemy[j][1]] = 1;
        // one step
        for(int j = 0; j < n_enemy; j++){
            y = enemy[j][0] + go[enemy[j][2]][0];
            x = enemy[j][1] + go[enemy[j][2]][1];
            if(y < 0 || x < 0 || y >= n || x >= m || map[y][x] == 0){
                enemy[j][2] ++;
                enemy[j][2] %= 4;
            }
            else{
                enemy[j][0] = y;
                enemy[j][1] = x;
            }
        }
    }
}