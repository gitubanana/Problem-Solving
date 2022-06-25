#include <stdio.h>

int	is_hansu(int num);

int	main(void)
{
	int	i, n, cnt;

	cnt = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		if (is_hansu(i))
			cnt++;
	printf("%d", cnt);
	return (0);
}

int	is_hansu(int num)
{
	int	d, tmp;

	tmp = num / 10 % 10;
	d = num % 10 - tmp;
	num /= 100;
	while (num > 0)
	{
		if (d != tmp - num % 10)
			return (0);
		tmp = num % 10;
		num /= 10;
	}
	return (1);
}
