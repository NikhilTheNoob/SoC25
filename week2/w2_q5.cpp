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
vector<ll> arr(t);
REP(t){
    cin >> arr[j];
}
sort(arr.begin(),arr.end());
ll m, c=0;
m = arr[t/2];
for(int i=0;i<t;i++){
    c += abs(arr[i]-m);
}
cout << c;
}