#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
ll t, n, k;
cin >> t;
REP(t){
    cin >> n >> k;
    if(n%2==0){ cout << "YES\n"; continue;}
    if(k==1){ cout << "YES\n"; continue;}
    if(k%2==0){ cout << "no\n"; continue;}
    if(n>=k){ cout << "yes\n"; continue;}
    else { cout << "no\n"; continue;}
}
}