#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>

typedef std::string t_num;
typedef std::map<t_num, int> t_waitlist;
typedef std::pair<t_num, int>	t_pair;

inline bool	cmp(const t_pair &a, const t_pair &b)
{
	return (a.second < b.second);
}

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	t_waitlist	waitlist;
	t_waitlist::iterator	iter;

	t_num	student_num;
	int		size, available, turn;

	std::cin >> available >> size;
	for (turn = 0; turn < size; ++turn)
	{
		std::cin >> student_num;
		waitlist[student_num] = turn;
	}

	std::vector<t_pair>	vec(waitlist.begin(), waitlist.end());

	std::sort(vec.begin(), vec.end(), cmp);

	std::vector<t_pair>::iterator it = vec.begin();
	for (; available-- && it != vec.end(); ++it)
		std::cout << it->first << '\n';
	return (0);
}
