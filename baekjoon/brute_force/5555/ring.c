#include <stdio.h>
#include <string.h>

int	get_len(char *str);
void	change(char *str, int len);
int	is_include(char *to_find, char *ring);

int	main(void)
{
	int	n;
	int	cnt;
	char	str[11];
	char	ring[11];

	cnt = 0;
	scanf("%s %d", str, &n);
	while (n--)
	{
		scanf("%s", ring);
		if (is_include(str, ring))
			cnt++;
	}
	printf("%d", cnt);
	return (0);
}

int	is_include(char *to_find, char *ring)
{
	int	i;
	int	len;

	len = get_len(ring);
	for (i = 0; i < len; i++)
	{
		change(ring, len);
		if (strstr(ring, to_find))
			return (1);
	}
	return (0);
}

int	get_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	change(char *str, int len)
{
	int	i;
	char	tmp;

	tmp = str[0];
	for (i = 0; i < len - 1; i++)
		str[i] = str[i + 1];
	str[len - 1] = tmp;
}
