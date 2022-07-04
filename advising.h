
///----------------- Prototypes start ---------------
void advising(int id);
void addCourseStudent(int id);
void enroledCourseS(int id);
void removeCourseS(int id);
///------------------ Prototypes end ---------------

///----------------------------------------  advising Function-start ----------------------------------
void advising(int id)
{
    clrscr();
    int x;
    printf("\n\n\n\n\t\t!!!!!!!!!!!!!!   ADVISING WINDOW   !!!!!!!!!!!!!\n");
    printf("\n\t\t\tAdd Course      .1");
    printf("\n\t\t\tRemove Course   .2");
    printf("\n\t\t\tCourse Enroled  .3");
    printf("\n\t\t\tBack            .4");
haha:
    printf("\n\n\t\tEnter your Choice: ");
    scanf("%d", &x);

    switch(x)
    {
    case 1:
        addCourseStudent(id);
        break;
    case 2:
        removeCourseS(id);
        break;
    case 3:
        enroledCourseS(id);
        break;
    case 4:
        student(id);
        break;
    default:
        goto haha;
    }
}
///----------------------------------------  advising Function-end ----------------------------------

///-----------------------------------  addCourseStudent Function-start ----------------------------------
void addCourseStudent(int id)
{
    clrscr();
    printf("%d\n", id);
    int row, c_code, i, j, currCourse, currStudent, m;
    char ans;
    Course courses[100];
    Student students[1000];
   // printf("%d\n", id);

    FILE *c, *l;
    c=fopen("course.dat", "r");
    fscanf(c,"%d", &currCourse);
    for(i=0; i<currCourse; i++)
    {
        fscanf(c,"%d %s %d %s",  &courses[i].code,  courses[i].nameC, &courses[i].seat, courses[i].faculty);
    }
    fclose(c);
    l=fopen("login.dat", "r");
    fscanf(l,"%d", &currStudent);
    for(i=0; i<currStudent; i++)
    {
        fscanf(l,"%d %s %s %s %s %d %s %s %d %d %s %s %d %s %s %d %s %s %d %s %s",
               &students[i].id, students[i].firstname, students[i].lastname, students[i].address, students[i].gmail,
               &students[i].number, students[i].username, students[i].password, &students[i].counter,
               &students[i].courselist[0].code, students[i].courselist[0].nameC, students[i].courselist[0].faculty,
               &students[i].courselist[1].code, students[i].courselist[1].nameC, students[i].courselist[1].faculty,
               &students[i].courselist[2].code, students[i].courselist[2].nameC, students[i].courselist[2].faculty,
               &students[i].courselist[3].code, students[i].courselist[3].nameC, students[i].courselist[3].faculty);
    }
    fclose(l);
    printf("\n\n\n\t\t!!!!!!!!!!!!!!  ADVISING WINDOW  !!!!!!!!!!!!!\n");
    gotoxy(10,7);
    printf("COURSE NAME");
    gotoxy(25,7);
    printf("COURSE CODE");
    gotoxy(40,7);
    printf("AVAILABLE SEAT");
    gotoxy(10,8);
    printf("=============================================");
    row=9;
    for(i=0; i<currCourse; i++)
    {
        gotoxy(10,row);
        printf("%s", courses[i].nameC);
        gotoxy(25,row);
        printf("%d", courses[i].code);
        gotoxy(40,row);
        printf("%d", courses[i].seat);
        row++;
    }
abc:
    printf("\n\tPress any key to continue...");
    getch();
def:
    // FIlE *cr, *lr;
    c=fopen("course.dat", "r");
    fscanf(c,"%d", &currCourse);
    for(i=0; i<currCourse; i++)
    {
        fscanf(c,"%d %s %d %s",  &courses[i].code,  courses[i].nameC, &courses[i].seat, courses[i].faculty);
    }
    fclose(c);
    l=fopen("login.dat", "r");
    fscanf(l,"%d", &currStudent);
    for(i=0; i<currStudent; i++)
    {
        fscanf(l,"%d %s %s %s %s %d %s %s %d %d %s %s %d %s %s %d %s %s %d %s %s",
               &students[i].id, students[i].firstname, students[i].lastname, students[i].address, students[i].gmail,
               &students[i].number, students[i].username, students[i].password, &students[i].counter,
               &students[i].courselist[0].code, students[i].courselist[0].nameC, students[i].courselist[0].faculty,
               &students[i].courselist[1].code, students[i].courselist[1].nameC, students[i].courselist[1].faculty,
               &students[i].courselist[2].code, students[i].courselist[2].nameC, students[i].courselist[2].faculty,
               &students[i].courselist[3].code, students[i].courselist[3].nameC, students[i].courselist[3].faculty);
    }
    fclose(l);

    for(i=0; i<currStudent; i++)
    {
        if(students[i].id==id)
        {
            //printf("id match\n");
            if(students[i].counter<4)
            {
jkl:
                printf("\n\n\tEnter course code to add: ");
                scanf("%d", &c_code);

                for(j=0; j<currCourse; j++)
                {
                    if(courses[j].code==c_code)
                    {
                        int flag=0;

                        for(m=0; m<4; m++)
                        {
                            if(students[i].courselist[m].code==c_code)
                            {
                                flag=1;
                            }
                        }
                        if(!flag)
                        {
                            if(courses[j].seat>0)
                            {
                                students[i].courselist[students[i].counter].code=courses[j].code;
                                strcpy(students[i].courselist[students[i].counter].faculty, courses[j].faculty);
                                strcpy(students[i].courselist[students[i].counter].nameC, courses[j].nameC);

                                students[i].counter++;
                                courses[j].seat--;
                                break;
                            }
                            else
                            {
                                printf("\n\n\tSeat not available.\n\tPlease take another course.\n");
                                goto abc;
                                break;
                            }
                        }
                        else
                        {
                            printf("\n\n\tYou have enrolled this course.\n\tPlease take another course.");
                            printf("\nPress any key to continue...");
                            getch();
                            goto jkl;
                        }

                    }
                }
                if(j==currCourse)
                {
                    printf("\n\nInvalid Course Code");
                    getch();
                    goto jkl;
                }
            }
            else
            {
                printf("\n\n\t**You have exceeded your maximum course limit**\n");
                printf("\nPress any key to back...\n");
                getch();
                advising(id);
            }

            break;
        }
    }
    FILE *cw, *lw;
    cw=fopen("course.dat", "w");
    fprintf(c,"%d\n", currCourse);
    for(i=0; i<currCourse; i++)
    {
        fprintf(c,"%d %s %d %s\n",  courses[i].code,  courses[i].nameC, courses[i].seat, courses[i].faculty);
    }
    fclose(cw);

    lw=fopen("login.dat", "w");
    fprintf(l,"%d\n", currStudent);
    for(i=0; i<currStudent; i++)
    {
        fprintf(l,"%d %s %s %s %s %d %s %s %d %d %s %s %d %s %s %d %s %s %d %s %s\n",
                students[i].id, students[i].firstname, students[i].lastname, students[i].address, students[i].gmail,
                students[i].number, students[i].username, students[i].password, students[i].counter,
                students[i].courselist[0].code, students[i].courselist[0].nameC, students[i].courselist[0].faculty,
                students[i].courselist[1].code, students[i].courselist[1].nameC, students[i].courselist[1].faculty,
                students[i].courselist[2].code, students[i].courselist[2].nameC, students[i].courselist[2].faculty,
                students[i].courselist[3].code, students[i].courselist[3].nameC, students[i].courselist[3].faculty);
    }
    fclose(l);
    printf("\n\n\tCourse added sucessfully");
ghi:
    printf("\n\n\tDo you want to add more course?[Y/N]-> ");
    scanf("%s", &ans);
    if (toupper(ans)=='Y')
    {
        goto def;
    }
    else if(toupper(ans)=='N')
    {
        printf("\n\t\t Thank you :) :)");
        printf("\nPress any key to back...");
        getch();
        advising(id);
    }
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto ghi;
    }
}
///-----------------------------------  addCourseStudent Function-end----------------------------------

