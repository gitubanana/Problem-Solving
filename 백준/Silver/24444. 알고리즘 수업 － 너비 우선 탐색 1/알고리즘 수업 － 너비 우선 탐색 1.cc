#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int	MAX = 100001;

std::vector<int>	map[MAX];
int					turn[MAX], cur_turn = 1;

void	print_turns(int &v_cnt)
{
	for (int v = 1; v <= v_cnt; ++v)
		printf("%d\n", turn[v]);
}

void	bfs(int cur_v)
{
	int				i;
	std::queue<int>	q;

	turn[cur_v] = cur_turn++;
	q.push(cur_v);
	while (!q.empty())
	{
		cur_v = q.front(), q.pop();
		for (i = 0; i < static_cast<int>(map[cur_v].size()); ++i)
		{
			if (turn[map[cur_v][i]] == 0)
			{
				turn[map[cur_v][i]] = cur_turn++;
				q.push(map[cur_v][i]);
			}
		}
	}
}

int	main(void)
{
	int	from, to;
	int	v_cnt, e_cnt, start;

	scanf(" %d %d %d", &v_cnt, &e_cnt, &start);
	while (e_cnt)
	{
		scanf(" %d %d", &from, &to);
		map[from].push_back(to);
		map[to].push_back(from);
		--e_cnt;
	}
	for (int i = 1; i <= v_cnt; ++i)
		std::sort(map[i].begin(), map[i].end());
	bfs(start);
	print_turns(v_cnt);
	return (0);
}
