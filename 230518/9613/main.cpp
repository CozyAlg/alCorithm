#include <bits/stdc++.h>

using namespace std;


long gcd(long n1, long n2){
    return n2==0? n1: gcd(n2, n1%n2);
}

long sumGCD(vector<long>& numVec){
    long ret=0;
    for (int i=0; i < numVec.size(); i++){
        for (int j=i+1; j < numVec.size(); j++){
            ret += gcd(numVec[i], numVec[j]);
        }
    }
    return ret;
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T, n;
    long tmp;
    cin >> T;
    for (int i=0; i < T; i++){
        cin >> n;
        vector<long> numbers;
        for (int j=0; j < n; j++){
            cin >> tmp;
            numbers.push_back(tmp);
        } 
        cout << sumGCD(numbers) << "\n";
    }
    return 0;
}