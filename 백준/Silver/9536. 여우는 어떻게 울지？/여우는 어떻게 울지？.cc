#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <limits>

const int MAX = 100;

bool shouldPrint[MAX];
std::string foxSounds[MAX];

typedef std::unordered_map<std::string, std::vector<int> > t_umap;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    std::cin >> testCnt;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (testCnt--)
    {
        t_umap umap;
        std::string sounds;

        std::getline(std::cin, sounds);

        // std::cout << "=======================" << '\n';
        // std::cout << "sounds : " << sounds << '\n';
        int soundSize = 0;
        int start = 0;
        while (start < sounds.size())
        {
            int end = start;
            while (sounds[end] &&sounds[end] != ' ')
                ++end;

            std::string key = sounds.substr(start, end - start);
            t_umap::iterator it = umap.find(key);
            if (it != umap.end())
            {
                it->second.push_back(soundSize++);
            }
            else
            {
                umap.insert({key, {soundSize++}});
            }
            start = end + 1;
        }

        while (true)
        {
            std::getline(std::cin, sounds);
            // std::cout << "dog : " << sounds << '\n';

            start = sounds.size() - 1;
            while (sounds[start] != ' ')
            {
                --start;
            }

            std::string toRemove = sounds.substr(start + 1);
            // std::cout << "toRemove : \"" << toRemove << '\"' << '\n';
            if (toRemove == "say?")
            {
                // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break ;
            }

            umap.erase(toRemove);
        }

        // std::cout << "\n========================" << '\n';
        for (std::pair<const std::string, std::vector<int> > &cur : umap)
        {
            // std::cout << cur.first << '\n';
            for (const int &idx : cur.second)
            {
                // std::cout << idx << ' ';
                foxSounds[idx] = cur.first;
                shouldPrint[idx] = true;
            }
            // std::cout << '\n';
        }

        for (int i = 0; i < soundSize; ++i)
        {
            if (!shouldPrint[i])
                continue ;
            std::cout << foxSounds[i] << ' ';
        }
        std::cout << '\n';

        if (testCnt >= 1)
            memset(shouldPrint, 0, sizeof(shouldPrint));
    }
    return (0);
}
