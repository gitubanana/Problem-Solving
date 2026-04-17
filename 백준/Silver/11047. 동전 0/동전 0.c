#include <stdio.h>

int main()
{
	int n, k,i,num;
	int coin[10];
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d", &coin[i]);
	num = 0;
	i--;
	for(;k != 0;i--)
	{
		if (coin[i] <= k)
			num += k / coin[i];
		k %= coin[i];
	}
	printf("%d", num);

	return 0;
}