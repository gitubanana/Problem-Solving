#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int sum, n;
	char k;

	sum = 0;
	while (1)
	{
		scanf("%d", &n);
		sum += n;

		scanf("%c", &k);

		if (k == '\n')
			break;
	}

	printf("%d\n", sum);
}