#include <iostream>
#include <iomanip>
#include <stack>
#include <algorithm>

const int	MAX = 500000;

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int	size;
	int	height[MAX];
	std::stack<int>	front_idx;

	std::cin >> size;
	for (int cur = 0;  cur < size; ++cur)
	{
		std::cin >> height[cur];

		while (!front_idx.empty())
		{
			int	&front = front_idx.top();
			if (height[front] >= height[cur])
				break ;
			front_idx.pop();
		}

		if (front_idx.empty())
			std::cout << "0";
		else
			std::cout << front_idx.top() + 1;
		std::cout << ' ';

		front_idx.push(cur);
	}
	return (0);
}
