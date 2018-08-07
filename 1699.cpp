#include<cstdio>
#include<algorithm>

using namespace std;
const int MAX = 100001;
int dp[MAX];
int sqrt[MAX];
const int IMPOSSIBLE = 1000000000;

int main(){
    int c;
    scanf("%d",&c);

    for(int i = 0 ; i < c+1 ; i++){
        dp[i] = -1;
    }

    dp[0] = 0;
    dp[1] = 1;
    dp [2] = 2;
    dp[3] = 3;

    for(int i = 4 ; i < c+1 ; i++){
        dp[i] = IMPOSSIBLE;
        for(int j = 1 ; j*j < i+1 ; j++){
            dp[i] = min(dp[i],dp[i-j*j]+1) ;
        }
    }


    printf("%d\n",dp[c]);


}