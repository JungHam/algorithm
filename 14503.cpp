#include <iostream>

using namespace std;

int N, M;

int dir[4][2] = {{-1, 0}, { 0, -1 }, { 1, 0 }, { 0, 1 } }; //움직이는 방향 저장.

int map[50][50] = {0}; //맵 초기화

//문제 해설 : 시뮬레이션, 탐색 기초
//제발 좌표 저장하는 변수 헷갈리지 말자

bool isRange(int x, int y){
    return (x >= 0 && x < N && y >= 0 && y < M);
}
void move(int sx, int sy, int sd){

    int currx = sx;
    int curry = sy;
    int currd = sd;
    map[currx][curry] = 2; //이미 청소한 곳은 2로 표시
    int num = 1;
    while (1){
        //print();

        int count = 0;

        for (int i = 1; i < 5; i++){ //4방향 
            int tempd = (currd + i)%4;
            int tempx = currx + dir[tempd][0];
            int tempy = curry + dir[tempd][1];
            if (map[tempx][tempy] == 0){ // 탐색 공간에 갈 곳 있다
                map[tempx][tempy] = 2;
                num++;
                currx = tempx;
                curry = tempy;
                currd = tempd;
                break;
            }
            else
                count++;
        }
        if (count == 4){
            // 후방 체크
            int backdir = (currd + 2)%4;

            if (map[currx + dir[backdir][0]][curry + dir[backdir][1]] == 1){ //뒤에 벽있나
                break;
            }
            else{
                currx += dir[backdir][0];
                curry += dir[backdir][1];
            }
        }

    }
    cout << num << endl;
}


int main(){
    cin >> N >> M;
    int startx, starty, startd;
    cin >> startx >> starty >> startd;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    if (startd == 1){
        startd = 3;
    }
    else if (startd == 3){
        startd = 1;
    }
    move(startx,starty,startd);

}