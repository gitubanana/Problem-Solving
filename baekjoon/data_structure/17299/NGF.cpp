#include <iostream>
#include <vector>
#include <stack>

const int MAX_SIZE = 1e6;
const int MAX_NUM = 1e6;

int size;
int arr[MAX_SIZE];
int freq[MAX_SIZE + 1];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int i = 0; i < size; ++i)
    {
        int &cur = arr[i];

        std::cin >> cur;
        ++freq[cur];
    }

    std::stack<int> stack;
    std::vector<int> NGF;

    NGF.push_back(-1);
    stack.push(arr[size - 1]);
    for (int i = size - 2; i >= 0; --i)
    {
        const int &cur = arr[i];

        while (!stack.empty())
        {
            const int &cmp = stack.top();
            if (freq[cur] < freq[cmp])
                break ;

            stack.pop();
        }

        NGF.push_back((stack.empty() ? -1 : stack.top()));
        stack.push(cur);
    }

    for (int i = size - 1; i >= 0; --i)
    {
        std::cout << NGF[i] << ' ';
    }
    std::cout << '\n';
    return (0);
}
