import sys

class Student:
    def __init__(self, name, korean, english, math):
        self.name = name
        self.korean = int(korean)
        self.english = int(english)
        self.math = int(math)

if __name__ == '__main__':
    readline = sys.stdin.readline
    size = int(readline())
    arr = [Student(*readline().split()) for _ in range(size)]
    
    arr.sort(key=lambda x: (-x.korean, x.english, -x.math, x.name))
    for student in arr:
        print(student.name)
