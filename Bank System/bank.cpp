#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;

class Bank
{
	
	long long int accno;
	char name[20];
	char IFSC[12];
	char branch[40];
	int balance;
	public:
	
	Bank()
	{
		//cout<<"\nConstructor invoked!\n";
	}
	~Bank()
	{
		//cout<<"\nDestructor invoked!\n";
	}
	Bank** newentry(Bank**,int,long long int);
	void search(Bank**,int);
	void deposit(Bank**,int);
	void withdraw(Bank**,int);
	void checkbalance(Bank**,int);
	int check(Bank**,int);
	
};
int main()
{
	Bank bank,**c;
	
	
	int option,i=0;
	char ch;
	long long int acc=25980345648;
	do
	{
		printf("\n********************************\n");
		printf("1. New Entry\n");
		printf("2. Deposit\n");
		printf("3. Withdraw\n");
		printf("4. Search\n");
		printf("5. Check balance\n");
		printf("6. Exit\n");
		printf("\n********************************\n");
		
		printf("Enter your choice : ");
		scanf("%d",&option);
		
			switch(option)
			{
				case 1:{
					c=bank.newentry(c,i,acc);
					if(bank.check(c,i))
					{
						acc++;
						i++;
					}
					break;
				}
				case 2:{
					bank.deposit(c,i-1);
					break;
				}
				case 3:{
					bank.withdraw(c,i-1);
					break;
				}
				case 4:{
				    bank.search(c,i-1);
					break;
				}
				case 5:{
					bank.checkbalance(c,i-1);
					break;
				}
				case 6:{
					printf("\n\t*********Exiting*********\n\n");
					exit(0);
				}
				default :{
					printf("\n\tInvalid Option Enter Correct Option\n");
					break;
				}
			}
				
	}
	while(option!=6);
	
	return 0;
	
}

Bank** Bank::newentry(Bank **n,int i,long long int acc)
{
	cout<<"\nFill details about customer["<<i+1<<"]\n";
	n[i]=(Bank*)malloc(sizeof(Bank));
	
	int j=0,amount,flag=0;
	printf("\nEnter the name : ");
	scanf("\n");
	scanf("%[^\n]%*c",&n[i]->name);
		
	  for(j=0;n[i]->name[j]!='\0';j++)
	  {
		  if(j==0||(n[i]->name[j-1]==32&&n[i]->name[j]!=32))
		  {
			  if(n[i]->name[j+1]!=32&&n[i]->name[j+2]!=32)
			  {
				  if(n[i]->name[j]>=97&&n[i]->name[j]<=122)
				  {
					  n[i]->name[j]=n[i]->name[j]-32;
				  }
			  }
		  }
	  }
	printf("\nEnter IFSC code : ");
	scanf("%s",&n[i]->IFSC);
	printf("\nEnter Branch name : ");
	scanf("\n");
	scanf("%[^\n]%*c",&n[i]->branch);
	for(j=0;n[i]->branch[j]!='\0';j++)
	  {
		  if(j==0||(n[i]->branch[j-1]==32&&n[i]->branch[j]!=32))
		  {
			  if(n[i]->branch[j+1]!=32&&n[i]->branch[j+2]!=32)
			  {
				  if(n[i]->branch[j]>=97&&n[i]->branch[j]<=122)
				  {
					  n[i]->branch[j]=n[i]->branch[j]-32;
				  }
			  }
		  }
	  }
	j=0;
	do
	{
		printf("\nEnter the balance (Minimum 500 balance required!) : ");
     	scanf("%d",&amount);
		if(amount>=500)
		{
			n[i]->balance=amount;
			n[i]->accno=acc;
			printf("\nAccount number is : %lld\n",acc);
			flag=1;
		}
		else if(j==2)
		{
			n[i]->balance=0;
			break;
		}
		else
		{
			printf("\n\tAmount entered is less than 500!!\n");
			j++;
		}
	}
	while(flag==0);
	return n;
}

int Bank::check(Bank**n,int i)
{
	if(n[i]->balance!=0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Bank::search(Bank **s,int k)
{
	long long int accno;
	int i=0,flag=0;
	printf("Enter account number : ");
	scanf("%lld",&accno);
	while(k>=0)
	{    
        if(s[k]->accno==accno)
		{ 
           	flag=1;
	        break;
		}
		else
		{  k--;}
    }
	if(flag==1)
	{
	    printf("\n********************************************\n");
		printf("\n\tAccount number : %lld\n",s[k]->accno);
		printf("\tAccount Holder name : %s\n",s[k]->name);
		printf("\tIFSC Code : %s\n",s[k]->IFSC);
		printf("\tBranch name : %s\n",s[k]->branch);
		printf("\tBalance : %d\n",s[k]->balance);
		printf("\n********************************************\n");
	}
	else
	{
		printf("\n\tNo Account with the entered number\n\n");
	}
}

void Bank::deposit(Bank **d,int k)
{
	long long int accno=0;
	int flag=0;
	printf("Enter account number in which you want to deposit the amount : ");
	scanf("%lld",&accno);
	while(k>=0)
	{    
        if(d[k]->accno==accno)
		{ 
           	flag=1;
	        break;
		}
		else
		{  k--;}
    }
	if(flag==1)
	{
	int amount=0;
	printf("\nEnter the amount you want to deposit : ");
	scanf("%d",&amount);
	d[k]->balance=d[k]->balance+amount;
	printf("\n\tAmount deposited successfully!\n");
	}
	else
	{
		printf("\n\tEntered Account doesn't exit\n");
	}
}

void Bank::withdraw(Bank **w,int k)
{
	long long int accno=0;
	int a=0,amount=0,flag=0;;
	printf("Enter account number in which you want to deposit the amount : ");
	scanf("%lld",&accno);
	while(k>=0)
	{    
        if(w[k]->accno==accno)
		{ 
           	flag=1;
	        break;
		}
		else
		{  k--;}
    }
	if(flag==1)
	{
		printf("\nEnter the amount you want to withdraw : ");
		scanf("%d",&amount);
		
		a=w[k]->balance-amount;
		if(a>=500)
		{
			w[k]->balance=a;
			printf("\n\tAmount withdrawed!\n");
		}
		else
		{
			printf("\n\tCannot withdraw the amount!!\n\tMinimum 500 amount to be maintained\n");
		}
	}
	else
	{
		printf("\n\tEntered Account doesn't exit\n");
	}
	
}

void Bank::checkbalance(Bank **b,int k)
{
	long long int accno=0;
	int a=0,amount=0,flag=0;;
	printf("Enter account number in which you want to deposit the amount : ");
	scanf("%lld",&accno);
	while(k>=0)
	{    
        if(b[k]->accno==accno)
		{ 
           	flag=1;
	        break;
		}
		else
		{  k--;}
    }
	
	if(flag==1)
	{
		printf("\n\tBalance is : %d\n",b[k]->balance);
	}
    else
	{
		printf("\n\tEntered Account doesn't exit\n");
	}
}