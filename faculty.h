
typedef struct
{
    char name[15];
    char dept[15];
    char room[15];
    char gmail[15];
} Faculty;

///----------------- Prototypes start ---------------
void addTeacherInfo();
void showTeacherInfo(int id);
void searchTeacherInfo();
void editTeacherInfo();
void deleteTeacherInfo();
///------------------ Prototypes end ---------------


///------------------------------------ addTeacherinfo Function-start ---------------------------------
void addTeacherInfo()
{
    clrscr();
    char ans;
    Faculty fac[1000];
    int currFac, i;

    ///--------------------------------Read data from file: Start---------------------------------

    FILE *c;
    c=fopen("faculty.dat", "r");

    fscanf(c,"%d", &currFac);
    for(i=0; i<currFac; i++)
    {
        fscanf(c,"%s %s %s %s", fac[i].name, fac[i].dept, fac[i].room, fac[i].gmail);
    }
    fclose(c);

    ///---------------------------------Read data from file: End---------------------------------

    ///------------------------------------System Work: Start---------------------------------

    printf("\n\n\t\tEnter Faculty Name : ");
    scanf("%s", fac[i].name);
    printf("\n\n\t\tEnter Department   : ");
    scanf("%s", fac[i].dept);
    printf("\n\n\t\tEnter Room         : ");
    scanf("%s", fac[i].room);
    printf("\n\n\t\tEnter Gmail        : ");
    scanf("%s", fac[i].gmail);


    currFac++;

    ///-------------------------------------System Work: End---------------------------------

    ///---------------------------------Write data to file: Start---------------------------------

    FILE *f_write;

    f_write=fopen("faculty.dat", "w");

    if(f_write== NULL)
        printf("File not found\n");
    else
    {
        fprintf(f_write,"%d\n", currFac);
        for(i=0; i<currFac; i++)
        {
            fprintf(f_write,"%s %s %s %s\n", fac[i].name, fac[i].dept, fac[i].room, fac[i].gmail);

        }
        printf("\n\n\t\t\t.... Information Record Successful ...");
    }

    fclose(f_write);

///--------------------------------------Write data to file: End---------------------------------

sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more Course[Y/N]-> ");
    scanf("%s", &ans);
    if (toupper(ans)=='Y')
    {
        addTeacherInfo();
    }
    else if(toupper(ans)=='N')
    {
        printf("\n\t\t Thank you :) :)");
        getch();
        addInfo();
    }
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}
///------------------------------------- addTeacherInfo Function-end ---------------------------------

///------------------------------------ showTeacherInfo Function-start ---------------------------------
void showTeacherInfo(int id)
{
    clrscr();
    char ans;
    Faculty fac[1000];
    int currFac, i, row;
    FILE *c;
    c=fopen("faculty.dat", "r");
    fscanf(c,"%d", &currFac);
    for(i=0; i<currFac; i++)
    {
        fscanf(c,"%s %s %s %s", fac[i].name, fac[i].dept, fac[i].room, fac[i].gmail);
    }
    fclose(c);

    printf("\n\n\n\t\t   !!!!!!!!!!!!!! FACULTY INFO !!!!!!!!!!!!!\n");
    gotoxy(10,6);
    printf("NAME");
    gotoxy(25,6);
    printf("DEPT");
    gotoxy(40,6);
    printf("ROOM");
    gotoxy(55,6);
    printf("GMAIL");
    gotoxy(10,7);
    printf("===========================================================");
    row=8;
    for(i=0; i<currFac; i++)
    {
        gotoxy(10,row);
        printf("%s", fac[i].name);
        gotoxy(25,row);
        printf("%s", fac[i].dept);
        gotoxy(40,row);
        printf("%s", fac[i].room);
        gotoxy(55,row);
        printf("%s", fac[i].gmail);
        row++;
    }
    printf("\n\n\npress any key to back...");
    getch();
    student(id);
}
///------------------------------------- showTeacherInfo Function-end ---------------------------------

