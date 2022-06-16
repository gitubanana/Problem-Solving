#include <stdio.h>

void	print_ans(char *str);

int	main(void)
{
	char	str[101];

	while (1)
	{
		gets(str);
		if (str[0] == '.')
			break;
		print_ans(str);
	}
	return (0);
}

void	print_ans(char *str)
{
	int	i, top;
	char	stack[100];

	top = i = -1;
	while (str[++i])
	{
		if (str[i] == '(' || str[i] == '[')
			stack[++top] = str[i];
		else if (str[i] == ')')
		{
			if (top == -1 || stack[top] != '(')
			{
				top = 0;
				break;
			}
			top--;
		}
		else if (str[i] == ']')
		{
			if (top == -1 || stack[top] != '[')
			{
				top = 0;
				break;
			}
			top--;
		}
	}
	printf("%s\n", top == -1 ? "yes" : "no");
}
