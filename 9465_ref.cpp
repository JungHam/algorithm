#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


const int MAX = 100001;
int tile[2][MAX];
int main(){
    int numoftest = 0;
    int numofcolumn = 0;
    cin >> numoftest;

    for(int t = 0 ; t < numoftest ; t++){
        cin >> numofcolumn;

        for(int i = 0 ; i < 2 ; i++)
            memset(tile[i],0,sizeof(tile[i]));

        for(int i = 0  ; i < 2 ; i++)
            for(int j = 0 ; j < numofcolumn ; j++)
                cin >> tile[i][j];

        //for(int i = 0 ; i < MAX ; i++) //2차원배열 초기화
         //   memset(dp[i],0,sizeof(dp[i]));
        int dp[MAX][3] = {0};


        for(int i = 0 ; i < numofcolumn ; i++){
           dp[i+1][0] = max(dp[i+1][0],max(dp[i][0],max(dp[i][1], dp[i][2])));
           dp[i+1][1] = max(dp[i+1][1],max(dp[i][0],dp[i][2])+tile[0][i]);
           dp[i+1][2] = max(dp[i+1][2], max(dp[i][0],dp[i][1])+tile[1][i]);
        }

        cout << max(dp[numofcolumn][0],max(dp[numofcolumn][1],dp[numofcolumn][2])) << endl;
    }




}