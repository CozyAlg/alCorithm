#include <bits/stdc++.h>

using namespace std;

int gcd(int n1, int n2){
    return n2==0? n1: gcd(n2, n1%n2);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    bool notPrime[1000001] = {true, true,};
    for (int i=2; i*i <= 1000000; i++){
        if (!notPrime[i]){
            for (int j=2*i; j <= 1000000; j+=i){
                notPrime[j]=true;
            }
        }
    }
    int  T, N;
    cin >> T;
    for (int i=0; i < T; i++){
        cin >> N;
        int rs=3, cnt=0;
        while ((N-rs)>= (int)(N/2)){
            if(!notPrime[rs] && !notPrime[N-rs]) cnt++;
            rs+=2;
        }
        if (N==4) cnt=1;
        cout << cnt << "\n";
    }
    return 0;
}