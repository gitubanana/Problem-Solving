#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>
#include <sstream>

void    parse_and_print(std::string &url)
{
    std::string tmp;
    std::string protocol, host, port, path;
    std::istringstream   ss(url);
    size_t      colon_pos;

    std::getline(ss, protocol, ':');

    std::getline(ss, tmp, '/'), std::getline(ss, tmp, '/');;

    std::getline(ss, host, '/');
    if ((colon_pos = host.find(':')) != std::string::npos)
    {
        port = host.substr(colon_pos + 1);
        host = host.substr(0, colon_pos);
    }

    std::getline(ss, path, '\0');

    std::cout << "Protocol = " << protocol << '\n';
    std::cout << "Host     = " << host << '\n';
    std::cout << "Port     = " << (port == "" ? "<default>" : port) << '\n';
    std::cout << "Path     = " << (path == "" ? "<default>" : path) << '\n';
}

int main(void)
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int test_cnt;
    std::string url;

    std::cin >> test_cnt;
    for (int i = 1; i <= test_cnt; ++i)
    {
        std::cin >> url;
        std::cout << "URL #" << i << '\n';
        parse_and_print(url);
        if (i != test_cnt)
            std::cout << '\n';
    }

    return 0;
}
