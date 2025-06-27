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
int n,s1,s2;
vector<int> a,b;
vector<pair<int,int>> balls;
REP(t){
    cin >> n >> s1 >> s2;
    a.clear();
    b.clear();
    balls.resize(n);
    for(int i=0;i<n;i++){
        cin >> balls[i].first;
        balls[i].second=i;
    }
    sort(balls.begin(),balls.end());
    int at=s1,bt=s2;
    for(int i=0;i<n;i++){
        if(at<bt){
            a.push_back(balls[i].second+1);
            at+=s1;
        }
        else{
            b.push_back(balls[i].second+1);
            bt+=s2;
        }
    }
    cout << a.size() << " ";
    for(auto h:a){
        cout << h <<" ";
    }
    cout <<"\n";
    cout << b.size() << " ";
    for(auto h:b){
        cout << h <<" ";
    }
} 
}