
typedef struct
{
    char location[20];
    char time[6];
} Stopage;

typedef struct
{
    int busno;
    Stopage stop[7];
} Bus;

///------------------ Prototypes start ---------------
void addBusSchedule();
void showBusSchedule(int id);
void searchBusSchedule();
void editBusSchedule();
void deleteBusSchedule();
///------------------- Prototypes end ----------------

///------------------------------------- addBusSchedule Function-start ---------------------------------
void addBusSchedule()
{
    char ans;
    int currBus,i;
    Bus buses[100];
    FILE *o, *w;//file pointer
qwe:
    o=fopen("bus.dat","r");//open file in write mode

    fscanf(o, "%d", &currBus);
    for(i=0; i<currBus; i++)
    {
        fscanf(o,"%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
               &buses[i].busno,
               buses[i].stop[0].location, buses[i].stop[0].time,
               buses[i].stop[1].location, buses[i].stop[1].time, buses[i].stop[2].location, buses[i].stop[2].time,
               buses[i].stop[3].location, buses[i].stop[3].time, buses[i].stop[4].location, buses[i].stop[4].time,
               buses[i].stop[5].location, buses[i].stop[5].time, buses[i].stop[6].location, buses[i].stop[6].time);
    }
    fclose(o);

    printf("\n\t\t!!!!!!!!!!  Add Bus Schedule  !!!!!!!!!!");

    printf("\n\t\t\tEnter Bus No.   : ");
    scanf("%d", &buses[i].busno);

    printf("\n\t\t\tStopage 1             : ");
    scanf("%s", buses[i].stop[0].location);
    buses[i].stop[0].location[0]= toupper(buses[i].stop[0].location[0]);
    printf("\n\t\t\tStopage 1 Time[00.00] : ");
    scanf("%s", buses[i].stop[0].time);

    printf("\n\t\t\tStopage 2             : ");
    scanf("%s", buses[i].stop[1].location);
    buses[i].stop[1].location[0]= toupper(buses[i].stop[1].location[0]);
    printf("\n\t\t\tStopage 2 Time[00.00] : ");
    scanf("%s", buses[i].stop[1].time);

    printf("\n\t\t\tStopage 3             : ");
    scanf("%s", buses[i].stop[2].location);
    buses[i].stop[2].location[0]= toupper(buses[i].stop[2].location[0]);
    printf("\n\t\t\tStopage 3 Time[00.00] : ");
    scanf("%s", buses[i].stop[2].time);

    printf("\n\t\t\tStopage 4             : ");
    scanf("%s", buses[i].stop[3].location);
    buses[i].stop[3].location[0]= toupper(buses[i].stop[3].location[0]);
    printf("\n\t\t\tStopage 4 Time[00.00] : ");
    scanf("%s", buses[i].stop[3].time);

    printf("\n\t\t\tStopage 5             : ");
    scanf("%s", buses[i].stop[4].location);
    buses[i].stop[4].location[0]= toupper(buses[i].stop[4].location[0]);
    printf("\n\t\t\tStopage 5 Time[00.00] : ");
    scanf("%s", buses[i].stop[4].time);

    printf("\n\t\t\tStopage 6             : ");
    scanf("%s", buses[i].stop[5].location);
    buses[i].stop[5].location[0]= toupper(buses[i].stop[5].location[0]);
    printf("\n\t\t\tStopage 6 Time[00.00] : ");
    scanf("%s", buses[i].stop[5].time);

    printf("\n\t\t\tStopage 7            : ");
    scanf("%s", buses[i].stop[6].location);
    buses[i].stop[6].location[0]= toupper(buses[i].stop[6].location[0]);
    printf("\n\t\t\tStopage 7 Time[00.00] : ");
    scanf("%s", buses[i].stop[6].time);

    currBus++;

    o=fopen("bus.dat","w");//open file in write mode
    fprintf(o, "%d\n", currBus);
    for(i=0; i<currBus; i++)
    {
        fprintf(o,"%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",
                buses[i].busno,
                buses[i].stop[0].location, buses[i].stop[0].time,
                buses[i].stop[1].location, buses[i].stop[1].time, buses[i].stop[2].location, buses[i].stop[2].time,
                buses[i].stop[3].location, buses[i].stop[3].time, buses[i].stop[4].location, buses[i].stop[4].time,
                buses[i].stop[5].location, buses[i].stop[5].time, buses[i].stop[6].location, buses[i].stop[6].time);
    }
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(o);
se:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf("%s",&ans);
    if (toupper(ans)=='Y')
    {
        goto qwe;
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
        goto se;
    }
}
///------------------------------------- addBusSchedule Function-end ---------------------------------

