#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string octal;
    cin >> octal;
    for (int i=0; i < octal.length(); i++){
        string binary = bitset<3> (octal[i]-'0').to_string();
        if (i==0){
            while (binary.length()>1){
                if (binary[0]=='1')   break;
                binary = binary.substr(1);
            }
        }
        cout << binary;
    }
    cout << "\n";
    return 0;
}