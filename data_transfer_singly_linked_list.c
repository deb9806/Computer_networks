//DATA TRANSFER SINGLY LINKED LIST


#include<stdio.h>
#include<stdlib.h>

struct node{

int data;
struct node*next;
};
struct node *p=NULL;
void create();
int count();
void disp();

void main()
{
	int num=0;
	while(1){
	printf("\n1 -> CREATE NODE \n2 -> PASSING DATA FROM NODE \n3-> EXIT");
	printf("\nENTER THE CHOICE::");
	scanf("%d",&num);
	switch(num){
	case 1: printf("\nCREATION");
		  create();
		  printf("\nNODE CREATED SUCCESSFULLY..!");
		  break;
	case 2: printf("\nDISPLAY");
		  disp();
		  break;

	case 3: printf("\nEXIT");
		  exit(0);
	
	default : printf("WRONG CHOICE");
	}
	}
}

void create()
{
	struct node *temp;
	temp=p;
	if(temp==NULL)
	{
		int num;
		struct node *nw;
		nw=(struct node *)malloc(sizeof(struct node));
		printf("\nENTER THE NUMBER IN FIRST NODE::");
		scanf("%d",&num);
		nw->data=num;
		nw->next=NULL;
		p=nw;
	}
	else{
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	
		struct node *nw;
		nw=(struct node *)malloc(sizeof(struct node));
		
		
		nw->data=0;
		nw->next=NULL;
		temp->next=nw;
	}
}
int count()
{
struct node *temp;
	temp=p;
	int c=0;
	if(temp==NULL)
	{
		printf("\nLIST IS EMPTY");
	}
	else
	{

	while(temp!=NULL)
	{
		c=c+1;
		temp=temp->next;
	}
		return c;
	}
	
}
void disp()
{
	struct node *temp;
	temp=p;
	if(temp==NULL)
	{
		printf("\nLIST IS EMPTY");
	}
	else
	{
		int d,e=0;
		d=count();
		
		
	while(temp->next!=NULL)
	{
		if(d>e){
			if(e==0)
			{
					printf("\nFIRST NODE ");
					printf("\tDATA => %d",temp->data);
				
			}
			else
			{
				printf("\nSUB NODE %d",e);
				printf("\tDATA => %d",temp->data);
			}
			
			temp->next->data=temp->data;
			e++;
			
		}
		
	temp=temp->next;
	}
	
		{
			printf("\nLAST NODE");
			printf("\tDATA => %d",temp->data);
			printf("\nDATA TRAVERSED COMPLETED.....!");
		}
	}
}
		

		
		
