#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

std::map<std::string, int>	_map;

int main(void)
{
	char	str[501];
	int		i, s_size, to_find_size;
	int		ans = 0;

	scanf(" %d %d", &s_size, &to_find_size);
	for (i = 0; i < s_size; ++i)
	{
		scanf(" %s", str);
		_map[str] = 1;
	}
	for (i = 0; i < to_find_size; ++i)
	{
		scanf(" %s", str);
		if (_map[str] == 1)
			++ans;
	}
	printf("%d\n", ans);
	return (0);
}