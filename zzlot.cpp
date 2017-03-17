#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};

node *newNode(int a)
{
	node *temp = new node;
	temp->data = a;
	temp->left = temp->right = NULL;
	return temp;
}

void lot(struct node *root)
{
	if(root == NULL)
		return;
	queue<node *> q;
	q.push(root);
	bool flip = false;

	while(true)
	{

		int nodecount = q.size();

		if(nodecount==0)
			break;
		stack<int> s;
		while(nodecount>0)
		{
			node *temp = q.front();
			q.pop();
			
			if(flip)
				s.push(temp->data);
			
			else
				cout<<temp->data<<"\t";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);		
			nodecount--;	
		}
		while(!s.empty())
		{
			cout<<s.top()<<"\t";
			s.pop();
		}
		flip = !flip;
		cout<<endl;
	}	
}

int main()
{
	node *root = newNode(10);
	root->left = newNode(15);
	root->right = newNode(12);

	root->left->left = newNode(9);
	root->left->right = newNode(10);
	root->right->left = newNode(5);
	root->right->right = newNode(8);
	lot(root);
	return 0;
}