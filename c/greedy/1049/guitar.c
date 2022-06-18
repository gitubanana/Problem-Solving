#include <stdio.h>

void	print_min(int price, int six, int one)
{
	int	ans;

	if (six > one * 6)
		ans = price * one;
	else
		ans = price / 6 * six + (six > price % 6 * one ? price % 6 * one : six);
	printf("%d", ans);
}

int	main(void)
{
	int	n;
	int	m;
	int	tmp[2];
	int	min_six;
	int	min_one;

	min_six = 1001;
	min_one = 1001;
	scanf("%d %d", &n, &m);
	while (m--)
	{
		scanf("%d %d", &tmp[0], &tmp[1]);
		if (tmp[0] < min_six)
			min_six = tmp[0];
		if (tmp[1] < min_one)
			min_one = tmp[1];
	}
	print_min(n, min_six, min_one);
}
