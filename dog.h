#ifndef DOG_H
#define DOG_H
#include"animal.h"

class dog: public animal{
	public:
		dog();
		~dog();
		string getName() const;
		string getType() const override;
		dog(const string & aname, const int dogAge);
		bool setter(const string str, const int ageU);
		bool checkAge(const int val);// checks if lifespan meets
		void print();
		bool feedAnimal();// will set hunger to true;
		bool getAlong();// will tell us if we can have other animals with this one. 
	private:
		string comments; // general comment on what others said
		int care; //care level from 1-10
		int lifespan; // life span of an animal
//		int size; // how big is the dog. 
		bool hunger; // when the user feeds the animal it will be true
		string name;
};
#endif
