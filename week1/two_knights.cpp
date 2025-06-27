#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(p) for(int j=0; j<=p-1;j++)

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
ll k;
cin >>k;
if(k==1){ cout << 0 ; return 0; }
if(k==2){ cout << 0 <<"\n"<<6 ; return 0; }
ll arr[k+1];
arr[1]=0;
arr[2]=6;
arr[3]=28;
cout << 0 <<"\n"<<6<<"\n"<<28<<"\n";
FOR(i,4,k){
    arr[i] = (2*arr[i-1]-arr[i-2]+1+((i*i-4)*2)+((i-2)*2+1)*((i-2)*2+1)-4);
    cout << arr[i]<<"\n";
}
}

// SOLUTION

// #include <iostream>
// using namespace std;

// // Function to calculate and print the number of ways two
// // knights can be placed on a K X K chessboard such that
// // they do not attack each other
// long calculateWays(int K) {
//     // Total number of ways two knights can be placed on
//     // the chessboard
//     long totalWays = ((long) K * K * (K * K - 1)) / 2;

//     // Number of ways two knights can attack each other
//     long attackingWays = 4 * (K - 1) * (K - 2);

//     // Number of ways two knights can be placed without
//     // attacking each other
//     long ans = totalWays - attackingWays;

//     // Return the result for the current chessboard size K
//     return ans;
// }

// // Driver Code
// int main() {
//     // Input the value of N (size of the chessboard)
//     int N = 8;

//     // Iterate for all the K sized chessboard
//     for (int K = 1; K <= N; K++) {
//         cout << calculateWays(K) << " ";
//     }

//     return 0;
// }