#include <cstdio>
#include <queue>
#define UI unsigned int
using namespace std;

int n, m, t;
int sy, sx; // start
int en;

int enemy[10005][3]; //y, x, direction
int map[105][105]; //wall & destinations
int nextpos[1005][105][105];
int change[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

UI inq(int time, int y, int x);
void deq(UI in, int &time, int &y, int &x);

int main(){
    scanf("%d%d%d", &n, &m, &t);
    en = 0;

    // input
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int in;
            scanf("%d", &in);
            if(in == 0) map[i][j] = 1; // wall
            else if(in == 1) map[i][j] = 0; // road
            else if(in == 2){ // start
                sy = i;
                sx = j;
                map[i][j] = 0;
            }
            else if(in == 3) map[i][j] = 3; // destination
            else{ // enemy
                map[i][j] = 0;
                enemy[en][0] = i;
                enemy[en][1] = j;
                enemy[en][2] = in;
                en ++;
            }
        }
    }

    for(int i = 0; i < en; i++){
        nextpos[1][enemy[i][0]][enemy[i][1]] = 1;
    }
    nextpos[1][sy][sx] = 2;

    for(int i = 2; i <= t; i++){
        for(int j = 0; j < en; j++){
            int step = enemy[j][2];
            step -= 4;
            int nexty = enemy[j][0] + change[step][0];
            int nextx = enemy[j][1] + change[step][1];
            if(nexty < 0 || nextx < 0 || nexty >= n || nextx >= m || map[nexty][nextx] == 1){
                step ++;
                step %= 4;
                step += 4;
                enemy[j][2] = step;
                nextpos[i][ enemy[j][0] ][ enemy[j][1] ] = 1;
            }
            else{
                enemy[j][0] = nexty;
                enemy[j][1] = nextx;
                nextpos[i][nexty][nextx] = 1;
            }
        }   
    }

    queue<UI> q;
    q.push(inq(1, sy, sx));
    int done = 0;
    while(!q.empty()){
        int nowt, nowy, nowx;
        deq(q.front(), nowt, nowy, nowx);
        q.pop();

        if(nowt == t) break;

        // up
        // right
        // down
        // left
        for(int i = 0; i < 4; i++){
            int nexty = nowy + change[i][0];
            int nextx = nowx + change[i][1];
            if(nexty < 0 || nextx < 0 || nexty >= n || nextx >= m) continue; // bound
            if(nextpos[(nowt+1)][nexty][nextx] == 2) continue; // done
            if(map[nexty][nextx] == 1) continue; // wall
            if(nextpos[(nowt+1)][nexty][nextx] == 1) continue; // enemy is there
            if(nextpos[nowt][nexty][nextx] == 1 && nextpos[(nowt+1)][nowy][nowx] == 1) continue; // enemy cross
            if(map[nexty][nextx] == 3){
                done = 1;
                printf("%d\n", nowt + 1);
                break;
            }
            q.push(inq(nowt+1, nexty, nextx));
            nextpos[(nowt+1)][nexty][nextx] = 2;
        }
        if(done) break;

        // no move
        if(nextpos[(nowt+1)][nowy][nowx] == 1){}
        else{
            q.push(inq(nowt+1, nowy, nowx));
            nextpos[(nowt+1)][nowy][nowx] = 2;
        }
    }
    if(!done) printf("-1\n");
}

UI inq(int time, int y, int x){
    UI ans = 0;
    ans |= time;
    ans <<= 8;
    ans |= y;
    ans <<= 8;
    ans |= x;
    return ans;
}

void deq(UI in, int &time, int &y, int &x){
    time = 0;
    time |= (in & 0xFFFF0000);
    time >>= 16;

    y = 0;
    y |= (in & 0x0000FF00);
    y >>= 8;

    x = 0;
    x |= (in & 0x000000FF);
}