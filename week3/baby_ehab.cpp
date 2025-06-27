#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin >> n;
vector<int> v(n);
int total=0;
pair<int,int> odd={0,-1};
for(int i=0;i<n;i++){
    cin >> v[i];
    total+= v[i];
    if(v[i]%2==1){ odd={1,i+1};}
}
if(total%2==1){
    cout << 0 <<"\n"; return 0;
}
vector<vector<int>> dp(n,vector<int>(total/2+1,0)); 
for(int i=0;i<n;i++){
    dp[i][0]=1;
}
for(int i=1;i<=total/2;i++){
    if(i==v[0]){ dp[0][i]=1; }
}
for(int i=1;i<n;i++){
    for(int j=1;j<=total/2;j++){
        dp[i][j]|=dp[i-1][j];
        if(j-v[i]>=0){
            dp[i][j]|=dp[i-1][j-v[i]];
        }
    }
}
if(dp[n-1][total/2]==0){ cout << 0 << "\n"; return 0;}
if(odd.first){
    cout << odd.first << "\n" << odd.second << "\n"; return 0;
}
for(int i=2;i<2048;i*=2){
    total/=2;
    if(total%2==1){
    cout << 0 <<"\n"; return 0;
    }
    odd={0,-1};
    for(int j=0;j<n;j++){
        v[j]/=2;
        if(v[j]%2==1){ odd={1,j+1};}
    }
    if(odd.first){
    cout << odd.first << "\n" << odd.second << "\n"; return 0;
    }
}
}