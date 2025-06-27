#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin >> t;
int n;
string s;
vector<int> v(26,0);
vector<int> num(26,0);
int m, total;
bool bul=false;
REP(t){
    cin >> n >> s;
    if(n%2!=0){ cout << "-1\n"; continue; }
    v.assign(26,0);
    num.assign(26,0);
    bul=0;
    total=0;
    for(int i=0;i<n/2;i++){
        v[s[i]-'a']++;
        v[s[n-1-i]-'a']++;
        if(s[i]==s[n-1-i]){ num[s[i]-'a']++; total++; }
    }
    for( auto x:v ){
        if(x>n/2){ bul=1; break; }
    }
    if(bul){ cout << "-1\n"; continue; }
    m = *max_element(num.begin(),num.end());
    if(m<=total/2){ cout << (total+1)/2 << "\n"; }
    else{ cout << m << "\n";}
}
}