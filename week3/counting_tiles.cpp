#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int n,m;
ll M = 1e9+7;

void generate_cols(int curr_col, int next_col, int idx, vector<int>& v){
    if(idx>=n){ v.push_back(next_col); return; }
    if(curr_col & (1<<idx)){
        generate_cols(curr_col,next_col,idx+1,v);
        return;
    }
    if(idx!=n-1){
        if(!(curr_col & (1<<idx)) && !(curr_col & (1<<(idx+1)))){
            generate_cols(curr_col,next_col,idx+2,v);
        }
    }
    if(!(curr_col & (1<<idx))){
        generate_cols(curr_col,next_col|(1<<idx),idx+1,v);
    }
}


int main() {
ios::sync_with_stdio(0);
cin.tie(0);
cin >> n >> m;
vector<vector<ll>> dp(m+1,vector<ll>((1<<n),0));
dp[0][0]=1;
vector<int> cols;
ll ans=0;
for(int i=0;i<m;i++){
    for(int j=0;j<(1<<n);j++){
        if(dp[i][j]==0){ continue; }
        cols.clear();
        generate_cols(j,0,0,cols);
        for(auto col : cols){
            dp[i+1][col] = (dp[i][j]+dp[i+1][col])%M;
        }
    }
}
cout << dp[m][0] << "\n";
}