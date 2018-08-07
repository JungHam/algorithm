#include<cstdio>
#include<algorithm>

using namespace std;
const int MAX = 10001;
int dp[MAX];
int main(){
    int c;
    scanf("%d",&c);
    dp[0] = 1;
    dp[1] = 2;
    for(int i = 0 ; i < c-2 ; i++)
        dp[i+2] = (dp[i] + dp[i+1])%10007; // 오버플로우 방지, n으로 나눈다는 것은 n진수 수를 다룬다는 것.
    int result = dp[c-1];
    printf("%d\n",result);
}