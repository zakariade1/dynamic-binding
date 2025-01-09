#include"animal.h"
#include"cat.h"
#include"horse.h"
#include"dog.h"
using namespace std;
class node{
	public:
		animal * data;
		node * left;
		node * right;
		node();
		~node();
		node(animal * myanimal);
};
class BST{
	public:
		BST();	
		~BST();
		bool remove(const string & Nanimal);	
		void display();
		bool remove_all();
		bool insert(animal * &myanimal, const string aname, const int ageC, const int kind);	
		BST& operator=(const BST& other);
	private:
		node * root;
		bool remove_helper(node * & curr, const string name);
		void display_helper(node * curr);
		void add_helper(node * &curr, animal * & myanimal);
		node * find_min(node * curr);
		bool remove_all_helper(node * & curr);
		node * copyNode(const node * other);
};
