#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
ll M = 1e9+7;
ll t;
cin >> t;
vector<ll> q(t,-1);
for(int i=0;i<t;i++){
    cin >> q[i];
}
ll a = *max_element(q.begin(),q.end());
vector<vector<ll>> v(a+1,vector<ll>(2,0));
v[1][1]=1;
v[1][0]=1;
for(int i=2;i<=a;i++){
    v[i][1]=(v[i-1][0]+(2LL*v[i-1][1])%M)%M;
    v[i][0]=(v[i-1][1]+(4LL*v[i-1][0])%M)%M;
}
for(auto x:q){
    cout << (v[x][0]+v[x][1])%M << "\n";
}
}