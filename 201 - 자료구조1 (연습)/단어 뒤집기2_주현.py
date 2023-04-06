s = input() + ' '
stack = []

idx = 0
while len(s) > 1:
    if s[idx] != '<' and s[idx + 1] != '<' and s[idx + 1] != ' ':
        idx += 1
    elif s[idx] != '<' and (s[idx + 1] == '<' or s[idx + 1] == ' '):
        a = s[:idx + 1]
        if a[0] == ' ':
            a = a[1:]
            stack.append(' ' + a[::-1])
        else:
            stack.append(a[::-1])
        s = s[idx + 1:]
        idx = 0
    elif s[idx] == '<':
        tmp = idx
        idx = s.index('>') + 1
        stack.append(s[tmp:idx])
        s = s[idx:]
        idx = 0

print(''.join(stack))