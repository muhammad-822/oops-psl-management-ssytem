
#include<fstream>
#include <iostream>
#include<conio.h>
#include <string>
#include<iomanip>
using namespace std;

struct Customer {
    string name;
    string contact;
    string address;
}; 


void displayMenu();
void takeOrder(string order[], int amount[], double price[], int &orderCount, double &total);
void saveOrderToFile(Customer &customer, string order[], int amount[], double price[], int &orderCount, double &total);


void billingSummary(Customer &customer, string order[], int amount[], double price[], int &orderCount, double &total);
void readPreviousOrders();
void askPaymentMethod();
void askpaymentmethod();

int main() {
    char continueProgram = 'Y';

    while ((continueProgram == 'Y')||(continueProgram == 'y')) {
       Customer customer;
        string order[50]; 
        int amount[50];   
        double price[50]; 
        int orderCount = 0;
        double total = 0.0;
        system("cls");
        
        cout<<"===================================================================================================================="<<endl;
        cout<<"     				       WELCOME TO THE STREET AND SPICE RESTAURANT"<<endl;
        cout<<"================================================================================================================="<<endl;
        cout << "==>   ENTER YOUR FULL NAME  :";
        getline(cin, customer.name);
        cout << "==>   ENTER CONTACT NUMBER  :";
        getline(cin, customer.contact);
        cout << "==>   Enter YOUR ADDRESS    :";
        getline(cin, customer.address);
        system("cls");
    
        displayMenu();
        takeOrder(order, amount, price, orderCount, total);

    
        billingSummary(customer, order, amount, price, orderCount, total);
       saveOrderToFile(customer, order, amount, price, orderCount, total);

    cout << "==>DO WANT TO ORDER SOME THING MORE FROM OUR \n RESTAURANT AGAIN FOR ORDERING OUR MENUE? (y/n): ";
    cin >> continueProgram;
    cin.ignore(); 
    
       
    }

    cout << "\n===================================================================" << endl;
cout << "        ==>  THANK YOU FOR CHOOSING STREET & SPICE             " << endl;
cout<<endl;
cout << "        ==> WE HOPE YOU ENJOY YOUR MEAL! HAVE A GREAT DAY!            " << endl;
cout << "===================================================================" << endl;
cout << "\nPrevious Orders:\n";
    readPreviousOrders(); // Read previous orders from the file
    return 0;
}

void displayMenu() {
	system("cls");
	cout << "   =========================================================="<<endl;
    cout << "   |	    	STREET AND SPICE RESTAURANT MENU            " << endl;
    cout << "   =========================================================="<<endl;
    cout << "   |                           PIZZAS:                         " << endl;   
    cout << "   =========================================================="<<endl;
    cout << "   |ITEM NUM"<<"   |     ITEM FLAVOR     | "<<"    ITEM PRICE "<<endl; 
    cout << "   =========================================================="<<endl;
    cout << "   |  1.   "<<"    | Chicken Fajita      | "<<"    1000Rs.    "<<endl;
    cout << "   |  2.   "<<"    | PERI PERI           | "<<"    1200Rs.    "<<endl;
    cout << "   |  3.   "<<"    | BUTTER CHICKEN      | "<<"    1500Rs.            "<<endl;
     cout << "  =========================================================="<<endl;
    cout << "   |                           BURGERS:                        " << endl;
    cout << "   =========================================================="<<endl;
    cout << "   |ITEM NUM"<<"   |     ITEM FLAVOR     | "<<"    ITEM PRICE "<<endl;
    cout << "   =========================================================="<<endl; 
    cout << "   |  4.   "<<"    | ZINGER              | "<<"    500Rs.     "<<endl;
    cout << "   |  5.   "<<"    | BEAF                | "<<"    900Rs.     "<<endl;
    cout << "   |  6.   "<<"    | CHICKEN             | "<<"    700Rs.             "<<endl;
     cout << "  =========================================================="<<endl;
    cout << "   |                            DRINKS:                 " << endl;
    cout << "   =========================================================="<<endl;
    cout << "   |ITEM NUM"<<"   |     ITEM FLAVOR     | "<<"    ITEM PRICE "<<endl;
    cout << "   =========================================================="<<endl; 
    cout << "   |  7.   "<<"    | LEMON               |" <<"    200Rs.     "<<endl;
    cout << "   |  8.   "<<"    | COLA                | "<<"    200Rs.     "<<endl;
    cout << "   |  9.   "<<"    | MARINDA             | "<<"    200Rs.             "<<endl;
     cout << "  =========================================================="<<endl;
    cout << "   |                            SANDWICH:               " << endl;
    cout << "   =========================================================="<<endl;
    cout << "   |ITEM NUM"<<"   |     ITEM FLAVOR     | "<<"    ITEM PRICE "<<endl;
    cout << "   =========================================================="<<endl;	 
    cout << "   |  10.   "<<"   | CLUB                | "<<"     500Rs.    "<<endl;
    cout << "   |  11.   "<<"   | CHICKEN CRISPY      | "<<"     600Rs.    "<<endl;
    cout << "   |  12.   "<<"   | EXTREME VEG         | "<<"     700Rs.            "<<endl;
    cout << "   =========================================================="<<endl;  
    
   
}

