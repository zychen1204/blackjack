#include"Card.h"
#include<iostream>
using namespace std;

Card::Card(){
    rank[0] = 0;
    suit[0] = "";
    for(int i = 1;i<=13;i++){
        rank[i] = rank[i+13] = rank[i+26] = rank[i+39] = i;
        suit[i] = "H";
        suit[i+13] = "D";
        suit[i+26] = "C";
        suit[i+39] = "S";
    }
    value[0] = 0;
    for(int i = 1;i<=52;i++){
        if(rank[i]==1){
            value[i] = 11;
        }
        else if(rank[i]<=10&&rank[i]>=2){
            value[i] = i%13;
        }
        else{
            value[i] = 10;
        }
    }
    name[0]="";
    for(int i = 0;i<4;i++){
        {
            name[1+13*i]="A";
            name[2+13*i]="2";
            name[3+13*i]="3";
            name[4+13*i]="4";
            name[5+13*i]="5";
            name[6+13*i]="6";
            name[7+13*i]="7";
            name[8+13*i]="8";
            name[9+13*i]="9";
            name[10+13*i]="10";
            name[11+13*i]="J";
            name[12+13*i]="Q";
            name[13+13*i]="K";
        }
    }
}