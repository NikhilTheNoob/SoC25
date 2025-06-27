#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
ll x,n;
multiset<ll> m;
ll temp;
ll ans=0;
cin >> x >> n;
for(int i=0;i<n;i++){
    cin >> temp;
    m.insert(temp);
}
for(int i=0;i<n-1;i++){
    ans += *next(m.begin())+*m.begin();
    m.insert(*next(m.begin())+*m.begin());
    m.erase(next(m.begin()));
    m.erase(m.begin());
}
cout << ans << "\n";
}