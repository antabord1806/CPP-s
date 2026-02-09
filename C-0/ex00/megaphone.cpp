#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    for (int i = 1; argv[i]; i++)
    {
        for (int j = 0; argv[i][j]; j++)
            std::cout << static_cast<char>(toupper(static_cast<unsigned char>(argv[i][j])));
    }
    std::cout << std::endl;
    return 0;
}