///------------------------------------- showBusSchedule Function-start ---------------------------------
void showBusSchedule(int id)
{
    clrscr();
    int currBus,i, row;
    Bus buses[100];
    FILE *o;
    o=fopen("bus.dat","r");

    fscanf(o, "%d", &currBus);
    for(i=0; i<currBus; i++)
    {
        fscanf(o,"%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
               &buses[i].busno,
               buses[i].stop[0].location, buses[i].stop[0].time,
               buses[i].stop[1].location, buses[i].stop[1].time, buses[i].stop[2].location, buses[i].stop[2].time,
               buses[i].stop[3].location, buses[i].stop[3].time, buses[i].stop[4].location, buses[i].stop[4].time,
               buses[i].stop[5].location, buses[i].stop[5].time, buses[i].stop[6].location, buses[i].stop[6].time);
    }
    fclose(o);

    printf("\n\n\n\t\t\t\t!!!!!!!!!!!!!! Bus Schedule !!!!!!!!!!!!!\n");
    gotoxy(1,7);
    printf("Bus No.");
    gotoxy(10,7);
    printf("Stop 1");
    gotoxy(23,7);
    printf("Stop 2");
    gotoxy(36,7);
    printf("Stop 3");
    gotoxy(49,7);
    printf("Stop 4");
    gotoxy(62,7);
    printf("Stop 5");
    gotoxy(75,7);
    printf("Stop 6");
    gotoxy(88,7);
    printf("Stop 7");

    gotoxy(10,8);
    printf("& Time");
    gotoxy(23,8);
    printf("& Time");
    gotoxy(36,8);
    printf("& Time");
    gotoxy(49,8);
    printf("& Time");
    gotoxy(62,8);
    printf("& Time");
    gotoxy(75,8);
    printf("& Time");
    gotoxy(88,8);
    printf("& Time");
    printf("\n====================================================================================================");
    row=10;
    for(i=0; i<currBus; i++)
    {
        gotoxy(1,row);
        printf("%d", buses[i].busno);
        gotoxy(10,row);
        printf("%s",buses[i].stop[0].location);
        gotoxy(23,row);
        printf("%s",buses[i].stop[1].location);
        gotoxy(36,row);
        printf("%s",buses[i].stop[2].location);
        gotoxy(49,row);
        printf("%s",buses[i].stop[3].location);
        gotoxy(62,row);
        printf("%s",buses[i].stop[4].location);
        gotoxy(75,row);
        printf("%s",buses[i].stop[5].location);
        gotoxy(88,row);
        printf("%s",buses[i].stop[6].location);
        row++;

        gotoxy(10,row);
        printf("%s",buses[i].stop[0].time);
        gotoxy(23,row);
        printf("%s",buses[i].stop[1].time);
        gotoxy(36,row);
        printf("%s",buses[i].stop[2].time);
        gotoxy(49,row);
        printf("%s",buses[i].stop[3].time);
        gotoxy(62,row);
        printf("%s",buses[i].stop[4].time);
        gotoxy(75,row);
        printf("%s",buses[i].stop[5].time);
        gotoxy(88,row);
        printf("%s",buses[i].stop[6].time);
        printf("\n----------------------------------------------------------------------------------------------------");
        row=row+2;
    }
    printf("\n\npress any key to back...");
    getch();
    student(id);

}
///------------------------------------- showBusSchedule Function-end ---------------------------------

