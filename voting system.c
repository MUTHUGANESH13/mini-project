#include<stdio.h>
#define CANDIDATE_COUNT
char name1[20]={0};
char name2[20]={0};
char name3[20]={0};
char name4[20]={0};
char name5[20]={0};
char name6[20]={0};
char info1[1000]={0};
char info2[1000]={0};
char info3[1000]={0};
char info4[1000]={0};
char info5[1000]={0};
char info6[1000]={0};
int size=0;
int si=0;
int ca=0;
int voteid[1024];



void modifycan(void);
/*
#define CANDIDATE1 "CANDIDATE A"
#define CANDIDATE2 "CANDIDATE B"
#define CANDIDATE3 "CANDIDATE C"
#define CANDIDATE4 "CANDIDATE D"
#define CANDIDATE5 "CANDIDATE E"-
#define CANDIDATE6 "CANDIDATE F"
*/
#define CANDIDATE1 name1
#define CANDIDATE2 name2
#define CANDIDATE3 name3
#define CANDIDATE4 name4
#define CANDIDATE5 name5
#define CANDIDATE6 name6

int votesCount1=0, votesCount2=0, votesCount3=0, votesCount4=0;
int votesCount5=0, votesCount6=0, spoiledtvotes=0;

void modifycan()
{
int pass;
    printf("ENTER ADMIN PASSWORD:");
    scanf("%d",&pass);
    if( pass==1234){

printf("Initializing Vote Setup...");
printf("\nEnter the name of the first candidate: ");
scanf("%s",name1);
printf("\nEnter the name of the second candidate: ");
scanf("%s",name2);
printf("\nEnter the name of the thrid candidate: ");
scanf("%s",name3);
printf("\nEnter the name of the fourth candidate: ");
scanf("%s",name4);
printf("\nEnter the name of the fifth  candidate: ");
scanf("%s",name5);
printf("\nEnter the name of the six candidate: ");
scanf("%s",name6);
}else
	{
	    
		printf("\n\nINVALID PASSWORD");
	}

 getchar();
 
}

void castVote(void) 
{
int choice;   
int number; 
printf("\n 1. %s", name1);
printf("\n 2. %s", name2);
printf("\n 3. %s", name3);
printf("\n 4. %s", name4);
printf("\n 5. %s", name5);
printf("\n 6. %s", name6);
printf("\n 7. %s", "NOTA");
printf("\n To exit press 8");
printf("\n\n Input your choice (1 - 7) : ");
scanf("%d",&choice);
switch(choice)
{
    case 1: votesCount1++; break;
    case 2: votesCount2++; break;
    case 3: votesCount3++; break;
    case 4: votesCount4++; break;
    case 5: votesCount5++; break;
    case 6: votesCount6++; break;
    case 7: spoiledtvotes++; break;
    default:printf("\n Action: Exiting to Main Screen");
             //hold the screen
             getchar();
}
ca--;
printf("\n Thanks for your vote !!");
}

void votesCount(){
	int pass;
	printf("ENTER ADMIN PASSWORD:");
	scanf("%d",&pass);
	if(pass==1234    )
	{
		
printf("\n\n ***** Voting Statics *****");
printf("\n =========================================================================================================");
printf("\nS.NO        		CANDIDATE NAME     		 		  VOTES GAINED");
printf("\n =========================================================================================================");
printf("\n 1.			%s				-			%d ", CANDIDATE1, votesCount1);
printf("\n 2.			%s				-			%d ", CANDIDATE2, votesCount2);
printf("\n 3.			%s				-			%d ", CANDIDATE3, votesCount3);
printf("\n 4.			%s				-			%d ", CANDIDATE4, votesCount4);
printf("\n 5.			%s				-			%d ", CANDIDATE5, votesCount5);
printf("\n 6.			%s				-			%d ", CANDIDATE6, votesCount6);

printf("\n 7.			%s				-			%d ", "NOTA", spoiledtvotes);
	}
	else
	{
	    
		printf("\n\nINVALID PASSWORD");
		
	}
	
}

