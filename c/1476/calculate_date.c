#include <stdio.h>

void	print_ans(int e, int s, int m);

int	main(void)
{
	int	e, s, m;

	scanf("%d %d %d", &e, &s, &m);
	print_ans(e, s, m);
}

void	print_ans(int e, int s, int m)
{
	int	year;
	int	a, b, c;

	a = b = c = year = 1;
	while (a != e || b != s || c != m)
	{
		a++;
		if (a == 16)
			a = 1;
		b++;
		if (b == 29)
			b = 1;
		c++;
		if (c == 20)
			c = 1;
		year++;
	}
	printf("%d", year);
}
