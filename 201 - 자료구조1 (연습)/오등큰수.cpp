#include <iostream>
#include <stack>
#include<vector>

using namespace std;

int A[1000001]; //���� ũ�⸦ ���� 
int B[1000001];

int main() {
	                     
	int N; //N�� �Է� ����
	
	stack <int> stack;
	
	
	
	cin >> N;
	/*if (N < 1 || N > 1000000)
	{
		return 0;
	}*/
	//ó������ ��ø���� ����Ͽ� ���� ���� ���� �� F[i] ���� �ϳ��� ���ϴ� ������� ����
	//for (int i = 0; i < N; i++) { //���� ���� ���� ���� F�迭�� ����
	//	for (int j = 0; j < N; j++)
	//	{
	//		if (A[i] == A[j])
	//		{
	//			F[i]++;
	//		}
	//		
	//	}
	//}--> �ð����⵵�� �ſ� ���� --> ���� �ڵ尡 �ƴ�.
	// ���� ����Ѱ� ����
	//vector �����̳ʴ� �ڵ����� �޸𸮰� �Ҵ�Ǵ� �迭��.


	vector <int> F(1000001, 0); // ������ �ʱ�ȭ

	for (int i = 0; i < N; i++)
	{

		cin >> A[i];
		F[A[i]]++; //�Է¹��� ���� �ε����� ���ѵ� �� ���� ���ϴ� ���. 
		
	}
	



	for (int i = N - 1; i >= 0; i--) 
	{
		while (!stack.empty()  && F[A[stack.top()]] <= F[A[i]])
			stack.pop();
			

		if (stack.empty()) B[i] = -1;
		else B[i] = A[stack.top()];

		stack.push(i);
	
	}

	// ���� ���


	for (int i = 0; i < N; i++)
		cout << B[i] << " ";


	

	return 0;
}