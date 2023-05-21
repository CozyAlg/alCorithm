#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long N=0; int i=0;
    cin >> N;
    bitset<64> num;
    do{
        int r = abs(N)%(2);
        num.set(i++, r);
        N -= r;
        N /= -2;
    } while (N!=0);
    
    string ret = num.to_string();
    while(ret[0]!='1' && ret.length()>1){
        ret = ret.substr(1);
    }
    cout << ret << "\n";
    return 0;
}