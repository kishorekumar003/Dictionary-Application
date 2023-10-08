#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct dict
{
	char word[20];
	char mean[50];
	struct dict *next;
};
struct dict *head = NULL;

struct dict *createnode(char word[],char meaning[])
{
	struct dict *t;
	t = (struct dict *)malloc(sizeof(struct dict));
	
	strcpy(t->word,word);
	strcpy(t->mean,meaning);
	t->next = NULL;
	return t;
}


void insert()
{
	struct dict *temp = head;
	char input_word[20];
	char word_meaning[50];
	printf("Enter Word : ");
	scanf("%s",input_word);
	
	while(temp != NULL)
	{
		if(strcmp(input_word,temp->word) == 0)
		{
			printf("Same word found dictionary\n");
			return;
		}
		temp = temp->next;
	} 
	
	printf("Enter meaning : ");
	scanf("%s",word_meaning);
	
	struct dict *newnode = createnode(input_word,word_meaning);
	
	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		struct dict *t;
		t = head;
		while(t->next != NULL)
		{
			t = t->next;
		}
		t->next = newnode;
	} 
}
void display()
{
	int i=1;
	struct dict *temp;
	temp = head;
	while(temp != NULL)
	{
		
		printf("%d. %s - %s\n",i,temp->word,temp->mean);
		i++;
		temp = temp->next;
	}
	printf("\n");
}
void search()
{
	char sw[20];
	printf("Enter the word to be searched : ");
	scanf("%s",sw);
	struct dict *temp = head;
	int result;
	while(temp != NULL)
	{
		result = strcmp(sw,temp->word);
		if(result == 0)
		{
			printf("%s - %s\n",temp->word,temp->mean);
			break;
		}
		temp = temp->next;
	}
}

int main()
{
	int opt;
	printf("Enter choise 1.insert 2.display 3.search 4.exit\n");
	while(1)
	{
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				search();
				break;
			case 4:
				exit(0);		
		}
	}
}

