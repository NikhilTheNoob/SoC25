#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin >> n;
vector<ll> v(n,-1);
for(int i=0;i<n;i++){
    cin >> v[i];
}
vector<ll> u=v;
sort(u.begin(),u.end());
u.erase(unique(u.begin(),u.end()),u.end());
vector<ll> dp(u.size(),0);
vector<vector<ll>> prefix_min(2,vector<ll>(u.size(),LLONG_MAX));

dp[0] = abs(v[0]-u[0]);
prefix_min[0][0] = abs(v[0]-u[0]);
for(int i=1;i<u.size();i++){
    dp[i] = abs(v[0]-u[i]);
    prefix_min[0][i] = min(prefix_min[0][i-1],abs(v[0]-u[i]));
}

for(int i=1;i<n;i++){
    prefix_min[1].assign(u.size(), LLONG_MAX);
    for(int j=0;j<u.size();j++){
        dp[j] = abs(v[i]-u[j])+prefix_min[0][j];
        if(j==0){ prefix_min[1][j]=dp[j]; }
        else{ prefix_min[1][j]=min(dp[j],prefix_min[1][j-1]);}
    }
    prefix_min[0]=prefix_min[1];
}
cout << *min_element(dp.begin(),dp.end()) << "\n";
}