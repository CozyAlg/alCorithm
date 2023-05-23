#include <bits/stdc++.h>
#define MAX 1000
#define DIV 10007

using namespace std;

int cache[MAX]={0, };
int tileDP(int N){
    int& ret = cache[N-1];
    if (ret!=-1)    return ret;
    if (N==2)   return ret=3;
    if (N==1)   return ret=1;
    ret = (tileDP(N-1)%DIV + 2*tileDP(N-2)%DIV)%DIV;
    return ret;
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; 
    cin >> n;
    for (int i=0; i < n; i++) cache[i]=-1;
    cout << tileDP(n) << "\n";
    return 0;
}