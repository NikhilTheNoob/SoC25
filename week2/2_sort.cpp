#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t;
vector<ll> v;
int n, k, l,r,ans;
cin >> t;
REP(t){
    cin >> n;
    cin >> k;
    k = k+1;
    v.resize(n);
    l=0;r=1;ans=0;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    while(r<n){
        if(v[r-1]<2*v[r]){ 
            r++;
            if(r-l==k){ ans++; l++;}    
        }
        else{ l=r; r++; }
    }
    cout << ans << "\n";
}
}