///------------------------------------ searchTeacherInfo Function-start ---------------------------------
void searchTeacherInfo()
{
    char ans, name[15];
    Faculty fac[1000];
    int currFac, i, row;
    FILE *c;
qwe:
    clrscr();
    c=fopen("faculty.dat", "r");
    fscanf(c,"%d", &currFac);
    for(i=0; i<currFac; i++)
    {
        fscanf(c,"%s %s %s %s", fac[i].name, fac[i].dept, fac[i].room, fac[i].gmail);
    }
    fclose(c);

    printf("\n\n\t\t!!!!!!!!!!!!!!  Search Faculty  !!!!!!!!!!!!!");
    gotoxy(15,5);
    printf("Enter Faculty Name: ");
    scanf("%s",name);

    for(i=0; i<currFac; i++)
    {
        if(strcmp(name, fac[i].name)==0)
        {
            gotoxy(10,8);
            printf("NAME");
            gotoxy(25,8);
            printf("DEPT");
            gotoxy(40,8);
            printf("ROOM");
            gotoxy(55,8);
            printf("GMAIL");
            gotoxy(10,9);
            printf("===========================================================");
            gotoxy(10,10);
            printf("%s", fac[i].name);
            gotoxy(25,10);
            printf("%s", fac[i].dept);
            gotoxy(40,10);
            printf("%s", fac[i].room);
            gotoxy(55,10);
            printf("%s", fac[i].gmail);
            printf("\n\n\nPress any key to continue...");
            break;
        }
    }
    if(i==currFac)
    {
        gotoxy(15,7);
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
///------------------------------------- searchTeacherInfo Function-end ---------------------------------

///------------------------------------ editTeacherInfo Function-start ---------------------------------

void editTeacherInfo()
{
    char ans, name[15];
    Faculty fac[1000];
    int currFac, i, row;
    FILE *c;
qwe:
    clrscr();
    c=fopen("faculty.dat", "r");
    fscanf(c,"%d", &currFac);
    for(i=0; i<currFac; i++)
    {
        fscanf(c,"%s %s %s %s", fac[i].name, fac[i].dept, fac[i].room, fac[i].gmail);
    }
    fclose(c);

    printf("\n\n\t\t!!!!!!!!!!!!!!  Edit Faculty  !!!!!!!!!!!!!");
    gotoxy(15,5);
    printf("Enter Faculty Name: ");
    scanf("%s",name);

    for(i=0; i<currFac; i++)
    {
        if(strcmp(name, fac[i].name)==0)
        {
            gotoxy(20,7);
            printf("*Existing record*");

            gotoxy(10,9);
            printf("NAME");
            gotoxy(25,9);
            printf("DEPT");
            gotoxy(40,9);
            printf("ROOM");
            gotoxy(55,9);
            printf("GMAIL");
            gotoxy(10,10);
            printf("===========================================================");
            gotoxy(10,11);
            printf("%s", fac[i].name);
            gotoxy(25,11);
            printf("%s", fac[i].dept);
            gotoxy(40,11);
            printf("%s", fac[i].room);
            gotoxy(55,11);
            printf("%s", fac[i].gmail);

            printf("\n\n\n\t\tEdit faculty:\n");

            printf("\n\n\t\tEnter Faculty name : ");
            scanf("%s", fac[i].name);
            printf("\n\n\t\tEnter Dept         : ");
            scanf("%s", fac[i].dept);
            printf("\n\n\t\tEnter Room         : ");
            scanf("%s", fac[i].room);
            printf("\n\n\t\tEnter Gmail        : ");
            scanf("%s", fac[i].gmail);

            printf("\nPress 'U' for update routine or press 'ANY KEY' to leave: ");
            scanf("%s", &ans);
            if(ans=='u' || ans=='U')
            {
                FILE *f_write;
                f_write=fopen("faculty.dat", "w");
                fprintf(f_write,"%d\n", currFac);
                for(i=0; i<currFac; i++)
                {
                    fprintf(f_write,"%s %s %s %s\n", fac[i].name, fac[i].dept, fac[i].room, fac[i].gmail);

                }
                printf("\n\n\t\t***Patient record updated successfully***");
                fclose(f_write);
            }
            break;
        }
    }
    if(i==currFac)
    {
        // gotoxy(6,10);
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
///------------------------------------- editTeacherInfo Function-end ---------------------------------

///------------------------------------ deleteTeacherInfo Function-start ---------------------------------
void deleteTeacherInfo()
{

    char ans, name[15];
    Faculty fac[1000];
    int currFac, i, j, row;
    FILE *c;
xyz:
    clrscr();
    c=fopen("faculty.dat", "r");
    fscanf(c,"%d", &currFac);
    for(i=0; i<currFac; i++)
    {
        fscanf(c,"%s %s %s %s", fac[i].name, fac[i].dept, fac[i].room, fac[i].gmail);
    }
    fclose(c);

    printf("\n\n\n\t\t   !!!!!!!!!!!!!! DELETE FACULTY !!!!!!!!!!!!!\n");
    gotoxy(10,6);
    printf("NAME");
    gotoxy(25,6);
    printf("DEPT");
    gotoxy(40,6);
    printf("ROOM");
    gotoxy(55,6);
    printf("GMAIL");
    gotoxy(10,7);
    printf("===========================================================");
    row=8;
    for(i=0; i<currFac; i++)
    {
        gotoxy(10,row);
        printf("%s", fac[i].name);
        gotoxy(25,row);
        printf("%s", fac[i].dept);
        gotoxy(40,row);
        printf("%s", fac[i].room);
        gotoxy(55,row);
        printf("%s", fac[i].gmail);
        row++;
    }
    printf("\n\n\nEnter Faculty Name: ");
    scanf("%s", name);
    int flag=0;
    for(i=0; i<currFac; i++)
    {
        if(strcmp(name, fac[i].name)==0)
        {
            flag=1;
            if(i<(currFac-1))
            {
                for(j=i; j<currFac; j++)
                {
                    strcpy(fac[j].name, fac[j+1].name);
                    strcpy(fac[j].dept, fac[j+1].dept);
                    strcpy(fac[j].room, fac[j+1].room);
                    strcpy(fac[j].gmail, fac[j+1].gmail);

                }
            }
            currFac--;
            printf("\n\n\t\tPress 'D' for Remove or press 'ANY KEY' to leave: ");
            scanf("%s", &ans);
            if(ans=='d' || ans=='D')
            {
                FILE *f_write;
                f_write=fopen("faculty.dat", "w");
                fprintf(f_write,"%d\n", currFac);
                for(i=0; i<currFac; i++)
                {
                    fprintf(f_write,"%s %s %s %s\n", fac[i].name, fac[i].dept, fac[i].room, fac[i].gmail);

                }
                printf("\n\n\t\t***Patient record updated successfully***");
                fclose(f_write);

            }
            break;
        }
    }
    if(!flag)
    {
        printf("\n\n\t\tData not Found!");
        printf("\nPress 'ENTER' to re-enter NAME OR press 'ANY KEY' to go back...[ENTER/ANY KEY]? ");
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
///------------------------------------- deleteTeacherInfo Function-end ---------------------------------


