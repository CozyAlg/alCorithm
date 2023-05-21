#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, base=2;
    cin >> N;
    while(N!=0){
        if (N%base==0){
            N/=base;
            cout << base << "\n";
        }
        else{
            if (N==1) break;
            base++;
        }
    }

    return 0;
}