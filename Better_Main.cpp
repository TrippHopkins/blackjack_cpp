#include <iostream>
#include <stdlib.h>
#include <array>
#include <vector>
#include <random>
#include <string>


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
        int i = 2;
        bool PlayerBusted = false;
        bool DealerBusted = false;
        std::random_device randnum;
        std::vector<card> dealer_hand;
        std::vector<card> player_hand;
        std::string HOS;
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
        void player_HitsOrStay(int playerSumTotal);
        void dealer_HitsOrStay(int dealerSumTotal);
        void finalResult(int playerSumTotal, int dealerSumTotal, double Bet, double Money);
        std::string type_to_string(card_t type);
        std::string Hit_or_stay(std::string HOS);
};

void GameUti::start(){
    std::cout << "************************** WELCOME TO THE TABLE **************************\n";
    std::cout << "Balence: $" << Money << '\n';
    std::cout << "What Would you like to bet? \n$";
    std::cin >> Bet;
    std::cout << "\n************************** Distributing Cards ****************************\n";

    add_dealer_card();
    add_dealer_card();
    add_player_card();
    add_player_card();

    std::cout << "DEALER'S SHOWING: ";
    if(dealer_hand[0].type != card_t::num){
        std::cout << type_to_string(dealer_hand[0].type);
    }
    else if(dealer_hand[0].type == card_t::num){
        std::cout << dealer_hand[0].value;
    }

    std::cout << '\n' << "YOUR FIRST CARD: ";
    if(player_hand[0].type != card_t::num){
        std::cout << type_to_string(player_hand[0].type);
    }
    else if(player_hand[0].type == card_t::num){
        std::cout << player_hand[0].value;
    }

    std::cout << '\n' << "YOUR SECOND CARD: ";
    if(player_hand[1].type != card_t::num){
        std::cout << type_to_string(player_hand[1].type);
    }
    else if(player_hand[1].type == card_t::num){
        std::cout << player_hand[1].value;
    }

    std::cout << '\n';
    int playerSumTotal = (player_hand[0].value + player_hand[1].value);
    int dealerSumTotal = (dealer_hand[0].value + dealer_hand[1].value);
    std::cout << "YOUR TOTAL AMOUNT: " << playerSumTotal;
    
    player_HitsOrStay(playerSumTotal);
    std::cout << "************************ Dealer's Turn *************************\n";
    dealer_HitsOrStay(dealerSumTotal);
    std::cout << "*********************** Tallying Results ***********************\n";
    finalResult(playerSumTotal, dealerSumTotal, Bet, Money);
    std::cout << "\n****************************************************************";

}
std::string GameUti::type_to_string(card_t type){
    switch(type){
        case card_t::Ace: return "Ace";
        case card_t::King: return "King";
        case card_t::Queen: return "Queen";
        case card_t::Jack: return "Jack";
        default: return "Unknown";
    }
    }
std::string GameUti::Hit_or_stay(std::string HOS){
    if(HOS == "1"){
        return "Hit";
    }
    else if(HOS == "0"){
        return "Stay";
    }else{
        return "Hit";
    }
    
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
void GameUti::player_HitsOrStay(int playerSumTotal){
    do{
    std::cout << '\n' << "Please type 1 to Hit or 0 to stay: ";
    std::cin >> HOS;
    if(GameUti::Hit_or_stay(HOS) == "Hit"){
        add_player_card();
        if(player_hand[i].type != card_t::num){
            std::cout << "New Card: " << type_to_string(player_hand[i].type);
        }
        else if(player_hand[i].type == card_t::num){
            std::cout << "New Card: " << player_hand[i].value;
        }
        playerSumTotal = playerSumTotal + player_hand[i].value;
        std::cout << "\nNew Total: " << playerSumTotal << '\n';
        if(playerSumTotal > 21){
            PlayerBusted = true;
            std::cout << "YOU BUSTED\n";
        }
        i = i + 1;
    }
    }while(Hit_or_stay(HOS) == "Hit" && PlayerBusted != true);
}
void GameUti::dealer_HitsOrStay(int dealerSumTotal){
    i = 2;
    std::cout << "Dealer's Second Card: ";
     if(dealer_hand[1].type != card_t::num){
        std::cout << type_to_string(dealer_hand[1].type);
    }
    else if(dealer_hand[1].type == card_t::num){
        std::cout << dealer_hand[1].value;
    }
    do{
        add_dealer_card();
        if(player_hand[i].type != card_t::num){
            std::cout << "\nDealer Hits! \n" << "Dealer's New Card: " << type_to_string(dealer_hand[i].type);
        }
        else if(player_hand[i].type == card_t::num){
            std::cout << "\nDealer Hits! \n" << "Dealer's New Card: " << dealer_hand[i].value;
        }
        dealerSumTotal = dealerSumTotal + dealer_hand[i].value;
        std::cout << "\nNew Total: " << dealerSumTotal << '\n';
        i = i + 1;
    }while(dealerSumTotal < 17);
    do{
        std::cout << "Dealer Chooses to stay with a total of: " << dealerSumTotal << '\n';
    }while(dealer_hand[i].value >= 17 && dealer_hand[i].value <= 21);
    if(dealerSumTotal > 21){
        DealerBusted = true;
        std::cout << "Dealer Busted\n";
    }
}
void GameUti::finalResult(int playerSumTotal, int dealerSumTotal, double Bet, double Money){

    if(DealerBusted || PlayerBusted){
    if(DealerBusted && !PlayerBusted){
        std::cout << "You Win! Payout: $" << Bet;
        Money = Money + Bet;
        std::cout << "\nNew Balence: $" << Money;
    }else if(!DealerBusted && PlayerBusted){
        std::cout << "You Loose! Payout: -$" << Bet;
        Money = Money - Bet;
        std::cout << "\nNew Balence: $" << Money;
    }
    }
    if(!DealerBusted && !PlayerBusted){
    if(playerSumTotal > dealerSumTotal){
        std::cout << "You Win! Payout: $" << Bet;
         Money = Money + Bet;
         std::cout << "\nNew Balence: $" << Money; 
    }else if(playerSumTotal < dealerSumTotal){
        std::cout << "You Loose! Payout: -$" << Bet;
        Money = Money - Bet;
        std::cout << "\nNew Balence: $" << Money;
    }else if(playerSumTotal == dealerSumTotal){
        std::cout << "You Tied! No Payout!\n";
        std::cout << "New Balence: " << Money;
    }
    }
}
int main()
{
    GameUti* g = new GameUti();
    g->Money = 1500;
    g->start();

    return 0;
}