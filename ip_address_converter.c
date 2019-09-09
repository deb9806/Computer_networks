//IP ADDRESS CONVERTER

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void b_d();
void d_b();
int chartoint(char );


void main()
{
	int ch;
	while(1){
	printf("\n--------------------------------------------");
	printf("\n1 -> BINARY IP TO DECIMAL IP \n2 -> DECIMAL IP TO BINARY IP \n3 -> EXIT");
	printf("\nENTER THE CHOICE::");
	scanf("%d",&ch);
	switch(ch){
		
		case 1: printf("\n----BINARY IP TO DECIMAL IP CONVERSION------");
			  b_d();
			  break;
		case 2 : printf("\n----DECIMAL IP TO BINARY IP CONVERSION------");
			   d_b();
			   break;
		case 3 : printf("\nEXIT...!");
			   exit(0);
		default : printf("\nWRONG CHOICE");
		}
	}
}

int chartoint(char n)
{
	if(n=='0')
		return 0;
	else if(n=='1')
		return 1;
	else if(n=='2')
		return 2;
	else if(n=='3')
		return 3;
	else if(n=='4')
		return 4;
	else if(n=='5')
		return 5;
	else if(n=='6')
		return 6;
	else if(n=='7')
		return 7;
	else if(n=='8')
		return 8;
	else if(n=='9')
		return 9;

}

	

void d_b()
{
	
	int num;

	char s[60],r;
	int p;
	/*for(p=0;p<60;p++)
		s[p]='.'; */
	
	printf("\nENTER THE DECIMAL IP TO CONVERT INTO BINARY IP::");
	scanf("%s",s);
	int i=0,j,m=0,l=0,k;
	int bit1=0,bit2=0,bit3=0,bit4=0;
	//FIRST BIT
	printf("\nIP IN BINARY FORMAT IS :: ");
	while(s[i]!='.' )
	{
		
		bit1=bit1*10 + chartoint(s[i]);
		i++;
	}
	
	int obit1[60];
	//int bit11=bit1; //STORING BIT1
	for(j=0;bit1>0;j++)
	{
		//obit1[j]=0;
		obit1[j]= (bit1 %2);
		
		bit1=bit1/2;
		m++;
		
	}
	
	//FOR ADDING ZEROS

	for(k=0;k<8-m;k++)
	{
		obit1[j]=0;
		j++;
		
	}
	
	
	
	
	


	for(j=j-1;j>=0;j--) //PRINTING VALUES
	{
	printf("%d",obit1[j]);
	}
	printf(".");
	//int k=i; //STRORING PREVIOUS VALUE OF I
	
 //SECOND BIT
	i=i+1;	

	while(s[i]!='.' )
	{
		//printf("1");
		bit2=bit2*10 + chartoint(s[i]);
		i++;
	}
	//printf("\n%d\n",bit2);
	int obit2[60];
	m=0;
	for(j=0;bit2>0;j++)
	{
		obit2[j]= (bit2 %2);
		bit2=bit2/2;
		m++;
	}


	for(k=0;k<8-m;k++)
	{
		obit2[j]=0;
		j++;
		
	}

	for(j=j-1;j>=0;j--)
	{
	printf("%d",obit2[j]);
	}
	
	//THIRD BIT
	printf(".");
	i=i+1;	

	while(s[i]!='.')
	{
		
		bit3=bit3*10 + chartoint(s[i]);
		i++;
	}
	
	int obit3[60];
	m=0;
	for(j=0;bit3>0;j++)
	{
		obit3[j]= (bit3 %2);
		bit3=bit3/2;
		m++;
	}


	for(k=0;k<8-m;k++)
	{
		obit3[j]=0;
		j++;
		
	}

	for(j=j-1;j>=0;j--)
	{
	printf("%d",obit3[j]);
	}

	//fourth bit
	printf(".");
	i=i+1;	

	while(s[i]!='\0' )  //&& i!=num
	{
		
		bit4=bit4*10 + chartoint(s[i]);
		i++;
		
	}
	
	
	
	int obit4[60];
	m=0;
	for(j=0;bit4>0;j++)
	{
		obit4[j]= (bit4 %2);
		bit4=bit4/2;
		m++;
	}
	

	for(k=0;k<8-m;k++)
	{
		obit4[j]=0;
		j++;
		
	}
	for(j=j-1;j>=0;j--)
	{
	printf("%d",obit4[j]);
	}


	
		
	
}

void b_d()
{
	char s[40],temp;
	printf("\nENTER THE BINARY IP (OCTAL FORMAT SEPERATED BY SPACE) TO CONVERT INTO DECIMAL IP ::");
	scanf("%c",&temp); //FLUSHING INPUT BUFFER WITH PREVIOUSLY STORED INTEGER
	scanf("%[^\n]s",s); //STORING STRING WITH SPACE
	int bit1=0,bit2=0,num;
	int i=0;
	printf("\nIP IN DECIMAL FORMAT IS :: ");
	//FIRST BIT CALCULATION
	while(s[i]!=' ')
	{
		bit1=bit1*10 +chartoint(s[i]);
		i++;
		
	}
	
	int num1=0,base=1;
	while(bit1>0) //CONVERSION OF FIRST BIT
	{
		
		num=bit1%10;
		num1=num1 + (num*base);
		base= base *2;
		bit1=bit1/10;
		
	}
	printf("%d.",num1); //PRINTING FIRST BIT

	i=i+1 ;//INCREMENT OF I AFTER THE 

	while(s[i]!=' ') //SECOND BIT CALCULATION
	{
		bit2=bit2*10 +chartoint(s[i]);
		i++;
		//printf("\na");
	}
	
	 num1=0,base=1;
	while(bit2>0) //CONVERSION OF SECOND BIT
	{
		
		num=bit2%10;
		num1=num1 + (num*base);
		base= base *2;
		bit2=bit2/10;
		
	}
	printf("%d.",num1); //PRINTING OF SECOND BIT */



		i=i+1 ;//INCREMENT OF I AFTER THE 

	while(s[i]!=' ') //THIRD BIT CALCULATION
	{
		bit2=bit2*10 +chartoint(s[i]);
		i++;
		//printf("\na");
	}
	
	 num1=0,base=1;
	while(bit2>0) //CONVERSION OF THIRD BIT
	{
		
		num=bit2%10;
		num1=num1 + (num*base);
		base= base *2;
		bit2=bit2/10;
		
	}
	printf("%d.",num1);

	i=i+1;
	
	int j=1; 
	while(j<=8) //FOURTH BIT CALCULATION
	{
		bit2=bit2*10 +chartoint(s[i]);
		i++;
		j++;
	}
	num1=0,base=1;
	
	while(bit2>0) //CONVERSION OF FOURTH BIT
	{
		
		num=bit2%10;
		num1=num1 + (num*base);
		base= base *2;
		bit2=bit2/10;
		
	}
	printf("%d",num1);



}
		
	
	




	





















