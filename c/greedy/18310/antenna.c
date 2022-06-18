#include <stdio.h>
#include <stdlib.h>

int	cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int	main(void)
{
	int	i;
	int	n;
	int	*home;

	i = 0;
	scanf("%d", &n);
	home = malloc(sizeof(int) * n);
	if (!home)
		return (1);
	while (i < n)
		scanf("%d", &home[i++]);
	qsort(home, n, sizeof(int), cmp);
	printf("%d", n % 2 == 0 ? home[n / 2 - 1] : home[n / 2]);
	free(home);
	return (0);
}
