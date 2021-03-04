#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

struct Machine{
	int id;
	string name;
	int price;
	int quantity;
};
int Menu();
int main()
{
	int choice;
	//Choosing main  menu//
	cout<<"Welcome to PAFIAST Vending machine\n";
	cout<<"1.Want to Purchase ";
	cout<<"\n2.Exit ";
	cin>>choice;
	switch(choice){
		case 1:
		{
			Menu();
			break;
		}
		default:
		{break;
		}
	}
}
int Menu()
{
	// Declaring the Products in The vending machine///
	Machine p[10];
	p[0]={1,"Lays",50,10};
	p[1]={2,"Pepsi",20,10};
	p[2]={3,"Juice",20,10};
	p[3]={4,"Candy",10,10};
	p[4]={5,"Sting",30,10};
	p[5]={6,"Popcorn",25,10};
	p[6]={7,"Coffee",20,10};
	p[7]={8,"Kurkure",20,10};
	p[8]={9,"Nimko",10,10};
	p[9]={10,"Peanuts",15,10};
	
	int product_option,userMoney=0,remaining,rebuy,cashMultiple,userCash;
	int return_tenCoins,return_fiveCoins;
	
	//Declaring the Coins which will be used to Return cash to The costumer after buying//
	int available_five_coins=200,available_ten_coins=100;
	
	//printing the all products id,price,name,quantity//
	for(int i=0;i<10;i++){
		cout<<"Product ID= ";
		cout<<p[i].id;
		cout<<"\tName= "<<p[i].name;
		cout<<"\tPrice = "<<p[i].price;	
		cout<<endl;
	}
	cout<<"Please Enter the Cash (Must not greater than 100): ";
	cin>>userCash;
	
	// This if condition will be execitued if the User entered money is multiple of 5 and is not > 100 //
	if(userCash%5==0 && userCash<=100 && userCash>5){
		
		cout<<"How many multiple of "<<userCash<<" (if you Want to Enter More Cash Note:At least you Must Enter:1) ";
		cin>>cashMultiple;
		userMoney= userCash*cashMultiple;
		
		start:
		bool invalidity=0;
		cout<<"______________________________________";
		cout<<"\nPlease enter the Product ID to buy : ";
		cin>>product_option;
		if(product_option>10 || product_option<1){
			cout<<"\nInvalid Choice for the product";
			invalidity=1;
		}
		
		if((userMoney<p[product_option-1].price && invalidity==0)){
			cout<<"Cannot Buy -> Less Cash Entered for the Costly Product ";
		}
		else if(invalidity==0) {
			
			cout<<"Enjoy Your "<<p[product_option-1].name;
			userMoney-=p[product_option-1].price;
			if(userMoney>=5)
			{
				cout<<"\nTake out your Remaining Cash of Rs"<<userMoney;
				return_tenCoins=userMoney/10;
				return_fiveCoins=(userMoney%10/5);
				if(return_tenCoins>=1 && available_ten_coins>=1){
					cout<<"---> The Remaining Cash Includes "<<return_tenCoins<<" Coins of TEN ";
					available_ten_coins-=return_tenCoins;
				}
				if(return_fiveCoins>=1 && available_five_coins>=1){
					cout<<" And this includes "<<return_fiveCoins<<" Coins of FIVE";
					available_five_coins-=return_tenCoins;
				}
				if(userMoney>5 ){
					cout<<"\nOR \nBuy some more Products(Just press 1) \t Either you can Exit(just Press 0) : ";
					cin>>rebuy;
					if(rebuy==1 ){
					goto start ;}
				}
			}
		}
		if(invalidity==1){
			goto start;
		}
	}
	else{
		cout<<"Cash Not Accepatble.\nYou can take Your Cash Out";
	}
	
}
