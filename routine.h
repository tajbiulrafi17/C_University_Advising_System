
typedef struct
{
    char one[10];
    char two[10];
    char three[10];
    char four[10];
    char five[10];
    char six[10];
} Classes;

typedef struct
{
    char day[10];
    Classes c;
} Routine;

///------------------ Prototypes start ---------------
void addClassRoutine();
void showClassRoutine();
void searchClassRoutine();
void editClassRoutine();
void deleteClassRoutine();
///--------------- -- Prototypes end ---------------

///------------------------------------ addClassRoutine Function-start ---------------------------------
void addClassRoutine()
{
    int currRoutine, i;
    Routine rout[7];
    char ans;
    FILE*ek;//file pointer
again:
    ek=fopen("routine.dat","r");//open file in write mode

    fscanf(ek,"%d", &currRoutine);
    if(currRoutine<7)
    {
        for(i=0; i<currRoutine; i++)
        {
            fscanf(ek,"%s %s %s %s %s %s %s", rout[i].day, rout[i].c.one, rout[i].c.two, rout[i].c.three, rout[i].c.four, rout[i].c.five,rout[i].c.six);
            // printf("%s %s %s %s %s %s %s", rout[i].day, rout[i].c.one, rout[i].c.two, rout[i].c.three, rout[i].c.four, rout[i].c.five,rout[i].c.six);
        }
        fclose(ek);
        printf("\n\n\t\t!!!!!!!!!!!!!! ADD ROUTINE !!!!!!!!!!!!!\n");

        printf("\n\t\t\tDay Name     : ");
        scanf("%s",rout[i].day);
        strupr(rout[i].day);

        printf("\n\t\t\t08.00-09.30  : ");
        scanf("%s",rout[i].c.one);
        strupr(rout[i].c.one);

        printf("\n\t\t\t09.40-11.10  : ");
        scanf("%s",rout[i].c.two);
        strupr(rout[i].c.two);

        printf("\n\t\t\t11.20-12.50  : ");
        scanf("%s",rout[i].c.three);
        strupr(rout[i].c.three);

        printf("\n\t\t\t01.00-02.30   : ");
        scanf("%s",rout[i].c.four);
        strupr(rout[i].c.four);

        printf("\n\t\t\t02.40-04.10  : ");
        scanf("%s",rout[i].c.five);
        strupr(rout[i].c.five);

        printf("\n\t\t\t04.20-05.50  : ");
        scanf("%s",rout[i].c.six);
        strupr(rout[i].c.six);

        currRoutine++;

        ek=fopen("routine.dat", "w");
        fprintf(ek, "%d\n", currRoutine);
        for(i=0; i<currRoutine; i++)
        {
            fprintf(ek,"%s %s %s %s %s %s %s\n", rout[i].day, rout[i].c.one, rout[i].c.two, rout[i].c.three, rout[i].c.four, rout[i].c.five, rout[i].c.six);
        }
        printf("\n\n\t\t\t.... Information Record Successful ...");
        fclose(ek);
rafi:
        getch();
        printf("\n\n\t\t\tDo you want to add more?[Y/N]-> ");
        scanf(" %c",&ans);
        if (toupper(ans)=='Y')
        {
            goto again;
        }
        else if(toupper(ans)=='N')
        {
            printf("\n\t\t Thank you :) :)");
            printf("Press any key to back...");
            getch();
            addInfo();
        }
        else
        {
            printf("\n\t\tInvalid Input\n");
            goto rafi;
        }
    }
    else
    {
        printf("\tSORRY! You added routine for 7 days of week \n\tPlease edit routine or remove one to add new one :)\n");
        printf("Press any key to back...");
        getch();
        addInfo();
    }
}
///------------------------------------ addClassRoutine Function-end ---------------------------------

