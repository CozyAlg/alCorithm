s = input() + ' '
stick = 0
cut = 0

for i in range(len(s)):
    if s[i] == '(' and s[i + 1] != ')':
        stick += 1
        cut += 1
    elif s[i] == '(' and s[i + 1] == ')':
        cut += stick
    elif s[i] == ')' and s[i - 1] != '(':
        stick -= 1

print(cut)