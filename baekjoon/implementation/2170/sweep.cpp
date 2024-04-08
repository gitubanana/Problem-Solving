#include <iostream>
#include <algorithm>

struct t_line
{
    long long start;
    long long end;

    inline bool operator<(const t_line &other) const
    {
        return (this->start < other.start);
    }

    inline long long length(void) const
    {
        return (end - start);
    }

    inline bool in(const t_line &line) const
    {
        return (line.start <= this->start && this->end <= line.end);
    }
};

inline std::istream &operator>>(std::istream &in, t_line &input)
{
    in >> input.start >> input.end;
    return (in);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    std::cin >> size;

    t_line *lines = new t_line[size];
    for (int i = 0; i < size; ++i)
        std::cin >> lines[i];

    std::sort(lines, lines + size);

    long long ans = 0;
    t_line &line = lines[0];
    for (int i = 1; i < size; ++i)
    {
        t_line &curLine = lines[i];

        if (curLine.in(line))
            continue ;

        if (line.start <= curLine.start && curLine.start <= line.end)
        {
            line.end = curLine.end;
        }
        else
        {
            ans += line.length();
            line = curLine;
        }
    }
    ans += line.length();

    std::cout << ans << '\n';
    delete[] lines;
    return (0);
}
