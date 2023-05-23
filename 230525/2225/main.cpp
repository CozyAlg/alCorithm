#include <bits/stdc++.h>
#define MAX 200
#define DIV 1000000000

using namespace std;
int cache[MAX+1][MAX+1];

int getSplitN(int n, int k){
    int& ret = cache[n][k];
    if (ret != -1)  return ret;
    if (n==0 | k==1) return ret=1;
    ret = 0;
    for (int i=0; i <= n; i++){
        ret = (ret + getSplitN(n-i, k-1)%DIV)%DIV;
    }
    return ret;
}
int main(){
    int N, K;
    cin >> N >> K;
    for (int i=0; i < N+1; i++){
        for (int j=0; j < K+1; j++){
            cache[i][j]=-1;
        }
    }
    cout << getSplitN(N, K) << "\n";
    return 0;
}