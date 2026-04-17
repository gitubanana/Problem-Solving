#include <iostream>
#include <algorithm>

typedef struct
{
	int	vowel;
	int	consonant;
}	ch_cnt;

const int	MAX = 15;

int		idx[MAX];
char	elem[MAX];
int		comb_cnt, char_cnt;

bool	is_vowel(char to_find)
{
	static int					i;
	static const std::string	vowel = "aeiou";

	for (i = 0; i < static_cast<int>(vowel.length()); ++i)
		if (vowel[i] == to_find)
			return (true);
	return (false);
}

void	back_tracking(int cur_v, int depth)
{
	int		i;
	ch_cnt	cnt;

	if (depth == comb_cnt)
	{
		cnt.vowel = cnt.consonant = 0;
		for (i = 0; i < comb_cnt; ++i)
		{
			if (is_vowel(elem[idx[i]]))
				++cnt.vowel;
			else
				++cnt.consonant;
		}
		if (!(cnt.vowel >= 1 && cnt.consonant >= 2))
			return ;
		for (i = 0; i < comb_cnt; ++i)
			printf("%c", elem[idx[i]]);
		printf("\n");
		return ;
	}
	for (i = cur_v; i < char_cnt; ++i)
	{
		idx[depth] = i;
		back_tracking(i + 1, depth + 1);
	}
}

int	main(void)
{
	int		i;

	scanf(" %d %d", &comb_cnt, &char_cnt);
	for (i = 0; i < char_cnt; ++i)
		scanf(" %c", &elem[i]);
	std::sort(elem, elem + char_cnt);
	back_tracking(0, 0);
	return (0);
}
