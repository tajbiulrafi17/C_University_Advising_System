

///----------------- Prototypes start ---------------
void studentLogin();
void login();
void signup();
void student(int id);
void showStudentDetails();
///------------------ Prototypes end ---------------


///--------------------------------------- studentLogin Function-start ---------------------------------
void studentLogin()
{
    clrscr();
    int i6;
    printf("\n\n\t*********************************************");
    printf("\n\t\t\t   STUDENT                               ");
    printf("\n\t*********************************************");
hehe:
    printf("\n\t\t\tLogin      .1");
    printf("\n\t\t\tSignup     .2");

    printf("\n\n\tEnter your choice: ");
    scanf("%d", &i6);
    switch(i6)
    {
    case 1:
        login();
        break;
    case 2:
        signup();
        break;
    default:
        printf("\nInvalid input!\nPress any key to continue...");
        getch();
        printf("\n");
        goto hehe;
        break;
    }
}
///-------------------------------------- studentLogin Function-end ---------------------------------

///---------------------------------------- student Function-start ---------------------------------

void student(int id)
{
    clrscr();
   // printf("%d\n", id);
    int i5;
    printf("\n\n\t*********************************************");
    printf("\n\t\t\t     STUDENT                               ");
    printf("\n\t*********************************************");
    printf("\n\t\t\tClass Routine   .1");
    printf("\n\t\t\tBus Schedule    .2");
    printf("\n\t\t\tTeacher Info    .3");
    printf("\n\t\t\tUniversity Info .4");
    printf("\n\t\t\tAdvising        .5");
    printf("\n\t\t\tSign out        .6");
    printf("\n\n\tEnter your choice: ");
    scanf("%d", &i5);
    switch(i5)
    {
    case 1:
        showClassRoutine(id);
        break;
    case 2:
        showBusSchedule(id);
        break;
    case 3:
         showTeacherInfo(id);
        break;
    case 4:
        showUniversityInfo(id);
        break;
    case 5:
        advising(id);
        break;
    case 6:
        clrscr();
        mainmenu();
        break;
    default:
        printf("\nInvalid input!");
        getch();
        student(id);
        break;
    }
}
///--------------------------------------------- student Function-end ---------------------------------


///---------------------------------------------- signup Function-start ---------------------------------
void signup()
{
    int z2;
    Student students[1000];
    int currStudent, i;

    ///---------------------------------------Read data from file: Start---------------------------------

    FILE *log;
    log= fopen("login.dat", "r");
    if(log == NULL)
        printf("File not found\n");
    else
    {
        fscanf(log, "%d", &currStudent);

        for(i=0; i<currStudent; i++)
        {
            fscanf(log, "%d %s %s %s %s %d %s %s %d %d %s %s %d %s %s %d %s %s %d %s %s",
                   &students[i].id, students[i].firstname, students[i].lastname, students[i].address, students[i].gmail,
                   &students[i].number, students[i].username, students[i].password, &students[i].counter,
                   &students[i].courselist[0].code, students[i].courselist[0].nameC, students[i].courselist[0].faculty,
                   &students[i].courselist[1].code, students[i].courselist[1].nameC, students[i].courselist[1].faculty,
                   &students[i].courselist[2].code, students[i].courselist[2].nameC, students[i].courselist[2].faculty,
                   &students[i].courselist[3].code, students[i].courselist[3].nameC, students[i].courselist[3].faculty);
            //getc(log);
        }
        fclose(log);

        ///-------------------------------------Read data from file: End---------------------------------

        ///----------------------------------------System Work: Start---------------------------------

        printf("\n\n\t\tEnter ID  : ");
        scanf("%d", &students[i].id);
        printf("\n\n\t\tEnter First Name  : ");
        scanf("%s", students[i].firstname);
        printf("\n\t\tEnter Last Name   : ");
        scanf("%s", students[i].lastname);
        printf("\n\t\tEnter Address     : ");
        scanf("%s", students[i].address);
        printf("\n\t\tEnter Gmail       : ");
        scanf("%s", students[i].gmail);
        printf("\n\t\tEnter Phone Number: ");
        scanf("%d", &students[i].number);

        printf("\n\n\t\tEnter Username  : ");
        scanf("%s", students[i].username);
        printf("\t\tEnter Password  : ");
        scanf("%s", students[i].password);

        students[i].counter=0;
        strcpy(students[i].courselist[0].nameC, "-");
        strcpy(students[i].courselist[1].nameC, "-");
        strcpy(students[i].courselist[2].nameC, "-");
        strcpy(students[i].courselist[3].nameC, "-");

        strcpy(students[i].courselist[0].faculty, "-");
        strcpy(students[i].courselist[1].faculty, "-");
        strcpy(students[i].courselist[2].faculty, "-");
        strcpy(students[i].courselist[3].faculty, "-");


        currStudent++;

        ///-------------------------------------System Work: End---------------------------------

        ///----------------------------------Write data to file: Start---------------------------------

        FILE *fptr_write = fopen("login.dat", "w");
        if(fptr_write == NULL)
            printf("File not found\n");
        else
        {
            fprintf(fptr_write, "%d\n", currStudent);

            for(i=0; i<currStudent; i++)
            {
                fprintf(fptr_write, "%d %s %s %s %s %d %s %s %d %d %s %s %d %s %s %d %s %s %d %s %s\n",
                        students[i].id, students[i].firstname, students[i].lastname, students[i].address, students[i].gmail,
                        students[i].number, students[i].username, students[i].password, students[i].counter,
                        students[i].courselist[0].code, students[i].courselist[0].nameC, students[i].courselist[0].faculty,
                        students[i].courselist[1].code, students[i].courselist[1].nameC, students[i].courselist[0].faculty,
                        students[i].courselist[2].code, students[i].courselist[2].nameC, students[i].courselist[0].faculty,
                        students[i].courselist[3].code, students[i].courselist[3].nameC, students[i].courselist[0].faculty);
            }
        }
        printf("\n\n\t\t\t.... Information Record Successful ...");
        fclose(log);

        ///-----------------------------------Write data to file: End---------------------------------

        printf("\n\n\tSignup Successsful.\n\tNow login with Username and Password.");
        printf("\n\nPress any key to continue...");
        getch();
        login();

    }
}
///------------------------------------ signup Function-end ---------------------------------

