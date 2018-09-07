#include <iostream>
#include <random>

#include "seeder.h"

int main(void)
{

    std::mt19937  rng1;
    jle::seed(rng1);

    jle::seeder seeder;
    std::mt19937  rng2{seeder};

    std::cout << rng1() << " " << rng2() << "\n";


}
