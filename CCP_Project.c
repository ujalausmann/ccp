#include <stdio.h>
#include<string.h>

#define num_candidate 3
#define candidate_name 40

char candidate[num_candidate][candidate_name]={"Candidate 1", "Candidate 2", "Candidate 3"};
int votes[num_candidate]={0,0,0}; //initializing votes to 0 for each candidiate
int i; //for loop

void Menu();
void Results();

int main()
{
	int choice;
	int r=1;
	while(r==1)
	{
		Menu(); //display menu first
			printf("\nEnter choice : ");
	scanf("%d",&choice);
	
		if(choice>=1 && choice<=3)
		{
			votes[choice-1]++;
			printf("\n%s : Vote has been cast!\n\n\n\n",candidate[choice-1]);
		}
		else if(choice==4) //num_candidate+1
		{
			Results();
		}
		else if(choice==5) //num_candidate + 2
		{
			r=0;
			printf("\t\tEXIT\t\t\n");
		}
		else
		{
			printf("Invalid choice!\n\n\n\n"); //if choice>0 && choice<5
		}
		
	}
	return 0;
	//choice 1-3 = take votes for respective candidates
	//choice 4 = display result
	//choice 5 = exit program
}

void Menu()
{
printf("\t\tVOTING SYSTEM\t\t\n\n");
printf("\t\tMENU\t\t\n\n");
for(i=0;i<num_candidate;i++)
{
   printf("[%d]: Vote for %s\n",i+1,candidate[i]); 
}
printf("[%d]: Display Result\n",num_candidate + 1); //4
printf("[%d]: Exit\n",num_candidate + 2); //5
}
void Results()
{
	int max=-1;
	int win=-1;
char Winner[candidate_name];
int tie=0;
	
	printf("\t\tVOTING RESULTS\t\t\n\n");
	for(i=0;i<num_candidate;i++)
	{
		printf("%s--Votes: %d\n",candidate[i],votes[i]);
	if(votes[i]>max)
	{
		max=votes[i];
	    win=i;
	    tie=0;
	}
	else if(votes[i]==max && max>0)
	{
		tie=1;
	}	
	}
	//display
	if(max==0)
	{
		printf("0 votes cast!\n\n\n\n");
	}
	else if(tie==1)
	{
	printf("\t\tIt's a TIE!\n\n\n\n"); }
	else
	{
	printf("\t\tWINNER\t\t\n");
	printf("%s : %d votes\n\n\n\n",candidate[win],max); }
}