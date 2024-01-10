import sys

if __name__ == '__main__':
    def readline(): return sys.stdin.readline()
    def splitIntoInt(): return map(int, readline().split())

    price = tuple(splitIntoInt())
    entry = [0 for _ in range(101)]
    exit = [0 for _ in range(101)]
    for _ in range(3):
        start, end = splitIntoInt()
        entry[start] += 1
        exit[end] -= 1

    start_time = 1
    while entry[start_time] == 0:
        start_time += 1

    sum_ = 0
    total_truck = entry[start_time]
    time = start_time
    while time < 100:
        sum_ += price[total_truck - 1] * total_truck
        time += 1
        total_truck += entry[time] + exit[time]

    print(sum_)
