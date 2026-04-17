#include <iostream>
#define CANNOT_FIND -1

int find_char(const std::string line, char to_find)
{
    int idx;
    
    for (idx = 0; line[idx]; ++idx)
        if (line[idx] == to_find)
            return (idx);
    return (-1);
}

void    decrypt_rot13(std::string &line)
{
    int                         i, find_idx;
    const static std::string    vowel = "aiyeou";
    const static std::string    consonant = "bkxznhdcwgpvjqtsrlmf";
    const static std::string    vowel_up = "AIYEOU";
    const static std::string    consonant_up = "BKXZNHDCWGPVJQTSRLMF";
    
    for (i = 0; line[i]; ++i)
    {
        if ((find_idx = find_char(vowel, line[i])) != CANNOT_FIND)
        {
            if (find_idx >= 3)
                line[i] = vowel[(find_idx - 3)];
            else
                line[i] = vowel[(find_idx + 3)];
        }
        else if ((find_idx = find_char(consonant, line[i])) != CANNOT_FIND)
        {
            if (find_idx >= 10)
                line[i] = consonant[(find_idx - 10)];
            else
                line[i] = consonant[(find_idx + 10)];
        }
        else if ((find_idx = find_char(vowel_up, line[i])) != CANNOT_FIND)
        {
            if (find_idx >= 3)
                line[i] = vowel_up[(find_idx - 3)];
            else
                line[i] = vowel_up[(find_idx + 3)];
        }
        else if ((find_idx = find_char(consonant_up, line[i])) != CANNOT_FIND)
        {
            if (find_idx >= 10)
                line[i] = consonant_up[(find_idx - 10)];
            else
                line[i] = consonant_up[(find_idx + 10)];
        }
    }
}

int main()
{
    std::string line;
    
    std::getline(std::cin, line, '\0');
    decrypt_rot13(line);
    std::cout << line << std::endl;
    return 0;
}