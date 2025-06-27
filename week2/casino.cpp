#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int i=0; i<=p-1;i++)

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin >> t;
vector<multiset<ll>> v;
REP(t){
    v.clear();
    int n,m;
    ll temp,ans=0;
    cin >> n >> m;
    v.resize(m);
    for(int k=0;k<n;k++){
        for(int j=0;j<m;j++){
            cin >> temp;
            v[j].insert(temp);
        }
    }
    for(int j=0;j<m;j++){
        temp = n-1;
        for(auto it = v[j].rbegin();it!=v[j].rend();it++,temp-=2){
            ans+=(*it)*temp;
            // cout << (*it) <<"  "<<temp<<"  "<<ans << "\n";
        }
    }
    cout << ans << "\n";
}
}