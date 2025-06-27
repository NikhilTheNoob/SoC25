#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin >> t;
vector<int> p;
int n,temp,a1,b1,ans;
REP(t){
 cin >> n;
 a1=1;b1=1;
 ans=INT32_MAX;
 p.resize(n+1);
 for(int k=1;k<=n;k++){
    cin>>temp;
    p[temp]=k;
 }
 while(b1<=n){
    // cout << b1 << a1 << endl;
    if(b1==n){ break;}
    if(p[b1+1]>p[b1]){ b1++; }
    else{ 
        if(max(a1-1,n-b1)<ans){ ans = max(a1-1,n-b1);}
        a1=b1+1;
        b1++;
    }
 }
 if(max(a1-1,n-b1)<ans){ ans = max(a1-1,n-b1);}
 cout << ans << "\n";
}
}