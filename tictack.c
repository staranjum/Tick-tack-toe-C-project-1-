#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define ROW 3
#define COL 3


int board[ROW][COL];
const int X = 1;
const int O = -1;
int player;

void fill();
void printBoard();
int isFound(int x, int y);
int iswin(int player);

int main()
{
    system("COLOR 1F");
    int choice;

    do
    {
        printf("\n\t\t\t\t\t\t1.start Game\n\t\t\t\t\t\t2.exit Game\n");
        printf("Enter your choice : ");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                system("CLS");
                play();
                break;
            case 2:
                  choice = 0;

                break;

            default :
                printf("Not a valid selection\n");

        }

        getch();
    }while(choice!=0);


}
void fill()
{
    int i,j;

    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            board[i][j] = 0;
        }
    }
    player = X;
}
void printBoard()
{
    int i,j;
    printf("\n\n\n");

    for(i=0;i<ROW;i++)

    {
        printf("\t\t\t\t\t\t\t\t");
        for(j=0;j<COL;j++)
        {
            printf("%3s",board[i][j] == 0 ? " " :(board[i][j] == 1 ? " X " : " O "));

            if(j<2)
            {
                printf("%c",'|');
            }
        }
        printf("\n");

        if(i<2)
        {
            printf("\t\t\t\t\t\t\t\t");
            for(j=0;j<11;j++)
            {
                printf("%c",'-');
            }
        }
        printf("\n");

   }



}

void play()
{
    fill();
    printBoard();

    int counter = 0, choice, isExist = 0, isDraw = 1;


    while(counter<9)
    {

        isExist = 0;


        if(player == 1)
          {
             printf("1st player's turn\n");
          }
          else
          {
              printf("2nd player's turn\n");

          }



         printf("Enter your box choice...\n");
         scanf("%d",& choice );

        system("CLS");

        switch(choice)
        {
           case 1:
               if(isFound(0,0) == 1)
                {

                    board[0][0]= player;
                     counter++;
                }
                else
                {
                     isExist = 1;
                }
                     break;

            case 2:
                if(isFound(0,1) == 1)
                  {

                    board[0][1]= player;
                     counter++;
                  }
                else
                   {
                     isExist = 1;
                   }
                     break;
             case 3:
                 if(isFound(0,2) == 1)
                  {

                    board[0][2]= player;
                     counter++;
                  }
                else
                   {
                     isExist = 1;
                   }
                     break;
             case 4:
                 if(isFound(1,0) == 1)
                  {

                    board[1][0]= player;
                     counter++;
                  }
                else
                   {
                     isExist = 1;
                   }
                     break;
             case 5:
                  if(isFound(1,1) == 1)
                  {

                    board[1][1]= player;
                     counter++;
                  }
                else
                   {
                     isExist = 1;
                   }
                     break;
             case 6:
                 if(isFound(1,2) == 1)
                  {

                    board[1][2]= player;
                     counter++;
                  }
                else
                   {
                     isExist = 1;
                   }
                     break;
             case 7:
                  if(isFound(2,0) == 1)
                  {

                    board[2][0]= player;
                     counter++;
                  }
                else
                   {
                     isExist = 1;
                   }
                     break;
             case 8:
                 if(isFound(2,1) == 1)
                  {

                    board[2][1]= player;
                     counter++;
                  }
                else
                   {
                     isExist = 1;
                   }
                     break;
             case 9:
                  if(isFound(2,2) == 1)
                  {

                    board[2][2]= player;
                     counter++;
                  }
                else
                   {
                     isExist = 1;
                   }
                     break;

             default:
                printf("Not a valide one ...\n");
                break;

        }

         printBoard();

        if(isExist == 1)
        {
            printf("This box is already blocked...\n");
            continue;
        }


        if(iswin(player) == 1)
        {
            if(player == 1)
            {
                printf("\n\t\t\t\t\t\t\t\tPlayer 1 wins\n");
            }else
            {
                printf("\n\t\t\t\t\t\t\t\tPlayer 2 wins\n");
            }
            isDraw = 0;
            break;
        }

        player = -player;

    }

    if(isDraw == 1)
    {
        printf("\t\t\t\t\t\t\t\tTIE\n");
    }

}


int iswin(int player)

{
    if (board[0][0]+board[0][1]+board[0][2] == 3*player)
    {
        return 1;
    }
    if(board[1][0]+board[1][1]+board[1][2] == 3*player)
    {
        return 1;
    }

    if(board[2][0]+board[2][1]+board[2][2] == 3*player)
    {
        return 1;
    }
     if (board[0][0]+board[1][0]+board[2][0] == 3*player)
    {
        return 1;
    }
     if (board[0][1]+board[1][1]+board[2][1] == 3*player)
    {
        return 1;
    }
     if (board[0][2]+board[1][2]+board[2][2] == 3*player)
    {
        return 1;
    }
     if (board[0][0]+board[1][1]+board[2][2] == 3*player)
    {
        return 1;
    }
     if (board[0][2]+board[1][1]+board[2][0] == 3*player)
    {
        return 1;
    }
     return 0;

}

int isFound(int i,int j)
{
    if (board[i][j] == 0)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

