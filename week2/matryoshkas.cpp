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
int n, temp;
int count, least;

REP(t){
    map<ll,int> s={};
    count=0;
    cin >> n;
    for(int k=0;k<n;k++){
        cin >> temp;
        if(s.find(temp)==s.end()){ s[temp]=1; }
        else{
            s[temp]++;
        }
    }
    while(!s.empty()){
        auto l=s.begin();
        auto r=next(l);
        least = l->second;
        while(r!=s.end()){
            if(r->first==prev(r)->first+1){ least=min(least,r->second); r++;}
            else{
                count+=least;
                while(l!=r){
                    l->second-=least;
                    if(!l->second){ l=s.erase(l);}
                    else{ l++; }
                }
                least=l->second;
                r++;
            }
        }
        count+=least;
        while(l!=r){
            l->second-=least;
            if(!l->second){ l=s.erase(l);}
            else{ l++; }
        }
    }
    cout << count << "\n";
}
}