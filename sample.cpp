#include <iostream>
#include <iomanip>
#include <random>

#include "seeder.h"

int main(void)
{

    std::mt19937  rng1;
    jle::seed(rng1);

    jle::seeder seeder;
    std::mt19937  rng2{seeder};

    auto rng3 = jle::make_mt_rng();
    auto rng4 = jle::make_mt64_rng();

    std::cout << std::hex 
              << rng1() << " " 
              << rng2() << " " 
              << rng3() << " "
              << rng4() << " "
              << "\n";
}
