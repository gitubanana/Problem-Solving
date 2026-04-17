#include <iostream>
#include <queue>

const int	MAX = 101;

int	map[MAX][MAX];
int	cnt[MAX];

int	bfs(int &start, int &end, int &v_cnt)
{
	std::queue<int>	q;
	int				i, cur_v;

	q.push(start);
	while (!q.empty())
	{
		cur_v = q.front(), q.pop();
		for (i = 1; i <= v_cnt; ++i)
		{
			if (map[cur_v][i] == 1 && cnt[i] == 0)
			{
				cnt[i] = cnt[cur_v] + 1;
				q.push(i);
				if (i == end)
					return (cnt[end]);
			}
		}
	}
	return (-1);
}

int	main(void)
{
	int	from, to;
	int	start, end;
	int	v_cnt, e_cnt;

	scanf(" %d", &v_cnt);
	scanf(" %d %d", &start, &end);
	scanf(" %d", &e_cnt);
	while (e_cnt)
	{
		scanf(" %d %d", &from, &to);
		map[from][to] = 1;
		map[to][from] = 1;
		--e_cnt;
	}
	printf("%d\n", bfs(start, end, v_cnt));
	return (0);
}
