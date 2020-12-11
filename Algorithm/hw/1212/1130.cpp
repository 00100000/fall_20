#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int go[1005][102][102]; // [time][y][x] : 1 if threre is an enemy
int target[105][105]; // [y][x] : wall(0) and destination(3)
int enemy[10005][3]; // [# of enemy][y, x, direction]

int sx, sy; // source

int inq(int y, int x, int t){
    int ans = 0;
    ans |= y;
    ans <<= 8;
    ans |= x;
    ans <<= 16;
    ans |= t;
    return ans;
}

void deq(unsigned int in, int &y, int &x, int &t){
    y = 0;
    x = 0;
    t = 0;
    y = (in & 0xFF000000) >> 24;
	y &= 0x000000FF;
    x = (in & 0x00FF0000) >> 16;
	x &= 0x000000FF;
    t = in & 0x0000FFFF;
}

int main(){
    int n, m, t;
    int en = 0; // # of enemy
    scanf("%d%d%d", &n, &m, &t);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int in;
            scanf("%d", &in);

            if(in == 2){ //source
                sy = i;
                sx = j;
            }

            if(in == 0) target[i][j] = 0; // wall
            else if(in == 3) target[i][j] = 3; // destination
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
    
    // move enemy
    for(int i = 0; i <= t; i++){
        for(int j = 0; j < en; j++){

            //
            go[i][ enemy[j][0] ][ enemy[j][1] ] = 1;

            // move or turn
            int moved = 0; // no use XDD
                if(!moved && enemy[j][2] == 4){ //up
                    if(target[ enemy[j][0] - 1][ enemy[j][1] ] == 0 || enemy[j][0] - 1 < 0){ // wall & boundary
                        enemy[j][2] = 5;
                    }
                    else{
                        enemy[j][0] --;
                        moved = 1;
                    } 
                }

                else if(!moved && enemy[j][2] == 5){ //right
                    if(target[ enemy[j][0] ][ enemy[j][1] + 1] == 0 || enemy[j][1] + 1 >= m){ // wall & boundary
                        enemy[j][2] = 6;
                    }
                    else{ 
                        enemy[j][1] ++;
                        moved = 1;
                    }
                }

                else if(!moved && enemy[j][2] == 6){ //down
                    if(target[ enemy[j][0] + 1][ enemy[j][1] ] == 0 || enemy[j][0] + 1 >= n){ // wall & boundary
                        enemy[j][2] = 7;
                    }
                    else {
                        enemy[j][0] ++;
                        moved = 1;
                    }
                }

                else if(!moved && enemy[j][2] == 7){ //left
                    if(target[ enemy[j][0] ][ enemy[j][1] - 1] == 0 || enemy[j][1] - 1 < 0){ // wall & boundary
                        enemy[j][2] = 4;
                    }
                    else {
                        enemy[j][1] --;
                        moved = 1;
                    }
                }            
        }
        /*
        printf("time: %d\n", i);
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++) printf("%d ", go[i][j][k]);
            printf("\n");
        }
        printf("\n");
        */
    }

    queue<int> q;
    q.push(inq(sy, sx, 0));
    go[0][sy][sx] = 5; // pushed
    int done = 0;
    while(!q.empty()){
        int y, x, now;
        deq(q.front(), y, x, now);
        q.pop();
        if(now >= t) break;

        //up
        
        if(y-1 < 0 || go[now+1][y-1][x] || target[y-1][x] == 0){} // boundary || pushed/enemy will be there || wall
        else if(go[now][y-1][x] == 1){} // enemy is there
        else if(target[y-1][x] == 3){ // destination
            printf("%d\n", now + 1);
            done = 1;
            break;
        }
        else { //move
            q.push(inq(y-1, x, now+1)); 
            go[now+1][y-1][x] = 5; 
            //printf("UP y: %d x: %d t: %d\n", y-1, x, now+1);
        }

        //right
        
        if(x+1 >= m || go[now+1][y][x+1] || target[y][x+1] == 0){}
        else if(go[now][y][x+1] == 1){}
        else if(target[y][x+1] == 3){
            printf("%d\n", now + 1);
            done = 1;
            break;
        }
        else {
            q.push(inq(y, x+1, now+1)); 
            go[now+1][y][x+1] = 5; 
            //printf("RI y: %d x: %d t: %d\n", y, x+1, now+1);
        }

        //down
        
        if(y+1 >= n || go[now+1][y+1][x] || target[y+1][x] == 0){}
        else if(go[now][y+1][x] == 1){}
        else if(target[y+1][x] == 3){
            printf("%d\n", now + 1);
            done = 1;
            break;
        }
        else {
            q.push(inq(y+1, x, now+1)); 
            go[now+1][y+1][x] = 5; 
            //printf("DN y: %d x: %d t: %d\n", y+1, x, now+1);
        }

        //left
        
        if(x-1 < 0  || go[now+1][y][x-1] || target[y][x-1] == 0){}
        else if(go[now][y][x-1] == 1){}
        else if(target[y][x-1] == 3){
            printf("%d\n", now + 1);
            done = 1;
            break;
        }
        else {
            q.push(inq(y, x-1, now+1)); 
            go[now+1][y][x-1] = 5; 
            //printf("LE y: %d x: %d t: %d\n", y, x-1, now+1);
        }

        //no change
        if(go[now+1][y][x]){} // enemy will be there 
        else {
            q.push(inq(y, x, now+1)); 
            go[now+1][y][x] = 5; 
            //printf("NO MOVE y: %d x: %d t: %d\n", y, x, now+1);
        }

        //printf("\n");
    }
    if(!done) printf("-1\n");
}