input_str = input()

in_tag = False
tag_chars = ""
output = ""
current_word = ""

# '<' bracket 또는 space 만나는 두 경우로 처리 --> current_word 를 reverse order로 output에 대입
for c in input_str:
    if c == "<":
        in_tag = True
        output += current_word[::-1] #sequence[start:stop:step]
        current_word = "" 
        output += "<"
    elif c == ">":
        in_tag = False
        output += tag_chars + ">"
        tag_chars = ""
    elif in_tag:
        tag_chars += c #tag_char variable에 c (characters) 대입 w/o reversing
    else: # <> tag 밖에 str을 읽었을 때
        if c == " ":
            output += current_word[::-1]
            current_word = ""
            output += " "
        else:
            current_word += c

output += current_word[::-1]

print(output)

