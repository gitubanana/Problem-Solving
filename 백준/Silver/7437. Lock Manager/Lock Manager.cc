#include <stdio.h>
#include <unordered_map>
#include <unordered_set>

using Id = int;

template <typename T>
using Uset = std::unordered_set<T>;

template <typename K, typename V>
using Umap = std::unordered_map<K, V>;

enum e_mode {
    SHARED = 'S',
    EXCLUSIVE = 'X'
};

class Lock {
private:
    Id item;
    Id transaction;
    bool isExclusive;

public:
    bool readFrom(FILE *stream) {
        char mode;

        if (fscanf(stream, " %c %d %d", &mode, &transaction, &item) != 3) {
            return false;
        }

        isExclusive = (mode == EXCLUSIVE);
        return true;
    }

    friend class LockManager; // friend 키워드 연습
};

class LockManager {
private:
    Uset<Id> blockedTr;
    Umap<Id, Umap<Id, bool>> trsByItem;

    inline bool isIgnored(const Lock &lock) {
        return blockedTr.find(lock.transaction) != blockedTr.end();
    }

    inline bool hasConflict(const Lock &lock) {
        for (std::pair<const Id, bool> &pair : trsByItem[lock.item]) {
            if (pair.first == lock.transaction) {
                continue;
            }

            if (pair.second | lock.isExclusive) {
                return true;
            }
        }
        return false;
    }
public:
    void process(const Lock &lock, FILE *stream) {
        if (isIgnored(lock)) {
            fprintf(stream, "IGNORED\n");
            return;
        }

        if (hasConflict(lock)) {
            blockedTr.insert(lock.transaction);
            fprintf(stream, "DENIED\n");
            return;
        }

        trsByItem[lock.item][lock.transaction] |= lock.isExclusive;
        fprintf(stream, "GRANTED\n");
    }
};

int main(void) {
    Lock lock;
    LockManager lockManager;

    while (lock.readFrom(stdin)) {
        lockManager.process(lock, stdout);
    }
    return 0;
}
