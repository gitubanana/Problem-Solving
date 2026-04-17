num = lambda: int(input())
print("happy" if num() + num() * 2 + num() * 3 >= 10 else "sad")