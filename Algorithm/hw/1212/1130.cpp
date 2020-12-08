#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int go[1005][100][100]; // 1 if there is enemy
int target[105][105]; // wall and destination
int enemy[10000][3];

int stx, sty;

int make(int y, int x, int t){
    int ans = 0;
    ans |= y;
    ans <<= 8;
    ans |= x;
    ans <<= 16;
    ans |= t;
    return ans;
}

void anal(int in, int &y, int &x, int &t){
    y = 0;
    x = 0;
    t = 0;
    y = (in & 0xFF000000) >> 24;
    x = (in & 0x00FF0000) >> 16;
    t = in & 0x0000FFFF;
}

int main(){
    int n, m, t;
    int en = 0;
    scanf("%d%d%d", &n, &m, &t);

    //printf("%d %d %d\n", n, m, t);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int in;
            scanf("%d", &in);
            //go[1][i][j] = in;

            if(in == 2){
                sty = i;
                stx = j;
            }

            if(in == 0) target[i][j] = 0;
            else if(in == 3) target[i][j] = 3;
            else target[i][j] = 1;

            if(in >= 4){
                enemy[en][0] = i;
                enemy[en][1] = j;
                enemy[en][2] = in;
                en++;
            }
        }
    }
    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) printf("%d ", target[i][j]);
        printf("\n");
    }
    */
    
    for(int i = 2; i <= t; i++){
        for(int j = 0; j < en; j++){
            int cury = enemy[j][0];
            int curx = enemy[j][1];

            if(enemy[j][2] == 4){ //up
                if(target[cury - 1][curx] == 0 || cury - 1 < 0){ // wall
                    enemy[j][2] = 5;
                }
                else enemy[j][0] --;
            }

            else if(enemy[j][2] == 5){ //right
                if(target[cury][curx + 1] == 0 || curx + 1 >= m){ // wall
                    enemy[j][2] = 6;
                }
                else enemy[j][1] ++;
            }

            else if(enemy[j][2] == 6){ //down
                if(target[cury + 1][curx] == 0 || cury + 1 >= n){ // wall
                    enemy[j][2] = 7;
                }
                else enemy[j][0] ++;
            }

            else{ //left
                if(target[cury][curx - 1] == 0 || curx - 1 < 0){ // wall
                    enemy[j][2] = 4;
                }
                else enemy[j][1] --;
            }
            go[i][ enemy[j][0] ][ enemy[j][1] ] = 1;
        }

        printf("time: %d\n", i);
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++) printf("%d ", go[i][j][k]);
            printf("\n");
        }
        printf("\n");
    }

    queue<int> q;
    q.push(make(sty, stx, 1));
    int done = 0;
    while(!q.empty()){
        int y, x, now;
        anal(q.front(), y, x, now);
        q.pop();
        if(now == t) break;

        printf("cy: %d, cx: %d, ct: %d\n", y, x, now);

        //up
        if(target[y-1][x] == 3){
            printf("%d\n", now + 1);
            done = 1;
            break;
        }
        if(y-1 < 0 || go[now+1][y-1][x] || target[y-1][x] == 0){}
        else if(go[now][y-1][x] && go[now+1][y][x]){}
        else {
            q.push(make(y-1, x, now+1)); 
            go[now+1][y-1][x] = 5; 
            printf("UP y: %d x: %d t: %d\n", y-1, x, now+1);
        }

        //right
        if(target[y][x+1] == 3){
            printf("%d\n", now + 1);
            done = 1;
            break;
        }
        if(x+1 >= m || go[now+1][y][x+1] || target[y][x+1] == 0){}
        else if(go[now][y][x+1] && go[now+1][y][x]){}
        else {
            q.push(make(y, x+1, now+1)); 
            go[now+1][y][x+1] = 5; 
            printf("RI y: %d x: %d t: %d\n", y, x+1, now+1);
        }

        //down
        if(target[y+1][x] == 3){
            printf("%d\n", now + 1);
            done = 1;
            break;
        }
        if(y+1 >= n || go[now+1][y+1][x] || target[y+1][x] == 0){}
        else if(go[now][y+1][x] && go[now+1][y][x]){}
        else {
            q.push(make(y+1, x, now+1)); 
            go[now+1][y+1][x] = 5; 
            printf("DN y: %d x: %d t: %d\n", y+1, x, now+1);
        }

        //left
        if(target[y][x-1] == 3){
            printf("%d\n", now + 1);
            done = 1;
            break;
        }
        if(x-1 < 0  || go[now+1][y][x-1] || target[y][x-1] == 0){}
        else if(go[now][y][x-1] && go[now+1][y][x]){}
        else {
            q.push(make(y, x-1, now+1)); 
            go[now+1][y][x-1] = 5; 
            printf("LE y: %d x: %d t: %d\n", y, x-1, now+1);
        }

        //no change
        if(go[now+1][y][x]){}
        else {
            q.push(make(y, x, now+1)); 
            go[now+1][y][x-1] = 5; 
            printf("NO y: %d x: %d t: %d\n", y, x, now+1);
        }

        printf("\n");
    }
    if(!done) printf("-1\n");
}