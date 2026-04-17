#include <iostream>

int    main(void)
{
    size_t     book_idx;
    std::string    book, word, to_find;

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> book >> to_find;
    for (book_idx = 0; book_idx < book.size(); ++book_idx)
    {
        if (std::isdigit(book[book_idx]))
            continue ;
        word += book[book_idx];
    }
    std::cout << (word.find(to_find) != std::string::npos) << '\n';
    return (0);
}