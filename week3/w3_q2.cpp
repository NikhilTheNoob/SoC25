#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
ll n,t;
cin >> n >> t;
// multiset<pair<ll,ll>> m;
// ll temp,ans=0;
// for(int i=0;i<n;i++){
//  cin >> temp;
//  m.insert({temp,temp});
// }
// REP(t){
//     auto curr = m.begin();
//     ans = max(ans,(*curr).first);
//     m.insert({(*curr).first+(*curr).second,(*curr).second});
//     m.erase(curr);
// }
// cout << ans << endl;
vector<ll> v(n,-1);
for(int i=0;i<n;i++){
    cin >> v[i];
}
ll l,r;
l=0;
ll curr,ans;
r = *min_element(v.begin(),v.end())*t;
while(l<=r){
    curr=0;
    ll mid = l+(r-l)/2;
    for(auto x : v){
        curr += mid/x;
    }
    if(curr>=t){
        ans = mid;
        r = mid-1;
    }
    else{
        l = mid+1;
    }
}
cout << ans << endl;
}