void takeOrder(string order[], int amount[], double price[], int &orderCount, double &total) {
    char choice;
    do {
       int item;
         do
         { 
         cout << "==>ENTER THE ITEM NUMBER TO ADD TO YOUR ORDER(1-12): ";
        
        cin >> item;
        cin.ignore(); 
       if (item < 1 || item > 12) {
           cout << "Invalid item number. Please try again.\n";
        }
    } while ((item < 1 )|| (item > 12));

        int quantity;
        do { 
         cout << "==>ENTER THE QUANTITY OF YOUR SELECTED ITEM: ";
        
        cin >> quantity;
        cin.ignore(); 
       if (quantity < 1 ) {
           cout << "Invalid item number. Please try again.\n";
        }
    } while (quantity < 1 );
        switch (item) {
            case 1: order[orderCount] = "CHICKEN FAJITA"; 
			price[orderCount] = 1000.0;
			 total += 1000.0 * quantity;
			  break;
            case 2: order[orderCount] = "PERI PERI";
			 price[orderCount] =1200.0 ; 
			 total += 1200.0 * quantity;
			  break;
            case 3: order[orderCount] = "BUTTER CHICKEN";
			 price[orderCount] = 1500.0;
			  total += 1500.0 * quantity;
			   break;
            case 4: order[orderCount] = "ZINGER";
			 price[orderCount] = 500.0;
			  total += 500.0 * quantity;
			   break;
            case 5: order[orderCount] = "BEAF"; 
			price[orderCount] = 900.0; 
			total += 900.0 * quantity; 
			break;
            case 6: order[orderCount] = "CHICKEN"; 
			price[orderCount] = 700.0;
			 total += 700.0 * quantity;
			  break;
            case 7: order[orderCount] = "LEMON";
			 price[orderCount] = 200.0; 
			 total += 200.0 * quantity;
			  break;
            case 8: order[orderCount] = "COLA";
			 price[orderCount] = 200.0;
			  total += 200.0 * quantity;
			   break;
            case 9: order[orderCount] = "MARINDA";
			 price[orderCount] = 200.0; 
			 total += 200.0 * quantity;
			  break;
            case 10: order[orderCount] = "CLUB"; 
			price[orderCount] = 500.0;
			 total += 500.0 * quantity;
			  break;
            case 11: order[orderCount] = "CHICKEN CRISPY";
			 price[orderCount] = 600.0;
			  total += 600.0 * quantity;
			   break;
            case 12: order[orderCount] = "EXTREME VEG";
			 price[orderCount] = 700.0; 
			 total += 700.0 * quantity;
			  break;
           
           
		    
			
        }

        amount[orderCount] = quantity;
        orderCount++;

        cout << "==>DO YOU WANT TO ADD ANOTHER ITEM IN YOUR ORDER? (y/n): ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

    } while (choice == 'y' || choice == 'Y');
}

