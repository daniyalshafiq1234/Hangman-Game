#include<stdio.h>
#include<string.h>
#include<windows.h>

void write(char hang[10]){
	FILE *ptr;
	ptr=fopen("words entered.txt","a");
	fprintf(ptr,"missing word :- %s\n",hang);
	fclose(ptr);
}

int gamescore(int sc){
	  FILE *fptr;
   fptr = fopen("scores.txt","a");
   int score=NULL;
   if(sc==1)
	 fprintf(fptr,"Score : %d (WON)\n",sc);
   else 
   fprintf(fptr,"Score : %d (LOST)\n",sc);
   fclose(fptr);
}

void showhangman(int);
int main(void)
{ char n,cc;
	int load,length,i,wrongtry=6,matchfound=0,counter,position=0,winner,score=0;
	char hangmanword[100],hint[100],hangmanoutput[100],useralphabet,tempword[100];
		system("color F3");
    printf("||=====================================================================================||    \t||=======      \n");
	printf("||=====================================================================================||    \t||      | \n");
	printf("||=                                                                                   =||    \t||     %cO/ \n",'\\');
	printf("||=                               HANGMAN GAME                                        =||    \t||      |\n");
	printf("||=                                                                                   =||    \t||     / %c  \n",'\\');
	printf("||=====================================================================================||    \t||       \n");
	printf("||=====================================================================================||    \t||       \n");
	printf("\n\n\n\n\n \t\t\t\t\t\t start game \n\t\t\t\n ");
   
	getchar();
	system("cls");
	printf("\n\n\n\n\t\t\t INSTRUCTIONS:- \n\n\n\t\t\t -you are only allowed to enter alphabets.\n\n\t\t\t -you will be having 6 chances to guess the word \n\n\n\t\t\t\t press enter");
	getchar();
	
	system("cls");

	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading ");
	for(load=1;load<=25;load++)
	{
		system("color F3");
		Sleep(70);
		printf("%c",219);
	}
	system("cls");
	printf("\n\n \t\t Enter word :-");
	scanf("%s",&hangmanword);
	write(hangmanword);	
	printf("\n \t\tenter hint :- ");
	gets(hint);
	system("cls");
	
	printf("\n \t\t\tNow give it to your friend and see weather he or she can guess it..");
	getchar();
	length = strlen(hangmanword);
	printf("\n\n\n \t\t\tRead :- \n\t\t\t\t you will get 5 chances to guess the word \n\n\t\t\t \n");
	
	system("color F");
	printf("\t ||==== \n");
	printf("\t ||   | \n");
	printf("\t || \n");
	printf("\t || \n");
	printf("\t || \n");
	printf("\t || \n");
	printf("\n The word has %d alphabets :-\n",length);
	printf("This is the hint:%s",hint);
	
	while(wrongtry!=0)
		{
			matchfound=0;
			printf("\n\n\t\tEnter any alphabet from 'a' to 'z' in small case : \n\n\t\tEnter here:- ");
		   	scanf("%s",&useralphabet);
			if(useralphabet<'a' || useralphabet>'z')
				{
					system("cls");
					printf("\n Wrong Input . Please enter only alphabets(small case)");
				}
			if(matchfound!=2)
			{
				for(counter=0;counter<length;counter++)
				{
				if(useralphabet==hangmanword[counter])
					{
					matchfound=1;
					}	
				}
			if(matchfound==0)
			{
				printf("\n\t you have %d tries left",--wrongtry);
				showhangman(wrongtry);
			}
			else
	   		{
	    	 for(counter = 0; counter < length; counter++)
             {
     	         matchfound = 0;
                 if(useralphabet == hangmanword[counter])
	          		{
     		     	position = counter ;
     		     	matchfound = 1;
	          		}
				 if(matchfound == 1)
	          	{
                	for(i = 0 ; i < length ; i++)
                 	{
                    if( i == position)
                    {
                    hangmanoutput[i] = useralphabet; 
                    }
                    else if( hangmanoutput[i] >= 'a' && hangmanoutput[i] <= 'z' ) 
                      {
                          continue;
                  	  }

                      else
                      {
                          hangmanoutput[i] = '_';           
                      }
                	  }
                tempword[position] = useralphabet;      
                tempword[length] = '\0';                    
                winner = strcmp(tempword,hangmanword);      

                if(winner == 0)
				{
				printf("you won. the word was %s ",hangmanword); 
				score++; 
				
				printf("\n\t\t\tScore    %d ",score);
				gamescore(score);
				
      printf("\nEnter 's' to play again and 'x' to exit");
        
		scanf(" %c",&cc);
		if(cc=='s')
		{
			system("cls");
			main();
		}
		else
		exit(1);
                     
   				}	
				}
			}
			}
	}
	printf("\n\n\t");
    for(i = 0 ; i < length ; i++)
      {
          printf(" ");
          printf("%c",hangmanoutput[i]);               
      }
//    getchar();
    }
		if(wrongtry <= 0)                               
        {
          printf("\n\n\t The Word was %s . you lost. better luck next type :)",hangmanword);
          gamescore(0);
        }
        printf("\nEnter 's' to play again and 'x' to exit");

		scanf(" %c",&cc);
		if(cc=='s')
		{
			system("cls");
			main();
		}
		else
	    exit(1);
	
}
void showhangman(int choice)                            
 {
     switch(choice)
     {
 case 0:
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||   / %c",'\\');
	printf("\n\t||      ");
	break;
 case 1:
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||     %c",'\\');
	printf("\n\t||      ");
	break;
case 2:
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
 case 3:    
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
 case 4:
 	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO ",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
 case 5:
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||    O ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
      }//end of switch-case
      return;
}
