#include <bits/stdc++.h>
#define MAX 100000
#define DIV 1000000009

using namespace std;

int cache[4][MAX]={{0,},};
int getPartN(int n, int prev){
    int& ret = cache[prev][n-1];
    if (ret != -1) return ret;

    ret=0;
    for (int i=1; i <=3; i++){
        if (i == prev) continue;
        if (n > i) ret = (ret%DIV + getPartN(n-i, i)%DIV)%DIV;
        else if (n == i) ret = (ret%DIV + 1)%DIV;
    }
    return ret%DIV;
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T, n; 
    cin >> T;
    for (int j=0; j < MAX; j++)
        for (int k=0; k < 4; k++)
            cache[k][j]=-1;
    
    for (int i=0; i < T; i++){
        cin >> n;
        cout << getPartN(n, 0)%DIV << "\n";
    }
    return 0;
}