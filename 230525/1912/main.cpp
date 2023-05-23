#include <bits/stdc++.h>
#define MAX 100000

using namespace std;
int cache[MAX], A[MAX];

int maxSum(int idx, int N){
    int& ret = cache[idx];
    if (ret != -1)  return ret;
    if (idx == N-1) return ret=A[idx];
    ret = max(A[idx], A[idx]+maxSum(idx+1, N));
    return ret;
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL); 
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i=0; i < N; i++){
        cin >> A[i]; cache[i]=-1;
    }
    int ans = maxSum(0, N);
    for (int i=1; i < N; i++){
        ans = max(ans, cache[i]);
    }
    cout << ans << "\n";
    return 0;
}