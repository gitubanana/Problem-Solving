#include <iostream>
#include <map>

typedef std::multimap<std::string, std::string> t_map;

int main()
{
    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int cnt, ans = 0;
	char	first, second;
    std::string city, state_code;
    t_map  cities[26][26];
    t_map::iterator    iter;
	std::pair<std::string, std::string>	pair;

    std::cin >> cnt;
    while (cnt--)
    {
		std::string	&city = pair.first;
		std::string	&state_code = pair.second;

        std::cin >> city >> state_code;

		t_map	&state = cities[city[0] - 'A'][city[1] - 'A'];
		for (iter = state.begin(); iter != state.end(); ++iter)
		{
			const std::string	&cur_city = iter->first;
			if (cur_city[0] == state_code[0]
				&& cur_city[1] == state_code[1]
				&& iter->second != state_code)
				++ans;
		}

		cities[state_code[0] - 'A'][state_code[1] - 'A'].insert(pair);
    }

    std::cout << ans << '\n';
    return 0;
}

