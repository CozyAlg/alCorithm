#include <bits/stdc++.h>
#define MAX 100
#define DIV 1000000000

using namespace std;
int cache[MAX][11]={{0,},};


int getSN(int n, int prev){
    if (n==0)   return 1;
    int& ret = cache[n-1][prev];
    if (ret!= -1)   return ret;

    ret = 0;
    if (prev==10){
        for (int i=1; i <= 9; i++){
            ret = (ret + getSN(n-1, i)%DIV)%DIV;
        }  
    }
    else{
        if (prev+1 <= 9) ret = (ret + getSN(n-1, prev+1)%DIV)%DIV;
        if (prev-1 >= 0) ret = (ret + getSN(n-1, prev-1)%DIV)%DIV;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin  >> N;
    for (int i=0; i < N; i++) 
        for (int j=0; j < 11; j++)
            cache[i][j]=-1;
    cout << getSN(N, 10) << "\n";
    return 0;
}