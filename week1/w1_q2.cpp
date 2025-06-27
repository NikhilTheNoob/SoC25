#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p,k) for(int k=0; k<=p-1;k++)

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
string s;
cin >> s;
char temp=s[0];
ll curr=1;
ll max=0;
FOR(i,1,s.length()-1){
    if(s[i]==temp){
        curr++;
        continue;
    }
    temp = s[i];
    max = curr > max ? curr : max;
    curr = 1;
}
max = curr > max ? curr : max;
cout << max;
}