void getLeadingCandidate(){
    int pass;
    printf("ENTER ADMIN PASSWORD:");
    scanf("%d",&pass);
    if( pass==1234)
    	{
    printf("\n\n  ***** Leading Candiate *****\n\n");
    if(votesCount1>votesCount2 && votesCount1>votesCount3 && votesCount1>votesCount4 && votesCount1>votesCount5 && votesCount1>votesCount6)
    printf("[%s] is leading the election",CANDIDATE1);
    else if (votesCount2>votesCount3 && votesCount2>votesCount4 && votesCount2 >votesCount1 && votesCount2 >votesCount5 && votesCount2 >votesCount6)
    printf("[%s] is leading the election",CANDIDATE2);
    else if(votesCount3>votesCount4 && votesCount3>votesCount2 && votesCount3 >votesCount1 && votesCount3 > votesCount5 && votesCount3 >votesCount6)
    printf("[%s] is leading the election",CANDIDATE3);
    else if(votesCount4>votesCount1 && votesCount4>votesCount2 && votesCount4 >votesCount3 && votesCount4>votesCount5 && votesCount4 >votesCount6)
    printf("[%s] is leading the election" ,CANDIDATE4);
    else if(votesCount5>votesCount1 && votesCount5>votesCount2 && votesCount5>votesCount3 && votesCount5>votesCount4 && votesCount5>votesCount6)
    printf("[%s] is leading the election",CANDIDATE5);
    else if(votesCount6>votesCount1 && votesCount6>votesCount2 && votesCount6>votesCount3 && votesCount6>votesCount4 && votesCount6>votesCount5)
    printf("[%s] is leading the election",CANDIDATE6);
    	}
    else
    printf("\n\nINVALID PASSWORD");    
}

void candinfo(){
	int pass;
    printf("ENTER ADMIN PASSWORD:");
    scanf("%d",&pass);
    if( pass==1234)
    {
		printf("enter the info of first candidate: ");
		scanf("\n");
		fgets(info1,1000,stdin);
		printf("\nenter the info of second candidate: ");
		scanf("\n");
		fgets(info2,1000,stdin);
		printf("\nenter the info of third candidate: ");
		scanf("\n");
		fgets(info3,1000,stdin);
		printf("\nenter the info of fourth candidate: ");
		scanf("\n");
		fgets(info4,1000,stdin);
		printf("\nenter the info of fifth candidate: ");
		scanf("\n");
		fgets(info5,1000,stdin);
		printf("\nenter the info of Sixth candidate: ");
		scanf("\n");
		fgets(info6,1000,stdin);
	}
		else
	{
	    
		printf("\n\nINVALID PASSWORD");
	}
}

void candisplay()
{
	printf("The first candidate is....");
	printf("%s",name1);
	printf("\n%s",info1);
	printf("\n\n\nThe second candidate is....");
	printf("%s",name2);
	printf("\n%s",info2);
	printf("\n\n\nThe third candidate is....");
	printf("%s",name3);
	printf("\n%s",info3);
	printf("\n\n\nThe fourth candidate is....");
	printf("%s",name4);
	printf("\n%s",info4);
	printf("\n\n\nThe fifth candidate is....");
	printf("%s",name5);
	printf("\n%s",info5);
	printf("\n\n\nThe sixth candidate is....");
	printf("%s",name6);
	printf("\n%s",info6);
	
	
}
int voteID()
{
	printf("enter your voter ID");
    int toSearch, found;
    printf("\nEnter voter ID: ");
    scanf("%d", &toSearch);
    found = 0; 
    for(si=0; si<size; si++)
    {
       
        if(voteid[si] == toSearch)
        {
            found = 1;
            voteid[si]=1123581119;
            break;
        }
    }
    if(found == 1)
    {
        ca++;
		printf("\n voter ID %d is found", toSearch);
        return ca;
    }
    else
    {
        printf("\n%d is not found in the system", toSearch);
        return 0;
    }
    
}
void voteIDstor()
{
		int pass;
	printf("ENTER ADMIN PASSWORD:");
	scanf("%d",&pass);
	if(pass==1234)
	{
		printf("Enter no of voters: ");
    scanf("%d", &size);
    printf("Enter the voter id of voters: ");
    for(si=0; si<size; si++)
    {
        scanf("%d", &voteid[si]);
    }
	}
			else
	{
	    
		printf("\n\nINVALID PASSWORD");
	}
}
	
int main()
{
int i;
int choice;

do{
printf("\n\n ***** Welcome to Election/Voting 2022 *****");
printf("\n\n 1.Enter voter ID");
printf("\n 2. Cast the Vote");
printf("\n 3. Display candidate information");
printf("\n 4. Modify candidate");
printf("\n 5. Find Vote Count");
printf("\n 6. Find leading Candidate");
printf("\n 7. Change Candidate Information");
printf("\n 8. Storage of Voter ID");
printf("\n 9. Press 9 to exit");

printf("\n\n Please enter your choice : ");
scanf("%d", &choice);

switch(choice)
{
case 1: voteID();break;
case 2: if(ca==1){castVote();}
	break;

case 3: candisplay();break;
case 4: modifycan();break;
case 5: votesCount();break;
case 6: getLeadingCandidate();break;
case 7: candinfo();break;
case 8: voteIDstor();break;

default: break;
}
}while(choice<9);

//hold the screen
getchar();

}
