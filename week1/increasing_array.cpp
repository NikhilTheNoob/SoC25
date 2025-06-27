#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
ll n;
cin >> n;
ll ans = 0, curr, temp;
cin >> curr;
REP(n-1){
    cin >> temp;
    if(temp<curr) ans+= curr-temp;
    else if(temp == curr) continue;
    else curr = temp;
}
cout << ans;
}