///------------------------------------- enrolesCourseS Function-start ---------------------------------
void enroledCourseS(int id)
{
    clrscr();
    // printf("%d\n", id);
    Student students[1000];
    int currStudent, i, j, row;
    FILE *o;
    o=fopen("login.dat", "r");
    fscanf(o,"%d", &currStudent);
    for(i=0; i<currStudent; i++)
    {
        fscanf(o,"%d %s %s %s %s %d %s %s %d %d %s %s %d %s %s %d %s %s %d %s %s",
               &students[i].id, students[i].firstname, students[i].lastname, students[i].address, students[i].gmail,
               &students[i].number, students[i].username, students[i].password, &students[i].counter,
               &students[i].courselist[0].code, students[i].courselist[0].nameC, students[i].courselist[0].faculty,
               &students[i].courselist[1].code, students[i].courselist[1].nameC, students[i].courselist[1].faculty,
               &students[i].courselist[2].code, students[i].courselist[2].nameC, students[i].courselist[2].faculty,
               &students[i].courselist[3].code, students[i].courselist[3].nameC, students[i].courselist[3].faculty);
    }
    fclose(o);
    printf("\n\n\n\n\t\t!!!!!!!!!!!!!!  ENROLED COURSE  !!!!!!!!!!!!!\n");
    gotoxy(10,7);
    printf("COURSE NAME");
    gotoxy(30,7);
    printf("COURSE CODE");
    gotoxy(48,7);
    printf("FACULTY");
    gotoxy(10,8);
    printf("=============================================");
    row=9;
    for(i=0; i<currStudent; i++)
    {
        if(students[i].id==id)
        {
            for(j=0; j<4; j++)
            {
                gotoxy(10,row);
                printf("%s", students[i].courselist[j].nameC);
                gotoxy(30,row);
                printf("%d", students[i].courselist[j].code);
                gotoxy(48,row);
                printf("%s", students[i].courselist[j].faculty);
                row++;
            }
            break;
        }
    }
    printf("\n\n\nPress any key to back...");
    getch();
    advising(id);
}
///------------------------------------- enrolesCourseS Function-end ---------------------------------

