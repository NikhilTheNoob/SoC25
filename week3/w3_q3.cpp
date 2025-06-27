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
vector<ll> ans(n+1,0);
ans[0]=1;
ll M = 1e9+7;
for(int i=1;i<=n;i++){
    // cout << i << "  " << ans[i] << endl;
    for(int j=1;j<7;j++){
        if(i-j>=0){
            // cout << j << "  " << ans[i-j] << endl;
            ans[i] = (ans[i]+ans[i-j])%M;
            // cout << i << "  " << ans[i] << endl;
        }
    }
    // cout << i << "  " << ans[i] << endl;
}
cout << ans[n]<< endl;
}