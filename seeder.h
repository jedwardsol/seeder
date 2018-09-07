#include <random>
#include <array>
#include <iterator>         // being/end
#include <algorithm>        // generate_n
#include <functional>       // ref


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
    rng.discard(1'000'000);
}


using seeder = seed_seq_emulator;





template <typename generator>
auto make_rng()
{
    std::random_device                                   rd;
    std::array<uint32_t,generator::state_size>           seed_data;

    std::generate_n(seed_data.data(),seed_data.size(),std::ref(rd));

    std::seed_seq                                        seed(std::begin(seed_data),std::end(seed_data));
    generator                                            engine{seed};

    return engine;
}

auto make_mt_rng()
{
    return make_rng<std::mt19937>();
}

auto make_mt64_rng()
{
    return make_rng<std::mt19937_64>();
}




}


