#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "\x1b[1;31mError: wrong number of arguments\x1b[0m" << std::endl;
        return 1;
    }

    PmergeMe pmerge;
    pmerge.Init(argc, argv);
}