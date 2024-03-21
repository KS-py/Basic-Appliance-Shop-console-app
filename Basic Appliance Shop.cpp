#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>


using namespace std; 

int main(){
	char start;
	float shop(void);
	char choice;
	ofstream receipt("receipt.txt");
	ofstream purchases("purchases.xls", ios::app);
	
	
	startL:
		cout << "Please press H to start shopping for home appliances" << endl;
		start:
			cin >> start;
			system("cls");
			
			if(start == 'h' || start == 'H'){
				float total = shop();
				time_t t = time(NULL); 			//t is an object of the time_t struct
				tm* tPtr = localtime(&t);		//tm struct has localtime func that takes t object by reference and converts it into local system time
				int hours = tPtr -> tm_hour;
				int minutes = tPtr -> tm_min;
				int seconds = tPtr -> tm_sec;
				
				int day = tPtr->tm_mday;
				int month = (tPtr->tm_mon) + 1 ;
				int year = 1900 + tPtr->tm_year;
				
				cout << "Bill Date: ";
				cout << day << "/";
				cout << month << "/";
				cout << year << endl;
				
				receipt << "  KS VENTURES  " << endl;
				receipt << "===============" << endl;
				
				receipt << "Bill Date: ";
				receipt << day<< "/";
				receipt << month << "/";
				receipt << year << endl;				
				
				
				if(minutes < 10 && hours < 12){
					cout << "Bill time: 0" << hours << ":" << "0" << minutes << ":" << seconds << endl;	
					receipt << "Bill time: 0" << hours << ":" << "0" << minutes << ":" << seconds << endl;							
				}
				else if(minutes < 10){
					cout << "Bill time: " << hours << ": 0" << minutes << ":" << seconds << endl;
					receipt << "Bill time: " << hours << ": 0" << minutes << ":" << seconds << endl;					
				}
				else if(hours < 12){
					cout << "Bill time: " << "0" << hours << ":" << minutes << ":" << seconds << endl;
					receipt << "Bill time: " << "0" << hours << ":" << minutes << ":" << seconds << endl;									 
				}else{
					cout << "Bill time: " << hours << ": 0" << minutes << ":" << seconds << endl;
					receipt << "Bill time: " << hours << ": 0" << minutes << ":" << seconds << endl;					
				}


				cout << "Total Bill Amount: " << total << endl;
				receipt << "Total Bill Amount: " << total << endl;
				
				
				if(total > 50000 && 100000){
					total = total - (0.05 * total);
					cout << "Total Discount is: 5%" << endl;
					receipt << "Total Discount is: 5%" << endl;					
				}
				else if(total > 100000 && 125000){
					total = total - (0.1 * total);
					cout << "Total Discount is: 10%" << endl;					
					receipt << "Total Discount is: 10%" << endl;					
				}
				else if(total > 125000 && 150000){
					total = total - (0.25 * total);
					cout << "Total Discount is: 25%" << endl;
					receipt << "Total Discount is: 25%" << endl;					
				}
				else if(total > 150000){
					total = total - (0.5 * total);
					cout << "Total Discount is: 50%" << endl;					
					receipt << "Total Discount is: 50%" << endl;
				}
				
				cout << "Total bill amount is: $" << total << endl;
				receipt << "Total bill amount is: $" << total << endl;
				receipt << endl;
				receipt << "Thanks for shopping!!!" << endl;
			
				purchases << total << endl;
				
				
				Again:
					cout << "Do you want to shop again? [y/n]" << endl;
					cin >> choice;
					if(choice == 'y'|| choice == 'Y'){
						goto startL;
					}
					else if(choice == 'n' || choice == 'N'){
						cout << "Thanks for shopping!!" << endl;
					}
					else{
						cout << "Please you have entered the wrong option, please press Y/N " <<endl;
						goto Again;
					}
			}
			else{
				cout << "You have entered a wrong option, please press H to shop" << endl;
				goto start;
			}
}

