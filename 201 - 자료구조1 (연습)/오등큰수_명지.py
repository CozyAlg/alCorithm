from collections import Counter #Count를 이용해서 개수 딕셔너리를 만들기 위해
import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split())) #리스트의 모든 요소를 int를 사용해서 변환
count = Counter(arr)
result = [-1] * N #모든 원소 -1로 세팅(N번 만큼)
stack = []

#스택에서 원소를 제거하지 않고 가져오기만 할 때에는 [-1]을 이용하여 찾을 수 있다.
for i in range(N): #현재 인덱스(stack [-1])의 값보다 i의 값이 더 작으면 전부 pop
    #Counter class -> dictionary 확장해서 사전에서 제공하는 API그대로 사용 가능
    while stack and count[arr[stack[-1]]] < count[arr[i]]: 
        result[stack.pop()] = arr[i]
    stack.append(i)

print(*result) #unpacking list
