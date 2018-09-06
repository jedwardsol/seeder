#include <random>

namespace jle
{

struct seed_seq_emulator
{
    template <typename U>
    void generate(U begin, U end)
    {
        for(auto seed=begin;seed<end;seed++)
        {
            *seed=rd();
        }
    }

private:
    std::random_device rd;
};



template <typename RNG>
void seed(RNG &rng)
{
    seed_seq_emulator   seeder;   
    rng.seed(seeder);
}
        

}

//std::mt19937 rng;
//jle::seed(rng);    
