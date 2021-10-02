#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
//#include <graphics.h>

void func();
int main()
{
    Beep(0,300); Beep(2000,100);    ////parameters (x,y) x=frequency of sound, y=duration of sound
    system("COLOR 02");
    printf("***** WELLCOME TO");
    Beep(0,600);
    printf(" MATH QUIZ GAME *****\n");
    Beep(2000,100); Beep(1500,100); Beep(2000,100); Beep(1500,100); Beep(2000,700); Beep(0,400);
    Beep(0,700);
    system("COLOR 07");
    again:
    {
        printf("\n   Hello!\n ");
        sleep(1);
        char oper;
        int game, difficulty, questions, number1, number2, answer, lower, upper, correct_answers=0, incorrect_answers;
        printf("Press 1 for simple arithmetic\n Press 2 for Timed Challenge\n Press 3 to Exit:\n     ");
        scanf("%d", &game);
    if (game == 2) {
        func();
        exit(0);
    }
    if (game == 3) {
        exit(0);
    }
    if ((game!=1)&&(game!=2)&&(game!=3))
    {
        Beep(0,300); Beep(2000,100);
        printf("Wrong input!!!\n\n");
        goto again;
    }
    else {
        printf("\nChoose difficulty\nPress 1 for Novice, 2 for Expert:  ");
        scanf("%d", &difficulty);
        printf("Choose operation +  -  *  /   ");
        fflush(stdin);
        scanf("%c", &oper);
        printf("Give the number of questions you want: ");
        scanf("%d", &questions);
    for(int i=1; i<=questions; i++)
    {
        if(difficulty == 1)
        {
            lower = 1, upper = 10;
            goto process;
        }
        if(difficulty == 2)
        {
            lower = 1, upper = 100;
            goto process;
        }
    process:
    {
        if(oper == '/')
        {
            double ans;
            srand(time(0));
            number2 = 2 * ((rand() % (upper - lower + 1)) + lower);
            lower = lower + 10, upper = upper + 20;
            number1 = 2 * ((rand() % (upper - lower + 1)) + lower);
            printf("%d.  %d %c %d = ", i, number1, oper, number2);
            scanf("%lf", &ans);
        if(ans == (number1 / number2)) {
            Beep(0,300); Beep(2000,100);
            printf("Correct!\n");
            correct_answers++; }
        else {
            printf("Wrong!\n"); }
        }
        if((oper == '+')||(oper == '-')||(oper == '*'))
        {
            srand(time(0));
            number1 = (rand() % (upper - lower + 1)) + lower;
            number2 = (rand() % (upper - lower + 1)) + lower;
            printf("%d.  %d %c %d = ", i, number1, oper, number2);
            scanf("%d", &answer);
        if(oper == '+')
            { if(answer == (number1 + number2)) {
                    correct_answers++;
                    Beep(0,300); Beep(2000,100);
                    printf("Good!\n"); }
                else {
                    printf("Wrong!\n"); }
            }
        if(oper == '-')
            { if(answer == (number1 - number2)) {
                    Beep(0,300); Beep(2000,100);
                    correct_answers++;
                    printf("Good!\n"); }
                else {
                    printf("Wrong!\n"); }
            }
        if(oper == '*')
            { if(answer == (number1 * number2)) {
                    Beep(0,300); Beep(2000,100);
                    correct_answers++;
                    printf("Good!\n"); }
                else {
                    printf("Wrong!\n"); }
            }
        }
    }
    }
    sleep(1);
    printf("\n\n************** RESULTS ****************\n");
    sleep(1);
    char smile = 1;
    int score = correct_answers*10;
    printf("Your score is %d out of %d.\n", score, questions*10);
    incorrect_answers = questions - correct_answers;
    if(correct_answers > incorrect_answers) {
        printf("----- Well done! -----\n You did Good!...%c\n", smile); }
    if(incorrect_answers > correct_answers) {
        Beep(2000,300);Beep(1700,300);Beep(1400,300);Beep(1100,900);
        printf("----- You failed! -----\n Better Luck next time...%c\n", smile); }
    }
    char a;
    printf("\nWant to try it again? Enter y/n  ");
    fflush(stdin);
    scanf("%c", &a);
    if(a == 'y')
    {
        system("cls");
        sleep(1);
        goto again;
    }
    else
    {
        printf("\n   Thank you for playing...\n");
        getch();
        exit(0);
    }
}

    getch();
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
  void func()
{
    sleep(1);
    system("cls");
    sleep(1);
    int j = 0, score = 0;
    printf("GET READY TO PLAY IN... ");
    Beep(2000,300); Beep(0,700);
    sleep(1);
    for(int i=3; i>=0; i--)
    {
        system("cls");
        printf("\n\n\n---------------  %d  --------------- ", i);
        Beep(0,500);
        //sleep(1);
        system("cls");
    }
    printf("\nLEVEL 1...Adding Quiz\n------------------- You have 5 seconds to answer each question ------------------\n");
    sleep(1);
    for (int i=1; i<=5; i++)
    {
        srand(time(0));
        int upper = 15, lower = 0;
        int num1 = (rand() % (upper - lower + 1)) + lower;
        int num2 = (rand() % (upper - lower + 1)) + lower;
        printf("\n%d + %d = ", num1, num2);
        int ans;
        time_t start;              // time_t is data type for storing time values
        start = time(0);
        while (!kbhit())
        {
            if(abs(time(0) - start) > 5)
            {
                j=1;
                break;
            }
        }
        if(j==1)
        {
            printf("\n   Time out");
            j=2;
        }
        else
        {
            scanf("%d", &ans);
            if((time(0) - start) > 5)
            {
                printf("\n   Time up");
                j=2;
            }
            else if(ans == num1 + num2)
                printf("\nGOOD!\n");
            else
            {
                printf("\nWRONG!\nYou Failed!");
                j=2;
            }
        }
        if (j==2)
        {
            Beep(2000,300);Beep(1700,300);Beep(1400,300);Beep(1100,1000);
            break;
        }
        score += 10;
    }

    ////////////////////////////////////////////// LEVEL 2
    for(int x=1; (x!=2) && (j!=2); x++)   //to make it run only once
    {
    system("cls");
    system("COLOR 01");
    printf("\n\n\n\n\n\n\n\n           *** Very Goood!!! ***\n");
    sleep(1);
    system("cls");
    system("COLOR 07");
    printf("LEVEL 2...Subtracting Quiz\n------------------- You have 5 seconds to answer each question ------------------\n");
    sleep(1);
    for (int i=1; i<=5; i++)
    {
        srand(time(0));
        int num1 = rand()%10+1+10*(i-1);
        int num2 = rand()%10+1+10*(i-1);
        printf("\n%d - %d = ", num1, num2);
        int ans;
        time_t start = time(0);
        while (!kbhit())
        {
            if(abs(time(0) - start) > 5)
            {
                j=1;

                break;
            }
        }
        if(j==1)
        {
            printf("\n   Time out");
            j=2;
        }
        else
        {
            scanf("%d", &ans);
            if((time(0) - start) > 5)
            {
                printf("\n   Time up");
                j=2;
            }
            else if(ans == num1-num2)
            printf("\nGOOD!\n");
            else
            {
                printf("\nWRONG!\nYou Failed!");
                j=2;
            }
        }
        if (j==2)
        {
            Beep(2000,300);Beep(1700,300);Beep(1400,300);Beep(1100,1000);
            break;
        }
        score += 10;
       }
    }

    //////////////////////////////// Level 3
    for(int x=1; (x!=2) && (j!=2); x++)
    {
    system("cls");
    system("COLOR 02");
    printf("\n\n\n\n\n\n\n\n            *** Well Done!!! ***\n");
    sleep(1);
    system("cls");
    system("COLOR 07");
    printf("LEVEL 3...Multiplying Quiz\n------------------- You have 5 seconds to answer each question ------------------\n");
    sleep(1);
        for (int i=1; i<=5; i++)
    {
        srand(time(0));
        int upper = 10, lower = 0;
        int num1 = (rand() % (upper - lower + 1)) + lower;
        int num2 = (rand() % (upper - lower + 1)) + lower;
        printf("\n%d x %d = ", num1, num2);
        int ans;
        time_t start = time(0);
        while (!kbhit())
        {
            if(abs(time(0) - start) > 5)
            {
                j=1;

                break;
            }
        }
        if(j==1)
        {
            printf("\n   Time out");
            j=2;
        }
        else
        {
            scanf("%d", &ans);
            if((time(0) - start) > 5)
            {
                printf("\n   Time up");
                j=2;
            }
            else if(ans == num1 * num2)
            printf("\nGOOD!\n");
            else
            {
                printf("\nWRONG!\nYou Failed!");
                j=2;
            }
        }
        if (j==2)
        {
            Beep(2000,300);Beep(1700,300);Beep(1400,300);Beep(1100,1000);
            break;
        }
        score += 10;
       }
    }

    ////////////////////////////////////////Level 4
    for(int x=1; (x!=2) && (j!=2); x++)
    {
    system("cls");
    system("COLOR 05");
    printf("\n\n\n\n\n\n\n      *** Well Done!!! ***\nYou've reached the final level...GoodLuck!");
    sleep(1);
    system("cls");
    system("COLOR 07");
    printf("LEVEL 4...Final Quiz\n------------------- You have 5 seconds to answer each question ------------------\n");
    sleep(1);
    for (int i=1; i<=5; i++)
    {
        srand(time(0));
        int num1 = rand()%10+1+10*(i-1);
        int num2 = rand()%10+1+10*(i-1);
        int num3 = rand()%10+1+10*(i-1);
        printf("\n%d + %d x %d = ", num1, num2, num3);
        int ans;
        time_t start = time(0);
        while (!kbhit())
        {
            if(abs(time(0) - start) > 5)
            {
                j=1;
                break;
            }
        }
        if(j==1)
        {
            printf("\n   Time out");
            j=2;
        }
        else
        {
            scanf("%d", &ans);
            if((time(0) - start) > 5)
            {
                printf("\n   Time up");
                j=2;
            }
        else if(ans == num1 + num2 * num3)    printf("\nGOOD\n");
        else
            {
                printf("\nWRONG!\nYou Failed!\n");
                j=2;
            }
        }
        if (j==2)
        {
            Beep(2000,300);Beep(1700,300);Beep(1400,300);Beep(1100,1000);
            break;
        }
        score += 10;
       }
    }

    char name[10];
    printf("\n\nEnter your name...");
    fflush(stdin);
    scanf("%s", name);
    FILE *fp;
    fp = fopen("HIGHEST SCORE.txt", "aw");
        //fprintf(fp, "\n---NAME----------SCORE---");
        fprintf(fp, "\n   %s            %d", name, score);
        fclose(fp);

    fp = fopen("HIGHEST SCORE.txt", "r");
    char single_line[100];
    while(!feof(fp))
    {
        fgets(single_line, 100, fp);
        puts(single_line);
    }
    printf("\nPress the first letter of your name to play again:  ");
    while(1)
    if(kbhit())
    {
        system("cls");
        sleep(1);
        main();
    }
    getch();
}
