#include <bits/stdc++.h>
#define MAX 1000


using namespace std;

int cache[MAX]={0,};
int P[MAX]={0,};

int maxPayDP(int n){
    int& ret = cache[n-1];
    if (ret != -1)  return ret;
    if (n==1)   return ret=P[0];
    ret = P[n-1];
    for (int i=0; i < n-1; i++){
        ret = max(ret, P[i]+maxPayDP(n-i-1));
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
        cin >> P[i]; cache[i]=-1;
    }
    cout << maxPayDP(N) << "\n";
    return 0;
}