#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

inline int luckiness(int x) {
    int mn = 9, mx = 0;
    while (x > 0) {
        int d = x % 10;
        mn = min(mn, d);
        mx = max(mx, d);
        x /= 10;
    }
    return mx - mn;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
ll z, r, l, n;
int m=0, v;
cin >> z;
REP(z){
    cin >> l >> r;
    if(r==l){ cout << r << "\n"; continue;}
    if(r-l>=100){ 
        if(l%100>90){ cout << l/100+1 << 90 << "\n";}
        else{ 
            if(l/100!=0){ cout << l/100; }
            cout << 90 << "\n";} 
        continue; }
    m=0;
    n=l;
    for( ll i=l;i<=r;i++){
        v = luckiness(i);
        if(v>m){
            m=v;
            n=i;
        }
    }
    cout << n << "\n";
    continue;
    // if(r/10+l/10==0){ cout << l << "\n"; continue; }
    // else if(r/10==0){ r=10; }
    // if(l==10){ cout << "10\n"; continue; }
    // s = r%100; b=l%100;
    // if(b>s){ 
    //     if(b>=90 && s<=90){ 
    //         if(r/100!=0){ cout << r/100; }
    //         cout<< 90 << "\n"; continue;}
    //     for(int i=s;i<=b;i++){
    //         p = max(i/10,i%10);
    //         q = min(i/10,i%10);
    //         if(p-q>m){ m=p-q; n=i;}
    //     }
    //     if(r/100!=0){ cout << r/100; }
    //     cout << n << "\n";
    //     continue;
    // }
    // else if(b<=s){
    //     if(s<=90){ 
    //         if(r/100!=0){ cout << r/100; }
    //         cout<< 90 << "\n"; continue; }
    //     if(b>=9){ cout<< l/100 << "09" << "\n"; continue; }
    //     for(int i=s;i<=99;i++){
    //         p = max(i/10,i%10);
    //         q = min(i/10,i%10);
    //         if(p-q>m){ m=p-q; n=i;t=0; }
    //     }
    //     for(int i=0;i<=b;i++){
    //         p = max(i/10,i%10);
    //         q = min(i/10,i%10);
    //         if(p-q>m){ m=p-q; n=i;t=1; }
    //     }
    //     if(t==0){
    //         if(r/100!=0){ cout << r/100; }
    //         cout << n << "\n";
    //     }
    //     else {
    //         if(l/100!=0){ cout << r/100; }
    //         cout << n << "\n";
    //     }
    // }

}
}