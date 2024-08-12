#include <iostream>
#include <ctime>
#include <unistd.h>

int money = 100;

void userDec();
int userBet(int bet);
void reward();

int main(){


    std::string showingPlayCard1;
    std::string showingPlayCard2;
    std::string optshowingPlayCard3;
    std::string optshowingPlayCard4;
    std::string showingDealCard1;
    std::string showingDealCard2;
    std::string optshowingDealCard3;
    std::string optshowingDealCard4;


    int bet;
    int dealCard1 = rand() % 12 + 2;
    switch(dealCard1){
        case 11: showingDealCard1 = "Jack";
            break;
        case 12: showingDealCard1 = "Queen";
            break;
        case 13: showingDealCard1 = "King";
            break;
        case 14: showingDealCard1 = "Ace";
            break;
        default: showingDealCard1 = std::to_string(dealCard1);
            break;
    }
    int dealCard2 = rand() % 12 + 2;
    switch(dealCard2){
        case 11: showingDealCard2 = "Jack";
            break;
        case 12: showingDealCard2 = "Queen";
            break;
        case 13: showingDealCard2 = "King";
            break;
        case 14: showingDealCard2 = "Ace";
            break;
        default: showingDealCard2 = std::to_string(dealCard2);
            break;
    }
    int dealCard3 = rand() % 12 + 2;
    switch(dealCard3){
        case 11: optshowingDealCard3 = "Jack";
            break;
        case 12: optshowingDealCard3 = "Queen";
            break;
        case 13: optshowingDealCard3 = "King";
            break;
        case 14: optshowingDealCard3 = "Ace";
            break;
        default: optshowingDealCard3 = std::to_string(dealCard3);
            break;
    }
    
    int dealCard4 = rand() % 12 + 2;
    switch(dealCard4){
        case 11: optshowingDealCard4 = "Jack";
            break;
        case 12: optshowingDealCard4 = "Queen";
            break;
        case 13: optshowingDealCard4 = "King";
            break;
        case 14: optshowingDealCard4 = "Ace";
            break;
        default: optshowingDealCard4 = std::to_string(dealCard4);
            break;
    }

    int playerCard1 = rand() % 12 + 2;
    switch(playerCard1){
        case 11: showingPlayCard1 = "Jack";
            break;
        case 12: showingPlayCard1 = "Queen";
            break;
        case 13: showingPlayCard1 = "King";
            break;
        case 14: showingPlayCard1 = "Ace";
            break;
        default: showingPlayCard1 = std::to_string(playerCard1);
            break;
    }

    int playerCard2 = rand() % 12 + 2;
    switch(playerCard2){
        case 11: showingPlayCard2 = "Jack";
            break;
        case 12: showingPlayCard2 = "Queen";
            break;
        case 13: showingPlayCard2 = "King";
            break;
        case 14: showingPlayCard2 = "Ace";
            break;
        default: showingPlayCard2 = std::to_string(playerCard2);
            break;
    }
    
    int playerCard3 = rand() % 12 + 2;
    switch(playerCard3){
        case 11: optshowingPlayCard3 = "Jack";
            break;
        case 12: optshowingPlayCard3 = "Queen";
            break;
        case 13: optshowingPlayCard3 = "King";
            break;
        case 14: optshowingPlayCard3 = "Ace";
            break;
        default: optshowingPlayCard3 = std::to_string(playerCard3);
            break;
    }

    int playerCard4 = rand() % 12 + 2;
    switch(playerCard4){
        case 11: optshowingPlayCard4 = "Jack";
            break;
        case 12: optshowingPlayCard4 = "Queen";
            break;
        case 13: optshowingPlayCard4 = "King";
            break;
        case 14: optshowingPlayCard4 = "Ace";
            break;
        default: optshowingPlayCard4 = std::to_string(playerCard4);
            break;
    }

    bool stay = 1;

    int DC1 =0;
    int DC2 =0;
    int DC3 =0;
    int DC4 =0;
    int PC1 =0;
    int PC2 =0;
    int PC3 =0;
    int PC4 =0;

    if(showingDealCard1 == "Jack" || showingDealCard1 == "Queen" || showingDealCard1 == "King" || showingDealCard1 == "Ace"){
        DC1 = 10;
    }
    else{
        DC1 = stoi(showingDealCard1);
    }
    if(showingDealCard2 == "Jack" || showingDealCard2 == "Queen" || showingDealCard2 == "King" || showingDealCard2 == "Ace"){
        DC2 = 10;
    }
    else{
        DC2 = stoi(showingDealCard2);
    }
    if(showingPlayCard1 == "Jack" || showingPlayCard1 == "Queen" || showingPlayCard1 == "King" || showingPlayCard1 == "Ace"){
        PC1 = 10;
    }
    else{
        PC1 = stoi(showingPlayCard1);
    }
    if(showingPlayCard1 == "Jack" || showingPlayCard1 == "Queen" || showingPlayCard1 == "King" || showingPlayCard1 == "Ace"){
        PC2 = 10;
    }
    else{
        PC2 = stoi(showingPlayCard1);
    }


    std::cout << "*********** WELCOME TO THE TABLE ***********\n";
    std::cout << "what would you like to bet: $";
    std::cin >> bet;

    std::cout << "$" << userBet(bet) << '\n';
    std::cout << "********** Distributing Cards **********\n";
    sleep(2);
    std::cout << "Your Cards: " << showingPlayCard1 << " and " << showingPlayCard2 << '\n';
    std::cout << "Dealer is showing: " << showingDealCard1 << '\n' << '\n';
    
    while(stay == 1){
        std::cout << "Please type 0 if you would like to stay or 1 if you would like to hit?\n";
        std::cin >> stay;
            if(stay == 1){
                std::cout << "New Card: " << optshowingPlayCard3 << '\n';
                if(optshowingPlayCard3 == "Jack" || optshowingPlayCard3 == "Queen" || optshowingPlayCard3 == "King" || optshowingPlayCard3 == "Ace"){
                    PC3 = 10;
                }
                else{
                    PC3 = stoi(optshowingPlayCard3);
                }
            }
            else if(PC1 + PC2 + PC3 >= 22){
                std::cout << "Busted\n";
                stay = 0; 
                break;
            }
        std::cout << "Please type 0 if you would like to stay or 1 if you would like to hit?\n";
        std::cin >> stay;
            if(stay == 1){
                std::cout << "New Card: " << optshowingPlayCard4 << '\n';;
                if(optshowingPlayCard4 == "Jack" || optshowingPlayCard4 == "Queen" || optshowingPlayCard4 == "King" || optshowingPlayCard4 == "Ace"){
                    PC4 = 10;
                }
                else{
                    PC4 = stoi(optshowingPlayCard3);
                }
            }
            else if(PC1 + PC2 + PC3 + PC4 >= 22){
                std::cout << "Busted\n";
                stay = 0; 
                break;
            }
    }

    sleep(1);
    std::cout << "Dealer's second card: " << showingDealCard2 << '\n';
    sleep(1.37);

    if(DC1 + DC2 < 17){
        std::cout << "Dealer HITS!\n";
        std::cout << "Dealer's New Card: " << optshowingDealCard3 << '\n';
        if(optshowingDealCard3 == "Jack" || optshowingDealCard3 == "Queen" || optshowingDealCard3 == "King" || optshowingDealCard3 == "Ace"){
                    DC3 = 10;
                }
                else{
                    DC3 = stoi(optshowingDealCard3);
                }
        sleep(3);
    }

    if(DC1 + DC2 + DC3 < 17){
        std::cout << "Dealer HITS!\n";
        std::cout << "Dealer's New Card: " << optshowingDealCard4 << '\n';
        if(optshowingDealCard4 == "Jack" || optshowingDealCard4 == "Queen" || optshowingDealCard4 == "King" || optshowingDealCard4 == "Ace"){
                    DC4 = 10;
                }
                else{
                    DC4 = stoi(optshowingDealCard3);
                }
        sleep(3);
    }   

    int PlayerFinal = (PC1 + PC2 + PC3 + PC4);
    int DealerFinal = (DC1 + DC2 + DC3 + DC4);

    if(PlayerFinal > DealerFinal && PlayerFinal < 22 && DealerFinal < 22){
        std::cout << "You WIN!";
        money = money + userBet(bet);
        std::cout << "Total Money; $" << money << '\n';
    }
    else if(PlayerFinal < DealerFinal && PlayerFinal < 22 && DealerFinal < 22){
        std::cout << "You Loose!";
        money = money - userBet(bet);
        std::cout << "Total Money; $" << money << '\n';
    }
    else if(PlayerFinal == DealerFinal && PlayerFinal < 22 && DealerFinal < 22){
        std::cout << "You Draw!";
        std::cout << "Total Money; $" << money << '\n';
    }
    else if(PlayerFinal > 21 && DealerFinal < 22){
        std::cout << "You Loose!";
        money = money - userBet(bet);
        std::cout << "Total Money; $" << money << '\n';
    }
    else if(PlayerFinal < 22 && DealerFinal > 21){
        std::cout << "You WIN!";
        money = money + userBet(bet);
        std::cout << "Total Money; $" << money << '\n';
    }

    return 0;

}
int userBet(int bet){
    bet;
    return bet;
}