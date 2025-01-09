#ifndef CAT_H
#define CAT_H
#include"animal.h"
class cat: public animal{
	public:
		cat(const string & aname, int catAge);
		cat();
		~cat();
		string getName() const;
		string getType() const override;
		void print();
		bool setter(const string str, const int ageU);
		bool checkAge(const int val);// checks if lifespan meets
		bool feedAnimal();// will set hunger to true;
		bool getAlong();// will tell us if we can have other animals with this one. 
	private:
		string name;// what type of animal
		int age;// age that the user wants
		bool hungry;// if the cat was fed or not
};
#endif
