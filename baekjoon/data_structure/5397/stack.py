import sys
from collections import deque


class Logger:
    def __init__(self, input_):
        self.left = deque()
        self.right = deque()

        speciallist = '<>-'
        funclist = [Logger.move_left, Logger.move_right, Logger.remove]
        for ch in input_:
            i = speciallist.find(ch)
            if i == -1:
                self.left.append(ch)
            else:
                funclist[i](self)

    def move_left(self):
        if self.left:
            self.right.appendleft(self.left[-1])
            self.left.pop()

    def move_right(self):
        if self.right:
            self.left.append(self.right[0])
            self.right.popleft()

    def remove(self):
        if self.left:
            self.left.pop()

    def output(self):
        return ''.join(self.left) + ''.join(self.right)


if __name__ == '__main__':
    def readline(): return sys.stdin.readline()

    test_cnt = int(readline())
    while test_cnt:
        vscode = Logger(readline().strip())
        print(vscode.output())
        test_cnt -= 1
