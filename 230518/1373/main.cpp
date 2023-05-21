#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string binary;
    cin >> binary;
    while(binary.length()%3!=0) binary = "0"+binary;
    int exp=2, odigit=0;
    for (int i=0; i < binary.length(); i++){
        int bdigit = binary[i]-'0';
        if (exp==-1){
            cout << odigit;
            odigit=0;
            exp=2;
        }
        odigit += pow(2, exp--)*bdigit;
    }
    cout << odigit<< "\n";
    return 0;
}