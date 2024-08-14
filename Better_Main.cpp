#include <iostream>
#include <unistd.h>
#include <array>
#include <vector>
#include <random>


//    std::mt19937 gen(randnum());
//    std::uniform_int_distribution<> distr(0, cards.size() -1);
//    distr(gen);

enum card_t {num, Jack, Queen, King, Ace};

struct card{
    int value;
    card_t type;
};
class GameUti{
    public:
        double Money;
        double Bet;
        std::random_device randnum;
        std::vector<card> dealer_hand;
        std::vector<card> player_hand;
        std::array<card, 13> cards {{
            {1, card_t::Ace},
            {2, card_t::num},
            {3, card_t::num},
            {4, card_t::num},
            {5, card_t::num},
            {6, card_t::num},
            {7, card_t::num},
            {8, card_t::num},
            {9, card_t::num},
            {10, card_t::num},
            {10, card_t::Jack},
            {10, card_t::Queen},
            {10, card_t::King},
        }};
        void start();
        void add_dealer_card();
        void add_player_card();
};

void GameUti::start(){
    std::cout << "************************** WELCOME TO THE TABLE **************************\n";
    std::cout << "Balence: " << Money << '\n';
    std::cout << "What Would you like to bet? \n";
    std::cin >> Bet;
    std::cout << "\n************************** Distributing Cards ****************************\n";
    std::cout << "DEALERS SHOWING" << dealer_hand[0].type;


}
void GameUti::add_dealer_card(){
    std::mt19937 gen(randnum());
    std::uniform_int_distribution<> distr(0, cards.size() -1);
    int a = distr(gen);
    dealer_hand.push_back(cards[a]);
}
void GameUti::add_player_card(){
    std::mt19937 gen(randnum());
    std::uniform_int_distribution<> distr(0, cards.size() -1);
    int b = distr(gen);
    player_hand.push_back(cards[b]);
}

int main()
{
    GameUti* g = new GameUti();
    g->Money = 1500;
    g->start();

    return 0;
}