#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin >> n;
vector<pair<int,int>> v(n,{-1,-1});
for(int i=0;i<n;i++){
    cin >> v[i].first >> v[i].second;
}
sort(v.begin(),v.end());
ll curr=0;
ll ans=0;
for(int i=0;i<n;i++){
    curr+=v[i].first;
    ans+= v[i].second-curr;
}
cout << ans << endl;
}