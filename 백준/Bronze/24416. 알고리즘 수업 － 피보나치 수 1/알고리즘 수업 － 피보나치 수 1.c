
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define MAX 1000

uint64_t	cnt = 1;

void	fibo_recursive(int n)
{
	if (n < 3)
		return ;
	cnt++;
	return (fibo_recursive(n - 1), fibo_recursive(n - 2));
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	fibo_recursive(n);
	printf("%llu ", cnt);
	printf("%d", n - 2 );
	return (0);
}
