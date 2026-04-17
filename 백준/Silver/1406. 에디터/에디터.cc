#include <iostream>
#include <iomanip>
#include <queue>
#include <list>
#include <algorithm>

class Editor
{
	private:
		typedef std::list<char> t_line;
		typedef t_line::iterator t_cursor;

		t_line		line;
		t_cursor	cursor;
	public:
		template <typename Iter>
		Editor(Iter begin, Iter end)
			: line(begin, end), cursor(line.end())
		{
		}

		void	move_cursor_left(void)
		{
			if (cursor == line.begin())
				return ;
			--cursor;
		}

		void	move_cursor_right(void)
		{
			if (cursor == line.end())
				return ;
			++cursor;
		}

		void	delete_left(void)
		{
			if (cursor == line.begin())
				return ;
			t_cursor	to_delete = cursor;

			--to_delete;
			line.erase(to_delete);
		}

		void	add_left(char to_add)
		{
			line.insert(cursor, to_add);
		}

		void	print_line(void) const
		{
			std::cout << std::string(line.begin(), line.end()) << '\n';
		}
};

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	std::string	str;
	int			cmd_cnt;
	char		cmd, to_add;
	std::cin >> str >> cmd_cnt;

	Editor	vscode(str.begin(), str.end());
	while (cmd_cnt--)
	{
		std::cin >> cmd;
		switch (cmd)
		{
			case 'L':
				vscode.move_cursor_left();
				break ;
			case 'D':
				vscode.move_cursor_right();
				break ;
			case 'B':
				vscode.delete_left();
				break ;
			default:
				std::cin >> to_add;
				vscode.add_left(to_add);
		}
	}
	vscode.print_line();
	return (0);
}