///----------------------------------- searchBusSchedule Function-start ---------------------------------
void searchBusSchedule()
{
    char ans;
    Bus buses[100];
    int currBus, i, bus;
    FILE *o;
qwe:
    clrscr();
    o=fopen("bus.dat","r");//open file in write mode
    fscanf(o, "%d", &currBus);
    for(i=0; i<currBus; i++)
    {
        fscanf(o,"%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
               &buses[i].busno,
               buses[i].stop[0].location, buses[i].stop[0].time,
               buses[i].stop[1].location, buses[i].stop[1].time, buses[i].stop[2].location, buses[i].stop[2].time,
               buses[i].stop[3].location, buses[i].stop[3].time, buses[i].stop[4].location, buses[i].stop[4].time,
               buses[i].stop[5].location, buses[i].stop[5].time, buses[i].stop[6].location, buses[i].stop[6].time);
    }
    fclose(o);
    printf("\n\n\n\t\t\t\t!!!!!!!!!!!!!! Search Bus !!!!!!!!!!!!!\n");
    gotoxy(20,5);
    printf("\t\t\tEnter Bus No: ");
    scanf("%d",&bus);

    for(i=0; i<currBus; i++)
    {
        if(buses[i].busno==bus)
        {
            gotoxy(1,8);
            printf("Bus No.");
            gotoxy(10,8);
            printf("Stop 1");
            gotoxy(23,8);
            printf("Stop 2");
            gotoxy(36,8);
            printf("Stop 3");
            gotoxy(49,8);
            printf("Stop 4");
            gotoxy(62,8);
            printf("Stop 5");
            gotoxy(75,8);
            printf("Stop 6");
            gotoxy(88,8);
            printf("Stop 7");

            gotoxy(10,9);
            printf("& Time");
            gotoxy(23,9);
            printf("& Time");
            gotoxy(36,9);
            printf("& Time");
            gotoxy(49,9);
            printf("& Time");
            gotoxy(62,9);
            printf("& Time");
            gotoxy(75,9);
            printf("& Time");
            gotoxy(88,9);
            printf("& Time");
            printf("\n====================================================================================================");

            gotoxy(1,11);
            printf("%d", buses[i].busno);
            gotoxy(10,11);
            printf("%s",buses[i].stop[0].location);
            gotoxy(23,11);
            printf("%s",buses[i].stop[1].location);
            gotoxy(36,11);
            printf("%s",buses[i].stop[2].location);
            gotoxy(49,11);
            printf("%s",buses[i].stop[3].location);
            gotoxy(62,11);
            printf("%s",buses[i].stop[4].location);
            gotoxy(75,11);
            printf("%s",buses[i].stop[5].location);
            gotoxy(88,11);
            printf("%s",buses[i].stop[6].location);

            gotoxy(10,12);
            printf("%s",buses[i].stop[0].time);
            gotoxy(23,12);
            printf("%s",buses[i].stop[1].time);
            gotoxy(36,12);
            printf("%s",buses[i].stop[2].time);
            gotoxy(49,12);
            printf("%s",buses[i].stop[3].time);
            gotoxy(62,12);
            printf("%s",buses[i].stop[4].time);
            gotoxy(75,12);
            printf("%s",buses[i].stop[5].time);
            gotoxy(88,12);
            printf("%s",buses[i].stop[6].time);
            printf("\n----------------------------------------------------------------------------------------------------");
            printf("\n\n\nPress any key to continue...");
            break;
        }
    }
    if(i==currBus)
    {
        gotoxy(10,8);
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
///----------------------------------- searchBusSchedule Function-end ---------------------------------

///----------------------------------- editBusSchedule Function-start ---------------------------------
void editBusSchedule()
{

    char ans;
    Bus buses[100];
    int currBus, i, bus;
    FILE *o;
qwe:
    clrscr();
    o=fopen("bus.dat","r");//open file in write mode
    fscanf(o, "%d", &currBus);
    for(i=0; i<currBus; i++)
    {
        fscanf(o,"%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
               &buses[i].busno,
               buses[i].stop[0].location, buses[i].stop[0].time,
               buses[i].stop[1].location, buses[i].stop[1].time, buses[i].stop[2].location, buses[i].stop[2].time,
               buses[i].stop[3].location, buses[i].stop[3].time, buses[i].stop[4].location, buses[i].stop[4].time,
               buses[i].stop[5].location, buses[i].stop[5].time, buses[i].stop[6].location, buses[i].stop[6].time);
    }
    fclose(o);
    printf("\n\n\n\t\t\t\t!!!!!!!!!!!!!!   Edit Bus  !!!!!!!!!!!!!\n");
    gotoxy(20,5);
    printf("\t\t\tEnter Bus No: ");
    scanf("%d",&bus);

    for(i=0; i<currBus; i++)
    {
        if(buses[i].busno==bus)
        {
            gotoxy(1,8);
            printf("Bus No.");
            gotoxy(10,8);
            printf("Stop 1");
            gotoxy(23,8);
            printf("Stop 2");
            gotoxy(36,8);
            printf("Stop 3");
            gotoxy(49,8);
            printf("Stop 4");
            gotoxy(62,8);
            printf("Stop 5");
            gotoxy(75,8);
            printf("Stop 6");
            gotoxy(88,8);
            printf("Stop 7");

            gotoxy(10,9);
            printf("& Time");
            gotoxy(23,9);
            printf("& Time");
            gotoxy(36,9);
            printf("& Time");
            gotoxy(49,9);
            printf("& Time");
            gotoxy(62,9);
            printf("& Time");
            gotoxy(75,9);
            printf("& Time");
            gotoxy(88,9);
            printf("& Time");
            printf("\n====================================================================================================");

            gotoxy(1,11);
            printf("%d", buses[i].busno);
            gotoxy(10,11);
            printf("%s",buses[i].stop[0].location);
            gotoxy(23,11);
            printf("%s",buses[i].stop[1].location);
            gotoxy(36,11);
            printf("%s",buses[i].stop[2].location);
            gotoxy(49,11);
            printf("%s",buses[i].stop[3].location);
            gotoxy(62,11);
            printf("%s",buses[i].stop[4].location);
            gotoxy(75,11);
            printf("%s",buses[i].stop[5].location);
            gotoxy(88,11);
            printf("%s",buses[i].stop[6].location);

            gotoxy(10,12);
            printf("%s",buses[i].stop[0].time);
            gotoxy(23,12);
            printf("%s",buses[i].stop[1].time);
            gotoxy(36,12);
            printf("%s",buses[i].stop[2].time);
            gotoxy(49,12);
            printf("%s",buses[i].stop[3].time);
            gotoxy(62,12);
            printf("%s",buses[i].stop[4].time);
            gotoxy(75,12);
            printf("%s",buses[i].stop[5].time);
            gotoxy(88,12);
            printf("%s",buses[i].stop[6].time);
            printf("\n----------------------------------------------------------------------------------------------------");
            printf("\n\n\n\t\t\t\tEdit your bus:\n");

            printf("\n\t\t\t\tEnter Bus No.   : ");
            scanf("%d", &buses[i].busno);

            printf("\n\t\t\t\tStopage 1             : ");
            scanf("%s", buses[i].stop[0].location);
            buses[i].stop[0].location[0]= toupper(buses[i].stop[0].location[0]);
            printf("\n\t\t\t\tStopage 1 Time[00.00] : ");
            scanf("%s", buses[i].stop[0].time);

            printf("\n\t\t\t\tStopage 2             : ");
            scanf("%s", buses[i].stop[1].location);
            buses[i].stop[1].location[0]= toupper(buses[i].stop[1].location[0]);
            printf("\n\t\t\t\tStopage 2 Time[00.00] : ");
            scanf("%s", buses[i].stop[1].time);

            printf("\n\t\t\t\tStopage 3             : ");
            scanf("%s", buses[i].stop[2].location);
            buses[i].stop[2].location[0]= toupper(buses[i].stop[2].location[0]);
            printf("\n\t\t\t\tStopage 3 Time[00.00] : ");
            scanf("%s", buses[i].stop[2].time);

            printf("\n\t\t\t\tStopage 4             : ");
            scanf("%s", buses[i].stop[3].location);
            buses[i].stop[3].location[0]= toupper(buses[i].stop[3].location[0]);
            printf("\n\t\t\t\tStopage 4 Time[00.00] : ");
            scanf("%s", buses[i].stop[3].time);

            printf("\n\t\t\t\tStopage 5             : ");
            scanf("%s", buses[i].stop[4].location);
            buses[i].stop[4].location[0]= toupper(buses[i].stop[4].location[0]);
            printf("\n\t\t\t\tStopage 5 Time[00.00] : ");
            scanf("%s", buses[i].stop[4].time);

            printf("\n\t\t\t\tStopage 6             : ");
            scanf("%s", buses[i].stop[5].location);
            buses[i].stop[5].location[0]= toupper(buses[i].stop[5].location[0]);
            printf("\n\t\t\t\tStopage 6 Time[00.00] : ");
            scanf("%s", buses[i].stop[5].time);

            printf("\n\t\t\t\tStopage 7            : ");
            scanf("%s", buses[i].stop[6].location);
            buses[i].stop[6].location[0]= toupper(buses[i].stop[6].location[0]);
            printf("\n\t\t\t\tStopage 7 Time[00.00] : ");
            scanf("%s", buses[i].stop[6].time);

            printf("\nPress 'U' for update routine or press 'ANY KEY' to leave: ");
            scanf("%s", &ans);
            if(ans=='u' || ans=='U')
            {
                o=fopen("bus.dat","w");//open file in write mode
                fprintf(o, "%d\n", currBus);
                for(i=0; i<currBus; i++)
                {
                    fprintf(o,"%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",
                            buses[i].busno,
                            buses[i].stop[0].location, buses[i].stop[0].time,
                            buses[i].stop[1].location, buses[i].stop[1].time, buses[i].stop[2].location, buses[i].stop[2].time,
                            buses[i].stop[3].location, buses[i].stop[3].time, buses[i].stop[4].location, buses[i].stop[4].time,
                            buses[i].stop[5].location, buses[i].stop[5].time, buses[i].stop[6].location, buses[i].stop[6].time);
                }
                printf("\n\n\t\t\t.... Information Record Successful ...");
                fclose(o);
            }
            break;
        }
    }
    if(i==currBus)
    {
        gotoxy(10,8);
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
///----------------------------------- editBusSchedule Function-end ---------------------------------

///--------------------------------- deleteBusSchedule Function-start ---------------------------------
void deleteBusSchedule()
{
    int currBus,i, j, row, bus;
    char ans;
    Bus buses[100];
    FILE *o;//file pointer
 xyz:
      clrscr();
    o=fopen("bus.dat","r");//open file in write mode
    fscanf(o, "%d", &currBus);
    for(i=0; i<currBus; i++)
    {
        fscanf(o,"%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
               &buses[i].busno,
               buses[i].stop[0].location, buses[i].stop[0].time,
               buses[i].stop[1].location, buses[i].stop[1].time, buses[i].stop[2].location, buses[i].stop[2].time,
               buses[i].stop[3].location, buses[i].stop[3].time, buses[i].stop[4].location, buses[i].stop[4].time,
               buses[i].stop[5].location, buses[i].stop[5].time, buses[i].stop[6].location, buses[i].stop[6].time);
    }
    fclose(o);

    printf("\n\n\n\n\t\t\t\t!!!!!!!!!!!!!! Bus Schedule !!!!!!!!!!!!!\n");
    gotoxy(1,7);
    printf("Bus No.");
    gotoxy(10,7);
    printf("Stop 1");
    gotoxy(23,7);
    printf("Stop 2");
    gotoxy(36,7);
    printf("Stop 3");
    gotoxy(49,7);
    printf("Stop 4");
    gotoxy(62,7);
    printf("Stop 5");
    gotoxy(75,7);
    printf("Stop 6");
    gotoxy(88,7);
    printf("Stop 7");

    gotoxy(10,8);
    printf("& Time");
    gotoxy(23,8);
    printf("& Time");
    gotoxy(36,8);
    printf("& Time");
    gotoxy(49,8);
    printf("& Time");
    gotoxy(62,8);
    printf("& Time");
    gotoxy(75,8);
    printf("& Time");
    gotoxy(88,8);
    printf("& Time");
    printf("\n====================================================================================================");
    row=10;
    for(i=0; i<currBus; i++)
    {
        gotoxy(1,row);
        printf("%d", buses[i].busno);
        gotoxy(10,row);
        printf("%s",buses[i].stop[0].location);
        gotoxy(23,row);
        printf("%s",buses[i].stop[1].location);
        gotoxy(36,row);
        printf("%s",buses[i].stop[2].location);
        gotoxy(49,row);
        printf("%s",buses[i].stop[3].location);
        gotoxy(62,row);
        printf("%s",buses[i].stop[4].location);
        gotoxy(75,row);
        printf("%s",buses[i].stop[5].location);
        gotoxy(88,row);
        printf("%s",buses[i].stop[6].location);
        row++;

        gotoxy(10,row);
        printf("%s",buses[i].stop[0].time);
        gotoxy(23,row);
        printf("%s",buses[i].stop[1].time);
        gotoxy(36,row);
        printf("%s",buses[i].stop[2].time);
        gotoxy(49,row);
        printf("%s",buses[i].stop[3].time);
        gotoxy(62,row);
        printf("%s",buses[i].stop[4].time);
        gotoxy(75,row);
        printf("%s",buses[i].stop[5].time);
        gotoxy(88,row);
        printf("%s",buses[i].stop[6].time);
        printf("\n----------------------------------------------------------------------------------------------------");
        row=row+2;
    }
    printf("\n");
    printf("\n\n\t\t\t\t\tEnter bus no to remove: ");
    scanf("%d", &bus);

    int flag=0;
    for(i=0; i<currBus; i++)
    {

        if(buses[i].busno==bus)
        {
            flag=1;
            if(i<(currBus-1))
            {
                for(j=i; j<currBus; j++)
                {
                    buses[j].busno=buses[j+1].busno;
                    strcpy(buses[j].stop[0].location, buses[j+1].stop[0].location);
                    strcpy(buses[j].stop[0].time, buses[j+1].stop[0].time);
                    strcpy(buses[j].stop[1].location, buses[j+1].stop[1].location);
                    strcpy(buses[j].stop[1].time, buses[j+1].stop[1].time);
                    strcpy(buses[j].stop[2].location, buses[j+1].stop[2].location);
                    strcpy(buses[j].stop[2].time, buses[j+1].stop[2].time);
                    strcpy(buses[j].stop[3].location, buses[j+1].stop[3].location);
                    strcpy(buses[j].stop[3].time, buses[j+1].stop[3].time);
                    strcpy(buses[j].stop[4].location, buses[j+1].stop[4].location);
                    strcpy(buses[j].stop[4].time, buses[j+1].stop[4].time);
                    strcpy(buses[j].stop[5].location, buses[j+1].stop[5].location);
                    strcpy(buses[j].stop[5].time, buses[j+1].stop[5].time);
                    strcpy(buses[j].stop[6].location, buses[j+1].stop[6].location);
                    strcpy(buses[j].stop[6].time, buses[j+1].stop[6].time);
                }
            }
            currBus--;
            printf("\n\n\t\tPress 'D' for Remove or press 'ANY KEY' to leave: ");
            scanf("%s", &ans);
            if(ans=='d' || ans=='D')
            {
                 o=fopen("bus.dat","w");
                fprintf(o, "%d\n", currBus);
                for(i=0; i<currBus; i++)
                {
                    fprintf(o,"%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",
                            buses[i].busno,
                            buses[i].stop[0].location, buses[i].stop[0].time,
                            buses[i].stop[1].location, buses[i].stop[1].time, buses[i].stop[2].location, buses[i].stop[2].time,
                            buses[i].stop[3].location, buses[i].stop[3].time, buses[i].stop[4].location, buses[i].stop[4].time,
                            buses[i].stop[5].location, buses[i].stop[5].time, buses[i].stop[6].location, buses[i].stop[6].time);
                }
                printf("\n\n\t\t\t.... Patient record updated successfully ...");
                fclose(o);
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
///----------------------------------- deleteBusSchedule Function-end ---------------------------------

