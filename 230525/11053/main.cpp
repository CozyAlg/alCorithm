#include <bits/stdc++.h>
#define MAX 1000

using namespace std;
int A[MAX]={0,};
int cache[MAX]={-1,};

int lls(int idx, int N){
    int& ret = cache[idx];
    if (ret != -1)  return ret;
    ret = 1;
    for (int i=idx+1; i < N; i++){
        if (A[i] > A[idx]) ret = max(ret, 1+lls(i, N));
    }
    return ret;
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL); 
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i=0; i < N; i++){
        cin >> A[i];
        cache[i]=-1;
    }
    int ans=0;
    for (int i=0; i < N; i++){
        ans = max(ans, lls(i, N));
    }
    cout << ans << "\n";
    return 0;
}