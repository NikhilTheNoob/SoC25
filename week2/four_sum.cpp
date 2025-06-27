#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int n;
ll x;
cin >> n >> x;
vector<pair<ll,int>> v(n,{-1,-1});
for(int i=0;i<n;i++){
    cin >> v[i].first;
    v[i].second=i+1;
}
sort(v.begin(),v.end());
int l1,r1,l2,r2;
l1=0;r1=n-1;
ll x2, last;
bool ans=false;
for(l1=0;l1<n;l1++){
    for(r1=n-1;r1>l1;r1--){
        x2 = x-v[l1].first-v[r1].first;
        l2=l1+1; r2=r1-1;
        while(l2<r2){
            last = v[l2].first+v[r2].first;
            if(last<x2){ l2++; continue;}
            else if(last>x2){ r2--; continue;}
            else if(last==x2){ cout << v[l1].second << " " << v[l2].second << " " << v[r2].second << " " << v[r1].second << "\n"; return 0;}
        }
    }
}
cout<<"IMPOSSIBLE\n";
}