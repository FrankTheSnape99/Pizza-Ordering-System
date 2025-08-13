/*Francis Snape, 21051145*/

#include <iostream> 
using namespace std;

//function references
void newOrder();
void setCredits();
void recentOrders();
void done();

double credits = 0.0;
double additionalCredits = 0.0;

int main()
{
	// initalize the userOrder variable so the user can answer.
	string userOrder;
	//initialize userExtras for any toppings they want.
	string userToppings;
	// itiliaze the orderComplete, so the user can tell the program if they're done ordering or not.
	string orderComplete;
	//initialize choice to select main menu option.
	int choice;
	//initialize and set amount of toppings
	int toppings;
	//sets the menu to always true
	bool menu = true;

	//adds the pizzas size price with the toppings price to get the total price.
	double totalPrice = 0.0;

	//sets the size of the pizzas price and the toppings price to 0.0
	double pizzaSizePrice = 0.0;
	double toppingsPrice = 0.0;

	//initalize and set prices for toppings
	double cheesePrice = 1.50;
	double hamPrice = 0.8;
	double mushroomPrice = 0.50;
	double onionPrice = 0.40;
	double peppersPrice = 0.80;
	double pepperoniPrice = 1.0;

	//initializes pizzaSize as a string so when the size, small, medium, large is selected it recognises characters. 
	string pizzaSize;

	cout << "" << endl;
	cout << "Hello!	Welcome to the Student Centre cafe" << endl;
	cout << "How can i help you today?" << endl;
	cout << "" << endl;

	cout << "1. New Order" << endl;
	cout << "2. Set Credits" << endl;
	cout << "3. Recent orders" << endl;
	cout << "" << endl;
	cout << "Enter selection: " << endl;
	cout << "> ";
	cin >> choice;
	cout << "" << endl;

	//switch statement for each option in the main menu.
	switch (choice)
	{
	case 1:
		if (credits < 20.0) // if the users credits is less than 20.0 they cannot start an order. and directs them to add credits.
		{
			cout << "Insufficient credits to place an order, add credits first." << endl;
			setCredits();
		}
		else if (credits > 20.0) //if user has more than 20 credits they are directed to start the order.
		{
			newOrder();
		}
		break;
	case 2:
		setCredits();
		break;
	case 3:
		recentOrders();
		break;
	default:
		cout << "Your selection is incorrect. Try again..." << endl;
		cout << "" << endl;
		main();

	}
	return 0;
}

