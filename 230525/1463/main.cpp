#include <bits/stdc++.h>
#define MAX 1000000


using namespace std;

int cache[MAX]={0,};

int getOpN(int n){
    int& ret = cache[n-1];
    if (ret != -1)  return ret;
    if (n==1)   return ret=0;
    ret = 1+getOpN(n-1);
    if (n%3==0) ret = min(ret, 1+getOpN(n/3));
    if (n%2==0) ret = min(ret, 1+getOpN(n/2));
    return ret;
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i=0; i < N; i++) cache[i]=-1;
    cout << getOpN(N) << "\n";
    return 0;
}