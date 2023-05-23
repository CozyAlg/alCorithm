#include <bits/stdc++.h>
#define MAX 11


using namespace std;

int cache[MAX]={0, };
int getPartN(int n){
    int& ret = cache[n-1];
    if (ret!=-1)    return ret;
    if (n==1) return ret=1;
    if (n==2) return ret=2;
    if (n==3) return ret=4;
    ret = getPartN(n-1);
    if (n>2) ret += getPartN(n-2);
    if (n>3) ret += getPartN(n-3);
    return ret;
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T, n; 
    cin >> T;
    for (int i=0; i < T; i++){
        cin >> n;
        for (int j=0; j < n; j++) cache[j]=-1;
        cout << getPartN(n) << "\n";
    }
    return 0;
}