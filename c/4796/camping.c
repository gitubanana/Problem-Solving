#include <stdio.h>

int	get_days(int l, int p, int v)
{
	return v / p * l + (l < v % p ? l : v % p);
}

void	print_ans(int i, int l, int p, int v)
{
	printf("Case %d: ", i + 1);
	printf("%d\n", get_days(l, p, v));
}

int	main(void)
{
	int	i;
	int	l;
	int	p;
	int	v;

	i = 0;
	while (1)
	{
		scanf("%d %d %d", &l, &p, &v);
		if (l == 0)
			break;
		print_ans(i, l, p, v);
		i++;
	}
}
