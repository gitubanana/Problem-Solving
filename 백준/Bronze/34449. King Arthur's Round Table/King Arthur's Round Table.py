num = lambda: float(input())
PI = 3.14159

diameter = num()
space = num()
people = num()

print('YES' if diameter * PI / space >= people else 'NO')
