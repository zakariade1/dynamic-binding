#include"animal.h"
#include"cat.h"
#include"dog.h"
#include"horse.h"
#include"tree.h"
#include<vector>
#include<memory>
/*************************************************************************/
//makes border
void line(){
	cout << "\n-----------------------------------------------------\n";
}	
/*************************************************************************/
// prints menu and returns option
int  menu(){
		int option = 0;
		cout << "\n0. To print infos of the parent";
		cout << "\n1.To enter information";
		cout << "\n2.To display";
		cout << "\n3. To feed an animal"; 
		cout << "\n4. Get Along check";
		cout << "\n5. Quit";
		cout << "\nPlease enter: ";
		cin >> option;
		while((option != 0) &&(option != 1) && (option != 2) && (option != 3) && (option != 4) && (option != 5)){
			cout << "\nInvalid entry, try again: ";
			cin >> option;
		}
		return option;
}
/*************************************************************************/
//cats section
void catFunction(BST & mytree, animal * & mycat){
	int option = 0;
	string catName;
	int age = 0;
	line();
	cout << "\nWelcome to the cat section" << endl;
	line();
	do{
		option = menu();
		try{
		switch(option){
			case 0:
				
				break;
			case 1:
				cout << "\nWhat do you want to name your cat: ";
				cin >> catName;	
				cout << "\nHow long (in yrs) do you want to have: ";
				cin >> age;
				mycat = new cat(catName, age);
//				mytree.insert(mycat,catName, age, 0);
				//check = true;	
				break;
			case 2:
				mycat->print();
				break;
			case 3: 
				mycat->feedAnimal();
				break;
			case 4: 
				mycat->getAlong();
				break;
			case 5:
				cout << "\nIt was good having you at the cat section" << endl;
				option = 0;
				break;
		}
		}
		catch (const char * txt) {
			cout << "\nException: " << txt << endl;
		}
	}while(option != 0);
	mytree.insert(mycat,catName, age, 0);
	int perform = 0;
	cout << "\nWant to try RTTI?, 0 for yes: ";
	cin >> perform;
	if(perform == 0){
		cat * myCat = dynamic_cast<cat*>(mycat);
		if(myCat){
			cout << "\nTHE pointer is for a cat :) :) " << endl;
		}
		else{
			cout << "\nThe pointer is not a cat :(" << endl;

		}
	}
}
/**************************************************************************/
//dogs section
void dogFunction(BST & mytree, animal *& mydog ){
	int option = 0;
	string dogName;
	int age = 0;
	//mydog = new dog();
	line();
	cout << "\nWelcome to the dog section" << endl;
	line();
	do{
		option = menu();
		try{
		switch(option){
			case 0:
				break;
			case 1:
				cout << "\nWhat do you want to name your dog: ";
				cin >> dogName;	
				cout << "\nHow long (in yrs) do you want to have: ";
				cin >> age;
				mydog = new dog(dogName, age);
//				mytree.insert(mydog,dogName, age, 2);
				//check = true;	
				break;
			case 2:
				mydog->print();
				break;
			case 3: 
				mydog->feedAnimal();
				break;
			case 4: 
				mydog->getAlong();
				break;
			case 5:
				cout << "\nIt was good having you at the dog section" << endl;
				option = 0;
				break;
		}
		}
		catch (const char * txt) {
			cout << "\nException: " << txt << endl;
		}
	}while(option != 0);
	mytree.insert(mydog,dogName, age, 0);
	int perform = 0;
	cout << "\nWant to try RTTI?, 0 for yes: ";
	cin >> perform;
	if(perform == 0){
		dog * myDog = dynamic_cast<dog*>(mydog);
		if(myDog){
			cout << "\nTHE pointer is for a dog :) :) " << endl;
		}
		else{
			cout << "\nThe pointer is not a dog :(" << endl;

		}
	}
}
/*************************************************************************/
//horse section
void horseFunction(BST & mytree, animal * & myhorse){
	int option = 0;
	string horseName;
	int age = 0;
//	myhorse = new horse();
	line();
	cout << "\nWelcome to the horse section" << endl;
	line();
	do{
		option = menu();
		try{
		switch(option){
			case 0:
				break;
			case 1:
				cout << "\nWhat do you want to name your horse: ";
				cin >> horseName;	
				cout << "\nHow long (in yrs) do you want to have: ";
				cin >> age;
				//check = true;	
				myhorse = new horse(horseName, age);	
//				mytree.insert(myhorse,horseName, age, 1);
				break;
			case 2:
				myhorse->print();
				break;
			case 3: 
				myhorse->feedAnimal();
				break;
			case 4: 
				myhorse->getAlong();
				break;
			case 5:
				cout << "\nIt was good having you at the cat section" << endl;
				option = 0;
				break;
		}
		}
		catch (const char * txt) {
			cout << "\nException: " << txt << endl;
		}
	}while(option != 0);
	mytree.insert(myhorse,horseName, age, 0);
	int perform = 0;//For RTTI
	cout << "\nWant to try RTTI?, 0 for yes: ";
	cin >> perform;
	if(perform == 0){
		horse * myHorse = dynamic_cast<horse *>(myhorse);
		if(myHorse){
			cout << "\nTHE pointer is for a horse :) :) " << endl;
		}
		else{
			cout << "\nThe pointer is not a horse :(" << endl;

		}
	}
}
/*************************************************************************/
void welcome(){
	line();
	cout << "Welcome to the shopping for animal mall";
	line();
}
/*************************************************************************/
int main(){
	animal * mydog;//ptr for a dog
	animal * mycat;// ptr for a cat
	animal * myhorse; // ptr for a horse
	vector<unique_ptr<string>> namesList;
	int Otree;
	int checking = 0;
	int stay = 0;
	int check = 0;
	string customer;
	welcome();
	BST mytree;
	do{
		if(check == 0){
			cout << "\nPlease Enter customers name. If not new press 0: ";
			cin >> customer;
			if(customer != "0"){
				namesList.push_back(make_unique<string>(customer));
			}
			check = 0;
		}
		cout << "\nChoose what animal you woul like to check out" << endl;
		cout << "1. cat, 2. dog, 3. horse: ";
		cin >> checking;
		while((checking != 1) && (checking != 2) && (checking != 3)){
			cout << "\nInvalid Entry, try again: ";
			cin >> checking;
		}
		switch(checking){
			case 1:
				catFunction(mytree, mycat);
				break;
			case 2:
				dogFunction(mytree, mydog);
				break;
			case 3: 
				horseFunction(mytree, myhorse);
				break;

		}
		line();
		line();
		cout << "\nInformation have been stored." << endl;
		cout << "\nWould you like to 1. display, 2. remove, 3. remove everything" << endl;
		cin >> Otree;
		switch(Otree){
			case 1:
				mytree.display();
				break;
			case 2:
				string nameAnimal;
				cout << "\nEnter the name of the animal to be removed: ";
				cin >> nameAnimal;
				bool found = mytree.remove(nameAnimal);	
				if(found){
					cout << nameAnimal << "Deleted" << endl;
				}
				else {
					cout << nameAnimal << " Not found" << endl;
				}
				break;
		}
		if(Otree == 3){
			bool check = mytree.remove_all();
			if(check){
				cout << "\nEVERYTHING GOT REMOVED" << endl;
			}
		}
		cout << "\nEnter 1 to Quit: ";
		cin >> stay;
	}while(stay != 1);

		line();
		cout << "\nprinting customers that came today: ";
		for(const auto& strPtr: namesList){
			cout << "\nCustomer: " << *strPtr << endl;
		}
		line();
		cout << "\nGood bye"<< endl;
//	delete mydog;
//	delete mycat;
//	delete myhorse;


	return 0;
}
