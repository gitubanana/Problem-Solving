days = int(input())
math = int(input())
kor = int(input())
a = int(input())
b = int(input())

while math > 0 or kor > 0:
    math -= a
    kor -= b
    days -= 1
print(days if days > 0 else 0)