#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int n,q;
int N=1;

void update(vector<int>& v, int k, int change){
    k+=N;
    v[k]+=change;
    for(k/=2;k>=1;k/=2){
        v[k]=min(v[2*k],v[2*k+1]);
    }
}

int retrieve(vector<int>& v, int a, int b){
    int r=INT_MAX;
    a+=N;
    b+=N;
    while(a<=b){
        if(a%2==1){ r=min(r,v[a++]);}
        if(b%2==0){ r=min(r,v[b--]);}
        a/=2; b/=2;
    }
    return r;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

cin >> n >> q;
while(N < n) N <<= 1;
vector<int> r(2*N,0);
vector<int> c(2*N,0);
int t,x,y,a,b;
REP(q){
    cin >> t;
    if(t==1){
        cin >> x >> y;
        update(r,x-1,1);
        update(c,y-1,1);
    }
    else if(t==2){
        cin >> x >> y;
        update(r,x-1,-1);
        update(c,y-1,-1);
    }
    else {
        cin >> x >> y >> a >> b;
        if(retrieve(r,x-1,a-1)){ cout << "Yes\n"; continue;}
        if(retrieve(c,y-1,b-1)){ cout << "Yes\n"; continue;}
        cout << "No\n";
    }
}
}