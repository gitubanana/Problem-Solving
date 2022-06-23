#include <stdio.h>

int	peek();
int	pop(int flag);
void	push(int data, int flag);
int	print_or_bool(int size, int flag);

int	stack[10001];
int	arr[100001];
int	top = -1;

int	main(void)
{
	int	i, n;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	if (!print_or_bool(n, 1))
		printf("NO");
	else
	{
		top = -1;
		print_or_bool(n, 0);
	}
	return (0);
}

int	print_or_bool(int size, int flag)
{
	int	i, j;

	j = 1;
	push(j++, flag);
	for (i = 0; i < size; i++)
	{
		if (peek() < arr[i])
		{
			while (j <= arr[i])
				push(j++, flag);
			pop(flag);
		}
		else if (peek() == arr[i])
			pop(flag);
		else
			return (0);
	}
	return (1);
}

void	push(int data, int flag)
{
	if (!flag)
		printf("+\n");
	stack[++top] = data;
}

int	pop(int flag)
{
	if (!flag)
		printf("-\n");
	return (stack[top--]);
}

int	peek()
{
	return (stack[top]);
}
