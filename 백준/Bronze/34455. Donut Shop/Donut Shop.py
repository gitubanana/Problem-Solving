import sys

line = lambda: sys.stdin.readline().strip()
expression = line()
for _ in range(int(line())):
    expression += line()
    expression += line()

print(eval(expression))
