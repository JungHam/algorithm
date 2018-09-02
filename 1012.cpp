#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int totalBug = 0;
int ground[50][50];
bool visited[50][50];
int r,c, k = 0;

class P{
public:
    int x;
    int y;
    P();
    P(int a, int b){x = a, y = b;}
};
void dfs(int i, int j){
    visited[i][j] = true;
    if(i+1 < r && ground[i+1][j] == 1 && !visited[i+1][j])
        dfs(i+1,j);
    if(j+1 < c && ground[i][j+1] == 1 && !visited[i][j+1])
        dfs(i,j+1);
    if(i-1 >= 0 && ground[i-1][j] == 1 && !visited[i-1][j])
        dfs(i-1,j);
    if(j-1 >= 0 && ground[i][j-1] == 1 && !visited[i][j-1])
        dfs(i,j-1);

}

int main(){
    int testCase = 0;


    cin >> testCase;

    for(int i = 0 ; i < testCase ; i++){
        cin >> r >> c >> k;

        for(int j = 0 ; j < r ; j++){
            memset(ground[j],0,sizeof(int)*c);
            memset(visited[j], false, sizeof(bool)*c);
        }

        vector<P>list;

        for(int j = 0 ; j < k ; j++){
            int tx, ty;
            cin >> tx >> ty;
            P tp(tx,ty);
            list.push_back(tp);
            ground[tx][ty] = 1;
        }
        int count = 0;
        for(int j = 0 ; j < k ; j++){
            if(!visited[list[j].x][list[j].y]){
                dfs(list[j].x,list[j].y);
                count++;
            }

        }
        cout << count << endl;
    }
}