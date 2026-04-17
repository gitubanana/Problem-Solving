class Square:
    def __init__(self, w, h):
        self.w = w
        self.h = h

    def isSuitable(self, cover):
        return self.w >= cover.w \
                and self.h >= cover.h

    def __str__(self):
        return f'{self.w} {self.h}'

arr = list(map(int, input().split()))
laptop = Square(arr[0], arr[1])
sticker = Square(arr[2]+2, arr[3]+2)

# print(laptop, sticker)
print(1 if laptop.isSuitable(sticker) else 0)
