#include <iostream>
#include <queue>

const int	MAX = 1000001;

int	building[MAX];

bool	bfs(int &limit, int &start, int &dest, int &up, int &down)
{
	std::queue<int>	q;
	int				cur_pos, next_pos;

	building[start] = 1;
	if (start == dest)
		return (true);
	q.push(start);
	while (!q.empty())
	{
		cur_pos = q.front(), q.pop();

		next_pos = cur_pos - down;
		if (((1 <= next_pos && next_pos <= limit))
			&& building[next_pos] == 0)
		{
			building[next_pos] = building[cur_pos] + 1;
			if (next_pos == dest)
				return (true);
			q.push(next_pos);
		}

		next_pos = cur_pos + up;
		if ((1 <= next_pos && next_pos <= limit)
			&& building[next_pos] == 0)
		{
			building[next_pos] = building[cur_pos] + 1;
			if (next_pos == dest)
				return (true);
			q.push(next_pos);
		}
	}
	return (false);
}

int	main(void)
{
	int	limit;
	int	start, dest;
	int	up, down;

	scanf(" %d %d %d %d %d", &limit, &start, &dest, &up, &down);
	if (bfs(limit, start, dest, up, down))
		printf("%d\n", building[dest] - 1);
	else
		printf("use the stairs\n");
	return (0);
}
