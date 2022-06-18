#include <stdio.h>

void	print_ans(char *str);

int	main(void)
{
	int	n;
	char	str[51];

	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", str);
		print_ans(str);
	}
}

void	print_ans(char *str)
{
	int	i;
	int	left, right;

	left = right = 0;
	for (i = 0; str[i] && left >= right; i++)
	{
		if (str[i] == '(')
			left++;
		else
			right++;
	}
	printf("%s\n", left == right ? "YES" : "NO");
}
