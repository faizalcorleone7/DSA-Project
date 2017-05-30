#include<iostream>						//stack implemenatation//
#include<malloc.h>
#include<math.h>
using namespace std;
struct node
{
	int data;int count;
	struct node*left;
	struct node*right;
	struct node*prev;
} *head=NULL,*top=NULL,*n1=NULL;
struct node* push(int d,int i);
struct node* pop();
void find(int v1,struct node *temp);
struct node* parentnode(struct node *t1,struct node *t2);
void display();
main()
{
	int a,b,v1,v2;
	cout<<"Enter the no. of elements to be inserted = ";
	cin>>a;
	for (int i=1;i<=a;i++)
	{	
		cin>>b;
		top=push(b,i);	
	}	
	display();
	cout<<endl;
	struct node *popnode;
	popnode=pop();
	if (popnode!=NULL)
	{	
		cout<<"In main function 1 "<<endl;
		cout<<"poped node->data= "<<popnode->data<<endl<<"New top->data= "<<top->data<<endl;
	}
	struct node *t1=head,*t2=head,*c;
	cout<<"Enter the values of the nodes whose common ancestor is to be found - "<<"\t";cin>>v1>>v2;
	find(v1,t1);t1=n1;find(v2,t2);t2=n1;cout<<"t1->data= "<<t1->data<<" "<<"t2->data= "<<t2->data<<endl;
	c=parentnode(t1,t2);cout<<"c->data= "<<c->data<<endl;
}
struct node* push(int d,int i)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=d;
	temp->count=i;
	if (head==NULL)																								//head node updation//
	{
		head=temp;
		head->left=NULL;
		head->right=NULL;
		head->prev=NULL;
		top=head;
	return top;}
	else if (top->prev==NULL&& head!=NULL)																		//second node updation//
	{
		top->left=temp;
		temp->prev=top;
		top=temp;top->left=NULL;top->right=NULL;
	return top;}
	else if (top->prev && top->count%2==0)																	//right node updation//		
	{
		temp->prev=top->prev;top->prev->right=temp;
		top=temp;top->left=NULL;top->right=NULL;
	return top;}
	else if ((top->count)%2!=0&&top->prev&&top->count<(pow(2,((double)((int)(log(top->count)/log(2))+1)))-1))	//left node updation//
	{
		struct node* transport=top;
		while(transport->count%2!=0)
		{	
			transport=transport->prev;
		}
		transport=transport->prev;
		transport=transport->right;
		if(transport->left!=NULL)
		{while(transport->left!=NULL)
		{	
			transport=transport->left;}
		}
		temp->prev=transport;
		transport->left=temp;
		top=temp;top->left=NULL;top->right=NULL;
	return top;}
	else if ((top->count)%2!=0&&top->prev&&top->count==(pow(2,((double)((int)(log(top->count)/log(2))+1)))-1))  //left node special updation//
	{
		struct node*transport=head;int z=0;
		while(z!=(log((top->count)+1)/log(2)-1))
		{	z=z+1;
			transport=transport->left;
		}
		temp->prev=transport;
		transport->left=temp;
		top=temp;top->left=NULL;top->right=NULL;
	return top;}
}
void display()
{
	cout<<"This is display value = "<<top->data;
}
struct node* pop()
{
	if (head==NULL)																						//stack empty condition//
	{
		cout<<"Stack is empty";
	return head;}
	else if(top->count%2!=0)																			//right node and head removal//
	{	
		struct node* temp=top;
		if (top->prev!=NULL)
		{top=top->prev->left;}
		else
		{	
			cout<<"Head node removed"<<endl<<"poped node->data= "<<top->data<<endl;
			top=top->prev;
		}
		return temp;
	}
	else if (top->count%2==0&&top->count==(pow(2,((double)((int)(log(top->count)/log(2)))))))			//left node special removal//
	{	struct node*returnnode=top;
		if (top->count==2){top=top->prev;}
		else
		{struct node*temp=head;
		while(temp->right!=NULL)
		{
			temp=temp->right;
		}
		top=temp;}
		return returnnode;
	}
	else if(top->count%2==0&&top->count>(pow(2,((double)((int)(log(top->count)/log(2)))))))				//removing left node//
	{
		struct node*transport=top,*temp=top;
		while(transport->prev->right!=transport)
		{	
			transport=transport->prev;
		}	
			transport=transport->prev;
			transport=transport->left;
			while(transport->right!=NULL)
			{
			transport=transport->right;
			}
		top=transport;
		return temp;
	}
}
void find(int v,struct node *t)
{
	struct node *temp=t;
	if (temp->left!=NULL&&temp->right!=NULL&&temp->data!=v)
	{
		find(v,temp->left);
		find(v,temp->right);	
	}
	else 
	{
		if (temp->data==v)
		{n1=temp;}
	}
}
struct node *parentnode(struct node *t1,struct node *t2)
{
	struct node *a,*b;
	if (t1->count>t2->count)
	{
		a=t1;
		b=t2;
	}
	else
	{
		a=t2;
		b=t1;
	}
	int c1,c2;
	while((int)(log(a->count)/log(2))-(int)(log(b->count)/log(2)))
	{
		a=a->prev;
	}
	while (((b->count)-(a->count))!=0)
	{
		b=b->prev;
		a=a->prev;
	}
	return a;
}

