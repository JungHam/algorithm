#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


const int MAX = 1000001;
int dp[MAX];
int main(){

    memset(dp,0,sizeof(dp));
    int n = 0;
    cin >> n;
    fill(dp, dp+MAX,10000000000);
    dp[1] = 0;
    for(int i = 0 ; i < n ; i++){
        dp[i+1] =  min(dp[i+1],dp[i]+1);
        if(i*2 < MAX) dp[i * 2] = min(dp[i*2], dp[i] + 1);
        if(i*3 < MAX) dp[i * 3] = min(dp[i*3], dp[i] + 1);
    }
    cout << dp[n];
}