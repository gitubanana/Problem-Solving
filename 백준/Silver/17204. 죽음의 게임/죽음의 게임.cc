#include <iostream>

const int	MAX = 10001;

int	map[MAX];
int	v_cnt;

void	simulation(int cur_v, int end, int &min, int &cnt)
{
	if (cur_v == end)
		return ;
	if (cnt == v_cnt)
	{
		min = -1;
		return ;
	}
	++min, ++cnt;
	cur_v = map[cur_v];
	simulation(cur_v, end, min, cnt);
}

void	print_min(int &start, int &end)
{
	int	min;
	int	cnt;

	min = cnt = 0;
	simulation(start, end, min, cnt);
	printf("%d\n", min);
}

int	main(void)
{
	int	i, start, end, v;

	scanf(" %d %d", &v_cnt, &end);
	for (i = 0; i < v_cnt; ++i)
	{
		scanf(" %d", &v);
		map[i] = v;
	}
	start = 0;
	print_min(start, end);
	return (0);
}

