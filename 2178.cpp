#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <queue>
using namespace std;

int place[100][100];
bool visited[100][100];
int r,c;
class Point{
public :
    int x,y;
    Point(){}
    Point(int a, int b){
        x = a;
        y = b;
    }
};

int bfs(){
    queue<Point> q;
    Point a(0,0);
    q.push(a);
    visited[0][0] = true;
    int count = 0;
    while(!q.empty()){
        int qsize = q.size();
        for(int i = 0 ; i < qsize ; i++){
            Point curr = q.front();
            q.pop();
            if(curr.x == r-1 && curr.y == c-1)
                return count;
            if(curr.x+1< r && place[curr.x+1][curr.y] == 1 && !visited[curr.x+1][curr.y]){
                visited[curr.x+1][curr.y] = true;
                Point next(curr.x+1, curr.y);
                q.push(next);
            }
            if(curr.x-1 >= 0 && place[curr.x-1][curr.y] == 1 && !visited[curr.x-1][curr.y]){
                visited[curr.x-1][curr.y] = true;
                Point next(curr.x-1, curr.y);
                q.push(next);
            }
            if(curr.y+1< c && place[curr.x][curr.y+1] == 1 && !visited[curr.x][curr.y+1]){
                visited[curr.x][curr.y+1] = true;
                Point next(curr.x, curr.y+1);
                q.push(next);
            }
            if(curr.y-1 >= 0&& place[curr.x][curr.y-1] == 1 && !visited[curr.x][curr.y-1]){
                visited[curr.x][curr.y-1] = true;
                Point next(curr.x, curr.y-1);
                q.push(next);
            }
        }
        count++;
    }
    return count;
}

int main(){

    cin >> r >> c;



    for(int i = 0 ; i < r ; i++){
        string temp;
        cin >> temp;
        for(int j = 0 ; j < c ; j++){
            place[i][j] = temp.at(j)-'0';
            visited[i][j] = false;
        }
    }
    cout << bfs()+1 << endl;



}
