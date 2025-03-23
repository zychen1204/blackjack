#include<iostream>
#include<string.h>
#include"Player.h"

using namespace std;

Human::Human(){
    cout<<"creating Human ...."<<endl;
    cout<<"What's Human name?"<<endl;
    cin>>name;
    cout<<"What's Human bankroll?"<<endl;
    cin>>bankroll;
    bet = cur_value = participate = final_winner  = 0;
    cout<<"Human had been created!!"<<endl;
}
void Human::strategy(){
    cout<<"Would you like to draw another card?(Y or N):";
    char k ;
    cin>>k;
    if(k=='Y'){
        cout<<name<<" chooses to draw."<<endl;
        participate = 1;
        return;
    }
    else if(k=='N'){
        cout<<name<<" chooses to stay."<<endl;
        participate = 0;
        return ;
    }
}

Dealer::Dealer(){
    cout<<"creating Dealer ...."<<endl;
    name = "Dealer";
    bankroll = 10000;
    bet = cur_value = participate = final_winner  = 0;
    cout<<"Dealer had been created!!"<<endl;
}
void Dealer::strategy(){
    if(cur_value <=16){
        cout<<name<<" chooses to draw."<<endl;
        participate = 1;
        return ;
    }
    else{
        cout<<name<<" chooses to stay."<<endl;
        participate = 0;
        return ;
    }
}
Meek::Meek(){
    cout<<"creating Meek Computer ...."<<endl;
    cout<<"What's Meek Computer name?"<<endl;
    cin>>name;
    cout<<"What's Meek Computer bankroll?"<<endl;
    cin>>bankroll;
    win = weird = 0;
    bet = 2;
    cur_value = participate = final_winner = 0;
    cout<<"Meek Computer had been created!!"<<endl;
}
void Meek::strategy(){

    if(cur_value%2==0){
        cout<<name<<" chooses to draw."<<endl;
        participate = 1;
        return;
    }
    else{
        cout<<name<<" chooses to stay."<<endl;
        participate = 0;
        return;
    
    }
}
Random::Random(){
    cout<<"creating Random Computer ...."<<endl;
    cout<<"What's Random Computer name?"<<endl;
    cin>>name;
    cout<<"What's Random Computer bankroll?"<<endl;
    cin>>bankroll;
    bet = cur_value = participate = final_winner =  0;
    cout<<"Random Computer had been created!!"<<endl;
}
void Random::strategy(){
    if(cur_value<=9){
        cout<<name<<" chooses to draw."<<endl;
        participate = 1;
        return ;
    }
    if(cur_value>=10&&cur_value<=12){
        bool TrueFalse = (rand() % 100) < 80;
        if(TrueFalse == 1){
            cout<<name<<" chooses to draw."<<endl;
            participate = 1;
            return ;
        }
        else{
            cout<<name<<" chooses to stay."<<endl;
            participate = 0;
            return ;
        }
    }
    else if(cur_value>=13&&cur_value<=15){
        bool TrueFalse = (rand() % 100) < 70;
        if(TrueFalse == 1){
            cout<<name<<" chooses to draw."<<endl;
            participate = 1;
            return ;
        }
        else{
            cout<<name<<" chooses to stay."<<endl;
            participate = 0;
            return ;
        }
    }
    else if(cur_value>=16&&cur_value<=18){
        bool TrueFalse = (rand() % 100) < 50;
        if(TrueFalse == 1){
            cout<<name<<" chooses to draw."<<endl;
            participate = 1;
            return ;
        }
        else{
            cout<<name<<" chooses to stay."<<endl;
            participate = 0;
            return ;
        }
    }
    else{
        cout<<name<<" chooses to stay."<<endl;
        participate = 0;
        return ;
    }
}