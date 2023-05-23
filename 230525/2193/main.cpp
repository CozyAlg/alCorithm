#include <bits/stdc++.h>
#define MAX 90

using namespace std;

long cache[MAX][3]={{0,},};

long getPN(int n, int prev){
    if (n==0) return 1;
    long& ret = cache[n-1][prev];
    if (ret!=-1)    return ret;
    ret = 0;
    if (prev==2){
        ret += getPN(n-1, 1);
    }else if(prev==1){
        ret += getPN(n-1, 0);
    }else{
        ret += (getPN(n-1, 0) + getPN(n-1, 1));
    }
    return ret; 
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL); 
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i=0; i < N; i++) 
        for (int j=0; j < 3; j++)
            cache[i][j]=-1;
    cout << getPN(N, 2) << "\n";
    return 0;
}