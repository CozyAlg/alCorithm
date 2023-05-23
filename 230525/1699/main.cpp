#include <bits/stdc++.h>
#define MAX 100000

using namespace std;
int cache[MAX];


int getMinSq(int n){
    int& ret = cache[n-1];
    if (ret!=-1)    return ret;
    ret = n;
    for (int i=1; i*i <= n; i++){
        ret = min(ret, 1+getMinSq(n-i*i));
    }
    return ret;
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL); 
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i=0; i < N; i++) cache[i]=-1;
    cout << getMinSq(N) << "\n";
    return 0;
}