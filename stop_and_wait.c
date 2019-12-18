#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void delay(int );
void main()
{
	char a[20]; //sender
	char b[20]; //receiver
	int i,y;
	for(i=0;i<20;i++)
		b[i]=-'\0';
	printf("\nENTER THE MESSAGE IN 0 & 1 ::");
	scanf("%s",a);


	int k=0,p1=0;
	char ack;
	double t=0;
	time_t start , stop ;
	while(a[k]!='\0')
	{
		if(p1>2)
		{
			printf("\nSESSION TIME OUT....!");
			exit(0);
		}


		if(a[k]=='0') //sending & receiving for first time
		{
			printf("\n-------------INITIATING TRANSMISSION-------------");
			printf("\nSENDING DATA-FRAME %c (sender)",a[k]);
			start=clock();


			b[k]=a[k]; //receiving  data frame
			printf("\nRECEIVED DATA FRAME %c (receiver)",a[k]);

		}
		else if(a[k]=='1')
		{
			printf("\n-------------INITIATING TRANSMISSION-------------");
			printf("\nSENDING DATA-FRAME %c (sender)",a[k]);
			start=clock();

			b[k]=a[k]; //receiving  data frame
			printf("\nRECEIVED DATA FRAME %c (receiver)",a[k]);


		}


		if(a[k]=='0')  //RECEIVER SIDE
		{
			printf("\n-------------------------------------------------");
			printf("\nEXPECT ACKNOWLEDGEMENT 1 (receiver)");
			printf("\nSENDING ACKNOWLEDGEMENT 1 TO SENDER TO SEND DATA-FRAME 1");
			ack='1';
		}
		else if(a[k]=='1')
		{
			printf("\n-------------------------------------------------");
			printf("\nEXPECTING ACKNOWLEDGEMENT 0 (receiver)");
			printf("\nSENDING ACKNOWLEDGEMENT 0 TO SENDER TO SEND DATA-FRAME 0");
			ack='0';
		}



		if(a[k]=='0')  //SENDERS SIDE
		{
			if(a[k+1]==ack || a[k+1]=='\0')
			{
				printf("\n-------------------------------------------------");
				printf("\nRECEIVED ACKNOWLEDGEMENT...(SENDER)");
				delay(100);
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
				printf("\nRECEIVED ACKNOWLEDGEMENT...(SENDER)");
				delay(100);
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
			printf("%d",p1);
	}
	printf("\n------------------------------------------------");
	printf("\nNO MORE DATA-FRAME LEFT TO BE TRANSMITTED");
	printf("\n------------------------------------------------");
	printf("\nDATA TRANSMITTED SUCCESSFULLY\n");
	printf("\n------------------------------------------------");
	printf("\nDATA AT RECEIVER SIDE IS::");
	int m=0;
	while(b[m]!='\0')
	{
		printf("%c",b[m]);
		m++;
	}
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


