
///----------------- Prototypes start---------------
void password();
void admin();
void addInfo();
void searchInfo();
void editInfo();
void deleteInfo();
///------------------ Prototypes end ---------------

///----------------------------------------  password Function-start ----------------------------------
void password()
{
    clrscr();
    int v, p;
    for(v=3; v>0; v--)
    {
        char ch=0, mainPass[10]= {"12345"};
        int i=0;
        printf("\n\n\t*********************************************");
        printf("\n\t\t\t     ADMIN                               ");
        printf("\n\t*********************************************");

        printf("\n\t\t***** Password Protected *****");
        printf("\n\n\t\t Enter Password:");
        char pass[10]="";
        while(ch!=13)
        {
            ch=getch();
            if(ch!=13)
            {
                putch('*');
                pass[i]=ch;
                i++;
            }
        }
        if(strcmp(mainPass,pass)==0)
        {
                printf("\n\n\tPassword Match!\n\n\tLOADING");
                for(p=0; p<=5; p++)
                {
                    Sleep(500);
                    printf(".");
                }
                admin();               //if password correct access to admin menu.
                break;
            }
            else
            {
                printf("\a\n\n\t\t* Wrong Password *");
                Sleep(1000);
                printf("\n\n\n\n\t\Your Try Left- %d",v-1);
                if(v==2)
                {
                    printf("\a\n\n\tThis is your last chance pls type correct password.\n\tOtherwise you have to wait 10 sec !!");
                }
                else if(v==1)
                {
                    printf("\n\n\t\t\t\tPls try after 10 sec\n");
                    Sleep(1000);
                    int count=10;
                    do
                    {
                        Sleep(1000);
                        count--;
                        printf("\n\t\t\t\tWait...\a %d sec",count);
                    }
                    while(count!=0);
                    clrscr();
                    mainmenu();      //if password wrong threetime go back to main menu
                }
            }
        }
    }
///----------------------------------------- password Function-end ----------------------------------


///------------------------------------------  admin Function-start ----------------------------------
    void admin()
    {
        int i1;
        clrscr();
        printf("\n\n\t*********************************************");
        printf("\n\t\t\t     ADMIN                               ");
        printf("\n\t*********************************************");
        printf("\n\t\t\tADD INFO       .1");
        printf("\n\t\t\tSEARCH INFO    .2");
        printf("\n\t\t\tEDIT INFO      .3");
        printf("\n\t\t\tDELETE INFO    .4");
        printf("\n\t\t\tSTUDENT DETAILS.5");
        printf("\n\t\t\tSign out       .6");
        printf("\n\n\tEnter your choice: ");
        scanf("%d", &i1);
        switch(i1)
        {
        case 1:
            addInfo();
            break;
        case 2:
            searchInfo();
            break;
        case 3:
            editInfo();
            break;
        case 4:
            deleteInfo();
            break;
        case 5:
            showStudentDetails();
            break;
        case 6:
            clrscr();
            mainmenu();
            break;
        default:
            printf("\nInvalid input!");
            getch();
            admin();
            break;
        }
    }
///-------------------------------------------  admin Function-end ----------------------------------

///-----------------------------------------  addinfo Function-start ----------------------------------
    void addInfo()
    {
        int i2;
        clrscr();
        printf("\n\n\tADD INFO:");
        printf("\n\t\t\tAdd Class Routine   .1");
        printf("\n\t\t\tAdd Bus Schedule    .2");
        printf("\n\t\t\tAdd Teacher Info    .3");
        printf("\n\t\t\tAdd Course          .4");
        printf("\n\t\t\tAdd University Info .5");
        printf("\n\t\t\tBack                .6");
        printf("\n\n\tEnter your choice: ");
        scanf("%d", &i2);
        switch(i2)
        {
        case 1:
            addClassRoutine();
            break;
        case 2:
            addBusSchedule();
            break;
        case 3:
            addTeacherInfo();
            break;
        case 4:
            addCourseList();
            break;
        case 5:addUniversityInfo();
            break;
        case 6:
            admin();
            break;
        default:
            printf("\nInvalid input!");
            getch();
            addInfo();
            break;
        }
    }
///-----------------------------------------  addinfo Function-start ----------------------------------

///----------------------------------------  searchinfo Function-start ----------------------------------
    void searchInfo()
    {
        clrscr();
        int i3;
        printf("\n\n\tSEARCH INFO:");
        printf("\n\t\t\tSearch Class Routine  .1");
        printf("\n\t\t\tSearch Bus Schedule   .2");
        printf("\n\t\t\tSearch Teacher Info   .3");
        printf("\n\t\t\tSearch Course List    .4");
        printf("\n\t\t\tBack                  .5");
        printf("\n\n\tEnter your choice: ");
        scanf("%d", &i3);
        switch(i3)
        {
        case 1:
            searchClassRoutine();
            break;
        case 2:
            searchBusSchedule();
            break;
        case 3:
            searchTeacherInfo();
            break;
        case 4:
            searchCourseList();
            break;
        case 5:
            admin();
            break;
        default:
            printf("\nInvalid input!");
            getch();
            searchInfo();
            break;
        }
    }
///-----------------------------------------  searchinfo Function-end ----------------------------------

///-----------------------------------------  editinfo Function-start ----------------------------------
    void editInfo()
    {
        clrscr();
        int i4;
        printf("\n\n\tEDIT INFO:");
        printf("\n\t\t\tEdit Class Routine   .1");
        printf("\n\t\t\tEdit Bus Schedule    .2");
        printf("\n\t\t\tEdit Teacher Info    .3");
        printf("\n\t\t\tEdit Course List     .4");
        printf("\n\t\t\tEdit University Info .5");
        printf("\n\t\t\tBack           .6");
        printf("\n\n\tEnter your choice: ");
        scanf("%d", &i4);
        switch(i4)
        {
        case 1:
            editClassRoutine();
            break;
        case 2:
            editBusSchedule();
            break;
        case 3:
            editTeacherInfo();
            break;
        case 4:
            editCourseList();
            break;
        case 5:// editUniversityInfo();
            break;
        case 6:
            admin();
            break;
        default:
            printf("\nInvalid input!");
            getch();
            editInfo();
            break;
        }
    }
///-------------------------------------------  editinfo Function-end ----------------------------------

///-----------------------------------------  deleteonfo function-start ----------------------------------
    void deleteInfo()
    {
        clrscr();
        int i5;
        printf("\n\n\tDELETE INFO:");
        printf("\n\t\t\tDelete Class Routine   .1");
        printf("\n\t\t\tDelete Bus Schedule    .2");
        printf("\n\t\t\tDelete Teacher Info    .3");
        printf("\n\t\t\tDelete Course List     .4");
        printf("\n\t\t\tDelete University Info .5");
        printf("\n\t\t\tBack           .6");
        printf("\n\n\tEnter your choice: ");
        scanf("%d", &i5);
        switch(i5)
        {
        case 1:
            deleteClassRoutine();
            break;
        case 2:
            deleteBusSchedule();
            break;
        case 3:
            deleteTeacherInfo();
            break;
        case 4:
            deleteCourseList();
            break;
        case 5:// deleteCollegeInfo();
            break;
        case 6:
            admin();
            break;
        default:
            printf("\nInvalid input!");
            getch();
            deleteInfo();
            break;
        }
    }
///-------------------------------------------  deleteinfo Function-end ----------------------------------
