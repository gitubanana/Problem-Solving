#include <iostream>

struct Wifi {
    int y, x;
    int energy;

    inline int speedTo(Wifi &other) const {
        return std::max(
            0,
            this->energy - (std::abs(this->y - other.y) + std::abs(this->x - other.x))
        );
    }

    inline bool isOff(void) const {
        return this->energy == 0;
    }
};

inline std::istream &operator>>(std::istream &in, Wifi &room) {
    in >> room.y >> room.x >> room.energy;
    return in;
}

const int MAX_SIZE = 1e3 + 1;
const int COMMON = 0;

int size;
int noise[MAX_SIZE];
Wifi rooms[MAX_SIZE];

void aggregateNoise(void) {
    for (int dest = 1; dest <= size; dest++) {
        Wifi &destRoom = rooms[dest];

        for (int src = 1; src <= size; src++) {
            Wifi &srcRoom = rooms[src];
            if (srcRoom.isOff()) {
                continue;
            }

            noise[dest] += srcRoom.speedTo(destRoom);
        }
    }
}

void printWifiSpeed(void) {
    int maxSpeed = 0;

    for (int i = 1; i <= size; i++) {
        maxSpeed = std::max(
            maxSpeed,
            rooms[COMMON].speedTo(rooms[i]) - noise[i]
        );
    }

    if (maxSpeed == 0) {
        std::cout << "IMPOSSIBLE" << '\n';
    } else {
        std::cout << maxSpeed << '\n';
    }
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size >> rooms[COMMON];
    for (int i = 1; i <= size; i++) {
        std::cin >> rooms[i];
    }

    aggregateNoise();
    printWifiSpeed();
    return 0;
}
