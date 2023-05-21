#include <bits/stdc++.h>

using namespace std;

int gcd(int n1, int n2){
    return n2==0? n1: gcd(n2, n1%n2);
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, S, max_dS=-1, max_D=-1;
    cin >> N >> S;
    vector<int> A(N, 0);
    for (int i=0; i < N; i++){
        cin >> A[i];
        max_dS = max(max_dS, abs(A[i]-S));
        if (i>=1)   max_D = max_D!=-1? gcd(max_D, abs(A[i]-A[i-1])): abs(A[i]-A[i-1]);
    }
    cout << (max_D!=-1? gcd(max_D, max_dS): max_dS )<< "\n";
    return 0;
}