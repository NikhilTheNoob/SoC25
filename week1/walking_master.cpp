#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
ll t,a,b,c,d;
ll d1,d2;
cin >> t;
REP(t){
    cin >> a >> b >> c >> d;
    if(b>d){ cout << -1 << "\n"; continue;}
    else {
        d1 = d-b;
        d2 = a+d1-c;
        if(d2<0){ cout << -1 << "\n"; continue;}
        else{cout << d1+d2 << "\n"; continue;}
    }
}
}