///------------------------------------ showClassRoutine Function-start ---------------------------------
void showClassRoutine(int id)
{
    int row, currRoutine, i;
    clrscr();
    Routine rout[7];
    FILE *ek;
    ek=fopen("routine.dat","r");
    fscanf(ek,"%d", &currRoutine);
    for(i=0; i<currRoutine; i++)
    {
        fscanf(ek,"%s %s %s %s %s %s %s", rout[i].day, rout[i].c.one, rout[i].c.two, rout[i].c.three, rout[i].c.four, rout[i].c.five, rout[i].c.six);
        //printf("%s %s %s %s %s %s %s\n", rout[i].day, rout[i].c.one, rout[i].c.two, rout[i].c.three, rout[i].c.four, rout[i].c.five,rout[i].c.six);
    }
    fclose(ek);

    printf("\n\n\n\t\t!!!!!!!!!!!!!! Class Routine !!!!!!!!!!!!!\n");
    gotoxy(12,7);
    printf("08.00");
    gotoxy(24,7);
    printf("09.40");
    gotoxy(36,7);
    printf("11.20");
    gotoxy(48,7);
    printf("01.00");
    gotoxy(60,7);
    printf("02.40");
    gotoxy(72,7);
    printf("04.20");
    gotoxy(1,8);
    printf("DAY");
    gotoxy(12,8);
    printf("09.30");
    gotoxy(24,8);
    printf("11.10");
    gotoxy(36,8);
    printf("12.50");
    gotoxy(48,8);
    printf("02.30");
    gotoxy(60,8);
    printf("04.10");
    gotoxy(72,8);
    printf("05.50");
    printf("\n==============================================================================");
    row=10;
    for(i=0; i<currRoutine; i++)
    {
        gotoxy(1,row);
        printf("%s",rout[i].day);
        gotoxy(12,row);
        printf("%s",rout[i].c.one);
        gotoxy(24,row);
        printf("%s",rout[i].c.two);
        gotoxy(36,row);
        printf("%s",rout[i].c.three);
        gotoxy(48,row);
        printf("%s",rout[i].c.four);
        gotoxy(60,row);
        printf("%s",rout[i].c.five);
        gotoxy(72,row);
        printf("%s",rout[i].c.six);

        row++;
    }
    printf("\n\npress any key to back...");
    getch();
    student(id);
}
///------------------------------------ showClassRoutine Function-end ---------------------------------

///------------------------------------ searchClassRoutine Function-start ---------------------------------

void searchClassRoutine()
{
    char day_name[10], ans;
    Routine rout[7];
    int currRoutine, i;
    FILE *ek;
qwe:
    clrscr();
    ek=fopen("routine.dat","r");
    fscanf(ek,"%d", &currRoutine);
    for(i=0; i<currRoutine; i++)
    {
        fscanf(ek,"%s %s %s %s %s %s %s", rout[i].day, rout[i].c.one, rout[i].c.two, rout[i].c.three, rout[i].c.four, rout[i].c.five, rout[i].c.six);
    }
    fclose(ek);
    printf("\n\n\n\t\t!!!!!!!!!!!!!! Search Routine !!!!!!!!!!!!!\n");
    gotoxy(12,5);
    printf("\t\tEnter Day Name: ");
    scanf("%s",day_name);
    //fflush(stdin);
    strupr(day_name);

    for(i=0; i<currRoutine; i++)
    {
        if(strcmp(rout[i].day, day_name)==0)
        {
            gotoxy(12,7);
            printf("08.00");
            gotoxy(24,7);
            printf("09.40");
            gotoxy(36,7);
            printf("11.20");
            gotoxy(48,7);
            printf("01.00");
            gotoxy(60,7);
            printf("02.40");
            gotoxy(72,7);
            printf("04.20");
            gotoxy(1,8);
            printf("DAY");
            gotoxy(12,8);
            printf("09.30");
            gotoxy(24,8);
            printf("11.10");
            gotoxy(36,8);
            printf("12.50");
            gotoxy(48,8);
            printf("02.30");
            gotoxy(60,8);
            printf("04.10");
            gotoxy(72,8);
            printf("05.50");
            printf("\n===============================================================================");
            gotoxy(1,10);
            printf("%s",rout[i].day);
            gotoxy(12,10);
            printf("%s",rout[i].c.one);
            gotoxy(24,10);
            printf("%s",rout[i].c.two);
            gotoxy(36,10);
            printf("%s",rout[i].c.three);
            gotoxy(48,10);
            printf("%s",rout[i].c.four);
            gotoxy(60,10);
            printf("%s",rout[i].c.five);
            gotoxy(72,10);
            printf("%s",rout[i].c.six);
            printf("\n\n\nPress any key to continue...");
            break;
        }

    }
    if(i==currRoutine)
    {
        gotoxy(6,10);
        printf("Record not found!");
    }
L:
    getch();
    fflush(stdin);
    printf("\n\n\t\tDo you want to search more?[Y/N]-> ");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        goto qwe;
    }
    else if(toupper(ans)=='N')
    {
        printf("\n\t\t Thank you :) :)");
        printf("\nPress any key to back...");
        getch();
        searchInfo();
    }
    else
    {
        printf("\n\tInvalid Input.");
        printf("\nPress any key to continue...");
        goto L;
    }
}
///------------------------------------ searchClassRoutine Function-end ---------------------------------


