#include"tree.h"
//copy constructor
node :: node(animal * myanimal){
	data = myanimal;
	left = nullptr;
	right = nullptr;
}
//constructor
node :: node(){
	data  = nullptr;
	left = nullptr;
	right = nullptr;
}
//destructor
/*********************************************************/
node :: ~node(){
	delete data;
	data = nullptr;
}
/*********************************************************/
//constructor
BST :: BST(){
	root = nullptr;
}
/*********************************************************/
//destructor
BST :: ~BST(){
	bool check = remove_all();
	if(check == true){
		delete root;
		root = nullptr;
	}
}
/*********************************************************/
// will display the list in the tree
void BST :: display(){
	display_helper(root);	
}
/********************************************************/
//Just a helper to display
void BST :: display_helper(node * curr){
	if(curr){	
		display_helper(curr->left);
		curr->data->print();
		display_helper(curr->right);
	}
}
/*********************************************************/
//removes everything
bool BST :: remove_all(){
	return remove_all_helper(root);
}
/*********************************************************/
//Just a helper
bool BST :: remove_all_helper(node * & curr){
	bool temp = false;
	if(curr){
		remove_all_helper(curr->left);
		remove_all_helper(curr->right);
		delete curr;
		curr = nullptr;
		temp = true;
	}
	return temp;
}
/*********************************************************/
// Function to insert to the tree
bool BST :: insert(animal * & myanimal, const string aname, const int ageC, const int kind){
	/*
		if the tree is empty
	*/
	if(root == nullptr){
		root = new node(myanimal);
	}
	else{//if not empty
		node * curr = root;
		add_helper(curr, myanimal);
	}
	return true;
}
/*********************************************************/
//just a helper to insert
void BST :: add_helper(node * & curr, animal * & myanimal){
	if(!curr){
		curr = new node(myanimal);
	}
	else{
		//Sorting my adding
		if(myanimal->getName() < curr->data->getName()){
			add_helper(curr->left, myanimal);
		}
		else {
			add_helper(curr->right, myanimal);
		}
	}
}
/*********************************************************/
//This function is to remove a ceertain node
bool BST :: remove(const string & Nanimal){
	if(root == nullptr){
		throw "\nError There is nothing to delete";
	}
	return remove_helper(root, Nanimal);
}
/*********************************************************/
//This is the helper
bool BST :: remove_helper(node * & curr, const string name){
	if(!curr){
		cout << "\nItem not in the list" << endl;
		return false;
	}
	string compare = curr->data->getName();
	if( compare == name){
		cout << "\nItem found" << endl;// if it is a leaf
		if(!curr->left && !curr->right){
			delete curr;
			curr = nullptr;
		}
		else if(!curr->left){// no right child
			node * temp = curr;
			curr = curr->right;
			delete temp;
			temp = nullptr;
		}
		else if(!curr->right){// no left child
			node * temp = curr;
			curr = curr->left;
			delete temp;
			temp = nullptr;
		}
		else{
			//case when node has 2 children
			node * min_n = find_min(curr->right);
			curr->data = min_n->data;
			remove_helper(curr->right, min_n->data->getName());
		}
		return true;
	}
	else if(name < compare){
		return remove_helper(curr->left, name);
	}
	else{
		return remove_helper(curr->right, name);
	}
}
/*********************************************************/
//Helps us to find the min data that a node has
node * BST :: find_min(node * curr){
	if(!curr){
		return nullptr;
	}
	//if we have a child that is less than us
	if(curr->left){
		return find_min(curr->left);
	}
	return curr;// No more children
}

/*******************************************************/
BST& BST :: operator=(const BST& other){
	if(this != &other){
		remove_all();//remove everything
		//deep copy
		root = copyNode(other.root);
		
	}
	return *this;
}
node * BST :: copyNode(const node * other){
	if(!other){
		return nullptr;
	}
	node * newnode = new node(*other);
	newnode->left = copyNode(other->left);
	newnode->right = copyNode(other->right);
	return newnode;
}
