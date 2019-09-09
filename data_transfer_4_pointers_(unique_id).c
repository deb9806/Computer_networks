//DATA TRANSFER (WITH UNIQUE ID)

#include<stdio.h>
#include<stdlib.h>

struct node{
struct node *prev;
struct node *top;
int data;
int nodeno;
struct node *bot;
struct node*next;
};

struct store{
int a[0];
};
struct store *q=NULL;
struct node *p=NULL;
void create();
int countt();
int countd();
int countl();
int countr();
void display();
void shift();


void main()
{
	struct store *n;
	n=(struct store *)malloc(sizeof(struct store));
	q=n;
	int num=0;
	while(1){
	printf("\n1 -> CREATE NODE \n2 -> DISPLAY \n3 -> DATA-TRANSFER \n4 -> DELETE \n5 -> EXIT");
	printf("\nENTER THE CHOICE::");
	scanf("%d",&num);
	switch(num){
	case 1: printf("\nCREATION\n");
		  create();
		  printf("\nNODE CREATED SUCCESSFULLY..!");
		  break;
	case 2: printf("\nDISPLAY\n");
		  display();
		  break;
	case 3: shift();
			break;
	case 4: p=NULL;
			printf("\nALL NODES DELETED FROM THE MEMORY....!");
			break;
	case 5: printf("\nEXIT");
		  exit(0);
	
	default : printf("\nWRONG CHOICE");
	}
	}
}

void create()
{
	struct node *temp;
	struct store *id;
	id=q;
	temp=p;
	if(temp==NULL)
	{
		int num;
		struct node *nw;
		nw=(struct node *)malloc(sizeof(struct node));
		
		nw->data=0;
		nw->next=NULL;
		nw->prev=NULL;
		nw->top=NULL;
		nw->bot=NULL;
		nw->nodeno=1;
		q->a[0]=1;
		p=nw;
	}
	else{
	
		struct node *tempt,*tempd,*tempr,*templ;
		
		tempr=p;
		templ=p;
		
		int num,nnum;
		label1:
		printf("\nENTER THE NODE WHERE TO BE INSERTED::");
		scanf("%d",&nnum);
		int e=countr();
		if(nnum>e || nnum==0)
		{
			printf("\nINVALID NODE NO....! PLEASE TRY AGAIN...!");
			goto label1;
		}
		
		int j;
		for(j=1;j<nnum;j++)
		{	
			
		tempr=tempr->next;}
		
		printf("\nENTER THE POSITION DATA TO BE INSERTED::\n1 -> TOP (CHANNEL 1) \n2 -> RIGHT (CHANNEL 2)\n3 -> BOTTOM (CHANNEL 3)\n ENTER THE CHOICE::");
		scanf("%d",&num);
		struct node *nw;
		nw=(struct node *)malloc(sizeof(struct node));
		
		switch(num){
		
			case 1: 
				
					while(tempr->top!=NULL)
						tempr=tempr->top;
							
					nw->bot=tempr;
					nw->top=NULL;
					nw->prev=NULL;
					nw->data=0;
					id->a[0]=(id->a[0])+1;
					nw->nodeno=id->a[0];
					nw->next=NULL;
					tempr->top=nw;
					
				
					break;
				
			
			case 2: nw->data=0;
					nw->next=NULL;
					nw->top=NULL;
					nw->bot=NULL;
					id->a[0]=(id->a[0])+1;
					nw->nodeno=id->a[0];
					nw->prev=tempr;
					tempr->next=nw;
					break;
					
			case 3: 
					while(tempr->bot!=NULL)
						tempr=tempr->bot;
					
					nw->bot=NULL;
					nw->top=tempr;
					nw->prev=NULL;
					id->a[0]=(id->a[0])+1;
					nw->nodeno=id->a[0];
					nw->data=0;
					nw->next=NULL;
					tempr->bot=nw;
					
					
					break;
				
							
							
			default : printf("\nWRONG CHOICE....!");			
				
				
					
			
		
	}
}
}


//COUNT RIGHT
int countr()
{
struct node *temp;
	temp=p;
	int c=0;
	
	
	

	while(temp!=NULL)
	{
		c=c+1;
		temp=temp->next;
	}
		return c;
	
	
}

//COUNT LEFT