///------------------------------------ editClassRoutine Function-start ---------------------------------
void editClassRoutine()
{
    char day_name[10], ans;
    Routine rout[7];
    int currRoutine, i;
    FILE *ek;
qwe:
    clrscr();
    ek=fopen("routine.dat","r");
    fscanf(ek,"%d", &currRoutine);
    for(i=0; i<currRoutine; i++)
    {
        fscanf(ek,"%s %s %s %s %s %s %s", rout[i].day, rout[i].c.one, rout[i].c.two, rout[i].c.three, rout[i].c.four, rout[i].c.five, rout[i].c.six);
    }
    fclose(ek);
    printf("\n\n\t\t!!!!!!!!!!!!!!  Edit Class Routine  !!!!!!!!!!!!!");
    gotoxy(12,5);
    printf("Enter Day name: ");
    scanf("%s",day_name);
    fflush(stdin);
    strupr(day_name);
    if(ek==NULL)
    {
        printf("\n Can not open file!");
        getch();
        editInfo();
    }
    int flag=1;
    for(i=0; i<currRoutine; i++)
    {
        if(strcmp(rout[i].day, day_name)==0)
        {
            flag=0;
            gotoxy(33,7);
            printf("*** Existing Record ***");

            gotoxy(12,8);
            printf("08.00");
            gotoxy(24,8);
            printf("09.40");
            gotoxy(36,8);
            printf("11.20");
            gotoxy(48,8);
            printf("01.00");
            gotoxy(60,8);
            printf("02.40");
            gotoxy(72,8);
            printf("04.20");
            gotoxy(1,9);
            printf("DAY");
            gotoxy(12,9);
            printf("09.30");
            gotoxy(24,9);
            printf("11.10");
            gotoxy(36,9);
            printf("12.50");
            gotoxy(48,9);
            printf("02.30");
            gotoxy(60,9);
            printf("04.10");
            gotoxy(72,9);
            printf("05.50");
            printf("\n===============================================================================");
            gotoxy(1,11);
            printf("%s",rout[i].day);
            gotoxy(12,11);
            printf("%s",rout[i].c.one);
            gotoxy(24,11);
            printf("%s",rout[i].c.two);
            gotoxy(36,11);
            printf("%s",rout[i].c.three);
            gotoxy(48,11);
            printf("%s",rout[i].c.four);
            gotoxy(60,11);
            printf("%s",rout[i].c.five);
            gotoxy(72,11);
            printf("%s",rout[i].c.six);

            printf("\n\n\n\t\tEdit your routine:\n");

            printf("\n\t\t\t08.00-09.30  : ");
            scanf("%s",rout[i].c.one);
            strupr(rout[i].c.one);

            printf("\n\t\t\t09.40-11.10  : ");
            scanf("%s",rout[i].c.two);
            strupr(rout[i].c.two);

            printf("\n\t\t\t11.20-12.50  : ");
            scanf("%s",rout[i].c.three);
            strupr(rout[i].c.three);

            printf("\n\t\t\t01.00-02.30   : ");
            scanf("%s",rout[i].c.four);
            strupr(rout[i].c.four);

            printf("\n\t\t\t02.40-04.10  : ");
            scanf("%s",rout[i].c.five);
            strupr(rout[i].c.five);

            printf("\n\t\t\t04.20-05.50  : ");
            scanf("%s",rout[i].c.six);
            strupr(rout[i].c.six);

            printf("\nPress 'U' for update routine or press 'ANY KEY' to leave: ");
            scanf("%s", &ans);
            if(ans=='u' || ans=='U')
            {
                ek=fopen("routine.dat","w");
                fprintf(ek,"%d\n", currRoutine);
                for(i=0; i<currRoutine; i++)
                {
                    fprintf(ek,"%s %s %s %s %s %s %s\n", rout[i].day, rout[i].c.one, rout[i].c.two, rout[i].c.three, rout[i].c.four, rout[i].c.five, rout[i].c.six);
                }
                fclose(ek);
                printf("\n\n\t\tPatient record updated successfully");
            }
            break;
        }
    }
    if(flag)
    {
        printf("\nRecord not found!");
    }
L:
    getch();
    fflush(stdin);
    printf("\n\n\t\tDo you want to edit more?[Y/N]-> ");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        goto qwe;
    }
    else if(toupper(ans)=='N')
    {
        printf("\n\t\t Thank you :) :)");
        printf("\n\nPress any key to back...");
        getch();
        editInfo();
    }
    else
    {
        printf("\n\tInvalid Input.");
        printf("\nPress any key to continue...");
        goto L;
    }
}
///------------------------------------ editClassRoutine Function-end ---------------------------------


