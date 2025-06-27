#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

// bool operator<(pair<int,int> p, pair<int,int> q){
//     return (p.first < q.first);
// }

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t;
ll x;
cin >> t >> x;
vector<pair<int,int>> v(t);
for(int i=0;i<t;i++){
    v[i].second = i;
    cin >> v[i].first;
}
sort(v.begin(),v.end());
int l=0; int r=t-1;
while(l<r){
    if(v[l].first+v[r].first<x){
        l++;
    }
    else if(v[l].first+v[r].first>x){
        r--;
    }
    else{
        cout << v[l].second+1 << " " << v[r].second+1;
        return 0;
    }
}
cout << "IMPOSSIBLE";
return 0;
}