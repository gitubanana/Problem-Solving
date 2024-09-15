#include <iostream>
#include <unordered_set>

const int MAX_SIZE = 1000;

int size;
int ips[MAX_SIZE];

int getMask(void)
{
    int mask = 0;
    for (int bit = 31; bit >= 0; --bit)
    {
        int i = 0;
        std::unordered_set<int> uset;

        mask |= (1 << bit);
        for (int i = 0; i < size; ++i)
        {
            const int &curIp = ips[i];

            uset.insert(curIp & mask);
            if (uset.size() > 1)
                return (mask ^ (1 << bit));
        }
    }

    return (-1);
}

void    printFourDot(int ip)
{
    static const int eigthBit = (1 << 8) - 1;

    for (int rightShift = 24; rightShift >= 0; rightShift -= 8)
    {
        printf("%d", (ip >> rightShift) & eigthBit);
        if (rightShift != 0)
            printf(".");
    }
    printf("\n");
}

int main(void)
{
    int a, b, c, d;

    scanf(" %d", &size);
    for (int i = 0; i < size; ++i)
    {
        int &curIp = ips[i];

        scanf(" %d.%d.%d.%d", &a, &b, &c, &d);
        curIp |= (a << 24);
        curIp |= (b << 16);
        curIp |= (c << 8);
        curIp |= d;
    }

    int mask = getMask();
    int networkID = ips[0] & mask;

    printFourDot(networkID);
    printFourDot(mask);
    return (0);
}
