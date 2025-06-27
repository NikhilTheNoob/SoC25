// #include<bits/stdc++.h>
// #include<algorithm>
// using namespace std;
// typedef long long ll;

// #define FOR(i,a,b) for(int i=a; i<=b; i++)
// #define REP(p) for(int j=0; j<=p-1;j++)

// int main() {
// ios::sync_with_stdio(0);
// cin.tie(0);
// int n;
// cin >> n;
// vector<pair<pair<ll,ll>,int>> v(n);
// vector<ll> rewards(n);
// for(int i=0;i<n;i++){
//     cin >> v[i].first.second >> v[i].first.first >> rewards[i];
//     v[i].second = i;
// }
// sort(v.begin(),v.end());
// vector<int> exclude(n,-1);
// int idx;
// for(int i=1;i<n;i++){
//     auto it = (upper_bound(v.begin(),v.end(),make_pair(make_pair(v[i].first.second,(ll)-1),-1)));
//     idx = distance(v.begin(),it);
//     exclude[i]=idx-1;
// }
// vector<ll> dp(n,0);
// dp[0]=rewards[v[0].second];
// for(int i=1;i<n;i++){
//     dp[i]=dp[i-1];
//     if(exclude[i]!=-1){
//         dp[i]=max(dp[i],dp[exclude[i]]+rewards[v[i].second]);
//     }
//     else{
//         dp[i]=max(dp[i],rewards[v[i].second]);
//     }
// }
// cout << dp[n-1] << "\n";
// }
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    struct Proj{ ll s,e,p; };
    vector<Proj> A(n);
    for(int i=0;i<n;i++){
        cin >> A[i].s >> A[i].e >> A[i].p;
    }
    // 1) sort by end‐time
    sort(A.begin(), A.end(), [](auto &L, auto &R){
        return L.e < R.e;
    });

    // 2) dp_map: key = end_time, value = best profit up to that time
    map<ll,ll> dp;        
    dp[0] = 0;            // before day 0, profit = 0

    ll answer = 0;
    for(auto &pr : A){
        // find best profit up to start pr.s
        auto it = prev(dp.upper_bound(pr.s-1));
        ll bestBefore = it->second;

        // if we take this project:
        ll cand = bestBefore + pr.p;
        answer = max(answer, cand);

        // insert/update dp at time = pr.e
        auto ins = dp.emplace(pr.e, cand);
        if(!ins.second){
            // already had an entry at pr.e, keep the max
            ins.first->second = max(ins.first->second, cand);
        }
        auto before = prev(ins.first);
        ins.first->second = max(ins.first->second, before->second);
        
    }

    cout << answer << "\n";
    return 0;
}