int countl()
{
struct node *temp;
	temp=p;
	int c=0;
	
	
	

	while(temp!=NULL)
	{
		c=c+1;
		temp=temp->prev;
	}
		return c;
	
	
}

//COUNT TOP

int countt(int n)
{
struct node *temp;
	temp=p;
	int c=0;
	
	int i;
	
		
	
	
	{
		for(i=1;i<n;i++)
			temp=temp->next;
	if(temp->top!=NULL)
	{
		temp=temp->top; //INCREASING THE TOP TO +1 CAUSE FIRST ONE IS BASE ONE
	while(temp!=NULL)
	{
		c=c+1;
		temp=temp->top;
	}
	}
	}
		return c;
	
	
}

// COUNT DOWN

int countd(int n)
{
struct node *temp;
	temp=p;
	int c=0;
	
	int i;
	
	
	{
		for(i=1;i<n;i++)
			temp=temp->next;
	if(temp->bot!=NULL)
	{
		temp=temp->bot;   //COUNTING DOWN FROM NEXT STATE SO ELIMINATING BASE ONE
	while(temp!=NULL)
	{
		c=c+1; 
		temp=temp->bot;
	}
	}
	}
		return c;
	
	
}

// DISPLAY


void display()
{
	
	if(p==NULL)
	{
		printf("\nLIST IS EMPTY");
	}
	else
	{
		struct node *tempt,*tempd,*tempr;
		tempt=p;
		tempd=p;
		tempr=p;
		
		
		
		
		int hval=0; //SUB HUB VALUE COUNT
		while(tempr!=NULL)
		{
			
			
			
			
			
			
			
			//PRINTING TOP SUB NODES
			
			if(tempr->top!=NULL)
			{
				int c=0;
					tempt=tempr;
					tempt=tempt->top; //FOR MOVING THE TOP POINTER TO THE +1 TOP
				while(tempt->top!=NULL)
				{
					
					tempt=tempt->top;
				}
				printf("\nULTIMATE-TOP-NODE OF NODE:: %d & UNIQUE-ID => %d & VALUE IS::%d",hval+1,tempt->nodeno,tempt->data); 
				
				tempt=tempt->bot; //GOING TO ONE STEP DOWN TO BOTTOM
				
				while(tempr!=tempt)
				{
					printf("\nTOP-SUBNODE OF NODE => %d ,SUB-NODE NO :: %d & UNIQUE-ID => %d & VALUE::%d",hval+1,c+1,tempt->nodeno,tempt->data);
					c=c+1;
					tempt=tempt->bot;
				}
			}
			
			printf("\n**MAIN--NODE** => %d & UNIQUE-ID => %d & VALUE => %d",hval+1,tempr->nodeno,tempr->data);
			
			//PRINTING DOWN SUB NODES
			if(tempr->bot!=NULL)
			{
				int c=0;
					tempd=tempr;
					tempd=tempd->bot;
				while(tempd->bot!=NULL)
				{
					printf("\nDOWN-SUBNODE OF NODE => %d ,SUB-NODE NO :: %d & UNIQUE-ID => %d & VALUE::%d",hval+1,c+1,tempd->nodeno,tempd->data);
					c=c+1;
					tempd=tempd->bot;
				}
				printf("\nULTIMATE-DOWN-NODE OF NODE::%d & UNIQUE-ID => %d VALUE IS::%d",hval+1,tempd->nodeno,tempd->data);
				
				
					
			}
			
			printf("\n----------------------------------------------------------------");
			
			
			hval=hval+1;
			tempr=tempr->next;
			tempt=tempr;
			tempd=tempr;
			
		}
	}
}



