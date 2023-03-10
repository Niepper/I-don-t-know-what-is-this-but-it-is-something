#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

int main()
{
    int tab[6][6] = {
        {1},
        {5, 10},
        {55, 6, 7},
        {88, 9, 5, 3},
        {5, 6, 2, 1000, 5},
        {200, 3, 45, 5, 2, 3},
       
    };
    
    // Obliczanie maksymalnych sum od dołu do góry
    for (int i = 6-2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            tab[i][j] += std::max(tab[i+1][j], tab[i+1][j+1]);
        }
    }

    std::cout << "Maksymalna suma dla od góry do dołu wynosi " << tab[0][0] << std::endl;

    return 0;
}