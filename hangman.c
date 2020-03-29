#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char a[12],q[12],g_w;


void clrscr()               //clear screen
{
    system("cls");
}
void delay(void)                                            // delay program
{
    int c,d;
  for (c = 1; c <= 32767; c++)
       for (d = 1; d <= 16338; d++)
       {}
}

void stat_hang(int tries)                   //tries == 5
{                                           //prints the status of the hangman                    
    switch(tries)
    {
        case 5: 
            printf("\n\t  _______ \n");
            printf("\t   |     |\n");
            printf("\t   O     |\n");
            printf("\t  /|\\    |\n");
            printf("\t   ^     |\n");
            printf("\t  / \\    |\n");
            printf("\t_=====___+\n");
            printf("\t|     |  |\n");
            break;
        case 4:
            printf("\n\t  _______ \n");
            printf("\t   |     |\n");
            printf("\t   O     |\n");
            printf("\t  /|\\    |\n");
            printf("\t   ^     |\n");
            printf("\t  / \\    |\n");
            printf("\t_==== ___+\n");
            printf("\t|     |  |\n");
            break;
        case 3:
            printf("\n\t  _______ \n");
            printf("\t   |     |\n");
            printf("\t   O     |\n");
            printf("\t  /|\\    |\n");
            printf("\t   ^     |\n");
            printf("\t  / \\    |\n");
            printf("\t_ === ___+\n");
            printf("\t|     |  |\n");
            break;
        case 2: 
            printf("\n\t  _______ \n");
            printf("\t   |     |\n");
            printf("\t   O     |\n");
            printf("\t  /|\\    |\n");
            printf("\t   ^     |\n");
            printf("\t  / \\    |\n");
            printf("\t_ = = ___+\n");
            printf("\t|     |  |\n");
            break;
        case 1:
            printf("\n\t  _______ \n");
            printf("\t   |     |\n");
            printf("\t   O     |\n");
            printf("\t  /|\\    |\n");
            printf("\t   ^     |\n");
            printf("\t  / \\    |\n");
            printf("\t_   = ___+\n");
            printf("\t|     |  |\n");
            break;
        case 0:
            printf("\n\t  _______ \n");
            printf("\t   |     |\n");
            printf("\t   |     |\n");
            printf("\t   O     |\n");
            printf("\t  /|\\    |\n");
            printf("\t   ^     |\n");
            printf("\t_ | | ___+\n");
            printf("\t|     |  |\n");
            break;
        default:
            printf("\n\t\t\t\t\t\tError the game files were rigged.");
            exit(0);
            break;
    }
}


void into_stars(int len,char *p)    //creates the guess question 
{
    int i;
    
    for(i = 0;i<len;i++)
    {
        if(p[i] != ' ')
            a[i] = '*';
        else
            a[i] = ' ';
    }
    a[len] = '\0';
    
    for(i = 0; i<len;i++)
        printf("%c",a[i]);

}


int check_w(int len)   //checks if the word fuessed is in the parent string of not 
{                       //also checks iif the guessed word is already taken or not
    int i,found = 0,taken = 0;
    
    for(i = 0;i<len;i++)
    {
        if (a[i] == '*')
        {
            if(g_w == q[i])
            {
                a[i] = g_w;
                found = 1;
            }
            else
            {
                continue;
            }
        }
        else if(a[i] == g_w)
        {
            taken = 1;
        }  
                
    }
    for(i = 0;i<len;i++)
    {
        printf("%c",a[i]);
    }
    if(taken == 1 && found == 0)    
        return 2;

    if(found == 0 && i == len)
    {
        return 0;
    }
}

void print_l(int tries) //printing lives
{
    for(int i  = 0; i<tries;i++)
        printf("(*)");



        
}

int check()
{
    if(!strcmp(a,q)) //checking if the two strings are the same or not
    {
        printf("\nHoorah you have guessed it all right. Yopu ahce saved an innocent live\n");
        return 10;
    }
    
    
}



void main()
{
    int res = 1,status_1 = 0,status,tries = 5;
    clrscr();
    printf("\n----------HOST set up the word for the player to guess---------\n");
    gets(q);
    printf("\n---------changing it into stars----------\n");
    into_stars(strlen(q),q);
    printf("\n---------conversion into stars completed----------\n");
    clrscr();
    printf("\n---------player is now allowed to guess----------\n");
    delay();
    do
    {
        clrscr();
        fflush(stdin);
        status_1 = check();
        printf("\t\t\t");
        if(status_1 == 10)
            exit(0);
        
        print_l(tries);
        stat_hang(tries);
        printf("\t\tThe word: ");
        fflush(stdin);
        for(int i = 0; i<strlen(q);i++)
            printf("%c",a[i]);
        printf("\t\tGuess the word now:");
        fflush(stdin);
        scanf("%c",&g_w);
        
        status = check_w(strlen(q));
        if (status == 1)
            res = 1;
        else if(status == 2)
        {
            printf("\nword is aready taken. try again\n");
            delay();
            
        }
        else if(status == 0)
        {
            printf("\nwrong guess\n");
            tries--;
            delay();
        
        }
        

    }while (res == 1 && tries > 0); 

    delay();

    if(tries == 0)
    {
        stat_hang(tries);
        printf("The word was: ");
        puts(q);
        printf("You lost and an innocent was punnished to death today. Your morale has decreased a lot.");
        getch();
    }

    exit(0);
    
}