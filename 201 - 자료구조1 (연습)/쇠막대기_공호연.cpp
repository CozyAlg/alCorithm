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

    for (char c : string) { //for�� 

        if (c == '(') { //������ȣ -> ������ �߰�
            s.push(1);
            prev = 0;
        }

        else if (c == ')') { //������ȣ �� ���
            if (prev) { //������ ������ȣ �� ��� 
                if (!s.empty()) { 
                    s.pop(); //����� �ϳ� ��
                    count++; //����� ���� �ϳ� �߰�
                }
            }
            else { //���� ��ȣ�� ������ȣ �� ���
                if (!s.empty()) {
                    s.pop(); //������ ��ȣ ����
                    count += s.size(); //���� ������ŭ �߰�
                }
            }
            prev = 1;
        }
    }

    cout << count;
    return 0;
}