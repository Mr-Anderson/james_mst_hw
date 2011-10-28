/*---------------------------------------------*\
|    CS284 Assignment 2 - Mutual Exclusion	|
|  Simulate a bank account shared between three	|
| people using multiple threads			|
|						|
| Adam Honse - March 7 2011			|
\*---------------------------------------------*/
#include <iostream>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int savings_account_balance = 0;
int checking_account_balance = 0;
pthread_mutex_t savings_lock;
pthread_mutex_t checking_lock;

bool withdraw(char accsel, int amount);
bool deposit(char accsel, int amount);
bool transfer(char accsel, int amount);

struct thread_data
{
	char * filename;
	char * name;
};

void *manage_account(void *threadarg)
{
	//Convert argument to thread data structure to get filename and name
	struct thread_data *my_data;
	my_data = (struct thread_data *) threadarg;

	//Seed the random number generator
	srand(time(0));

	//Open the given filename to read data
	ifstream file_in;
	file_in.open(my_data->filename);
	if(file_in.fail())
	{
		cout << "Failed to open file " << my_data->filename << "!" << endl;
		exit(1);
	}

	string buffer;
	
	//Read first line of file, loop until EOF reached
	getline(file_in,buffer);
	while(!file_in.eof())
	{
		//Extract the action and account from the string
		char action = buffer.c_str()[0];
		char accsel = buffer.c_str()[2];
		
		//Erase the used information from the string, leaving only the amount, convert it to int
		buffer.erase(0,4);
		int amount = atoi(buffer.c_str());
		
		//Chain of if statements checks for withdrawal, deposit, transaction, and invalid actions
		if(action == 'w')
		{
			if(accsel == '0')
			{
				if(withdraw(accsel, amount))
				{
					cout << my_data->name << ": " << "withdrawal from checking of $" << amount << " successful, new balance: $" << checking_account_balance << endl;
				}
				else
				{
					cout << my_data->name << ": " << "withdrawal from checking of $" << amount << " failed, new balance: $" << checking_account_balance << endl;
				}
			}
			else
			{
				if(withdraw(accsel, amount))
				{
					cout << my_data->name << ": " << "withdrawal from savings of $" << amount << " successful, new balance: $" << savings_account_balance << endl;
				}
				else
				{
					cout << my_data->name << ": " << "withdrawal from savings of $" << amount << " failed, new balance: $" << savings_account_balance << endl;
				}
			}
		}
		else if(action == 'd')
		{
			if(accsel == '0')
			{
				if(deposit(accsel, amount))
				{
					cout << my_data->name << ": " << "deposit to checking of $" << amount << " successful, new balance: $" << checking_account_balance << endl;
				}
				else
				{
					cout << my_data->name << ": " << "deposit to checking of $" << amount << " failed, new balance: $" << checking_account_balance << endl;
				}
			}
			else
			{
				if(deposit(accsel, amount))
				{
					cout << my_data->name << ": " << "deposit to savings of $" << amount << " successful, new balance: $" << savings_account_balance << endl;
				}
				else
				{
					cout << my_data->name << ": " << "deposit to savings of $" << amount << " failed, new balance: $" << savings_account_balance << endl;
				}
			}
		}	
		else if(action == 't')
		{
			if(accsel == '0')
			{
				if(transfer(accsel, amount))
				{
					cout << my_data->name << ": " << "transfer to checking of $" << amount << " successful, new balance: $" << checking_account_balance << endl;
				}
				else
				{
					cout << my_data->name << ": " << "transfer to checking of $" << amount << " failed, new balance: $" << checking_account_balance << endl;
				}
			}
			else
			{
				if(transfer(accsel, amount))
				{
					cout << my_data->name << ": " << "transfer to savings of $" << amount << " successful, new balance: $" << savings_account_balance << endl;
				}
				else
				{
					cout << my_data->name << ": " << "transfer to savings of $" << amount << " failed, new balance: $" << savings_account_balance << endl;
				}
			}
		}
		else
		{
			cout << my_data->name << ": " << "Invalid action was requested" << endl;
		}
		getline(file_in, buffer);
		usleep(10000*(rand()%100));
	}
	file_in.close();
	
	pthread_exit(NULL);
}

int main()
{
	//Create thread pointers
	pthread_t father, mother, daughter;

	//Create thread data structs
	thread_data father_data, mother_data, daughter_data;
	
	father_data.filename = "father.txt";
	father_data.name = "Bruce";

	mother_data.filename = "mother.txt";
	mother_data.name = "Jennifer";

	daughter_data.filename = "daughter.txt";
	daughter_data.name = "Jill";

	//Start threads
	if(pthread_create(&father, NULL, manage_account, &father_data))
	{
		cout << "ERROR" << endl;
	}
	if(pthread_create(&mother, NULL, manage_account, &mother_data))
	{
		cout << "ERROR" << endl;
	}
	if(pthread_create(&daughter, NULL, manage_account, &daughter_data))
	{
		cout << "ERROR" << endl;
	}
	pthread_join(father, NULL);
	pthread_join(mother, NULL);
	pthread_join(daughter, NULL);
}

