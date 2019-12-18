#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int b_d(int num);
void main()
{
	char a[4],b[7],c[7];
	label1 :
	printf("\n---USING 7-BIT HAMMING CODE ALGORITHM---");
	printf("\nENTER THE MESSAGE IN 0 & 1 (4 DATA BITS ONLY) ::");
	scanf("%s",a);
	int i,l1=strlen(a);
	
	
	if(l1>4)
	{
		printf("\nLENGTH GREATER THAN 4....!");
		goto label1;
	}
	
	int k1;
	for(k1=0;k1<4;k1++) 
	{
		if(k1==3)
			b[4]=a[k1];
		
		b[k1]=a[k1];
	}
		
	//calculation of parity of 3rd bit
	
	int k2=0,p3,p5,p6;
	
	if(b[0]=='1')
		k2++;
	
	if(b[1]=='1')
		k2++;
	
	if(b[2]=='1')
		k2++;
	
	
	if(k2%2 == 1)
	{
		b[3]='1';
	}
	else
	{
		b[3]='0';
	}
	
	//calculation of parity of 5th bit
	
	 k2=0;
	 
	if(b[0]=='1')
		k2++;
	
	if(b[1]=='1')
		k2++;
	
	if(b[4]=='1')
		k2++;
		
	
	
	if(k2%2 == 1)
	{
		b[5]='1';
	}
	else
	{
		b[5]='0';
	}
	
	//calculation of parity of 6th bit
	
	 k2=0;
	 
	if(b[0]=='1')
		k2++;
	
	if(b[2]=='1')
		k2++;
	
	if(b[4]=='1')
		k2++;
		
	
	
	if(k2%2 == 1)
	{
		b[6]='1';
	}
	else
	{
		b[6]='0';
	}
	
	printf("\nDATA AFTER ADDING PARITY::");
	for(k1=0;k1<7;k1++)
		printf("%c",b[k1]);
	
	
	int er=0;
	er=rand()%3; //choosing random bit
	printf("\n\n--PUSHING ERROR--");
	if(b[er]=='1') //PUSHING ERROR
		b[er]='0';
	else
		b[er]='1';
	
	printf("\nDATA AFTER ADDING ERROR::");
	for(k1=0;k1<7;k1++)
		printf("%c",b[k1]);
	
	
	printf("\n\n----SENDING DATA TO RECEIVER------");
	for(i=0;i<7;i++)
		c[i]=b[i];
	printf("\n\n----DATA RECEIVED FROM SENDER---");
	
	
	//detecting error in 3rd parity bit
	
	k1=0,k2=0,p3=0;
	
	
	if(c[0]=='1')
	k2++;
	
	if(c[1]=='1')
		k2++;
	
	if(c[2]=='1')
		k2++;
	
	
	if(k2%2 == 1)
	{
		if(c[3]=='1')
		{
			p3=0;
		}
		else
		{
			p3=1;
		}
	}
	else
	{
		if(c[3]=='0')
		{
			p3=0;
		}
		else
		{
			p3=1;
		}
		
	}
	
	
	//detecting error in 5th parity bit
	
	k1=0,k2=0,p5=0;
	
	
	
	if(c[0]=='1')
		k2++;
	
	if(c[1]=='1')
		k2++;
	
	if(c[4]=='1')
		k2++;
		
	
	
	if(k2%2 == 1)
	{
		if(c[5]=='1')
			p5=0;
		else
			p5=1;
			
	}
	else
	{
		if(c[5]=='0')
			p5=0;
		else
			p5=1;
	}
	

	//detecting error in 6th parity bit
	
	k1=0,k2=0,p6=0;
	
	
	
	if(c[0]=='1')
		k2++;
	
	if(c[2]=='1')
		k2++;
	
	if(c[4]=='1')
		k2++;
		
	
	
	if(k2%2 == 1)
	{
		if(c[6]=='1')
			p6=0;
		else
			p6=1;
			
	}
	else
	{
		if(c[6]=='0')
			p6=0;
		else
			p6=1;
	}
	
	int num1,num=p3;
	num=(num * 10) + p5;
	num=(num * 10) + p6;
	num1=b_d(num);
	num1=8-num1;
	printf("\n\nERROR OCCURED IN %d BIT",num1);
	
	printf("\n\n----CORRECTING ERROR----");
	
	if(c[num1-1]=='0')
		c[num1-1]='1';
	else
		c[num1-1]='0';
	
	printf("\nDATA RECEIVED (RECEIVER)::");
	for(i=0;i<3;i++)
		printf("%c",c[i]);
	
	printf("%c",c[4]);
	
	
	
	
	
	
	
	
}




int b_d(int num)
{
    int   decimal_val = 0, base = 1, rem;
 
    
    
    while (num > 0)
    {
        rem = num % 10;
        decimal_val = decimal_val + rem * base;
        num = num / 10 ;
        base = base * 2;
    }
   return (decimal_val);
}