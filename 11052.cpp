#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int dp[MAX];
int cost[MAX];

int main(){
    int num;
    cin >> num;
    for(int i = 1 ; i < num+1 ; i++){
        cin >> cost[i];
        dp[i] = cost[i];
    }
    for(int i = 2 ; i < MAX ; i++){
        for(int j = 1 ; j < i ; j++){
            dp[i] = max(dp[i],dp[i-j]+cost[j]);
        }
    }
    cout << dp[num];
}