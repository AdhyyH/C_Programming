#include <stdio.h>

void main ()
{
    char state[5][20]={"Kuantan","Pekan","Rompin","Temerloh","Bentong"};
    int newcase[5][5]={},newdeath[5][5]={},newrecovery[5][5]={};
    int totalcase[5][5]={},totaldeath[5][5]={},totalrecovery[5][5]={};
    int mco;
    char zone[20];

    for(int day=0;day<2;day++)
    {
        printf("\n\n========================== DAY %i =========================\n",(day+1));
        for(int i=0;i<5;i++)
        {
            printf("\n%s\n",state[i]);
            for(int j=0;j<1;j++)
            {
                printf("New case: ");
                scanf ("%d",&newcase[i][j]);
                printf("New death: ");
                scanf ("%d",&newdeath[i][j]);
                printf("New recovery: ");
                scanf ("%d",&newrecovery[i][j]);
            }
        }
        printf("\n========================= Cumulative Cases ======================");
        for(int i=0;i<5;i++)
        {
            printf("\n\n%s",state[i]);
            for(int j=0;j<1;j++)
            {
                totalcase[i][j]=totalcase[i][j]+newcase[i][j]-newdeath[i][j]-newrecovery[i][j];
                printf ("\ntotal active case:%i",totalcase[i][j]);
                totaldeath[i][j]=totaldeath[i][j]+newdeath[i][j];
                printf ("\ntotal death:%i",totaldeath[i][j]);
                totalrecovery[i][j]=totalrecovery[i][j]+newrecovery[i][j];
                printf ("\ntotal recovery:%i",totalrecovery[i][j]);
            }
        if(totalcase>40)
        {
           printf("\n zone red");
           newcase=10000;
        }
        else if(totalcase>=20)
        {
           printf("\n zone orange");
           newcase=1000;
        }
        else if(totalcase>=1)
        {
           printf("\n zone yellow");
           newcase=100;
        }
        else
        {
           printf("\n zone green");
            newcase=10;
        }
        mco = mco + newcase;
        }
    }
      if(mco>=40000)
     {
        printf("\nEnhanced Movement Control Order");
        printf("\nyour abbreviation is EMCO");
     }
    else if(mco>=4000)
     {
        printf("\nConditional Movement Control Order");
        printf("\n Abbreviation is CMCO");
     }
    else if(mco>=400)
     {
        printf("\nSemi Enhanced Movement Control Order");
        printf("\n Abbreviation is SEMCO");
     }
    else
     {
        printf("\nRecovery Movement Control Order");
        printf("\n Abbreviation is RMCO");
     }

return 0;
}

