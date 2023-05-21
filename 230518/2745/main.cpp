#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string N; int base, exp=0;
    cin >> N >> base;
    long num=0;
    while(N!=""){
        char lastDigit = N[N.length()-1];
        int d = lastDigit-'0' < 10? lastDigit-'0': lastDigit-'A'+10;
        num += d*pow(base, exp++);
        N = N.substr(0, N.length()-1);
    }
    cout << num << "\n";
    return 0;
}