n = int(input())
A = input()
# convert elements to int for arithmetic operations
lst = list(map(int, A.split()))

# initialization
stack = []
result = ['-1'] * n  # initialize result list with -1

for i in range(n):
    while stack and lst[stack[-1]] < lst[i]:  # compare with top elements in the stack
        result[stack.pop()] = str(lst[i])  # convert to string
    stack.append(i)  # add current element to stack

print(' '.join(result))  # works w/ strings
