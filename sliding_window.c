#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void main()
{
	time_t start,stop;
	char a[20]; //sender
	
	char c[20];//receiver array
	int i,d;
	for(i=0;i<20;i++)
		c[i]='\0';
	
	printf("\nENTER THE MESSAGE IN 0 & 1 ::");
	scanf("%s",a);
	printf("\nENTER THE WINDOW SIZE::");
	scanf("%d",&d);
	char b[d]; //window size
	int k1=0,k2=0,k3=0,k4=0,ack=0,p1=0;
	
	while(a[k1]!='\0')
	{
		k2=0;
		ack++;
		printf("\n%d SLIDE",ack);
		printf("\nDATA TRANSMITTED IN %d SLIDE::",ack);
		
		start=clock(); //starting clock
		while(k2<d)
		{
			if(a[k1]=='\0')
				goto label1;
			printf("%c",a[k1]);
			b[k2]=a[k1]; //sending into window array
			
			k2++;
			k1++;
		}
		
		label1 :
		k3=0;
		while(k2>0)
		{
			c[k4]=b[k3]; //assigning to receiver
			
			k3++;
			k4++;
			k2--;
		}
		stop=clock(); //stopping clock
		
		double t=((double)(stop-start))/CLOCKS_PER_SEC ;
		p1=(int) (t);
		
		if(p1>0.5)
		{
			printf("\nDelay In Transmission");
			p1=0;
		}
			
		
		printf("\nDATA RECEIVED...SENDING ACKNOWLEDGEMENT (RECEIVER)");
		
	}
	printf("\nDATA TRANSMISSION COMPLETED in %d SLIDES",ack);
	printf("\nDATA AT RECEIVER SIDE IS::");
	k1=0;
	while(c[k1]!='\0')
	{
		printf("%c",c[k1]);
		k1++;
	}
}
		
		
		
			
		
	
