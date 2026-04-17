size, rank = map(int, input().split())
print(sum(sorted([int(input()) for _ in range(size)], reverse=True)[:rank]))
