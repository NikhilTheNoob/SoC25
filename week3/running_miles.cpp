#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin >> t;
int n;
vector<ll> v,l,r;
REP(t){
    cin >> n;
    v.resize(n);
    r.assign(n, INT_MIN);
    l.assign(n, INT_MIN);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    l[0]=v[0];
    r[n-1]=v[n-1]-n+1;
    for(int i=1;i<n-1;i++){
        l[i]=max(l[i-1],v[i]+i);
        r[n-1-i]=max(r[n-i],v[n-1-i]-n+1+i);
    }
    l[n-1]=max(l[n-2],v[n-1]+n-1);
    r[0]=max(r[1],v[0]);
    ll ans=INT_MIN;
    for(int i=1;i<n-1;i++){
        // cout << v[i] << " "<< l[i] << " " << r[i]<<endl;
        ans = max(ans,v[i]+l[i-1]+r[i+1]);
    }
    cout << ans << "\n";
}
}