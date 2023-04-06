#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    stack<bool> s;
  
    string string;

    int count = 0;
    bool prev = 0;
    cin >> string;

    for (char c : string) { //for문 

        if (c == '(') { //열린괄호 -> 무조건 추가
            s.push(1);
            prev = 0;
        }

        else if (c == ')') { //닫힌괄호 일 경우
            if (prev) { //이전에 닫힌괄호 일 경우 
                if (!s.empty()) { 
                    s.pop(); //막대기 하나 뺌
                    count++; //막대기 개수 하나 추가
                }
            }
            else { //이전 괄호가 열린괄호 일 경우
                if (!s.empty()) {
                    s.pop(); //레이저 괄호 뺴고
                    count += s.size(); //숫자 개수만큼 추가
                }
            }
            prev = 1;
        }
    }

    cout << count;
    return 0;
}