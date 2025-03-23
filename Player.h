#include<string>
using namespace std;
class Player {
    public:
    int final_winner;
    string name;
    int bankroll;
    int bet;
    int cur_value;
    int participate;
    int card[10];
    virtual void strategy() = 0; 
};
class Human: public Player {
    public:
    
        Human();
    void strategy();
};
class Dealer:public Player{
    public:
        Dealer();
    void strategy();
};
class Meek:public Player{
    public:
        int win;
        int weird ;
        Meek();
        void strategy();
        void print();
};
class Random:public Player{
    public:
        Random();
        void strategy();
        void print();
};