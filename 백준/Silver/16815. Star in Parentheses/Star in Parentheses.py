depth = 0
for ch in input():
    if ch == '(':
        depth += 1
    elif ch == ')':
        depth -= 1
    else:
        print(depth)
        break