bool withdraw(char accsel, int amount)
{
	if(accsel == '0')
	{
		//Withdraw from checking
		if(checking_account_balance > amount)
		{
			pthread_mutex_lock(&checking_lock);
			//There is enough money in the account, proceed with withdrawal
			checking_account_balance = checking_account_balance - amount;
			pthread_mutex_unlock(&checking_lock);
			return true;
		}
		else
		{
			//There is not enough money in the account, initiate a transfer from savings
			if(transfer(accsel, amount))
			{
				//Money has been transferred into checking, continue with withdrawal
				pthread_mutex_lock(&checking_lock);
				checking_account_balance = checking_account_balance - amount;
				pthread_mutex_unlock(&checking_lock);
				return true;
			}
			else
			{
				//Transfer failed, withdrawal was unsuccessful
				return false;
			}
		}
	}
	else
	{
		//Withdraw from savings
		if(savings_account_balance > amount)
		{
			pthread_mutex_lock(&savings_lock);
			//There is enough money in the account, proceed with withdrawal
			savings_account_balance = savings_account_balance - amount;
			pthread_mutex_unlock(&savings_lock);
			return true;
		}
		else
		{
			if(savings_account_balance >= 0)
			{
				pthread_mutex_lock(&savings_lock);
				//Allow the balance to go negative
				savings_account_balance = savings_account_balance - amount;
				pthread_mutex_unlock(&savings_lock);
				return true;
			}
			else
			{
				//There is not enough money in the account, the withdrawal has failed
				return false;
			}
		}
	}
}

bool deposit(char accsel, int amount)
{
	if(accsel == '0')
	{
		pthread_mutex_lock(&checking_lock);
		//Deposit to checking
		checking_account_balance = checking_account_balance + amount;
		pthread_mutex_unlock(&checking_lock);
		return true;
	}
	else
	{
		pthread_mutex_lock(&savings_lock);
		//Deposit to savings
		savings_account_balance = savings_account_balance + amount;
		pthread_mutex_unlock(&savings_lock);
		return true;
	}
}

bool transfer(char accsel, int amount)
{
	if(accsel == '0')
	{
		//Transfer from savings to checking
		if(savings_account_balance > amount)
		{
			//There is enough money to transfer
			pthread_mutex_lock(&savings_lock);
			savings_account_balance = savings_account_balance - amount;
			pthread_mutex_unlock(&savings_lock);
			pthread_mutex_lock(&checking_lock);
			checking_account_balance = checking_account_balance + amount;
			pthread_mutex_unlock(&checking_lock);
			return true;
		}
		else
		{
			//There is not enough money to transfer
			if(savings_account_balance > 0)
			{
				//Allow checking account to go negative, print warning
				pthread_mutex_lock(&savings_lock);
				savings_account_balance = savings_account_balance - amount;
				pthread_mutex_unlock(&savings_lock);
				pthread_mutex_lock(&checking_lock);
				checking_account_balance = checking_account_balance + amount;
				pthread_mutex_unlock(&checking_lock);
				cout << "Bank: Transfer from checking to savings resulted in negative balance" << endl;
				return true;
			}
			else
			{
				//Deny the transfer
				return false;
			}
		}
	}
	else
	{
		//Transfer from checking to savings
		if(checking_account_balance > amount)
		{
			//There is enough money to transfer
			pthread_mutex_lock(&checking_lock);
			checking_account_balance = checking_account_balance - amount;
			pthread_mutex_unlock(&checking_lock);
			pthread_mutex_lock(&savings_lock);
			savings_account_balance = savings_account_balance + amount;
			pthread_mutex_unlock(&savings_lock);
			return true;
		}
		else
		{
			//There is not enough money to transfer
			if(checking_account_balance > amount)
			{
				//Allow the savings account to go negative, print warning
				pthread_mutex_lock(&checking_lock);
				checking_account_balance = checking_account_balance - amount;
				pthread_mutex_unlock(&checking_lock);
				pthread_mutex_lock(&savings_lock);
				savings_account_balance = savings_account_balance + amount;
				pthread_mutex_unlock(&savings_lock);
				cout << "Bank: Transfer from savings to checking resulted in negative balance" << endl;
				return true;
			}
			else
			{
				//Deny the transfer
				return false;
			}
		}
	}
}
