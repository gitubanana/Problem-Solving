#include <stdio.h>

struct IPv4 {
    unsigned int ipv4;

    IPv4(void) : ipv4(0) {
        unsigned int o1, o2, o3, o4; // octets
        
        scanf(" %u.%u.%u.%u", &o1, &o2, &o3, &o4);
        ipv4 |= o1;
        
        ipv4 <<= 8;
        ipv4 |= o2;
        
        ipv4 <<= 8;
        ipv4 |= o3;

        ipv4 <<= 8;
        ipv4 |= o4;
    }

    inline unsigned int networkID(int cidr) const {
        return ipv4 >> (32 - cidr);
    }
};

int calculateCIDR(IPv4 *arr, int size) {
    for (int cidr = 32; cidr >= 1; cidr--) {
        int i = 1;
        unsigned int cmp = arr[0].networkID(cidr);

        for (; i < size; i++) {
            if (cmp != arr[i].networkID(cidr)) {
                break;
            }
        }

        if (i == size) {
            return cidr;
        }
    }
    return 32;
}

int main(void) {
    int size;
    scanf(" %d", &size);

    IPv4 *arr = new IPv4[size];

    printf("%d\n", calculateCIDR(arr, size));
    delete[] arr;
    return 0;
}
