//Jun Lin Wu
//This program display the food menu and calculate the costs.
//Dec 06,2018

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

//Global constant
const int  deAnzaBurger=1, baconCheese=2, mushroomSwiss=3,
westernBurger=4, donCaliBurger=5, quitMenu=6;//Sign choice to the item

//Function prototype
void showMenu(double burgerPrice[]);
void taxAndBill(string, double);
void printBill(int, int,string, double);

int main()
{

    double beforeTax, taxAmount, totalAfterTax;//Declared the tax amount

    int choice, numberOfBurger;

    string studentOrStaff;

    //sign burger prices into an array
    double burgerPrice[]={5.25,5.75,5.95,5.95,5.95};

    //Set up the number output format
    cout<< fixed << showpoint << setprecision(2);
    do
    {
        //call showMenu function
        showMenu(burgerPrice);

        cin>>choice;

        //Display a invalid choice
        while(choice<deAnzaBurger||choice>quitMenu)
        {
            cout<<"\nPlease enter a valid menu choice: ";
            cin>>choice;
        }
        if(choice!=quitMenu)
        {
            //Ask user how many they want
            cout<<"\nHow many burger do you want? ";
            cin>>numberOfBurger;

            while(numberOfBurger<0)
            {
                //Respond if user enter a invalid number
                cout<<"\nPlease enter a number that's greater than 0: ";
                cin>>numberOfBurger;
            }
            //Respond to user's choice
            switch(choice)
            {
                case deAnzaBurger: beforeTax=numberOfBurger*burgerPrice[0];
                break;
                case baconCheese: beforeTax=numberOfBurger*burgerPrice[1];
                break;
                case mushroomSwiss: beforeTax=numberOfBurger*burgerPrice[2];
                break;
                case westernBurger: beforeTax=numberOfBurger*burgerPrice[3];
                break;
                case donCaliBurger: beforeTax=numberOfBurger*burgerPrice[4];
                break;
            }
            //Ask if user is student or staff
            cout<<"\nPlease enter you are a student or staff: ";
            cin>>studentOrStaff;
            //Ask user to enter again if they didn't enter "student" or "staff"
            while(studentOrStaff!="student"&&studentOrStaff!="staff")
            {
                cout<<"\nPlease enter student or staff: ";
                cin>>studentOrStaff;
            }
            //Display the information of the order
            cout<<"\nYou ordered order #"<<choice<<".";
            cout<<"\nYou ordered "<<numberOfBurger<<" order #"<<choice<<".";
            cout<<"\nYour order cost $"<<beforeTax<<" before tax.";
            //Call the taxAndBill to calculate the bill
            taxAndBill(studentOrStaff,beforeTax);

            //call printBill function
            printBill(choice,numberOfBurger, studentOrStaff,beforeTax);
            }
            cout<<"\nThank You!\n\n";
    }
    while(choice!=quitMenu);

        return 0;
}

//This function show the burger menu to user
void showMenu(double burgerPrice[])
{
    cout<<"\t\tDe Anza Burger Club Menu.\n";
    cout<<"1. De Anza Burger - "<<burgerPrice[0];
    cout<<"\n2. Bacon Cheese - "<<burgerPrice[1];
    cout<<"\n3. Mushroom Swiss - "<<burgerPrice[2];
    cout<<"\n4. Western Burger - "<<burgerPrice[3];
    cout<<"\n5. Don Cali Burger - "<<burgerPrice[4];
    cout<<"\n6. Quit the Menu\n";
    cout<<"\nEnter the menu number you want(1,2,3,4,5) or quit the menu(6): ";
}




//This function calculate the tax amount and the total bill based on user
//is student or staff
void taxAndBill(string studentOrStaff,double beforeTax)
{
    double taxAmount;
    double totalAfterTax;

    //Calculate the tax and bill based on they are student or staff
    if(studentOrStaff=="student")
        {
            cout<<"\nYou don't need to pay tax.\n";
            taxAmount=0;
            totalAfterTax=beforeTax+taxAmount;
            cout<<"\nYour tax is $"<<taxAmount<<".";
            cout<<"\nYour total bill is $"<<totalAfterTax<<".\n";


        }
    else if(studentOrStaff=="staff")
        {
            cout<<"\nYou have to pay tax amount based on 9 percent tax.\n";
            taxAmount=beforeTax*0.09;
            totalAfterTax=beforeTax+taxAmount;
            cout<<"\nYour tax is $"<<taxAmount<<".";
            cout<<"\nYour total bill is $"<<totalAfterTax<<".\n";

        }
}

