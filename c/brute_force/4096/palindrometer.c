#include <stdio.h>
#include <stdlib.h>

int	mod(int n, int cnt);
int	is_palindrome(int num, int len);
void	print_ans(char *str);

int	main(void)
{
	char	str[10];

	while (1)
	{
		scanf("%s", str);
		if (str[1] == '\0')
			break;
		print_ans(str);
	}
	return (0);
}

void	print_ans(char *str)
{
	int	i;
	int	num, len;

	i = 0;
	num = atoi(str);
	len = get_len(len);
	while (1)
	{
		if (is_palindrome(n + i, len))
			break;
		i++;
	}
	printf("%d\n", i);
}

int	is_palindrome(int num, int len)
{
	int	i;

	for (i = 0; i < len / 2; i++)
		if (mod(num, i) != mod(num, len - 1 - i))
			return (0);
	return (1);
}

int	mod(int n, int cnt)
{
	int	i;

	for (i = 0; i < cnt; i++)
		n /= 10;
	return (n % 10);
}