///------------------------------------ login Function-start ---------------------------------
void login()
{
    char username[20], password[20], c;
    Student students[1000];
    int z1=0, i, currStudent, t;
    FILE *log;
    log= fopen("login.dat","r");

    fscanf(log, "%d", &currStudent);
    for(i=0; i<currStudent; i++)
    {
        fscanf(log, "%d %s %s %s %s %d %s %s %d %d %s %s %d %s %s %d %s %s %d %s %s",
               &students[i].id, students[i].firstname, students[i].lastname, students[i].address, students[i].gmail,
               &students[i].number, students[i].username, students[i].password, &students[i].counter,
               &students[i].courselist[0].code, students[i].courselist[0].nameC, students[i].courselist[0].faculty,
               &students[i].courselist[1].code, students[i].courselist[1].nameC, students[i].courselist[0].faculty,
               &students[i].courselist[2].code, students[i].courselist[2].nameC, students[i].courselist[0].faculty,
               &students[i].courselist[3].code, students[i].courselist[3].nameC, students[i].courselist[0].faculty);
        getc(log);
    }
    fclose(log);
    //pass:
    printf("\n\n\t\tUsername  : ");
    scanf("%s", username);
    printf("\t\tPassword  : ");
    while((c=getch())!=13)
    {
        password[z1++]=c;
        printf("%c",'*');
    }
    password[z1]='\0';


    for(i=0; i<currStudent; i++)
    {
        if(strcmp(username,students[i].username)==0)
        {
            if(strcmp(password, students[i].password)==0)
            {
                 printf("\n\n\tLogin Successful !!\n\n\tLOADING");
                for(t=0; t<=5; t++)
                {
                    Sleep(500);
                    printf(".");
                }
               // printf("in login function id=%d\n", students[i].id);
                getch();
                student(students[i].id);
                break;
            }
            else
            {
                printf("\a\n\n\tWrong Password !");
                printf("\n\tPress any key to re-login...");
                getch();
                // goto pass;
                login();
            }
        }
    }

    if(i==currStudent)
    {
        printf("\a\n\n\tYou are not Registerd Student");
        printf("\n\tPress Enter to Register...");
        if(getch()==13)
            signup();
        else
        {
            clrscr();
            mainmenu();
        }
    }
}
///------------------------------------- login Function-end ---------------------------------

///--------------------------------- showStudentDetails Function-start ---------------------------------

void showStudentDetails()
{
    clrscr();

    int row, currStudent, i;
    Student students[1000];

    FILE *bk;
    bk=fopen("login.dat","r");
    printf("\n\n\n\t\t\t!!!!!!!!!!!!!! STUDENT DETAILS !!!!!!!!!!!!!\n");
    gotoxy(1,6);
    printf("NAME");
    gotoxy(25,6);
    printf("ID");
    gotoxy(35,6);
    printf("ADDRESS");
    gotoxy(56,6);
    printf("NUMBER");
    gotoxy(68,6);
    printf("Gmail\n");
    printf("========================================================================================");
    row=8;

    fscanf(bk, "%d", &currStudent);

    for(i=0; i<currStudent; i++)
    {
        fscanf(bk, "%d %s %s %s %s %d %s %s %d %d %s %s %d %s %s %d %s %s %d %s %s",
               &students[i].id, students[i].firstname, students[i].lastname, students[i].address, students[i].gmail,
               &students[i].number, students[i].username, students[i].password, &students[i].counter,
               &students[i].courselist[0].code, students[i].courselist[0].nameC, students[i].courselist[0].faculty,
               &students[i].courselist[1].code, students[i].courselist[1].nameC, students[i].courselist[0].faculty,
               &students[i].courselist[2].code, students[i].courselist[2].nameC, students[i].courselist[0].faculty,
               &students[i].courselist[3].code, students[i].courselist[3].nameC, students[i].courselist[0].faculty);
        getc(bk);

        gotoxy(1,row);
        printf("%s %s",students[i].firstname, students[i].lastname);
        gotoxy(25,row);
        printf("%d",students[i].id);
        gotoxy(35,row);
        printf("%s",students[i].address);
        gotoxy(56,row);
        printf("%d", students[i].number);
        gotoxy(68,row);
        printf("%s", students[i].gmail);
        row++;

    }
    fclose(bk);

    printf("\n\n\npress any key to back...");
    getch();
    clrscr();
    admin();
}
///--------------------------------- showStudentDetails Function-end ---------------------------------