void billingSummary(Customer &customer, string order[], int amount[], double price[], int &orderCount, double &total) {
	system("cls"); 
	
	
	
    cout<<"===================================================================================================================="<<endl;
    cout<<"     				       BILLING SUMMARY"<<endl;
    cout<<"================================================================================================================="<<endl;
    cout<<"===================================================================================================================="<<endl;
    cout<<"     				       CUSTOMER DETAIL"<<endl;
    cout<<"================================================================================================================="<<endl;
    cout << "==>Customer Name     : " << customer.name << endl;
    cout << "==>Contact           : " << customer.contact << endl;
    cout << "==>Address           : " << customer.address << endl;

    cout<<"===================================================================================================================="<<endl;
    cout<<"     				       ORDER DTAIL"<<endl;
    cout<<"================================================================================================================="<<endl;
   cout<<setw(20)<<" ITEM NAME"<<"|"<<setw(10)<< "QUANTITY"<<"|" <<setw(10) <<" PRICE" <<"|"<<setw(20) <<"PRICE*QUANTITY"<< endl;
   cout<<"================================================================================================================="<<endl;
	for (int i = 0; i < orderCount; i++) {
        cout<<setw(20)<< order[i]<<"|"<<setw(10)<< amount[i]<<"|" <<setw(10) << price[i] <<"|"<<setw(20) << price[i] * amount[i] << endl;
    cout<<"================================================================================================================="<<endl;
    }

    cout << "====Total: $====>" << total << endl;
    cout<<endl;
   cout << "====>DO YOU WANT HOME DELIVERY? (y/n): ";
    char delivery;
    cin >> delivery;
    cin.ignore(); // Clear input buffer

    if (delivery == 'y' || delivery == 'Y') {
    
        askPaymentMethod();
        
    } else {
        
        askpaymentmethod();
    }
   
    cout << "===========================\n";
     
}
   
void saveOrderToFile(Customer &customer, string order[], int amount[], double price[], int &orderCount, double &total) {
    ofstream outFile("AGREE.txt", ios::app); // Open file in append mode
    if (outFile.is_open()) {
        outFile << "===================================================================" << endl;
        outFile << "Customer Name: " << customer.name << endl;
        outFile << "Contact      : " << customer.contact << endl;
        outFile << "Address      : " << customer.address << endl;
        outFile << "-------------------------------------------------------------------" << endl;
        outFile << setw(20) << "ITEM NAME" << "|" << setw(10) << "QUANTITY" << "|" << setw(10) << "PRICE" << "|" << setw(20) << "PRICE*QUANTITY" << endl;
        for (int i = 0; i < orderCount; i++) {
            outFile << setw(20) << order[i] << "|" << setw(10) << amount[i] << "|" << setw(10) << price[i] << "|" << setw(20) << price[i] * amount[i] << endl;
        }
        outFile << "-------------------------------------------------------------------" << endl;
        outFile << "Total: " << total << endl;
        outFile << "===================================================================" << endl;
        outFile.close();
    } else {
        cout << "Unable to open file for writing.\n";
    }
}
void readPreviousOrders() {
	system("cls");
    ifstream inFile("AGREE.txt"); // Open file in read mode
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open file for reading.\n";
    }
}
   



