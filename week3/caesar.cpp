#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

ll M = 1e8;

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int n,m,a,b;
cin >> n >> m >> a >> b;
// vector<vector<ll>> dp(n-1,vector<ll>(m-1,0));
int p = max(a,b);
vector<vector<vector<vector<ll>>>> dp(n+1,vector<vector<vector<ll>>>(m+1,vector<vector<ll>>(p,vector<ll>(2,0))));
dp[1][0][0][0]=1;
dp[0][1][0][1]=1;
for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
        for(int k=0;k<p;k++){
           if(i<n){
            dp[i+1][j][0][0]=(dp[i+1][j][0][0]+dp[i][j][k][1])%M;
            if(k<a-1){
            dp[i+1][j][k+1][0]=(dp[i][j][k][0]+dp[i+1][j][k+1][0])%M;
           } 
           }
           if(j<m){
            if(k<b-1){
            dp[i][j+1][k+1][1]=(dp[i][j][k][1]+dp[i][j+1][k+1][1])%M;
           } 
           dp[i][j+1][0][1]=(dp[i][j+1][0][1]+dp[i][j][k][0])%M;
           }
        }
    }
}
int ans=0;
for(int k=0;k<p;k++){
    ans = (ans+dp[n][m][k][0]+dp[n][m][k][1])%M;
}
cout << ans;
}