
///----------------- Prototypes start ---------------
void addUniversityInfo();
void showUniversityInfo(int id);
///------------------ Prototypes end ---------------

///------------------------------------- addUniversityInfo Function-start ---------------------------------
void addUniversityInfo()
{
    char info[1000]="";
    printf("\n\n\n\tEnter Info: \n");
    gets(info);

     FILE *o;
    o=fopen("info.dat", "w");
    fprintf(o, "%s", info);
    fclose(o);
    printf("Press any key to back...");
    getch();
    addInfo();
}
///------------------------------------- addUniversityInfo Function-end ---------------------------------

///------------------------------------ showUniversityInfo Function-start ---------------------------------
void showUniversityInfo(int id)
{
    clrscr();
    char info[1000];

    FILE *o;
    o=fopen("info.dat", "r");
    printf("\n\n\n");
    while (fgets(info, 10000, o)!= NULL)
    printf("%s", info);
    printf("\n\n\n");
    printf("Pres any key to back...");
    getch();
    fflush(stdin);
    student(id);
}
///------------------------------------ showUniversityInfo Function-end ---------------------------------
