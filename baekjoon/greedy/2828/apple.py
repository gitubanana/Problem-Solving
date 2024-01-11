import sys

if __name__ == '__main__':
    def readline(): return sys.stdin.readline()

    map_size, bar_size = map(int, readline().split())
    apple_cnt = int(readline())

    move = 0
    cur_pos = 1
    bar_size -= 1
    for _ in range(apple_cnt):
        apple_pos = int(readline())
        if not (cur_pos <= apple_pos <= cur_pos + bar_size):
            if cur_pos > apple_pos:
                move += cur_pos - apple_pos
                cur_pos = apple_pos
            else:
                move += apple_pos - (cur_pos + bar_size)
                cur_pos = apple_pos - bar_size

    print(move)
