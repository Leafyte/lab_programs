#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define HASH_SIZE 100

typedef struct employee
{
	int id;
	char name[20];
}EMPLOYEE;

void initialize(EMPLOYEE a[])
{
	int i;
	for(i=0; i<HASH_SIZE; i++)
	{
		a[i].id=0;
	}
}

int H(int k)
{
	return k%HASH_SIZE;
}

void insert(int id, char name[], EMPLOYEE a[])
{
	int i,index,h_value;
	h_value= H(id);
	for(i=0; i<HASH_SIZE; i++)
	{
		index=(h_value+i)% HASH_SIZE;
		if(a[index].id==0)	
		{
			a[index].id=id;		
			strcpy(a[index].name,name);	
			break;
		}
	}
	if(i==HASH_SIZE) printf("Hash table full\n"); 
}

void display(EMPLOYEE a[], int n)
{
	int k,i;
	printf("H_Value\t Emp_id\t Emp_name\n");
	for(i=0; i<HASH_SIZE; i++)
	{
		if(a[i].id!=0)
printf("%d\t %d\t %s\n",i,a[i].id,a[i].name);
	}
}

void main()
{
	EMPLOYEE a[HASH_SIZE];
	char name[20];
	int key,id,choice,flag;
	initialize(a);	
	for(;;)
	{
		printf(" 1:Insert\n 2:Display\n 3:Exit\n");
		printf("Enter the choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter emp id:");
				scanf("%d",&id);
				printf("Enter the name:");
				scanf("%s",name);
				insert(id,name,a);
				break;
			case 2: printf("Contents of hash table\n");
				display(a,HASH_SIZE);
				printf("\n");
				break;
			case 3: exit(0);
			deafult: printf("Enter valid choice\n");
		}
	}
}
