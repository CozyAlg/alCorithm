#include <iostream>
#include <stack>
#include<vector>

using namespace std;

int A[1000001]; //수열 크기를 제한 
int B[1000001];

int main() {
	                     
	int N; //N을 입력 받음
	
	stack <int> stack;
	
	
	
	cin >> N;
	/*if (N < 1 || N > 1000000)
	{
		return 0;
	}*/
	//처음에는 중첩문을 사용하여 같은 값이 있을 때 F[i] 값을 하나씩 더하는 방법으로 진행
	//for (int i = 0; i < N; i++) { //같은 숫자 개수 세서 F배열에 저장
	//	for (int j = 0; j < N; j++)
	//	{
	//		if (A[i] == A[j])
	//		{
	//			F[i]++;
	//		}
	//		
	//	}
	//}--> 시간복잡도가 매우 증가 --> 좋은 코드가 아님.
	// 따라서 사용한게 벡터
	//vector 컨테이너는 자동으로 메모리가 할당되는 배열임.


	vector <int> F(1000001, 0); // 벡터의 초기화

	for (int i = 0; i < N; i++)
	{

		cin >> A[i];
		F[A[i]]++; //입력받은 값을 인덱스로 정한뒤 그 값을 더하는 방식. 
		
	}
	



	for (int i = N - 1; i >= 0; i--) 
	{
		while (!stack.empty()  && F[A[stack.top()]] <= F[A[i]])
			stack.pop();
			

		if (stack.empty()) B[i] = -1;
		else B[i] = A[stack.top()];

		stack.push(i);
	
	}

	// 정답 출력


	for (int i = 0; i < N; i++)
		cout << B[i] << " ";


	

	return 0;
}
