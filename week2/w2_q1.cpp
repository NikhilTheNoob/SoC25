#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
ll k;
cin >> k;
set<int> s;
int arr[k];
for(int i=0;i<k;i++){
    cin >> arr[i];
}
ll l=0,r=0, max=0;
s.insert(arr[0]);
while(r<k-1){
    if(s.find(arr[r+1])==s.end()){
        s.insert(arr[r+1]);
        r++;
    }
    else{
        if(r-l+1>max){ max = r-l+1; }
        while(arr[l]!=arr[r+1]){
            s.erase(arr[l]);
            l++;
        }
        l++; r++;
    }
}
if(r-l+1>max){ max = r-l+1; }
cout << max;
}