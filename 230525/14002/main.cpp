#include <bits/stdc++.h>
#define MAX 1000

using namespace std;
int A[MAX]={0,};
pair<int, vector<int> > cache[MAX]={};

pair<int, vector<int> > lls(int idx, int N){
    pair<int, vector<int> >& ret = cache[idx];
    if (ret.first != -1)  return ret;
    ret = make_pair(1, vector<int>(1, A[idx]));
    for (int i=idx+1; i < N; i++){
        if (A[i] > A[idx]){
            pair<int, vector<int> > mid = lls(i, N);
            vector<int> tmp(mid.second.size()+1, 0);
            tmp[0]=A[idx];
            for(int i=0; i < mid.second.size(); i++) tmp[i+1]=mid.second[i];
            mid.first+=1;
            mid.second = tmp;

            ret = ret.first > mid.first? ret: mid;
        }
    }
    return ret;
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL); 
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i=0; i < N; i++){
        cin >> A[i];
        cache[i].first=-1;
    }
    pair<int, vector<int> > ans;
    for (int i=0; i < N; i++){
        pair<int, vector<int> > tmp = lls(i, N);
        ans = ans.first > tmp.first? ans: tmp;
    }
    cout << ans.first << "\n";
    for (int i=0; i < ans.second.size(); i++) cout << ans.second[i] << " ";
    return 0;
}