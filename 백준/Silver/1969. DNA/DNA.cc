#include <iostream>
#include <vector>
#include <climits>

typedef std::vector<std::string>    t_vec;

int get_hamDist(t_vec &dna_vec, char nucleo, int cmp_idx)
{
    int hamDist = 0;

    for (int i = 0; i < dna_vec.size(); ++i)
    {
        hamDist += (dna_vec[i][cmp_idx] != nucleo);
    }
    return (hamDist);
}

void    print_smallest_hamDistance(t_vec &dna_vec, int dna_size)
{
    int     small_hamDist;
    std::string small_ham_str;
    std::string nucleotide = "ACGT";
    char    min_nucleo;
    int     min_hamDist, cur_hamDist;

    small_hamDist = 0;
    for (int i = 0; i < dna_size; ++i)
    {
        min_hamDist = INT_MAX;
        for (char &cur_nucleo : nucleotide)
        {
            cur_hamDist = get_hamDist(dna_vec, cur_nucleo, i);
            if (min_hamDist > cur_hamDist)
            {
                min_hamDist = cur_hamDist;
                min_nucleo = cur_nucleo;
            }
        }
        small_ham_str += min_nucleo;
        small_hamDist += min_hamDist;
    }
    std::cout << small_ham_str << '\n';
    std::cout << small_hamDist << '\n';
}

int main()
{
    int i;
    std::string dna;
    t_vec       dna_vec;
    int dna_cnt, dna_size;

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> dna_cnt >> dna_size;
    for (i = 0; i < dna_cnt; ++i)
    {
        std::cin >> dna;
        dna_vec.push_back(dna);
    }
    print_smallest_hamDistance(dna_vec, dna_size);
    return 0;
}