//This function print bill to a random number file between 1000 to 2000
void printBill(int choice, int numberOfBurger, string studentOrStaff, double beforeTax)
{
    ofstream outputFile;
    string fileName;
    double taxAmount;
    double totalAfterTax;

    //Range of document number
    const int MIN_VALUE = 1000;
    const int MAX_VALUE = 2000;

    int randomNum;//User's document number

    unsigned seed = time(0);//Get the system time
    srand(seed);//Seed the random number generator
    randomNum = (rand()%(MAX_VALUE - MIN_VALUE+1))+MIN_VALUE;//Get a random document number in the range

    fileName = to_string(randomNum) + ".txt";
    //Open an output file
    outputFile.open(fileName);

    cout<<"Your receipt# is "<<randomNum<<endl;

    //Write the output to output.txt
    outputFile<<"receipt #"<<randomNum<<endl;
    outputFile<<"\nYou ordered order #"<<choice<<".";
    outputFile<<"\nYou ordered "<<numberOfBurger<<" order #"<<choice<<".";
    outputFile<<"\nYour order cost $"<<fixed<<setprecision(2)<<beforeTax<<" before tax.\n";

     if(studentOrStaff=="student")
        {
            taxAmount=0;
            totalAfterTax=beforeTax+taxAmount;
            outputFile<<"\nYour tax is $"<<fixed<<setprecision(2)<<taxAmount<<".";
            outputFile<<"\nYour total bill is $"<<fixed<<setprecision(2)<<totalAfterTax<<".\n";


        }
    else if(studentOrStaff=="staff")
        {
            taxAmount=beforeTax*0.09;
            totalAfterTax=beforeTax+taxAmount;
            outputFile<<"\nYour tax is $"<<taxAmount<<".";
            outputFile<<"\nYour total bill is $"<<totalAfterTax<<".\n";

        }
    //Close output file
    outputFile.close();
}

/*
    Output 1

  De Anza Burger Club Menu.
1. De Anza Burger - 5.25
2. Bacon Cheese - 5.75
3. Mushroom Swiss - 5.95
4. Western Burger - 5.95
5. Don Cali Burger - 5.95
6. Quit the Menu

Enter the menu number you want(1,2,3,4,5) or quit the menu(6): 3

How many burger do you want? 5

Please enter you are a student or staff: student

You ordered order #3.
You ordered 5 order #3.
Your order cost $29.75 before tax.
You don't need to pay tax.

Your tax is $0.00.
Your total bill is $29.75.
Your receipt# is 1842

Thank You!

                De Anza Burger Club Menu.
1. De Anza Burger - 5.25
2. Bacon Cheese - 5.75
3. Mushroom Swiss - 5.95
4. Western Burger - 5.95
5. Don Cali Burger - 5.95
6. Quit the Menu

Enter the menu number you want(1,2,3,4,5) or quit the menu(6): 6

Thank You!

    Output 2
 De Anza Burger Club Menu.
1. De Anza Burger - 5.25
2. Bacon Cheese - 5.75
3. Mushroom Swiss - 5.95
4. Western Burger - 5.95
5. Don Cali Burger - 5.95
6. Quit the Menu

Enter the menu number you want(1,2,3,4,5) or quit the menu(6): 2

How many burger do you want? 3

Please enter you are a student or staff: staff

You ordered order #2.
You ordered 3 order #2.
Your order cost $17.25 before tax.
You have to pay tax amount based on 9 percent tax.

Your tax is $1.55.
Your total bill is $18.80.
Your receipt# is 1302

Thank You!

                De Anza Burger Club Menu.
1. De Anza Burger - 5.25
2. Bacon Cheese - 5.75
3. Mushroom Swiss - 5.95
4. Western Burger - 5.95
5. Don Cali Burger - 5.95
6. Quit the Menu

Enter the menu number you want(1,2,3,4,5) or quit the menu(6): 6

Thank You!
*/



