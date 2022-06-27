#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	cnt, len;
	char	*tmp;
	char	aim[51], doc[2501];

	cnt = 0;
	scanf("%[^\n] %[^\n]", doc, aim);
	tmp = doc;
	len = strlen(aim);
	while (tmp = strstr(tmp, aim))
	{
		cnt++;
		tmp += len;
	}
	printf("%d", cnt);
}
