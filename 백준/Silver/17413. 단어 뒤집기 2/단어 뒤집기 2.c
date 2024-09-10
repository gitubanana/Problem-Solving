#include <stdio.h>

int	get_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != ' ' && str[len] != '<')
        len++;
    return (len);
}

void	rev(char *str, int len)
{
	int    i;
	char	tmp;

	for (i = 0; i < len / 2; i++)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
	}
}

void	print_ans(char *str)
{
	int    i, j;
    int    sum;

	j = sum = 0;
	for (i = 0; str[i]; i++)
	{
        if (str[i] == '<')
            sum++;
        else if (str[i] == '>')
            sum--;
        
		if ((str[i] == ' ' && !sum) || str[i] == '<')
        {
            rev(&str[j], get_len(&str[j]));
            j += get_len(&str[j]);
        }
        else if (str[i] == '>' && !sum)
        {
            rev(&str[i + 1], get_len(&str[i + 1]));
            j = i + 1 + get_len(&str[i + 1]);
        }
        
        if (str[j] == ' ')
            j++;
	}
	rev(&str[j], get_len(&str[j]));
    printf("%s\n", str);
}

int	main(void)
{
	char	str[100001];

    scanf("%[^\n]",str);
    print_ans(str);
}