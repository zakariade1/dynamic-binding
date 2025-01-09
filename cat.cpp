#include"cat.h"
/*********************************************************/
//constructor
cat :: cat(){
	name = "";
	age = 0;
	hungry = false;	
}
/*********************************************************/
//copy constructor
cat :: cat(const string & aname, int catAge): animal("Cat", 5){
	name = aname;
	age = catAge;
	animal :: type = "Cat";
	animal :: max_age = 17;
	hungry = false;	
}
/*********************************************************/
//destructor
cat :: ~cat(){
	name = "";
	hungry = false;
	age = 0;
}
/*********************************************************/
bool cat :: setter(const string str, const int ageU){
	name = str;
	age = ageU;
	return true;
}
/*********************************************************/
void cat :: print(){
	if(name != ""){
		cout << "\n--CAT---";
		cout << "\nCat Name: " << name << "\n";
		cout << "Age: " << age << " Years";
		cout << "  Hungry: ";
		if(hungry)
			cout << "No";
		else
			 cout << "Yes" << endl;
	}
	else{
		throw "No info to print";
	}
}
/*********************************************************/
string cat :: getType() const{
	return type;
}
/*********************************************************/
bool cat :: checkAge(const int val){
	if( age != 0){
	bool result = false;
	if(age < 5){
			cout << "\n" << name << " is young cat. " << endl;
			result  = true;
		}
		else{
			cout << "\n" << name << " is mature cat. " << endl;
		}
		return result;
	}
	else{
		throw "No age to compare";
	}
}

/*********************************************************/
bool cat :: feedAnimal(){
	if( name != ""){
		if(hungry){
			cout << "\n" << name << " has been fed. MEOWWW!" << endl;
		}
		else{
			cout << "\n" << name << " Is eating MEOWWW!" << endl;
			hungry = true;
		}
		bool temp = hungry;
		return temp;
	}
	else{
		throw "No animal to feed";
	}
}

/*********************************************************/
bool cat :: getAlong(){
	cout << "\n" << name << " gets along well with othe. Animals" << endl;

	return true;	
}

/*********************************************************/
string cat:: getName() const{
	return name;
}