void askPaymentMethod() {
	system("cls");
	cout << "===>HOME DELIVERY WILL BE ARRANGED AFTER PAYING BILL.\n";

	
	cout<<"===>PLEASE SEND YOUR LOCTION OR ADDRESS AT \n +9387832342"<<endl;
    cout<<"===================================================================================================================="<<endl;
    cout<<"     				       PAYMENT OPTION"<<endl;
    cout<<"================================================================================================================="<<endl;
    cout << "                SELECT YOUR PREFFERED PAYMENT OPTION:\n";
     cout<<"================================================================================================================="<<endl;
    cout<<setw(10)<<"CHOICE"<<"|"<<setw(30)<<"METHODS"<<endl;
     cout<<"================================================================================================================="<<endl;
    cout <<setw(10)<< "1."<<"|"<<setw(30)<<" EASYPAISA AND JAZZCASH\n";
    cout <<setw(10 )<<"2."<<"|"<<setw(30)<<" CASH ON DELIVERY\n";
     cout<<"================================================================================================================="<<endl;
   

    int paymentChoice;
    cout << "==>ENTER CHOICE 1 AND 2 : ";
    cin >> paymentChoice;
    cin.ignore(); // Clear the input buffer

    switch (paymentChoice) {
        case 1:
        	 cout<<"===================================================================================================================="<<endl;
    cout<<"     				       RULES FOR PAYEMENT "<<endl;
    cout<<"================================================================================================================="<<endl;
            cout << "==>SEND THE PAYMENT ON THE NUMBER:+9223456789" << endl;
            cout << "==> ONCE THE PAYMENT IS COMPLETE" <<endl;
             cout <<"==> SEND THE NOTIFICATION MESSAGE ON WHATSAPP:+923456789" <<endl;
            cout<<"  ==>OTHERWISE YOUR ORDER WILL NOT BE DELIVERED"<<endl;
            break;

        case 2:
            cout<<"==>GIVE PAYMENT TO THE DELIVERY BOY AND TAKE YOUR ORDER"<<endl;
            break;

        default:
            cout << "\nINVALID CHOICE ;SELECT  1 or 2.\n";
            // Optionally, you can recall the function to prompt again
            askPaymentMethod();
           
    }
    cout << "=================================================" << endl;
}
void askpaymentmethod() { 
    system("cls");
    cout << "===>YOU CAN COLLECT YOUR ORDER FROM COUNTER AFTER PAYING BILL.\n";
    cout<<"===================================================================================================================="<<endl;
    cout<<"     				       PAYMENT OPTION"<<endl;
    cout<<"================================================================================================================="<<endl;
    cout << "                SELECT YOUR PREFFERED PAYMENT OPTION:\n";
     cout<<"================================================================================================================="<<endl;
    cout<<setw(10)<<"CHOICE"<<"|"<<setw(30)<<"METHODS"<<endl;
     cout<<"================================================================================================================="<<endl;
    cout <<setw(10)<< "1."<<"|"<<setw(30)<<" EASYPAISA AND JAZZCASH\n";
    cout <<setw(10 )<<"2."<<"|"<<setw(30)<<" PAY AT COUNTER\n";
     cout<<"================================================================================================================="<<endl;

    int paymentChoice;
    cout << "Enter your choice (1 or 2): ";
    cin >> paymentChoice;
    cin.ignore(); // Clear the input buffer

    switch (paymentChoice) {
      case 1:  cout<<"===================================================================================================================="<<endl;
    cout<<"     				       RULES FOR PAYEMENT "<<endl;
    cout<<"================================================================================================================="<<endl;
            cout << "==>SEND THE PAYMENT ON THE NUMBER:+9223456789" << endl;
           
            cout << "==> ONCE THE PAYMENT IS COMPLETE" <<endl;
             cout <<"==> SEND THE NOTIFICATION MESSAGE ON WHATSAPP:+923456789" <<endl;
            cout<<"  ==>OTHERWISE YOUR ORDER WILL NOT BE DELIVERED"<<endl;
            break;

        case 2:
            cout<<"==>GIVE PAYMENT TO THE CASIER ON COUNTER AND TAKE YOUR ORDER"<<endl;
           
            break;

        default:
            cout << "\nINVALID CHOICE ;SELECT  1 or 2.\n";
             askpaymentmethod();
}
cout << "=================================================" << endl;
}

