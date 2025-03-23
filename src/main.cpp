#include<iostream>
#include<string>
#include"Card.h"
#include"Player.h"
#include<ctime>
using namespace std;

int main(){
    srand( time(NULL) );
    int Human_number = 0;
    int Meek_number = 0;
    int Random_number = 0;
    cout<<"How many human?(>=0)"<<endl;
    cin>>Human_number;
    Human H[Human_number];

    cout<<"How many Meek computer?(>=0)"<<endl;
    cin>>Meek_number;
    Meek M[Meek_number];

    cout<<"How many Random computer?(>=0)"<<endl;
    cin>>Random_number;
    Random R[Random_number];
     
    Dealer D;
    Card card;
    int game = 0;
    cout<<"Okay, time for betting!"<<endl;
    cout<<"--------------------------------"<<endl;
    while(game==0){
        for(int i = 0;i<Human_number;i++){
            cout<<H[i].name<<", how much would you like to bet?(>=1)"<<endl;
            cin>>H[i].bet;
            cout<<H[i].name<<" bets "<<H[i].bet<<endl;
        }
        for(int i = 0;i<Meek_number;i++){
            if(M[i].win==3){
                M[i].bet *=2;
            }
            cout<<M[i].name<<" bets "<<M[i].bet<<endl;
        }
        for(int i = 0;i<Random_number;i++){
            R[i].bet = (rand() % (R[i].bankroll/2))+1;;
            cout<<R[i].name<<" bets "<<R[i].bet<<endl;
        }

        cout<<"The initial starting cards are:"<<endl;
        cout<<"-----------------------------------------"<<endl;

        for(int i = 0;i<Human_number;i++){
            int ra = rand()%52+1;
            H[i].card[0] = ra;
            ra = rand()%52+1;
            H[i].card[1] = ra;

            cout<<H[i].name<<"'s current hand"
            <<"[??]["<<card.name[H[i].card[1]]<<card.suit[H[i].card[1]]<<']'<<endl;
            H[i].cur_value = card.value[H[i].card[0]]+card.value[H[i].card[1]];
        }
        for(int i = 0;i<Meek_number;i++){
            int ra = rand()%52+1;
            M[i].card[0] = ra;
            ra = rand()%52+1;
            M[i].card[1] = ra;
            M[i].cur_value = card.value[M[i].card[0]]+card.value[M[i].card[1]];
            cout<<M[i].name<<"'s current hand"
            <<"[??]["<<card.name[M[i].card[1]]<<card.suit[M[i].card[1]]<<']'<<endl;
        }
        for(int i = 0;i<Random_number;i++){
            int ra = rand()%52+1;
            R[i].card[0] = ra;
            ra = rand()%52+1;
            R[i].card[1] = ra;
            R[i].cur_value = card.value[R[i].card[0]]+card.value[R[i].card[1]];
            cout<<R[i].name<<"'s current hand"
            <<"[??]["<<card.name[R[i].card[1]]<<card.suit[R[i].card[1]]<<']'<<endl;
        }
        int ra = rand()%52+1;
        D.card[0] = ra;
        ra = rand()%52+1;
        D.card[1] = ra;
        D.cur_value = card.value[D.card[0]]+card.value[D.card[1]];
        cout<<D.name<<"'s current hand"
        <<"[??]["<<card.name[D.card[1]]<<card.suit[D.card[1]]<<']'<<endl<<endl;
        
        

        for(int i = 0;i<Human_number;i++){
            cout<<H[i].name<<"'s turn:"<<endl;
            cout<<"----------------------"<<endl;
            int n = 1;
            cout<<H[i].name<<"'s current hand";
            for(int k = 0;k<=n;k++){
                
                cout<<'['<<card.name[H[i].card[k]]
                <<card.suit[H[i].card[k]]<<']';
            }
            cout<<"("<<H[i].cur_value<<" point)"<<endl;
            H[i].strategy();
            while(H[i].participate==1&&H[i].cur_value<=21){
                
                int ra = rand()%52+1;
                n++;
                H[i].card[n] = ra;
                H[i].cur_value+=card.value[H[i].card[n]];
                cout<<H[i].name<<"'s current hand";
                for(int k = 0;k<=n;k++){
                    
                    cout<<'['<<card.name[H[i].card[k]]
                    <<card.suit[H[i].card[k]]<<']';
                }
                cout<<"("<<H[i].cur_value<<" point)"<<endl;
                if(H[i].cur_value<=21)
                {
                    H[i].strategy();
                }
            }
            
            if(H[i].cur_value>21){
                cout<<H[i].name<<" busted at "<<H[i].cur_value<<"!"<<endl;
                H[i].cur_value = -1;
            }
            cout<<endl;
        }
        for(int i = 0;i<Meek_number;i++){
            int weird = 0;
            cout<<M[i].name<<"'s turn:"<<endl;
            cout<<"----------------------"<<endl;
            int n = 1;
            cout<<M[i].name<<"'s current hand";
            for(int k = 0;k<=n;k++){
                if(M[i].card[k]==33){
                    weird = 1;
                }
                
                cout<<'['<<card.name[M[i].card[k]]
                <<card.suit[M[i].card[k]]<<']';
            }
            cout<<"("<<M[i].cur_value<<" point)"<<endl;
            if(weird==0){

                M[i].strategy(); 
            }                   
            else if(weird==1){
                M[i].participate = 1;
            }
            while(M[i].participate==1&&M[i].cur_value<=21){
                
                int ra = rand()%52+1;
                n++;
                M[i].card[n] = ra;
                M[i].cur_value+=card.value[M[i].card[n]];
                cout<<M[i].name<<"'s current hand";
                for(int k = 0;k<=n;k++){
                    
                    cout<<'['<<card.name[M[i].card[k]]
                <<card.suit[M[i].card[k]]<<']';
                }
                cout<<"("<<M[i].cur_value<<" point)"<<endl;
                if(M[i].cur_value<=21)
                {
                    if(weird==0){
                        M[i].strategy();                    }
                    else if(weird==1){
                        M[i].participate = 1;
                    }
                }
            }
            if(M[i].cur_value>21){
                cout<<M[i].name<<" busted at "<<M[i].cur_value<<"!"<<endl;
                M[i].cur_value = -1;
            }
            cout<<endl;
        }

        for(int i = 0;i<Random_number;i++){
            cout<<R[i].name<<"'s turn:"<<endl;
            cout<<"----------------------"<<endl;
            int n = 1;
            cout<<R[i].name<<"'s current hand";
            for(int k = 0;k<=n;k++){
                cout<<'['<<card.name[R[i].card[k]]
                <<card.suit[R[i].card[k]]<<']';
                
            }
            cout<<"("<<R[i].cur_value<<" point)"<<endl;
            R[i].strategy();
            while(R[i].participate==1&&R[i].cur_value<=21){
                
                int ra = rand()%52+1;
                n++;
                R[i].card[n] = ra;
                R[i].cur_value+=card.value[R[i].card[n]];
                cout<<R[i].name<<"'s current hand";
                for(int k = 0;k<=n;k++){
                    
                    cout<<'['<<card.name[R[i].card[k]]
                        <<card.suit[R[i].card[k]]<<']';
                }
                cout<<"("<<R[i].cur_value<<" point)"<<endl;
                if(R[i].cur_value<=21)
                {
                    R[i].strategy();
                }
            }
            if(R[i].cur_value>21){
                cout<<R[i].name<<" busted at "<<R[i].cur_value<<"!"<<endl;
                R[i].cur_value = -1;
            }
            cout<<endl;
        }

        cout<<D.name<<"'s turn:"<<endl;
            cout<<"----------------------"<<endl;
            int n = 1;
            cout<<D.name<<"'s current hand";
            for(int k = 0;k<=n;k++){
                
                cout<<'['<<card.name[D.card[k]]
                <<card.suit[D.card[k]]<<']';
                
            }
            cout<<"("<<D.cur_value<<" point)"<<endl;
            D.strategy();
            while(D.participate==1&&D.cur_value<=21){
                
                int ra = rand()%52+1;
                n++;
                D.card[n] = ra;
                D.cur_value+=card.value[D.card[n]];
                cout<<D.name<<"'s current hand";
                for(int k = 0;k<=n;k++){
                    
                    cout<<'['<<card.name[D.card[k]]
                        <<card.suit[D.card[k]]<<']';
                }
                cout<<"("<<D.cur_value<<" point)"<<endl;
                if(D.cur_value<=21)
                {
                    D.strategy();
                }
            }
            if(D.cur_value>21){
                cout<<D.name<<" busted at "<<D.cur_value<<"!"<<endl;
                D.cur_value = -1;
            }
        cout<<endl;

        cout<<"Let's see how it turned out:"<<endl;
        cout<<"---------------------------------------"<<endl;

        int end = 0;
        int max = 21;



        while(end == 0&&max>=2){
            for(int i = 0 ;i<Human_number;i++){
                if(H[i].cur_value == max){
                    end ++;
                    H[i].final_winner = 1;
                }
            }
            for(int i = 0 ;i<Meek_number;i++){
                if(M[i].cur_value == max){
                    end ++;
                    M[i].final_winner = 1;
                }
            }
            for(int i = 0 ;i<Random_number;i++){
                if(R[i].cur_value == max){
                    end ++;
                    R[i].final_winner = 1;
                }
                
            }
            
            if(D.cur_value == max){
                    end ++;
                    D.final_winner = 1;
            }
            max--;
        }
        for(int i = 0 ;i<Human_number;i++){
            if(H[i].final_winner == 1&&end==1){
                    cout<<"Yowzah! "<<H[i].name<<" wins $ "<<H[i].bet<<endl;
                    H[i].bankroll+=H[i].bet;
                    D.bankroll-=H[i].bet;
            }
            else{
                cout<<"Ouch! "<<H[i].name<<" loses $ "<<H[i].bet<<endl;
                H[i].bankroll-=H[i].bet;
                D.bankroll+=H[i].bet;
            }
        }
        for(int i = 0 ;i<Meek_number;i++){
            if(M[i].final_winner == 1&&end==1){
                cout<<"Yowzah! "<<M[i].name<<" wins $ "<<M[i].bet<<endl;
                M[i].bankroll+=M[i].bet;
                D.bankroll-=M[i].bet;
            }
            else{
                cout<<"Ouch! "<<M[i].name<<" loses $ "<<M[i].bet<<endl;
                M[i].bankroll-=M[i].bet;
                D.bankroll+=M[i].bet;
            }
        }
        for(int i = 0 ;i<Random_number;i++){
            if(R[i].final_winner == 1&&end==1){
                cout<<"Yowzah! "<<R[i].name<<" wins $ "<<R[i].bet<<endl;
                R[i].bankroll+=R[i].bet;
                D.bankroll-=R[i].bet;
            }
            else{
                cout<<"Ouch! "<<R[i].name<<" loses $ "<<R[i].bet<<endl;
                R[i].bankroll-=R[i].bet;
                D.bankroll+=R[i].bet;
            }
        }
        
        cout<<endl;
        cout<<"The standings so far:"<<endl;
        cout<<"------------------------------"<<endl;
        for(int i = 0 ;i<Human_number;i++){
            cout<<H[i].name<<" $ "<<H[i].bankroll<<endl;
        }
        for(int i = 0 ;i<Meek_number;i++){
            cout<<M[i].name<<" $ "<<M[i].bankroll<<endl; 
        }
        for(int i = 0 ;i<Random_number;i++){
            cout<<R[i].name<<" $ "<<R[i].bankroll<<endl;
        }
        cout<<D.name<<" $ "<<D.bankroll<<endl;
        cout<<endl;
        
        char ar;
        cout<<"Another round? (Y or N):"<<endl;
        cin>>ar;
        if(ar=='N'){
            game = 1;
        }
        else{

        for(int i = 0;i<Human_number;i++){
            H[i].cur_value = H[i].participate = H[i].final_winner = 0;
        }
        for(int i = 0;i<Meek_number;i++){
            M[i].cur_value = M[i].participate = M[i].final_winner = 0;
        }
        for(int i = 0;i<Random_number;i++){
            R[i].cur_value = R[i].participate = R[i].final_winner = 0;
        }
            D.cur_value = D.participate = D.final_winner = 0;
        }
    }
}

    
