#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

ll tower_of_hanoi(ll n, vector<pair<int,int>>& v){
    ll m;
    int a,b,c,d;
    if(n==1){
        v.push_back(make_pair(1,3));
        return 1;
    }
    m = tower_of_hanoi(n-1,v);
    ll s = v.size();
    v.push_back(make_pair(1,3));
    for(int i=0;i<s;i++){
        a = v[i].first;
        b = v[i].second;
        c = a;
        d = b;
        if(a==2 || a==3){
            a = 5-a;
        }
        if(b==2 || b==3){
            b = 5-b;
        }
        if(c==2 || c==1){
            c = 3-c;
        }
        if(d==2 || d==1){
            d = 3-d;
        }
        v[i] = make_pair(a,b);
        v.push_back(make_pair(c,d));
    }
    return (2*m+1);
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
ll n;
cin >> n;
vector<pair<int,int>> v;
cout << tower_of_hanoi(n,v) << endl;
for(auto x : v){
    cout << x.first << " " << x.second << endl;
}
}