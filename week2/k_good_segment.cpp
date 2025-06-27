#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)
#define M 1e6

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
vector<int> v;
int k,n,temp;
scanf("%d",&n);
scanf("%d",&k);
v.resize(n+1);
unordered_map<int,int> s = {};
// vector<int> s(M,0);
// int tracker=0;
int l=1;
int r=1;
int a=1;
int b=1;
for(int i=1;i<=n;i++){
    scanf("%d",&v[i]);
}
while(r<=n){
    if(s.size()<k){
        s[v[r]]++;
        r++;
    }
    else if(s.size()==k){
        if(s.find(v[r])!=s.end()){
            s[v[r]]++;
            r++;
        }
        else{
            if(r-l>b-a){ b=r; a=l; }
            while(1){
                if(s[v[l]]==1){ s.erase(v[l]); l++; break;}
                else{ s[v[l]]--; l++; }
            }
            s[v[r]]++;
            r++;
        }
    }
}
if(r-l>b-a){ b=r; a=l; }
printf("%d %d",a,b-1);
}