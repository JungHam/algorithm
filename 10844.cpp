#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 101;
long long dp[MAX][10];
long long division = 1000000000;

int main(){
    int num;
    cin >> num;
    long long result = 0;

    for(int i = 1 ; i <= 9 ; i++){
        dp[1][i] = 1;
    }

    for(int i = 2 ; i <= num ; i++){
        for(int j = 0 ; j <= 9 ; j++){
            if(j-1 >= 0){
                dp[i][j] = (dp[i][j]+dp[i-1][j-1])%division;
            }
            if(j+1 < 10){
                dp[i][j] = (dp[i][j]+dp[i-1][j+1])%division;
            }
        }
    }

    for(int i = 0 ; i <= 9 ; i++){
        result = result%division + dp[num][i]%division;
    }
    cout << result%division;
}