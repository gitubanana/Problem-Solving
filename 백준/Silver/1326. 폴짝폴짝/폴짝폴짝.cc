#include <queue>
#include <iostream>

void	bfs(int *&arr, int *&cnt, int &size, int &start)
{
	std::queue<int>	q;
	int				mul, cur_idx, next_idx;

	q.push(start);
	while (!q.empty())
	{
		cur_idx = q.front(), q.pop();
		for (mul = 1; cur_idx + (mul * arr[cur_idx]) < size; mul++)
		{
			next_idx = cur_idx + (mul * arr[cur_idx]);
			if (next_idx >= size)
				break ;
			if (cnt[next_idx] != 0)
				continue ;
			q.push(next_idx);
			if (cnt[next_idx] == 0)
				cnt[next_idx] = cnt[cur_idx] + 1;
			else
				cnt[next_idx] = std::min(cnt[next_idx], cnt[cur_idx] + 1);
		}
		for (mul = -1; cur_idx + (mul * arr[cur_idx]) >= 0; mul--)
		{
			next_idx = cur_idx + (mul * arr[cur_idx]);
			if (next_idx < 0)
				break ;
			if (cnt[next_idx] != 0)
				continue ;
			q.push(next_idx);
			if (cnt[next_idx] == 0)
				cnt[next_idx] = cnt[cur_idx] + 1;
			else
				cnt[next_idx] = std::min(cnt[next_idx], cnt[cur_idx] + 1);
		}
	}
}

int	main(void)
{
	int	i;
	int	*arr, *cnt, size;
	int	start, dest;

	std::cin >> size;
	arr = new int[size];
	cnt = new int[size];
	for (i = 0; i < size; i++)
		std::cin >> arr[i], cnt[i] = 0;
	std::cin >> start >> dest;
	start--, dest--;
	bfs(arr, cnt, size, start);
	if (start == dest)
		std::cout << 0;
	else
		std::cout << (cnt[dest] == 0 ? -1 : cnt[dest]);
	delete[] arr;
	delete[] cnt;
	return (0);
}