///------------------------------------ removeCourseS Function-start ---------------------------------
void removeCourseS(int id)
{
    clrscr();
    // printf("%d\n", id);
    char ans;
    Student students[1000];
    Course courses[100];
    int currStudent, currCourse, i, j, row, find, m, n;
    FILE *o, *c;

    c=fopen("course.dat", "r");
    fscanf(c,"%d", &currCourse);
    for(i=0; i<currCourse; i++)
    {
        fscanf(c,"%d %s %d %s",  &courses[i].code,  courses[i].nameC, &courses[i].seat, courses[i].faculty);
    }
    fclose(c);

    o=fopen("login.dat", "r");
    fscanf(o,"%d", &currStudent);
    for(i=0; i<currStudent; i++)
    {
        fscanf(o,"%d %s %s %s %s %d %s %s %d %d %s %s %d %s %s %d %s %s %d %s %s",
               &students[i].id, students[i].firstname, students[i].lastname, students[i].address, students[i].gmail,
               &students[i].number, students[i].username, students[i].password, &students[i].counter,
               &students[i].courselist[0].code, students[i].courselist[0].nameC, students[i].courselist[0].faculty,
               &students[i].courselist[1].code, students[i].courselist[1].nameC, students[i].courselist[1].faculty,
               &students[i].courselist[2].code, students[i].courselist[2].nameC, students[i].courselist[2].faculty,
               &students[i].courselist[3].code, students[i].courselist[3].nameC, students[i].courselist[3].faculty);
    }
    fclose(o);
    printf("\n\n\n\n\t\t!!!!!!!!!!!!!!  ENROLED COURSE  !!!!!!!!!!!!!\n");
    gotoxy(10,7);
    printf("COURSE NAME");
    gotoxy(30,7);
    printf("COURSE CODE");
    gotoxy(48,7);
    printf("FACULTY");
    gotoxy(10,8);
    printf("=============================================");
    row=9;
    for(i=0; i<currStudent; i++)
    {
        if(students[i].id==id)
        {
            for(j=0; j<4; j++)
            {
                gotoxy(10,row);
                printf("%s", students[i].courselist[j].nameC);
                gotoxy(30,row);
                printf("%d", students[i].courselist[j].code);
                gotoxy(48,row);
                printf("%s", students[i].courselist[j].faculty);
                row++;
            }
            printf("\n");

xyz:
            printf("\n\n\tEnter Course Code you want to remove: ");
            scanf("%d", &find);
            for(j=0; j<4; j++)
            {
                if(students[i].courselist[j].code==find)
                {
                    if(j==3)
                    {
                        students[i].courselist[j].code=0;
                        strcpy(students[i].courselist[j].nameC, "-");
                        strcpy(students[i].courselist[j].faculty, "-");
                    }
                    else
                    {
                        for(n=j; n<3; n++)
                        {
                            students[i].courselist[n].code=students[i].courselist[n+1].code;
                            strcpy(students[i].courselist[n].nameC, students[i].courselist[n+1].nameC);
                            strcpy(students[i].courselist[n].faculty, students[i].courselist[n+1].faculty);
                        }
                        students[i].courselist[3].code=0;
                        strcpy(students[i].courselist[3].nameC, "-");
                        strcpy(students[i].courselist[3].faculty, "-");
                    }
                    students[i].counter--;

                    for(m=0; m<currCourse; m++)
                    {
                        if(find== courses[m].code)
                        {
                            courses[m].seat++;

                            o=fopen("login.dat", "w");
                            fprintf(o,"%d\n", currStudent);
                            for(i=0; i<currStudent; i++)
                            {
                                fprintf(o,"%d %s %s %s %s %d %s %s %d %d %s %s %d %s %s %d %s %s %d %s %s\n",
                                        students[i].id, students[i].firstname, students[i].lastname, students[i].address, students[i].gmail,
                                        students[i].number, students[i].username, students[i].password, students[i].counter,
                                        students[i].courselist[0].code, students[i].courselist[0].nameC, students[i].courselist[0].faculty,
                                        students[i].courselist[1].code, students[i].courselist[1].nameC, students[i].courselist[1].faculty,
                                        students[i].courselist[2].code, students[i].courselist[2].nameC, students[i].courselist[2].faculty,
                                        students[i].courselist[3].code, students[i].courselist[3].nameC, students[i].courselist[3].faculty);
                            }
                            fclose(o);
                            c=fopen("course.dat", "w");
                            fprintf(c,"%d\n", currCourse);
                            for(i=0; i<currCourse; i++)
                            {
                                fprintf(c,"%d %s %d %s\n",  courses[i].code,  courses[i].nameC, courses[i].seat, courses[i].faculty);
                            }
                            fclose(c);
                            printf("\n\n\tCourse removed successfully");
                            printf("\nPress any key to continue...");
                            getch();
                            fflush(stdin);
                            break;
                        }
                    }
                    break;
                }
            }
            if(j==4)
            {
                printf("\n\n\tCourse code you entered is not enrolled");
                printf("\nPress ENTER to re-enter course code OR press ANY KEY to go back...[ENTER/ANY KEY]? ");
                if(getch()==13)
                    goto xyz;
                else
                {
                    advising(id);
                }
            }
            break;
        }
    }
ghi:
    printf("\n\n\tDo you want to remove more course?[Y/N]-> ");
    scanf("%s", &ans);
    if (toupper(ans)=='Y')
    {
        goto xyz;
    }
    else if(toupper(ans)=='N')
    {
        printf("\n\t\t Thank you :) :)");
        printf("\nPress any key to back...");
        getch();
        advising(id);
    }
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto ghi;
    }
}
///------------------------------------ removeCourseS Function-end ---------------------------------