void newOrder()
{
	//All strings for each text output
	string userOrder;
	string pizzaSize;
	string userToppings;
	string wantToAdd; //initialization of string to check if user wants to add credits.
	string orderComplete;
	string allToppings = "";

	int selectedToppings = 0;

	double totalPrice;
	double toppingsPrice = 0.0;
	double pizzaSizePrice = 0.0;

	double cheesePrice = 1.50;
	double hamPrice = 0.80;
	double mushroomPrice = 0.50;
	double onionPrice = 0.40;
	double peppersPrice = 0.80;
	double pepperoniPrice = 1.0;

	do
	{
		cout << "New orders: " << endl;

		cout << "What pizza would you like today? " << endl;
		cout << "Pizza menu:" << endl;
		cout << "" << endl;
		cout << "**********************" << endl;
		cout << "Pepperoni" << endl;
		cout << "Margherita" << endl;
		cout << "Veggie Supreme" << endl;
		cout << "Tuna & Sweetcorn" << endl;
		cout << "**********************" << endl;

		cout << "" << endl;

		//allows the user to enter what pizza they want
		cout << "I'll take a ";
		cin >> userOrder;

		//whilst the user types anything but whats in the menu, it outputs an invalid option message
		while (!(userOrder == "margherita" || userOrder == "pepperoni" || userOrder == "tuna" || userOrder == "veggie"))
		{
			cout << "Invalid option, please try again..." << endl;
			cout << "I'll take a ";
			cin >> userOrder;
		}

		//if the user order entered matches one of the menu options.. run through this code
		if (userOrder == "pepperoni" || userOrder == "margherita" || userOrder == "veggie" || userOrder == "tuna") //if margherita is selected it runs through the code inside the if.
		{
			cout << userOrder << ", will that be small, medium or large" << endl;

			cout << "" << endl;
			cout << "> ";
			cin >> pizzaSize;

			//whilst the pizza size input is NOT small, medium or large, give error message.
			while (!(pizzaSize == "small" || pizzaSize == "medium" || pizzaSize == "large"))
			{
				cout << "Invalid pizza size, please select 'small', 'medium' or 'large'" << endl;
				cout << "> ";
				cin >> pizzaSize;
			}
			cout << "Great, now add your toppings? " << endl;
			cout << "Toppings menu:" << endl;
			cout << "" << endl;
			cout << "To add just 1 topping, type 'done' after adding your first topping." << endl;
			cout << "" << endl;

			cout << "**********************" << endl;
			cout << "ham" << endl;
			cout << "mushroom" << endl;
			cout << "pepperoni" << endl;
			cout << "peppers" << endl;
			cout << "onion" << endl;
			cout << "cheese" << endl;
			cout << "**********************" << endl;

			//while the true, output whats inside the while loop.
			while (true)
			{
				cout << "" << endl;
				cout << "> ";
				cin >> userToppings;

				if (userToppings == "done")
				{
					if (selectedToppings == 0)
					{
						cout << "You must select at least 1 topping" << endl;
						continue;
					}
					else
					{
						break;
					}
				}

				//whilst the input for userToppings is NOT one of the options on the menu, give error message.
				while (!(userToppings == "ham" || userToppings == "mushroom" || userToppings == "pepperoni" || userToppings == "peppers" || userToppings == "onion" || userToppings == "cheese"))
				{
					cout << "Invalid toppings, please choose an option from the menu..." << endl;
					cout << "> ";
					cin >> userToppings;
				}

				//check if its not the first topping selected.
				if (selectedToppings > 0)
				{
					allToppings += " and "; //if its not, then put and after first topping.
				}

				//adds the current toppings to the list.
				allToppings += userToppings;
				//increments the amount of toppings.
				selectedToppings++;

				//checks if theres been two toppings selected.
				if (selectedToppings == 2)
				{
					break; // if 2 are selected, exit loop.
				}

				//if the users extra is cheese for example, it takes the extras price which is constantly set to 0.0 and adds it to the cheeses price.
				if (userToppings == "ham")
					toppingsPrice += hamPrice;
				if (userToppings == "mushroom")
					toppingsPrice += mushroomPrice;
				if (userToppings == "pepperoni")
					toppingsPrice += pepperoniPrice;
				if (userToppings == "peppers")
					toppingsPrice += peppersPrice;
				if (userToppings == "onion")
					toppingsPrice += onionPrice;
				if (userToppings == "cheese")
					toppingsPrice += cheesePrice;
			}
		}

		//if the user wants a small pizza then it goes through the code
		if (pizzaSize == "small")
		{
			cout << "" << endl;
			cout << "1 small " << userOrder << " with " << allToppings << " coming up " << endl;
			pizzaSizePrice = 5.0; // cost of a small pizza
		}
		else if (pizzaSize == "medium")
		{
			cout << "" << endl;
			cout << "1 medium " << userOrder << " with " << allToppings << " coming up " << endl;
			pizzaSizePrice = 8.50; // cost of medium pizza
		}
		else if (pizzaSize == "large")
		{
			cout << "" << endl;
			cout << "1 large " << userOrder << " with " << allToppings << " coming up " << endl;
			pizzaSizePrice = 10.25; //cost of large pizza
		}
		else
		{
			cout << "Invalid size of pizza." << endl; // if anything but small/medium/large pizza is entered it shows the error message.
		}

		if (orderComplete != "yes" || orderComplete != "no")
		{
			cout << "" << endl;
			cout << "Is that everything?" << endl;
			cout << "yes/no: ";
			cin >> orderComplete;
		}

		//total price is calculated by adding the pizza size price to the selected toppings price.
		totalPrice = pizzaSizePrice + toppingsPrice;
		cout << "Your total is $" << totalPrice << endl;

		//if the users credits is less than the total price of the order, it says they have insufficient funds
		if (credits < totalPrice)
		{
			cout << "Insufficient funds, do you want to add credits? yes/exit" << endl;
			cout << "> ";
			cin >> wantToAdd;

			//if the user selects yes to add credits, they are directed to the set credits function.
			if (wantToAdd == "yes")
			{
				setCredits();
				//credits += additionalCredits;
			}
			else if (wantToAdd == "exit")
			{
				done();
			}

			//whilst want to add input is not yes or exit, error shown.
			while (!(wantToAdd == "yes" || wantToAdd == "exit"))
			{
				cout << "Invalid input, please type yes or no..." << endl;
				cout << "> ";
				cin >> wantToAdd;
			}
		}
		else
		{
			//takes the totalPrice amount off of the amount of credits.
			credits -= totalPrice;

			cout << "Purchase complete!" << endl;
			cout << "" << endl;
			cout << "Remaining credits = $" << credits << endl;
			done();
		}


	} while (orderComplete != "yes" /*anymore*/);

}

//function for setting credits.
void setCredits()
{
	cout << "Set Credits: " << endl;
	//shows current credits
	cout << "Current credits: $" << credits << endl;

	do
	{
		cout << "How many credits would you like to add: $";
		cin >> additionalCredits;

		//if credit total is less than 0, try again.
		if (additionalCredits < 0)
		{
			cout << "Invalid input. Please try again." << endl;
		}
	} while (additionalCredits < 0);

	//means, credits = credits + additionalCredits. it adds whatever amount the user types to the credits value.
	credits += additionalCredits;
	cout << "Credits updated. Total credits now: $" << credits << endl;
	main();
}

void recentOrders()
{
	cout << "Recent Order: " << endl;
}

//function to check if the user is done with everything and wants to end the program.
void done()
{
	string orderDone;

	cout << "Is that everything?" << endl;

	cin >> orderDone;

	if (orderDone == "yes")
	{

	}
	else if (orderDone == "no")
	{
		main();
	}
}