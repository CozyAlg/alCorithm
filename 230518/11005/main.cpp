#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    long N; int base, i=0;
    cin >> N >> base;
    int out[30] = {0,};
    do{
        out[29-i++]=N%base;
        N/=base;
    } while(N!=0);
    bool redundant=true;
    for (int i=0; i < 30 ; i++){
        if (redundant && out[i]==0) continue;
        else{
            redundant=false;
            cout << (char)((out[i] >= 10)? (char)('A'+out[i]-10): out[i]+'0');
        }
    }
    cout << "\n";
    return 0;
}