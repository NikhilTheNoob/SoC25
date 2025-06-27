#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

// int main() {
// ios::sync_with_stdio(0);
// cin.tie(0);
// int n,k;
// cin >> n >> k;
// multiset<pair<ll,int>> m;
// ll temp;
// vector<pair<ll,int>> v(n,{-1,-1});
// for(int i=0;i<n;i++){
//     cin >> v[i].first;
//     v[i].second = i;
// }
// if(k==1){
//     for(auto x : v){
//         cout << x.first << " ";
//     }
//     return 0;
// }
// for(int i=0;i<k;i++){
//     m.insert(v[i]);
// }
// auto median = m.begin();
// for(int i=0;i<(k-1)/2;i++){
//     median++;
// }
// cout << (*median).first << " ";
// auto one_before = prev(median);
// for(int i=0;i<n-k;i++){
//     m.erase(median);
//     m.insert(v[k+i]);
//     if(v[i]==*median){
//         if(v[k+i]<*one_before){ median = one_before; one_before=prev(median);}
//         else { median = next(one_before);}
//     }
//     else{
//         if(v[i]<*(median) && v[k+i]>*(median)){ median = next(median); one_before=prev(median);}
//         else if(v[i]>*(median) && v[k+i]<*(median)){ median = prev(median); one_before=prev(median);}
//     }
//     cout << (*median).first << " ";
// }
// }
multiset<ll> lower;
multiset<ll,greater<ll>> upper;
int n,k;
ll temp;
ll lower_sum=0;
ll upper_sum=0;

void rebalance(){
    while(upper.size()>lower.size()){
        temp = *prev(upper.end());
        upper.erase(prev(upper.end()));
        upper_sum-=temp;
        lower.insert(temp);
        lower_sum+=temp;
    }
    while(lower.size()>upper.size()+1){
        temp = *prev(lower.end());
        lower.erase(prev(lower.end()));
        lower_sum-=temp;
        upper.insert(temp);
        upper_sum+=temp;
    }
}

// inline ll abs(ll x){
//     if(x>0){
//         return x;
//     }
//     else{ return -1*x; }
// }
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
cin >> n >> k;
vector<ll> v(n,-1);
for(int i=0;i<n;i++){
    cin >> v[i];
}
for(int i=0;i<k;i++){
    lower.insert(v[i]);
    lower_sum+=v[i];
}
rebalance();
ll median = *prev(lower.end());
cout << upper_sum+(lower.size()-upper.size())*median-lower_sum << " ";
for(int i=0;i<n-k;i++){
    if(lower.empty() || v[k+i]<=*prev(lower.end())){
        lower.insert(v[k+i]);
        lower_sum +=v[k+i];
    }
    else{
        upper.insert(v[k+i]);
        upper_sum +=v[k+i];
    }
    if(upper.find(v[i])!=upper.end()){
        upper.erase(upper.lower_bound(v[i]));
        upper_sum -=v[i];
    }
    else{
        lower.erase(lower.lower_bound(v[i]));
        lower_sum -=v[i];
    }
    rebalance();
    median = *prev(lower.end());
    cout << upper_sum+(lower.size()-upper.size())*median-lower_sum << " ";
}
}