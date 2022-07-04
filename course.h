
typedef struct
{
    int code;
    char nameC[10];
    int seat;
    char faculty[5];
} Course;

typedef struct
{
    int id;
    char firstname[15];
    char lastname[10];
    char address[20];
    char gmail[20];
    int number;
    char username[20];
    char password[20];
    Course courselist[4];
    int counter;
} Student;

///----------------- Prototypes start ---------------
void addCourseList();
void editCourseList();
void searchCourseList();
void deleteCourseList();
///------------------ Prototypes end ---------------

///------------------------------------- addCourseList Function-start ---------------------------------
void addCourseList()
{
    char ans;
    Course courses[1000];
    int currCourse, i;

    ///--------------------------------Read data from file: Start---------------------------------

    FILE *c;
    c=fopen("course.dat", "r");

    fscanf(c,"%d", &currCourse);
    for(i=0; i<currCourse; i++)
    {
        fscanf(c,"%d %s %d %s", &courses[i].code,  courses[i].nameC, &courses[i].seat, courses[i].faculty);
    }
    fclose(c);

    ///---------------------------------Read data from file: End---------------------------------

    ///------------------------------------System Work: Start---------------------------------

    printf("\n\n\t\tEnter Course Code   : ");
    scanf("%d", &courses[currCourse].code);
    printf("\n\n\t\tEnter Course Name   : ");
    scanf("%s", courses[currCourse].nameC);
    printf("\n\n\t\tEnter Course Seat   : ");
    scanf("%d", &courses[currCourse].seat);
    printf("\n\n\t\tEnter Faculty name  : ");
    scanf("%s", courses[currCourse].faculty);

    currCourse++;

    ///-------------------------------------System Work: End---------------------------------

    ///---------------------------------Write data to file: Start---------------------------------

    FILE *f_write;
    f_write=fopen("course.dat", "w");
    if(f_write== NULL)
        printf("File not found\n");
    else
    {
        fprintf(f_write,"%d\n", currCourse);
        for(i=0; i<currCourse; i++)
        {
            fprintf(f_write,"%d %s %d %s\n", courses[i].code,  courses[i].nameC, courses[i].seat, courses[i].faculty);

        }
        printf("\n\n\t\t\t.... Information Record Successful ...");
    }
    fclose(f_write);

///--------------------------------------Write data to file: End---------------------------------

sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more Course[Y/N]?? ");
    scanf("%s", &ans);
    if (toupper(ans)=='Y')
    {
        addCourseList();
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
///------------------------------------- addCourseList Function-end ---------------------------------

///------------------------------------ editCourseList Function-start ---------------------------------
void editCourseList()
{
    char ans;
    Course courses[1000];
    int currCourse, i, code;

    ///--------------------------------Read data from file: Start---------------------------------

    FILE *c;
qwe:
    clrscr();
    c=fopen("course.dat", "r");

    fscanf(c,"%d", &currCourse);
    for(i=0; i<currCourse; i++)
    {
        fscanf(c,"%d %s %d %s", &courses[i].code,  courses[i].nameC, &courses[i].seat, courses[i].faculty);
    }
    fclose(c);

    printf("\n\n\t\t!!!!!!!!!!!!!!  Edit Courselist  !!!!!!!!!!!!!");
    gotoxy(12,5);
    printf("Enter Course Code: ");
    scanf("%d",&code);
    for(i=0; i<currCourse; i++)
    {
        if(courses[i].code==code)
        {
            gotoxy(25,7);
            printf("*** Existing Record ***");
            gotoxy(10,9);
            printf("COURSE NAME");
            gotoxy(25,9);
            printf("COURSE CODE");
            gotoxy(40,9);
            printf("AVAILABLE SEAT");
            gotoxy(50,9);
            printf("FACULTY");
            gotoxy(10,10);
            printf("========================================================");
            gotoxy(10,11);
            printf("%s", courses[i].nameC);
            gotoxy(25,11);
            printf("%d", courses[i].code);
            gotoxy(40,11);
            printf("%d", courses[i].seat);
            gotoxy(50,11);
            printf("%s", courses[i].faculty);

            printf("\n\n\n\t\tEdit your courselist:\n");

            printf("\n\n\t\tEnter Course Code   : ");
            scanf("%d", &courses[i].code);
            printf("\n\n\t\tEnter Course Name   : ");
            scanf("%s", courses[i].nameC);
            printf("\n\n\t\tEnter Course Seat   : ");
            scanf("%d", &courses[i].seat);
            printf("\n\n\t\tEnter Faculty name  : ");
            scanf("%s", courses[i].faculty);

            printf("\nPress 'U' for update routine or press 'ANY KEY' to leave: ");
            scanf("%s", &ans);
            if(ans=='u' || ans=='U')
            {
                FILE *f_write;
                f_write=fopen("course.dat", "w");

                fprintf(f_write,"%d\n", currCourse);
                for(i=0; i<currCourse; i++)
                {
                    fprintf(f_write,"%d %s %d %s\n", courses[i].code,  courses[i].nameC, courses[i].seat, courses[i].faculty);

                }
                fclose(f_write);
                printf("\n\n\t\tPatient record updated successfully");
            }
            break;
        }
    }
    if(i==currCourse)
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
///------------------------------------- editCourseList Function-end ---------------------------------

///------------------------------------ searchCourseList Function-start ---------------------------------
void searchCourseList()
{
    char ans;
    Course courses[1000];
    int currCourse, i, code;

    ///--------------------------------Read data from file: Start---------------------------------

    FILE *c;
qwe:
    clrscr();
    c=fopen("course.dat", "r");

    fscanf(c,"%d", &currCourse);
    for(i=0; i<currCourse; i++)
    {
        fscanf(c,"%d %s %d %s", &courses[i].code,  courses[i].nameC, &courses[i].seat, courses[i].faculty);
    }
    fclose(c);

    printf("\n\n\t\t!!!!!!!!!!!!!!  Search Courselist  !!!!!!!!!!!!!");
    gotoxy(12,5);
    printf("Enter Course Code: ");
    scanf("%d",&code);

    for(i=0; i<currCourse; i++)
    {
        if(courses[i].code==code)
        {
            gotoxy(10,8);
            printf("COURSE NAME");
            gotoxy(25,8);
            printf("COURSE CODE");
            gotoxy(40,8);
            printf("AVAILABLE SEAT");
            gotoxy(50,8);
            printf("FACULTY");
            gotoxy(10,9);
            printf("========================================================");
            gotoxy(10,10);
            printf("%s", courses[i].nameC);
            gotoxy(25,10);
            printf("%d", courses[i].code);
            gotoxy(40,10);
            printf("%d", courses[i].seat);
            gotoxy(50,10);
            printf("%s", courses[i].faculty);
            printf("\n\n\nPress any key to continue...");
            break;
        }
    }
    if(i==currCourse)
    {
        gotoxy(12,7);
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
///------------------------------------- editCourseList Function-end ---------------------------------

///------------------------------------ deleteCourseList Function-start ---------------------------------
void deleteCourseList()
{
    char ans;
    Course courses[1000];
    int currCourse, i, code, row, j;
    ///--------------------------------Read data from file: Start---------------------------------
    FILE *c;
xyz:
    clrscr();
    c=fopen("course.dat", "r");
    fscanf(c,"%d", &currCourse);
    for(i=0; i<currCourse; i++)
    {
        fscanf(c,"%d %s %d %s", &courses[i].code,  courses[i].nameC, &courses[i].seat, courses[i].faculty);
    }
    fclose(c);

    printf("\n\n\t\t!!!!!!!!!!!!!!  Delete Courselist  !!!!!!!!!!!!!");
    gotoxy(10,8);
    printf("COURSE NAME");
    gotoxy(25,8);
    printf("COURSE CODE");
    gotoxy(40,8);
    printf("AVAILABLE SEAT");
    gotoxy(50,8);
    printf("FACULTY");
    gotoxy(10,9);
    printf("========================================================");
    row=10;
    for(i=0; i<currCourse; i++)
    {
        gotoxy(10,row);
        printf("%s", courses[i].nameC);
        gotoxy(25,row);
        printf("%d", courses[i].code);
        gotoxy(40,row);
        printf("%d", courses[i].seat);
        gotoxy(50,row);
        printf("%s", courses[i].faculty);
        row++;
    }

    printf("\n\n\n\t\t\tEnter Course Code: ");
    scanf("%d",&code);

    int flag=0;
    for(i=0; i<currCourse; i++)
    {
        if(courses[i].code==code)
        {
            flag=1;
            if(i<(currCourse-1))
            {
                for(j=i; j<currCourse; j++)
                {
                    strcpy(courses[j].nameC, courses[j+1].nameC);
                    courses[j].code=courses[j+1].code;
                    courses[j].seat=courses[j+1].seat;
                    strcpy(courses[j].faculty, courses[j+1].faculty);
                }
            }
            currCourse--;
            printf("\n\n\t\tPress 'D' for Remove or press 'ANY KEY' to leave: ");
            scanf("%s", &ans);
            if(ans=='d' || ans=='D')
            {
                FILE *f_write;
                f_write=fopen("course.dat", "w");

                fprintf(f_write,"%d\n", currCourse);
                for(i=0; i<currCourse; i++)
                {
                    fprintf(f_write,"%d %s %d %s\n", courses[i].code,  courses[i].nameC, courses[i].seat, courses[i].faculty);

                }
                fclose(f_write);
                printf("\n\n\t\t...Patient record updated successfully...");
            }
            break;
        }
    }
    if(!flag)
    {
        printf("\n\n\t\tData not Found!");
        printf("\nPress 'ENTER' to re-enter Course Code OR press 'ANY KEY' to go back...[ENTER/ANY KEY]? ");
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
///------------------------------------ deleteCourseList Function-end ---------------------------------


