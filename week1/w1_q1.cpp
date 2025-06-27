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
vector<ll> v(n,1);
ll temp;
REP(n-1){
    cin >> temp;
    v[temp-1] = 0;
}
auto it = find(v.begin(),v.end(),1);
cout << distance(v.begin(), it)+1;
}