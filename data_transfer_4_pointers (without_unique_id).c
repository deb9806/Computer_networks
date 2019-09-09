//DATA TRANSFER 4 POINTERS (WITHOUT UNIQUE ID)


#include<stdio.h>
#include<stdlib.h>

struct node{
struct node *prev;
struct node *top;
int data;
struct node *bot;
struct node*next;
};
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
	temp=p;
	if(temp==NULL)
	{
		int num;
		struct node *nw;
		nw=(struct node *)malloc(sizeof(struct node));
		/*printf("\nENTER THE DATA TO BE INSERTED IN THE FIRST NODE::");
		scanf("%d",&num);*/
		nw->data=0;
		nw->next=NULL;
		nw->prev=NULL;
		nw->top=NULL;
		nw->bot=NULL;
		p=nw;
	}
	else{
	
		struct node *tempt,*tempd,*tempr,*templ;
		//tempt=p;
		//tempd=p;
		tempr=p;
		templ=p;
		
		int num,nnum;
		label1:
		printf("\nENTER THE NODE WHERE TO BE INSERTED::");
		scanf("%d",&nnum);
		int e=countr();
		if(nnum>e)
		{
			printf("\nINVALID NODE NO....! PLEASE TRY AGAIN...!");
			goto label1;
		}
		
		int j;
		for(j=1;j<nnum;j++)
		{	//printf("%d",j);
			
		tempr=tempr->next;}
		
		printf("\nENTER THE POSITION DATA TO BE INSERTED::\n1 -> TOP (CHANNEL 1) \n2 -> RIGHT (CHANNEL 2)\n3 -> BOTTOM (CHANNEL 3)\n ENTER THE CHOICE::");
		scanf("%d",&num);
		struct node *nw;
		nw=(struct node *)malloc(sizeof(struct node));
		/*int tcount=1,dcount=1;
		int t=countt(tcount);
		int d=countd(dcount);
		int l=countl();
		int r=countr();*/
		switch(num){
		
			case 1: 
				
					while(tempr->top!=NULL)
						tempr=tempr->top;
							
					nw->bot=tempr;
					nw->top=NULL;
					nw->prev=NULL;
					nw->data=0;
					nw->next=NULL;
					tempr->top=nw;
					
				
					break;
				
			
			case 2: nw->data=0;
					nw->next=NULL;
					nw->top=NULL;
					nw->bot=NULL;
					nw->prev=tempr;
					tempr->next=nw;
					break;
					
			case 3: 
					while(tempr->bot!=NULL)
						tempr=tempr->bot;
					
					nw->bot=NULL;
					nw->top=tempr;
					nw->prev=NULL;
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
	
		
	
	if(temp->top!=NULL){
		for(i=1;i<n;i++)
			temp=temp->next;
		temp=temp->top; //INCREASING THE TOP TO +1 CAUSE FIRST ONE IS BASE ONE
	while(temp!=NULL)
	{
		c=c+1;
		temp=temp->top;
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
	
	if(temp->bot!=NULL){
		for(i=1;i<n;i++)
			temp=temp->next;
		temp=temp->bot;   //COUNTING DOWN FROM NEXT STATE SO ELIMINATING BASE ONE
	while(temp!=NULL)
	{
		c=c+1; 
		temp=temp->bot;
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
		
		
		
		int nval=0; //NODE VALUE COUNT
		int snval=0; //SUB-NODE VALUE COUNT
		int hval=0; //SUB HUB VALUE COUNT
		while(tempr!=NULL)
		{
			
			
			
			
			
			/*if(tempr->top==NULL && tempr->bot==NULL && tempr->prev==NULL) //INCASE OF FIRST NODE
				printf("\nFIRST-NODE %d AND VALUE::%d",nval+1,tempr->data);
			
			else if(tempr->next==NULL && tempr->bot==NULL && tempr->prev==NULL) //INCASE OF FIRST NODE (HAVING ONLY TOP NODES)
				printf("\nFIRST-NODE %d AND VALUE::%d",nval+1,tempr->data);
			else if(tempr->top==NULL && tempr->next==NULL && tempr->prev==NULL) //INCASE OF FIRST NODE (HAVING ONLY DOWN NODES)
				printf("\nFIRST-NODE %d AND VALUE::%d",nval+1,tempr->data);
			else if(tempr->top==NULL && tempr->bot==NULL && tempr->next==NULL) //IN CASE OF LAST NODE
				printf("\nLAST-NODE %d AND VALUE::%d",nval+1,tempr->data);
				
			else if(tempr->top==NULL && tempr->bot==NULL && tempr->next!=NULL) // INCASE OF INTERMEDIATE
				printf("\nSUB-NODE %d AND VALUE::%d",snval+1,tempr->data);
			else if(tempr->top!=NULL && tempr->bot!=NULL||tempr->top!=NULL && tempr->next!=NULL||tempr->top!=NULL && tempr->prev!=NULL||tempr->next!=NULL && tempr->bot!=NULL||tempr->prev!=NULL && tempr->bot!=NULL )
					printf("\nSUB-HUB %d AND VALUE::%d",hval+1,tempr->data);
				else
					printf("\nLAST-NODE  AND VALUE::%d",tempr->data);*/
			
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
				printf("\nULTIMATE-TOP-NODE OF NODE %d & VALUE IS::%d",hval+1,tempt->data); 
				
				tempt=tempt->bot; //GOING TO ONE STEP DOWN TO BOTTOM
				
				while(tempr!=tempt)
				{
					printf("\nTOP-SUBNODE OF NODE %d IS :: %d AND NODE-NO::%d",hval+1,c+1,tempt->data);
					c=c+1;
					tempt=tempt->bot;
				}
			}
			
			printf("\n**MAIN--NODE** %d ==> DATA %d",hval+1,tempr->data);
			
			//PRINTING DOWN SUB NODES
			if(tempr->bot!=NULL)
			{
				int c=0;
					tempd=tempr;
					tempd=tempd->bot;
				while(tempd->bot!=NULL)
				{
					printf("\nDOWN-SUBNODE OF NODE %d IS :: %d & NODE-NO::%d",hval+1,c+1,tempd->data);
					c=c+1;
					tempd=tempd->bot;
				}
				printf("\nULTIMATE-DOWN-NODE OF NODE %d & VALUE IS::%d",hval+1,tempd->data);
				
				
					
			}
			
			printf("\n----------------------------------------------------------------");
			/*//ASSIGINING THE POINTERS FOR NEXT ITERATION
			if(tempr->top==NULL && tempr->bot==NULL && tempr->prev==NULL)
				nval=nval+1;
			else if(tempr->next==NULL && tempr->bot==NULL && tempr->prev==NULL)
				nval=nval+1;
			else if(tempr->top==NULL && tempr->next==NULL && tempr->prev==NULL)
				nval=nval+1;
			else if(tempr->top==NULL && tempr->bot==NULL && tempr->next==NULL)
				nval=nval+1;
			else if(tempr->top==NULL && tempr->bot==NULL && tempr->next!=NULL)
				snval=snval+1;
			else if(tempr->top!=NULL && tempr->bot!=NULL||tempr->top!=NULL && tempr->next!=NULL||tempr->top!=NULL && tempr->prev!=NULL||tempr->next!=NULL && tempr->bot!=NULL||tempr->prev!=NULL && tempr->bot!=NULL )
				hval=hval+1;*/
			
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
		printf("\nLIST IS EMPTY");
	}
	
	else{
			int totalnodes=countr();
			int pos1,pos2;
			label2 :
			printf("\nENTER THE STARTING NODE & ENDING NODE TO TRANSFER DATA::");
			scanf("%d%d",&pos1,&pos2);
			if(pos1 > totalnodes || pos2 > totalnodes)
			{
				printf("\nINVALID NODES SELECTION...PLEASE TRY AGAIN....!");
				goto label2;
			}
			int i;
			
			if(pos2>=pos1) {
			struct node *tempr,*tempr1;
			tempr=p;
			
			int num;
			printf("\nENTER THE NUMBER FOR DATA TANSFER::");
			scanf("%d",&num);
			int i;
			for(i=1;i<pos1;i++)
				tempr=tempr->next;
			tempr->data=num;
			
			tempr1=tempr; //STORING THE CURRENT TEMP POSITION
			
			//setting position from where to start transfer
			
			
			
				if(tempr->top!=NULL && tempr->bot!=NULL)
			{
				int ch;
				printf("\nENTER THE NODE FROM WHERE TO TRANSFER:: \n1 -> ULTIMATE TOP NODE \n2 -> ULTIMATE BOTTOM NODE");
				printf("\nENTER THE CHOICE::");
				scanf("%d",&ch);
				switch(ch){
							
							
							
							case 1: while(tempr->top!=NULL)
								{tempr->top->data=tempr->data;
								tempr=tempr->top;}
									
									break;
							case 2 : while(tempr->bot!=NULL)
									{tempr->bot->data=tempr->data;
									tempr=tempr->bot;}
									
									break;
							
							default: printf("\nWRONG CHOICE");
							
						}
			}
			
			
			else if(tempr->top!=NULL)
			{
				while(tempr->top!=NULL)
					{
					tempr->top->data=tempr->data;
					tempr=tempr->top;
					}
					
			}
			
			else if(tempr->bot!=NULL)
			{
				while(tempr->bot!=NULL)
					{tempr->bot->data=tempr->data;
					tempr=tempr->bot;}
					
			}
			
			
			
			tempr=tempr1; //RESTORING THE CURRENT TEMP POSITION
			
			
			//setting where to transfer
			
			
			for(i=pos1;i<pos2;i++)
			{
				tempr->next->data=tempr->data;
				tempr=tempr->next;
			}
			
			if(tempr->top!=NULL & tempr->bot!=NULL)
			{
				int ch;
				printf("\nENTER THE NODE TO TRANSFER:: \n1 -> ULTIMATE TOP NODE \n2 -> ULTIMATE BOTTOM NODE"); 
				printf("\nENTER THE CHOICE::");
				scanf("%d",&ch);
				switch(ch){
							
							
							
							case 1: while(tempr->top!=NULL)
								{tempr->top->data=tempr->data;
								tempr=tempr->top;}
									printf("\nDATA TRANSMISSION COMPLETED");
									break;
							case 2 : while(tempr->bot!=NULL)
									{tempr->bot->data=tempr->data;
									tempr=tempr->bot;}
									printf("\nDATA TRANSMISSION COMPLETED");
									break;
							
							default: printf("\nWRONG CHOICE");
							
						}
			}
			
			else if(tempr->top!=NULL)
			{
				while(tempr->top!=NULL)
					{
					tempr->top->data=tempr->data;
					tempr=tempr->top;}
					printf("\nDATA TRANSMISSION COMPLETED");
			}
			
			else if(tempr->bot!=NULL)
			{
				while(tempr->bot!=NULL)
					{tempr->bot->data=tempr->data;
					tempr=tempr->bot;}
					printf("\nDATA TRANSMISSION COMPLETED");
			}
				
			} //END OF IF (pos2>pos1)
			
			
			else{ // while (pos1> pos2)
				
				struct node *tempr , *tempr1;
				tempr=p;
				int num;
				printf("\nENTER THE NUMBER FOR DATA TANSFER::");
				scanf("%d",&num);
				
				for(i=1;i<pos1;i++)
					tempr=tempr->next;
				tempr->data=num;
				
				
				tempr1=tempr; //STORING CURRENT TEMP HEAD POSITION
				
					if(tempr->top!=NULL && tempr->bot!=NULL)
			{
				int ch;
				printf("\nENTER THE NODE FROM WHERE TO TRANSFER:: \n1 -> ULTIMATE TOP NODE \n2 -> ULTIMATE BOTTOM NODE"); 
				printf("\nENTER THE CHOICE::");
				scanf("%d",&ch);
				switch(ch){
							
							
							
							case 1: while(tempr->top!=NULL)
								{tempr->top->data=tempr->data;
								tempr=tempr->top;}
									
									break;
							case 2 : while(tempr->bot!=NULL)
									{tempr->bot->data=tempr->data;
									tempr=tempr->bot;}
									
									break;
							
							default: printf("\nWRONG CHOICE");
							
						}
			}
			
			
			else if(tempr->top!=NULL)
			{
				while(tempr->top!=NULL)
					{
					tempr->top->data=tempr->data;
					tempr=tempr->top;
					}
					
			}
			
			else if(tempr->bot!=NULL)
			{
				while(tempr->bot!=NULL)
					{tempr->bot->data=tempr->data;
					tempr=tempr->bot;}
					
			}
				
				
			tempr=tempr1; //RESTORING THE CURRENT HEAD POSITION
				
				
				
				
				
				
				
				
				
				for(i=pos1;i>pos2;i--)
				{
					tempr->prev->data=tempr->data;
					tempr=tempr->prev;
				}
				
				if(tempr->top!=NULL & tempr->bot!=NULL)
			{
				int ch;
				printf("\nENTER THE NODE TO TRANSFER:: \n1 -> ULTIMATE TOP NODE \n2 -> ULTIMATE BOTTOM NODE"); 
				printf("\nENTER THE CHOICE::");
				scanf("%d",&ch);
				switch(ch){
							
							
							
							case 1: while(tempr->top!=NULL)
								{tempr->top->data=tempr->data;
								tempr=tempr->top;}
									printf("\nDATA TRANSMISSION COMPLETED");
									break;
							case 2 : while(tempr->bot!=NULL)
									{tempr->bot->data=tempr->data;
									tempr=tempr->bot;}
									printf("\nDATA TRANSMISSION COMPLETED");
									break;
							
							default: printf("\nWRONG CHOICE");
							
						}
			}
			
			else if(tempr->top!=NULL)
			{
				while(tempr->top!=NULL)
					{
					tempr->top->data=tempr->data;
					tempr=tempr->top;}
					printf("\nDATA TRANSMISSION COMPLETED");
			}
			
			else if(tempr->bot!=NULL)
			{
				while(tempr->bot!=NULL)
					{tempr->bot->data=tempr->data;
					tempr=tempr->bot;}
					printf("\nDATA TRANSMISSION COMPLETED");
			}
				
				
				
				
			}
				
	}
}
									
									
									
									



		

		
		
