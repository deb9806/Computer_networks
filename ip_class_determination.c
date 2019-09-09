//IP CLASS DETERMINATION

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int b_d();
int d_b();
int chartoint(char );


void main()
{
	int ch;
	while(1){
	printf("\n--------------------------------------------");
	printf("\n---------IP CLASS DETERMINATION-------------");
	printf("\n1 -> BINARY IP  \n2 -> DECIMAL IP  \n3 -> EXIT");
	printf("\nENTER THE CHOICE::");
	scanf("%d",&ch);
	switch(ch){
		
		case 1: 
			  b_d();
			  break;
		case 2 : 
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

	

int d_b()
{
	
	//int num;

	char s[60],r;
	//int p;
	
	
	printf("\nENTER THE DECIMAL IP ::");
	scanf("%s",s);
	int i=0,j,m=0,l=0,k;
	int bit1=0;
	
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
	
	
	j=j-1;
	
		if(obit1[j]==0 )
		{
			printf("\nCLASS A IP");
			return 0;
		}
		else if(obit1[j]==1 && obit1[j-1]==0 )
		{
			printf("\nCLASS B IP");
			return 0;
		}
		else if(obit1[j]==1 && obit1[j-1]==1 && obit1[j-2]==0)
		{
			 printf("\nCLASS C IP");
			return 0;
		}
		else if(obit1[j]==1 && obit1[j-1]==1 && obit1[j-2]==1 && obit1[j-3]==0)
		{
			 printf("\nCLASS D IP");
			return 0;
		}
		else if(obit1[j]==1 && obit1[j-1]==1 && obit1[j-2]==1 && obit1[j-3]==1)
		{
			 printf("\nCLASS E IP");
			return 0;
		}
	
	
	
}

int b_d()
{
	
	char s[100];
	
	char k; //TEMP VARIABLE
	printf("\nENTER THE BINARY IP (OCTAL FORMAT SEPERATED BY SPACE) ::");
	scanf("%c",&k); //FOR OVER WRITING INPUT BUFFER TO A CHARACTER
	scanf("%[^\n]s",s); //TO TAKE STRING INPUT WITH SPACE
	//printf("1");
	//gets(s);
	int j=0;
	//fgets (s, 100, stdin);
	
	
	
	
	
		if(s[j]=='0' )
		{
			
			printf("\nCLASS A IP");
			

			return 0;
		}
		else if(s[j]=='1' && s[j+1]=='0' )
		{
			
			printf("\nCLASS B IP");

	
			
			return 0;
		}
		else if(s[j]=='1' && s[j+1]=='1' && s[j+2]=='0')
		{
			
			 printf("\nCLASS C IP");

	

			
			return 0;
		}
		else if(s[j]=='1' && s[j+1]=='1' && s[j+2]=='1' && s[j+3]=='0')
		{
			
			 printf("\nCLASS D IP");
		
		
			return 0;
		}
		else if(s[j]=='1' && s[j+1]=='1' && s[j+2]=='1' && s[j+3]=='1')
		{
			
			 printf("\nCLASS E IP");
			
			return 0;
		}
		
		else 
		{
			printf("\nINVALID IP....TRY AGAIN.....!");
			return 0;
		}
	
	
	




}
		
	
	




	





















