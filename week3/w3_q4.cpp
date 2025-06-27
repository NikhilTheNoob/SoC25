#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
string A,B;
cin >> A >> B;
int a,b;
a=A.size();
b=B.size();
vector<vector<ll>> v(a+1,vector<ll>(b+1,-1));
v[0][0]=0;
for(int i=1;i<=b;i++){
    v[0][i] = i;
}
for(int i=1;i<=a;i++){
    v[i][0] = i;
}
for(int i=1;i<=a;i++){
    for(int j=1;j<=b;j++){
        v[i][j]= min(1+v[i-1][j],1+v[i][j-1]);
        if(A[i-1]==B[j-1]){
            v[i][j]=min(v[i][j],v[i-1][j-1]);
        }
        else{
            v[i][j]=min(v[i][j],v[i-1][j-1]+1);
        }
    }
}
cout << v[a][b] << endl;
}