#include <stdio.h>

int	get_len(char *str);
void	rev(char *str);
void	print_ans(char *str);

int	main(void)
{
	int	n;
	char	str[1001];

	scanf("%d", &n);
	while (n--)
	{
		gets(str);
		print_ans(str);
	}
}

void	print_ans(char *str)
{
	int	i, j;

	j = 0;
	for (i = 0; str[i + 1]; i++)
	{
		if (str[i] == ' ')
		{
			str[i] = 0;
			rev(&str[j]);
			printf("%s ", &str[j]);
			j = i + 1;
		}
	}
	rev(&str[j]);
	printf("%s\n", &str[j]);
}

void	rev(char *str)
{
	int	i;
	int	len;
	char	tmp;

	len = get_len(str);
	for (i = 0; i < len / 2; i++)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
	}
}

int	get_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