float shop(){
	shop:
		char choice;
		int product;
		int quantity;
		float bill=0;
		itemLevel:
			cout << "\t\t\t*********************** Welcome************************" << endl;
			cout << "\t\t __Please follow the instructions__ " << endl;
			cout << "\t\t| 1. Please enter R to order Refrigerator" << endl;
			cout << "\t\t| 2. Please enter W to order Washing machine " << endl;
			cout << "\t\t| 3. Please enter T to order Television" << endl;
			cout << "\t\t| 4. Please enter M to order Microwave" << endl;
			cout << "\t\t| 5. Please enter A to order the Air conditoner" << endl;
			cin >> choice;
			system("cls");
			
			if(choice == 'r' || choice == 'R' || choice == 'w' || choice == 'W' || choice == 't'|| choice == 'T' || choice == 'm'|| choice == 'M'|| choice == 'a' || choice == 'A')
			{
				if(choice == 'r' ||choice == 'R'){
					cout << "\t\t ____Refrigerator Details_____" << endl;
					cout << "\t\t| 1. Nasco\t=> Price: 40000 |" << endl;
					cout << "\t\t| 2. Samsung\t=> Price: 25000 |" << endl;
					cout << "\t\t| 3. Haier\t=> Price: 20000 |" << endl;
					cout << "\t\t| 4. Voltas\t=> Price: 18000 |" << endl;
					cout << "\t\t| 5. Jerdog\t=> Price: 30000 |" << endl;
					cout << "\t\t| 6. Panasonic\t=> Price: 35000 |" << endl;
				
					refrigerator:	
						cout << "Please enter your choice "<< endl;
						cin >> product;
						switch(product){
							case 1:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 40000); 
								break;
							case 2:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 25000); 
								break;		
							case 3:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 20000); 
								break;		
							case 4:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 18000); 
								break;						
							case 5:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 30000); 
								break;	
							case 6:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 35000); 
								break;	
							default:
								cout << "You have entered the wrong option, please try again" << endl;
								goto refrigerator; 
						};	
				}

				if(choice == 'w' ||choice == 'W'){
					cout << "\t\t _____Washing Machine Details_____" << endl;
					cout << "\t\t| 1. Bosch\t=> Price: 40000 |" << endl;
					cout << "\t\t| 2. LG\t=> Price: 25000 |" << endl;
					cout << "\t\t| 3. IFB\t=> Price: 20000 |" << endl;
					cout << "\t\t| 4. Haier\t=> Price: 50000 |" << endl;
					cout << "\t\t| 5. Maytag\t=> Price: 30000 |" << endl;
					cout << "\t\t| 6. Samsung\t=> Price: 45000 |" << endl;
				
				washing_machine:
					cout << "Please enter your choice "<< endl;
					cin >> product;
					switch(product){
						case 1:
							cout << "Please enter the quantity of the product" << endl;
							cin >> quantity;
							bill = bill + (quantity * 40000); 
							break;
						case 2:
							cout << "Please enter the quantity of the product" << endl;
							cin >> quantity;
							bill = bill + (quantity * 25000); 
							break;		
						case 3:
							cout << "Please enter the quantity of the product" << endl;
							cin >> quantity;
							bill = bill + (quantity * 20000); 
							break;		
						case 4:
							cout << "Please enter the quantity of the product" << endl;
							cin >> quantity;
							bill = bill + (quantity * 50000); 
							break;						
						case 5:
							cout << "Please enter the quantity of the product" << endl;
							cin >> quantity;
							bill = bill + (quantity * 30000); 
							break;	
						case 6:
							cout << "Please enter the quantity of the product" << endl;
							cin >> quantity;
							bill = bill + (quantity * 45000); 
							break;	
						default:
							cout << "You have entered the wrong option, please try again" << endl;
							goto washing_machine ; 
					};
				}

				if(choice == 't' ||choice == 'T'){
					cout << "\t\t ____Television Details_____" << endl;
					cout << "\t\t| 1. Nasco\t=> Price: 40000 |" << endl;
					cout << "\t\t| 2. Samsung\t=> Price: 25000 |" << endl;
					cout << "\t\t| 3. Haier\t=> Price: 20000 |" << endl;
					cout << "\t\t| 4. Voltas\t=> Price: 18000 |" << endl;
					cout << "\t\t| 5. Jerdog\t=> Price: 30000 |" << endl;
					cout << "\t\t| 6. Panasonic\t=> Price: 35000 |" << endl;
				
					television:	
						cout << "Please enter your choice "<< endl;
						cin >> product;
						switch(product){
							case 1:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 40000); 
								break;
							case 2:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 25000); 
								break;		
							case 3:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 20000); 
								break;		
							case 4:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 18000); 
								break;						
							case 5:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 30000); 
								break;	
							case 6:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 35000); 
								break;	
							default:
								cout << "You have entered the wrong option, please try again" << endl;
								goto television; 
						};
				}
					
				if(choice == 'm' ||choice == 'M'){
					cout << "\t\t ____Microwave Details_____" << endl;
					cout << "\t\t| 1. Nasco\t=> Price: 40000 |" << endl;
					cout << "\t\t| 2. Samsung\t=> Price: 25000 |" << endl;
					cout << "\t\t| 3. Haier\t=> Price: 20000 |" << endl;
					cout << "\t\t| 4. Voltas\t=> Price: 18000 |" << endl;
					cout << "\t\t| 5. Jerdog\t=> Price: 30000 |" << endl;
					cout << "\t\t| 6. Panasonic\t=> Price: 35000 |" << endl;
					
					microwave:
						cout << "Please enter your choice "<< endl;
						cin >> product;
						switch(product){
							case 1:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 40000); 
								break;
							case 2:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 25000); 
								break;		
							case 3:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 20000); 
								break;		
							case 4:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 18000); 
								break;						
							case 5:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 30000); 
								break;	
							case 6:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 35000); 
								break;	
							default:
								cout << "You have entered the wrong option, please try again" << endl;
								goto microwave; 
						};
				}
					
				if(choice == 'a' ||choice == 'A'){
					cout << "\t\t ____Air Conditioner Details_____" << endl;
					cout << "\t\t| 1. Nasco\t=> Price: 40000 |" << endl;
					cout << "\t\t| 2. Samsung\t=> Price: 25000 |" << endl;
					cout << "\t\t| 3. Haier\t=> Price: 20000 |" << endl;
					cout << "\t\t| 4. Voltas\t=> Price: 18000 |" << endl;
					cout << "\t\t| 5. Jerdog\t=> Price: 30000 |" << endl;
					cout << "\t\t| 6. Panasonic\t=> Price: 35000 |" << endl;
					
					air_conditioner:
						cout << "Please enter your choice "<< endl;
						cin >> product;
						switch(product){
							case 1:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 40000); 
								break;
							case 2:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 25000); 
								break;		
							case 3:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 20000); 
								break;		
							case 4:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 18000); 
								break;						
							case 5:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 30000); 
								break;	
							case 6:
								cout << "Please enter the quantity of the product" << endl;
								cin >> quantity;
								bill = bill + (quantity * 35000); 
								break;	
							default:
								cout << "You have entered the wrong option, please try again" << endl;
								goto air_conditioner; 
						};	
				}
			
			}else{
				cout << "You have entered the wrong option, please try again: " << endl;
				goto shop;
			}
			return bill;
}



