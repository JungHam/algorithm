#include<cstdio>
#include<algorithm>

using namespace std;
const int MAX = 10001;
int dp[MAX];
int main(){
    int c;
    scanf("%d",&c);
    dp[0] = 1;
    dp[1] = 3;
    for(int i = 0 ; i < c-2 ; i++)
        dp[i+2] = (dp[i]*2%10007 + dp[i+1]%10007)%10007;
    int result = dp[c-1];
    printf("%d\n",result);
}