void shift()
{
	if(p==NULL)
	{
		printf("\nLIST IS EMPTY....!");
	}

	else{
			int totalnodes=countr();
			int pos1,pos2;
			label2 :
			printf("\nENTER THE STARTING UNIQUE-ID OF NODE TO TRANSFER DATA::");
			scanf("%d",&pos1);
			printf("\nENTER THE ENDING UNIQUIE-ID OF NODE TO TRANSFER DATA::");
			scanf("%d",&pos2);
			int num;
			printf("\nENTER THE NUMBER FOR DATA TANSFER::");
			scanf("%d",&num);
			if(pos1 > q->a[0] || pos2 > q->a[0] ||pos1==0 || pos2==0)
			{
				printf("\nINVALID UNIQUE ID....!");
				goto label2;
			}
			struct node *tempr,*templ,*store1;
			tempr=p;
			templ=p;
			
			int pos11,pos22;
			{//CHECKING POSITIONS
			
			
				while(tempr!=NULL){ //CHECKING WHERE THE NODE PRESENT WHEN STARTING UNIQUE-ID IS GIVEN 
			if(tempr->top!=NULL && tempr->bot!=NULL)
			{
				templ=tempr;
				while(templ!=NULL) //UP CHECKING
				{
					if(templ->nodeno==pos1)
					{
						
						store1=tempr;
						goto label11;
					}
					templ=templ->top;
					
				}


					


				templ=tempr;
				while(templ!=NULL)//DOWN CHECKING
				{
					
					if(templ->nodeno==pos1)
					{
						
						store1=tempr;
						goto label11;
					}
					
					templ=templ->bot;	
							
				}
			}//END OF FIRST IF
			else if(tempr->top!=NULL)
			{
				templ=tempr;
				while(templ!=NULL) //UP CHECKING
				{
					if(templ->nodeno==pos1)
					{
						
						store1=tempr;
						goto label11;
					}
					templ=templ->top;
					
				}
			}//FOR ONLY TOP CHECKING
			
			else if(tempr->bot!=NULL)//for only down checking
			{
				templ=tempr;
				while(templ!=NULL)//DOWN CHECKING
				{
					
					if(templ->nodeno==pos1)
					{
						
						store1=tempr;
						goto label11;
					}
					
					templ=templ->bot;	
							
				}
			}
			else if(tempr->top ==NULL && tempr->bot==NULL){
				if(tempr->nodeno==pos1)
				{
					store1=tempr;
						goto label11;
				}
			}//end if;
			
			
				tempr=tempr->next;
			}//END OF CHECKING STARTING UNIQUE-ID
			
			label11 : 
			pos11=store1->nodeno; //ASSIGNING STARTING POSITION
			
			
			
			
			
			//RESTORING TEMPR
			tempr=p;
			templ=p;
			
			
			
			
			
				while(tempr!=NULL){//CHECKING WHERE THE NODE PRESENT WHEN ENDING UNIQUE-ID IS GIVEN 
			if(tempr->top!=NULL && tempr->bot!=NULL)
			{
				templ=tempr;
				while(templ!=NULL) //UP CHECKING
				{
					if(templ->nodeno==pos2)
					{
						
						store1=tempr;
						goto label12;
					}
					templ=templ->top;
					
				}


					


				templ=tempr;
				while(templ!=NULL)//DOWN CHECKING
				{
					
					if(templ->nodeno==pos2)
					{
						
						store1=tempr;
						goto label12;
					}
					
					templ=templ->bot;	
							
				}
			}//END OF FIRST IF
			else if(tempr->top!=NULL)
			{
				templ=tempr;
				while(templ!=NULL) //UP CHECKING
				{
					if(templ->nodeno==pos2)
					{
						
						store1=tempr;
						goto label12;
					}
					templ=templ->top;
					
				}
			}//FOR ONLY TOP CHECKING
			
			else if(tempr->bot!=NULL)//for only down checking
			{
				templ=tempr;
				while(templ!=NULL)//DOWN CHECKING
				{
					
					if(templ->nodeno==pos2)
					{
						
						store1=tempr;
						goto label12;
					}
					
					templ=templ->bot;	
							
				}
			}
			else if(tempr->top ==NULL && tempr->bot==NULL){
				if(tempr->nodeno==pos2)
				{
					store1=tempr;
						goto label12;
				}
			}//end if;
			
			
				tempr=tempr->next;
			}//END OF CHECKING ENDING-ID
			
			label12 : //ASSIGNING ENDING POSITION
			pos22=store1->nodeno;
			
				
				
				
				
				
			}//END CHECKING POSITIONS
			
			
			
			
			
			tempr=p;
			templ=p;
			
			if(pos22>=pos11){ 
			while(tempr!=NULL){
			if(tempr->top!=NULL && tempr->bot!=NULL)
			{
				templ=tempr;
				while(templ!=NULL) //UP CHECKING
				{
					if(templ->nodeno==pos1)
					{
						templ->data=num;
						while(templ!=tempr)
						{
							templ->bot->data=templ->data;
							templ=templ->bot;
							
						}
						store1=tempr;
						goto label4;
					}
					templ=templ->top;
					
				}


					


				templ=tempr;
				while(templ!=NULL)//DOWN CHECKING
				{
					
					if(templ->nodeno==pos1)
					{
						templ->data=num;
						while(templ!=tempr)
						{
							templ->top->data=templ->data;
							templ=templ->top;
						}
						store1=tempr;
						goto label4;
					}
					
					templ=templ->bot;	
							
				}
			}//END OF FIRST IF
			else if(tempr->top!=NULL)
			{
				templ=tempr;
				while(templ!=NULL) //UP CHECKING
				{
					if(templ->nodeno==pos1)
					{
						templ->data=num;
						while(templ!=tempr)
						{
							templ->bot->data=templ->data;
							templ=templ->bot;
							
						}
						store1=tempr;
						goto label4;
					}
					templ=templ->top;
					
				}
			}//FOR ONLY TOP CHECKING
			
			else if(tempr->bot!=NULL)//for only down checking
			{
				templ=tempr;
				while(templ!=NULL)//DOWN CHECKING
				{
					
					if(templ->nodeno==pos1)
					{
						templ->data=num;
						while(templ!=tempr)
						{
							templ->top->data=templ->data;
							templ=templ->top;
						}
						store1=tempr;
						goto label4;
					}
					
					templ=templ->bot;	
							
				}
			}
			else if(tempr->top ==NULL && tempr->bot==NULL){ // SENDING FROM DEFAULT HOBE WHERE NO NODES ARE ATTACHED
				if(tempr->nodeno>=pos1)
				{
					tempr->data=num;
					//store1=tempr;
				}
			} 
			
			
				tempr=tempr->next;
			}//end if;
			
			label4 :  //MOVING OF DATA FROM LEFT
				
				tempr=store1;
				tempr=tempr->next;
				while(tempr!=NULL)
				{
						templ=tempr;
						if(tempr->top ==NULL && tempr->bot==NULL)
						{
							tempr->data=tempr->prev->data;
						}
						
						else if(tempr->top!=NULL && tempr->bot!=NULL)
						{
							tempr->data=tempr->prev->data;
							templ=tempr;
							while(templ!=NULL) //UP CHECKING
							{
								if(templ->nodeno==pos2)
								{
									templ->data=tempr->data;
									while(templ!=tempr)
									{
										templ->bot->data=templ->data;
										templ=templ->bot;
										
									}
									
									goto label7;
								}
								templ=templ->top;
								
							}
							
							templ=tempr;
							while(templ!=NULL)//DOWN CHECKING
							{
								
								if(templ->nodeno==pos2)
								{
									templ->data=tempr->prev->data;
									while(templ!=tempr)
									{
										templ->top->data=templ->data;
										templ=templ->top;
									}
									goto label7;
								}
								
								templ=templ->bot;	
										
							}
						}
						
						else if(tempr->top!=NULL)
						{
							tempr->data=tempr->prev->data;
							templ=tempr;
							while(templ!=NULL) //UP CHECKING
							{
								if(templ->nodeno==pos2)
								{
									templ->data=tempr->data;
									while(templ!=tempr)
									{
										templ->bot->data=templ->data;
										templ=templ->bot;
										
									}
									
									goto label7;
								}
								templ=templ->top;
								
							}
						}
						
						else if(tempr->bot!=NULL)
						{
							tempr->data=tempr->prev->data;
							templ=tempr;
							while(templ!=NULL)//DOWN CHECKING
							{
								
								if(templ->nodeno==pos2)
								{
									templ->data=tempr->prev->data;
									while(templ!=tempr)
									{
										templ->top->data=templ->data;
										templ=templ->top;
									}
									goto label7;
								}
								
								templ=templ->bot;	
										
							}
						}
						
						tempr=tempr->next;
				}
				
				
				label7 :
				printf("\nDATA TRANSMISSION COMPLETED.....!");
			}
			else{ //MAIN ELSE when (pos1>pos2)
			
				while(tempr!=NULL){
				if(tempr->top!=NULL && tempr->bot!=NULL)
			{
				templ=tempr;
				while(templ!=NULL) //UP CHECKING
				{
					if(templ->nodeno==pos1)
					{
						templ->data=num;
						while(templ!=tempr)
						{
							templ->bot->data=templ->data;
							templ=templ->bot;
							
						}
						store1=tempr;
						goto label9;
					}
					templ=templ->top;
					
				}


					


				templ=tempr;
				while(templ!=NULL)//DOWN CHECKING
				{
					
					if(templ->nodeno==pos1)
					{
						templ->data=num;
						while(templ!=tempr)
						{
							templ->top->data=templ->data;
							templ=templ->top;
						}
						store1=tempr;
						goto label9;
					}
					
					templ=templ->bot;	
							
				}
			}//END OF FIRST IF
			else if(tempr->top!=NULL)
			{
				templ=tempr;
				while(templ!=NULL) //UP CHECKING
				{
					if(templ->nodeno==pos1)
					{
						templ->data=num;
						while(templ!=tempr)
						{
							templ->bot->data=templ->data;
							templ=templ->bot;
							
						}
						store1=tempr;
						goto label9;
					}
					templ=templ->top;
					
				}
			}//FOR ONLY TOP CHECKING
			
			else if(tempr->bot!=NULL)//for only down checking
			{
				templ=tempr;
				while(templ!=NULL)//DOWN CHECKING
				{
					
					if(templ->nodeno==pos1)
					{
						templ->data=num;
						while(templ!=tempr)
						{
							templ->top->data=templ->data;
							templ=templ->top;
						}
						store1=tempr;
						goto label9;
					}
					
					templ=templ->bot;	
							
				}
			}
			else if(tempr->top ==NULL && tempr->bot==NULL){
				if(tempr->nodeno<=pos1 && tempr->nodeno>=pos2 )
				{
					tempr->data=num;
					store1=tempr;
						goto label9;
				}
			}//end if;
				tempr=tempr->next;
			}
			
			label9 :
			tempr=store1;
			
			tempr->prev->data=tempr->data;
			tempr=tempr->prev;
			while(tempr!=NULL){
			if(tempr->top==NULL && tempr->bot==NULL)
			{
				tempr->prev->data=tempr->data;
			}
			else if(tempr->top!=NULL && tempr->bot!=NULL)
						{
							tempr->data=tempr->next->data;
							templ=tempr;
							while(templ!=NULL) //UP CHECKING
							{
								if(templ->nodeno==pos2)
								{
									templ->data=tempr->data;
									while(templ!=tempr)
									{
										templ->bot->data=templ->data;
										templ=templ->bot;
										
									}
									
									goto label10;
								}
								templ=templ->top;
								
							}
							
							templ=tempr;
							while(templ!=NULL)//DOWN CHECKING
							{
								
								if(templ->nodeno==pos2)
								{
									templ->data=tempr->next->data;
									while(templ!=tempr)
									{
										templ->top->data=templ->data;
										templ=templ->top;
									}
									goto label10;
								}
								
								templ=templ->bot;	
										
							}
						}
						
						else if(tempr->top!=NULL)
						{
							tempr->data=tempr->next->data;
							templ=tempr;
							while(templ!=NULL) //UP CHECKING
							{
								if(templ->nodeno==pos2)
								{
									templ->data=tempr->data;
									while(templ!=tempr)
									{
										templ->bot->data=templ->data;
										templ=templ->bot;
										
									}
									
									goto label10;
								}
								templ=templ->top;
								
							}
						}
						
						else if(tempr->bot!=NULL)
						{
							tempr->data=tempr->next->data;
							templ=tempr;
							while(templ!=NULL)//DOWN CHECKING
							{
								
								if(templ->nodeno==pos2)
								{
									templ->data=tempr->next->data;
									while(templ!=tempr)
									{
										templ->top->data=templ->data;
										templ=templ->top;
									}
									goto label10;
								}
								
								templ=templ->bot;	
										
							}
						}
						
						tempr=tempr->prev;
				}
			
				
				
				label10 :
				printf("\nDATA TRANSMISSION COMPLETED.....!");
				
			
			
			
	}
}
}
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
	
				

