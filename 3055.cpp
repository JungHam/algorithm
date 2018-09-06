#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

class Point{
public:
    int x;
    int y;
    Point(){}
    Point(int a, int b){
        x = a;
        y = b;
    }

};

char map[50][50];
bool visited[50][50];
bool watered[50][50];
int r,  c;

bool checkPlace(int x, int y){
    if(!watered[x][y] && (char)map[x][y] != '*' && (char)map[x][y] != 'X' && !visited[x][y]){
        return true;
    }
    return false;

}
bool checkWaterPlace(int x, int y){
    if(map[x][y] != 'X' && map[x][y] != 'D' && !watered[x][y])
        return true;
    return false;
}

int bfs(int sx, int sy, vector<Point> waterList){
    queue<Point> waterQueue;
    queue<Point> aniQueue;

    Point start(sx,sy);
    visited[sx][sy] = true;
    //waterQueue.push(Point(ws,wy));
    for(int i = 0 ; i < waterList.size(); i++){
        waterQueue.push(waterList.at(i));
    }
    aniQueue.push(start);
    int count = 0;

    bool canEscape = false;
    while(!aniQueue.empty() && !canEscape){ // 종료되면 갈 수 있는 곳이 없거나 답을 찾은 경우
        int qsize = waterQueue.size();
        if(qsize != 0){

            for(int i = 0 ; i < qsize ; i++){
                Point curr = waterQueue.front();
                waterQueue.pop();
                if(curr.x+1 < r && !watered[curr.x+1][curr.y] && checkWaterPlace(curr.x+1, curr.y)){
                    watered[curr.x+1][curr.y] = true;
                    Point next(curr.x+1, curr.y);
                    waterQueue.push(next);
                }
                if(curr.x-1 >= 0 && !watered[curr.x-1][curr.y]&& checkWaterPlace(curr.x-1, curr.y)){
                    watered[curr.x-1][curr.y] = true;
                    Point next(curr.x-1, curr.y);
                    waterQueue.push(next);
                }
                if(curr.y+1 < c && !watered[curr.x][curr.y+1] && checkWaterPlace(curr.x, curr.y+1)){
                    watered[curr.x][curr.y+1] = true;
                    Point next(curr.x, curr.y+1);
                    waterQueue.push(next);
                }
                if(curr.y-1 >= 0 && !watered[curr.x][curr.y-1] && checkWaterPlace(curr.x, curr.y-1)){
                    watered[curr.x][curr.y-1] = true;
                    Point next(curr.x, curr.y-1);
                    waterQueue.push(next);
                }
            }

        }
        qsize = aniQueue.size();
        for(int i = 0 ; i < qsize ; i++){
            Point curr = aniQueue.front();
            aniQueue.pop();

            if((char)map[curr.x][curr.y] == 'D'){
                canEscape = true;
                break;
            }
            //cout << map[curr.x][curr.y] <<" " << curr.x << " "<< curr.y << endl;
            if(curr.x+1 < r && checkPlace(curr.x+1, curr.y)){
                visited[curr.x+1][curr.y] = true;
                aniQueue.push(Point(curr.x+1, curr.y));
            }
            if(curr.x-1 >= 0 && checkPlace(curr.x-1, curr.y)){
                visited[curr.x-1][curr.y] = true;
                aniQueue.push(Point(curr.x-1, curr.y));
            }
            if(curr.y+1 < c && checkPlace(curr.x, curr.y+1)){
                visited[curr.x][curr.y+1] = true;
                aniQueue.push(Point(curr.x, curr.y+1));
            }
            if(curr.y-1 >= 0 && checkPlace(curr.x, curr.y-1)){
                visited[curr.x][curr.y-1] = true;
                aniQueue.push(Point(curr.x, curr.y-1));
            }
        }
        count++;
    }
    if(!canEscape)
        count = 0;
    return count;
}

int main(){
    cin >> r >> c;
    int sx, sy;
    vector<Point>wl;
    for(int i = 0 ; i < r ; i++){
        string temp;
        cin >> temp;

        for(int j = 0 ; j < temp.size() ; j++){
            map[i][j] = (char)temp.at(j);
            visited[i][j] = false;
            watered[i][j] = false;
            if((char)temp.at(j) == 'S'){
                sx = i;
                sy = j;
            }
            if((char)temp.at(j) == '*'){
                wl.push_back(Point(i,j));
            }
        }
    }
    //cout << bfs(sx, sy)+1;
    int result = bfs(sx, sy,wl);
    if(result == 0){
        cout << "KAKTUS" << endl;
    }
    else{
        cout << result-1 << endl;
    }
}
