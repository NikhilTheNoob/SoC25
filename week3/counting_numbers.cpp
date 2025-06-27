#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

ll F(ll a){
    if(a==0){ return 1; }
    if(a==-1){ return 0; }
    string s = to_string(a);
    int n = s.size();
    vector<ll> d(n);
    for(int i=0;i<n;i++){
        d[i]=a%10;
        a/=10;
    }
    // reverse(d.begin(),d.end());
    // vector<vector<vector<vector<ll>>>> dp(d.size()+1,vector<vector<vector<ll>>>(1=0,vector<vector<ll>>(2,vector<ll>(2,0))));  
    ll dp[n+1][10][2][2];
    memset(dp, 0, sizeof dp);
    for(int i=1;i<d[n-1];i++){
        dp[1][i][0][0]=1;
    }
    dp[1][d[n-1]][1][0]=1;
    dp[1][0][0][1]=1;
    for(int i=1;i<n;i++){
        if(d[n-i-1]!=d[n-i]){ dp[i+1][d[n-i-1]][1][0]+=dp[i][d[n-i]][1][0]; }
        for(int l=0;l<d[n-i-1];l++){
            if(l==d[n-i]){ continue; }
            dp[i+1][l][0][0]+=dp[i][d[n-i]][1][0];
        }
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                if(k==j){ continue; }
                dp[i+1][k][0][0]+=dp[i][j][0][0];
            }
        }
        dp[i+1][0][0][1]+=dp[i][0][0][1];
        for(int l=1;l<10;l++){
            dp[i+1][l][0][0]+=dp[i][0][0][1];
        }
    }
    ll ans=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){ ans+= dp[n][i][j][k]; }
        }
    }
    return ans;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
ll a,b;
cin >> a >> b;
// int num_a, num_b;
// num_a = log10(a)+1;
// num_b = log10(b)+1;
// vector<vector<vector<vector<ll>>>> dp(num_b,vector<vector<vector<ll>>>(10,vector<vector<ll>>(2,vector<ll>(2,0))));
// int allow=num_b-num_a;
// if(allow>0){
//     for(int i=1;i<b/power(num_b-1);i++){
//         dp[0][i][0][0]=1;
//     }
//     dp[0][b/power(num_b-1)][1][0]=1;
//     dp[0][0][0][1]=1;
// }
// else{
//     for(int i=a/power(num_b-1)+1;i<b/power(num_b-1);i++){
//         dp[0][i][0][0]=1;
//     }
//     dp[0][b/power(num_b-1)][1][0]=1;
//     dp[0][a/power(num_b-1)][0][1]=1;
// }
// for(int i=0;i<num_b-1;i++){
//     for(int j=0;j<10;j++){
//         for(int k=0;k<10;k++){
//             if(k==j){ continue; }
//             dp[i+1][k][0][0]+=dp[i][j][0][0];
//         }
//         dp[i+1][b/power(num_b-i-2)][1][0]+=dp[i+1][j][1][0];
//         for(int l=b/power(num_b-i-2)-1;l>=0;l--){
//             dp[i+1][l][0][0]+=dp[i+1][j][1][0];
//         }
//         if(i+1<allow){  dp[i+1][0][0][1]+=dp[i][0][0][1];}
//         else{
//             dp[i+1][a/power(num_b-i-2)][0][1]+=dp[i][j][0][1];
//             for(int l=a/power(num_b-i-2)+1;l<=9;l++){
//             dp[i+1][l][0][0]+=dp[i+1][j][0][1];
//             }
//         }
//     }
// }
// ll ans =0;
// for(int i=0;i<2;i++){
//     for(int j=0;j<2;j++){
//         for(int k=0;k<=9;k++){
//             ans+=dp[num_b-1][k][i][j];
//         }
//     }
// }
cout << F(b)-F(a-1) << "\n";
}