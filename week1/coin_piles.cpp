#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
ll t,a,b,c,d;
cin >> t;
REP(t){
    cin >> a >> b;
    c = max(a,b);
    d = min(a,b);
    if(c>2*d){ 
        cout << "NO\n";
        continue;
    } 
    if((2*d-c)%3==0){ cout << "YES\n"; }
    else { cout << "NO\n"; }
}
}