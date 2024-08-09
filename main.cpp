#include <iostream>
#include <ctime>
#include <vector>


struct Card{
            int value;
        };




std::string genUserCard();
void userDec();
double userBet(double bet);
std::string genDealerCard();
void finaldec();
void reward();
int randCard();

int main(){

        Card card2;
        card2.value = 2;
        
        Card card3;
        card3.value = 3;
        
        Card card4;
        card4.value = 4;
        
        Card card5;
        card5.value = 5;
        
        Card card6;
        card6.value = 6;
            
        Card card7;
        card7.value = 7;
            
        Card card8;
        card8.value = 8;
            
        Card card9;
        card9.value = 9;
            
        Card card10;
        card10.value = 10;
            
        Card cardJack;
        cardJack.value = 10;
            
        Card cardQueen;
        cardQueen.value = 10;
            
        Card cardKing;
        cardKing.value = 10;
            
        Card cardAce;
        cardAce.value = 10;

    double bet;

    std::cout << "*********** WELCOME TO THE TABLE ***********\n";
    std::cout << "what would you like to bet: $";
    std::cin >> bet;

    std::cout << "$" << userBet(bet) << '\n';
    std::cout << "********** Distributing Cards **********";




    return 0;
}
std::string genUserCard(enum Heart, enum Spade, enum Diamond, enum Club, int num){



}
void userDec(){

}
double userBet(double bet){
    bet;
    return bet;
}
std::string genDealerCard(Card card2){
    
    int Card = randCard();
    

    switch(Card){
        case 0:
    }

}
void finaldec(){

}
void reward(){

}
int randCard(){
    srand(time(0));
    int randCard = rand() % 12;
    return randCard;
}
