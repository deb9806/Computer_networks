#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void delay(int );

void main()
{
	int i,f1=0,f2=0,f3=0;
	char a1[20],a2[20],b1[20],b2[20],c1[20],c2[20];
	for(i=0;i<20;i++)
	{
		a2[i]='\0';
		b2[i]='\0';		
		c2[i]='\0';
	}
	int k1=0,k2=0,k3=0,c,l=1;
	printf("\n----SLOTTED ALOHA---");
	printf("\n----USING 3 WORK STATIONS----");
	
	printf("\nENTER THE DATA TO BE SEND BY FIRST SENDER::");
	scanf("%s",a1);
	
	printf("\nENTER THE DATA TO BE SEND BY SECOND SENDER::");
	scanf("%s",b1);
	

	printf("\nENTER THE DATA TO BE SEND BY THIRD SENDER::");
	scanf("%s",c1);
	int g1,g2,g3;
	while((a1[k1] != '\0') || (b1[k2] != '\0') || (c1[k3] != '\0'))
	{
		
		c=rand()%3;
	
		if(c==0 )
		{
			if(a1[k1]=='\0')
			{
				if(f1==0)
				{
					printf("\n\n***TRANSMISSION FROM A COMPLETED in %d TIME SLOT***",g1);
					f1++;
					
				}
				l=l-1;
				goto label1;
			}
			printf("\n\n--STARTING TRANSMISSION FROM A--");
			printf("\n--USING %d TIME SLOT",l);
			g1=l;
			a2[k1]=a1[k1];
			delay(1000);
			printf("\n--TRANSMISSION FROM B & C ARE ABORTED--");
			k1++;
			goto label1;
		}
		
		if(c==1 )
		{
			if(b1[k2]=='\0')
			{
				if(f2==0)
				{
					printf("\n\n***TRANSMISSION FROM B COMPLETED in %d TIME SLOT***",g2);
					f2++;
					
				}
				
				l=l-1;
				goto label1;
			}
			printf("\n\n--STARTING TRANSMISSION FROM B--");
			printf("\n--USING %d TIME SLOT",l);
			g2=l;
			b2[k2]=b1[k2];
			delay(1000);
			printf("\n--TRANSMISSION FROM A & C ARE ABORTED--");
			k2++;
			goto label1;
		}

		if(c==2 )
		{
			if(c1[k3]=='\0')
			{
				if(f3==0)
				{
					printf("\n\n***TRANSMISSION FROM C COMPLETED in %d TIME SLOT***",g3);
					f3++;
					
				}
				
				l=l-1;
				goto label1;
			}
			printf("\n\n--STARTING TRANSMISSION FROM C--");
			printf("\n--USING %d TIME SLOT",l);
			g3=l;
			c2[k3]=c1[k3];
			delay(1000);
			printf("\n--TRANSMISSION FROM A & B ARE ABORTED--");
			k3++;
			goto label1;
		}


	label1 :
		 l=l+1;
	}
	
	
	if(f1==0)
	{
		printf("\n\n***TRANSMISSION FROM A COMPLETED in %d TIME SLOT***",g1);
				
	}
    if(f2==0)
	{
		printf("\n\n***TRANSMISSION FROM B COMPLETED in %d TIME SLOT***",g2);
				
	}
	 if(f3==0)
	{
		printf("\n\n***TRANSMISSION FROM C COMPLETED in %d TIME SLOT***",g3);
				
	}
		
	printf("\n\n--TANSMISSION COMPLETED--");
	printf("\nDATA RECEIVED BY 1ST RECEIVER::%s",a2);
	
	printf("\nDATA RECEIVED BY 2nd RECEIVER::%s",b2);
	
	
	printf("\nDATA RECEIVED BY 3rd RECEIVER::%s",c2);
	
	

	

}
	
	



void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ; 
} 
