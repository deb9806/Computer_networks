#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void t(char []	 ,int , int ,int );
void delay(int );
int aa();
void main()
{
	char a[20]; //sender
	
	printf("\nENTER THE MESSAGE IN 0 & 1 ::");
	scanf("%s",a);
	int st,ch;
	while(1)
	{
		printf("\n1 -> START TRANSMISSION \n2 -> PUSH ANAMOLIES \n3 -> EXIT");
		printf("\nENTER THE CHOICE::");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : t(a,0,0,0);
				  break;
			
			case 2 : st=aa();
				   if(st==1)
     				{
				  t(a,1,0,0);
				}
				else  if(st==2)
     				{
				  t(a,0,1,0);
				}
				else  if(st==3)
     				{
				  t(a,0,0,1);
				}
				break;
			case 3 : exit(0);
			default : printf("\nWRONG CHOICE.....!");
		}
	}

}

				  
	

int aa() //for pushing anamolies
{	
	int ch;
	label65 :
	printf("\n1 -> DATA LOST \n2 -> ACKNOWLEDGEMENT LOST \n3 -> BOTH \nENTER THE CHOICE::");
	scanf("%d",&ch);
	if(ch>4)
	{
		printf("\nINVALID....CHOICE");
		goto label65;
	}
	return(ch);
}




void t(char a[] ,int f1,int f2,int f3 )
{
	char b[20]; //receiver
	int i,y;
	for(i=0;i<20;i++)
		b[i]='\0';
	int k=0,p1=0;
	int h=0,j=0;
	if(f1==1)
	{
		h=1;
	}
	else if(f2==1)
	{

		h=2;
	}
	else if(f3==1)
	{
		h=2;
		j=3;
	}

	char ack;
	double t=0;
	time_t start , stop ;
	while(a[k]!='\0')
	{
		
			
		//printf("\n%d",h);
		if(a[k]=='0') //sending & receiving for first time
		{
			printf("\n-------------INITIATING TRANSMISSION-------------");
			printf("\nSENDING DATA-FRAME %c (sender)",a[k]);
			start=clock();
			if(f1==1 ||f3==1) //pushing delay in dataframe lost
				{
					delay(1000);
					f1=0;//resetting values
					//f3=0;
				}
			stop=clock();
			
			double t=((double)(stop-start))/CLOCKS_PER_SEC ;
			p1=(int) (t);
			//printf("%d",p1);
			if(p1>0.1 && (h==1 ||(h==2 && j==3)))
			{
				printf("\nDATA LOST....!");
				printf("\nRESENDING DATA....!");
				p1=0;
				
			}
			
			
		
			b[k]=a[k]; //receiving  data frame
			printf("\nRECEIVED DATA FRAME %c (receiver)",a[k]);
			 
		}
		
		else if(a[k]=='1')
		{
			printf("\n-------------INITIATING TRANSMISSION-------------");
			printf("\nSENDING DATA-FRAME %c (sender)",a[k]);
			start=clock();
			if(f1==1 ||f3==1) //pushing delay in dataframe lost
				{
					delay(1000);
					f1=0;//resetting values
					//f3=0;
				}
			stop=clock();
			
			double t=((double)(stop-start))/CLOCKS_PER_SEC ;
			p1=(int) (t);
			//printf("%d",p1);
			if(p1>0.1 && (h==1 ||(h==2 && j==3)))
			{
				printf("\nDATA LOST....!");
				printf("\nRESENDING DATA....!");
				p1=0;
				
			}
		
			b[k]=a[k]; //receiving  data frame
			printf("\nRECEIVED DATA FRAME %c (receiver)",a[k]);
			 
			
		}
		

		if(a[k]=='0')  //RECEIVER SIDE
		{
			printf("\n-------------------------------------------------");
			printf("\nEXPECT ACKNOWLEDGEMENT 1 (receiver)");
			printf("\nSENDING ACKNOWLEDGEMENT 1 TO SENDER TO SEND DATA-FRAME 1");
			ack='1';
			start=clock(); //starting clock
			if(f2==1 ||f3==1) //pushing delay acknowledgement lost
				{
					delay(1000);
					f2=0;//resetting values
					f3=0;
				}
		}
		else if(a[k]=='1')
		{
			printf("\n-------------------------------------------------");
			printf("\nEXPECTING ACKNOWLEDGEMENT 0 (receiver)");
			printf("\nSENDING ACKNOWLEDGEMENT 0 TO SENDER TO SEND DATA-FRAME 0");
			ack='0';
			start=clock(); //starting clock
			if(f2==1 ||f3==1) //pushing delay acknowledgement lost
				{
					delay(1000);
					f2=0;//resetting values
					f3=0;
				}
		}

		

		if(a[k]=='0')  //SENDERS SIDE
		{
			if(a[k+1]==ack || a[k+1]=='\0')
			{
				printf("\n-------------------------------------------------");
				if(h!=2 || (h!=2 && j!=3))
				{
					printf("\nRECEIVED ACKNOWLEDGEMENT...(SENDER)");
				}
				
				stop=clock();
				
				goto label1;
			}
			else
			{
				printf("\n-------------------------------------------------");
				printf("\nEXPECTED DATA 1 NOT PRESENT (receiver)");
				printf("\nERROR IN DATA....TANSMISSION TERMINATED");
				exit(0);
			}
		}
		else if(a[k]=='1')
		{
			if(a[k+1]==ack || a[k+1]=='\0')
			{
				printf("\n-------------------------------------------------");
				if(h!=2 || (h!=2 && j!=3))
				{
					printf("\nRECEIVED ACKNOWLEDGEMENT...(SENDER)");
				}
				
				stop=clock();
				
				goto label1;
			}
			else
			{
				printf("\n-------------------------------------------------");
				printf("\nEXPECTED DATA 0 NOT PRESENT (receiver)");
				printf("\nERROR IN DATA....TANSMISSION TERMINATED");
				exit(0);
			}
		}
			
		label1 : 
			k++;
			double t=((double)(stop-start))/CLOCKS_PER_SEC ;
			p1=(int) (t);
			//printf("%d",p1);
			if(p1>0.1 && (h==2 ||h==3) )
			{
				printf("\nACKNOWLEDGEMENT LOST....!");
				printf("\nRESENDING ACKNOWLEDGEMENT....!");
				p1=0;
				h=0;
				j=0;
				printf("\nRECEIVED ACKNOWLEDGEMENT...(SENDER)");
			}




	}
	printf("\n------------------------------------------------");
	printf("\nNO MORE DATA-FRAME LEFT TO BE TRANSMITTED");
	
	printf("\nDATA TRANSMITTED SUCCESSFULLY\n");
	
	printf("\nDATA AT RECEIVER SIDE IS::");
	int m=0;
	while(b[m]!='\0')
	{
		printf("%c",b[m]);
		m++;
	}
}


void delay(int ns) 
{ 
    // Converting time into milli_seconds 
    int ms = 1000 * ns; 
	
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + ms) 
        ;
} 
			
	
