
#define NODE_H
#define NULL 0
class Node{
public:
int coeff,power;
Node *next;
Node(int coeff, int power){
	this->coeff = coeff;
	this->power = power;
	this->next = NULL;
}
};