///---------------------------------- deleteClassRoutine Function-start ---------------------------------
void deleteClassRoutine()
{
    int row, currRoutine, i, j;
    char day_name[10], ans;
    Routine rout[7];

    FILE *ek;
xyz:
    clrscr();
    ek=fopen("routine.dat","r");
    fscanf(ek,"%d", &currRoutine);
    for(i=0; i<currRoutine; i++)
    {
        fscanf(ek,"%s %s %s %s %s %s %s", rout[i].day, rout[i].c.one, rout[i].c.two, rout[i].c.three, rout[i].c.four, rout[i].c.five, rout[i].c.six);
    }
    fclose(ek);

    printf("\n\n\n\n\t\t!!!!!!!!!!!!!! Class Routine !!!!!!!!!!!!!\n");
    gotoxy(12,7);
    printf("08.00");
    gotoxy(24,7);
    printf("09.40");
    gotoxy(36,7);
    printf("11.20");
    gotoxy(48,7);
    printf("01.00");
    gotoxy(60,7);
    printf("02.40");
    gotoxy(72,7);
    printf("04.20");
    gotoxy(1,8);
    printf("DAY");
    gotoxy(12,8);
    printf("09.30");
    gotoxy(24,8);
    printf("11.10");
    gotoxy(36,8);
    printf("12.50");
    gotoxy(48,8);
    printf("02.30");
    gotoxy(60,8);
    printf("04.10");
    gotoxy(72,8);
    printf("05.50");
    printf("\n==============================================================================");
    row=10;
    for(i=0; i<currRoutine; i++)
    {
        gotoxy(1,row);
        printf("%s",rout[i].day);
        gotoxy(12,row);
        printf("%s",rout[i].c.one);
        gotoxy(24,row);
        printf("%s",rout[i].c.two);
        gotoxy(36,row);
        printf("%s",rout[i].c.three);
        gotoxy(48,row);
        printf("%s",rout[i].c.four);
        gotoxy(60,row);
        printf("%s",rout[i].c.five);
        gotoxy(72,row);
        printf("%s",rout[i].c.six);
        row++;
    }
    printf("\n");
    printf("\n\n\t\t\t\tEnter Day Name to remove: ");
    scanf("%s", day_name);
    strupr(day_name);

    int flag=0;
    for(i=0; i<currRoutine; i++)
    {
        if(strcmp(day_name, rout[i].day)==0)
        {
            flag=1;
            if(i<(currRoutine-1))
            {
                for(j=i; j<currRoutine; j++)
                {
                    strcpy(rout[j].day, rout[j+1].day);
                    strcpy(rout[j].c.one, rout[j+1].c.one);
                    strcpy(rout[j].c.two, rout[j+1].c.two);
                    strcpy(rout[j].c.three, rout[j+1].c.three);
                    strcpy(rout[j].c.four, rout[j+1].c.four);
                    strcpy(rout[j].c.five, rout[j+1].c.five);
                    strcpy(rout[j].c.six, rout[j+1].c.six);

                }

            }
            currRoutine--;

            printf("\n\n\t\tPress 'D' for Remove or press 'ANY KEY' to leave: ");
            scanf("%s", &ans);
            if(ans=='d' || ans=='D')
            {
                ek=fopen("routine.dat","w");
                fprintf(ek,"%d\n", currRoutine);
                for(i=0; i<currRoutine; i++)
                {
                    fprintf(ek,"%s %s %s %s %s %s %s\n", rout[i].day, rout[i].c.one, rout[i].c.two, rout[i].c.three, rout[i].c.four, rout[i].c.five, rout[i].c.six);
                }
                fclose(ek);
                printf("\n\n\t\t... Patient record updated successfully ...");

            }
            break;
        }
    }
    if(!flag)
    {
        printf("\n\n\t\tData not Found!");
        printf("\nPress 'ENTER' to re-enter Day Name OR press 'ANY KEY' to go back...[ENTER/ANY KEY]? ");
        if(getch()==13)
            goto xyz;
        else
        {
            deleteInfo();
        }
    }
ghi:
    printf("\n\n\tDo you want to remove more?[Y/N]-> ");
    scanf("%s", &ans);
    if (toupper(ans)=='Y')
    {
        goto xyz;
    }
    else if(toupper(ans)=='N')
    {
        printf("\n\t\t Thank you :) :)");
        printf("\n\nPress any key to back...");
        getch();
        deleteInfo();
    }
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto ghi;
    }
}
///------------------------------------ deleteClassRoutine Function-end ---------------------------------

