#include <stdio.h>


int	main(void)
{
	int	n;

	scanf("%d", &n);
	print_ans(n);
}

void	print_ans(int n)
{
	int	i, tmp;
	int	cnt, max;

	i = n;
	max = 0;
	while (i >= 0)
	{
		cnt = print_or_cnt(n, i, 1);
		if (cnt > max)
		{
			max = cnt;
			tmp = i;
		}
		i--;
	}
	printf("%d\n", max);
	print_or_cnt(n, tmp, 0);
}

int	print_or_cnt(int n, int minus, int flag)
{
	int	cnt;
	int	one, two, next;

	cnt = 2;
	one = n;
	two = minus;
	next = one - two;
	if (flag == 0)
		printf("%d %d ", one, two);
	//one two next
	//    one  two next
	while (next >= 0)
	{
		if (flag == 0)
			printf("%d ", next);
		cnt++;
		one = two;
		two = next;
		next = one - two;
	}
	return (cnt);
}
