#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int A, B, m;
    cin >> A >> B >> m;
    uint64_t n=0;
    for (int i=m-1; i >=0 ; i--){
        int tmp=0;
        cin >> tmp;
        n += tmp*(long)pow(A, i);
    }
    int out[20] = {0,}, i=0;
    do{
        out[19-i++]=n%B;
        n/=B;
    } while(n!=0);
    bool redundant=true;
    for (int i=0; i < 20 ; i++){
        if (redundant && out[i]==0) continue;
        else{
            redundant=false;
            cout << out[i] << " ";
        }
    }
    cout << "\n";
    return 0;
}