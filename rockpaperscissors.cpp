#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<conio.h>
using namespace std;

int main(){
	string player_name;
	cout<<"Enter your name:";
	cin>>player_name;
	system("cls");
	int rounds;
	cout<<"Enter no of rounds: ";
	cin>>rounds;
	int player_score=0, computer_score=0;
	for(int round=1; round<=rounds; round++){
		system("cls");
		int player_choice, computer_choice;
		cout<<"Round No: "<< round<<"/"<< rounds<<endl;
		cout<<player_name<<"'s score= "<<player_score<<endl;
		cout<<"Computer Score="<<computer_score<<endl;
		cout<<"'1' for Rock"<<endl;
		cout<<"'2' for Paper"<<endl;
		cout<<"'3' for scissors"<< endl;
		
		do{
			cout<<"Enter your choice: ";
			cin>>player_choice;
		
		}while(player_choice!=1 && player_choice!=2 && player_choice!=3);
		
		srand(time(0));
		
		computer_choice=rand()%3+1;
		if(player_choice==1 && computer_choice==3){
			
			player_score++;
		}
		else if(player_choice==2 && computer_choice==1){
			
			player_score++;
		}
		else if(player_choice==3&& computer_choice==2){
			
			player_score++;
		}
		else if(player_choice ==computer_choice){
			cout<<"This round is draw."<<endl;
			
		}
		else{
			
			computer_score++;
		}
		
	}
	if(computer_score == player_score){
		cout<<"Game draw."<<endl;
		
	}	
	else if(player_score>computer_score){
		cout<<player_name<<"you won the game."<<endl;
	}
	else{
		cout<<"computer won."<<endl;
	}
	return 0;
}