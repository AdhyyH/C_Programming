#include <stdio.h>
#include <string.h>
#include <math.h>
float month_interest(float,float);
float annual_interest(int);
float remaining(float,float);
void display();
void view();
int main()
{
    char nme[25],ic[15],age[2],address[31],postcode[6],city[10],state[10],profession[15],family[2],type,loop,cr,house,category[12];
    char abc[3]={'A','B','C'},loan[30][30]={"Car loan","House Loan","Business loan"};
    float incme,arrloan[3]={0,0,0},net,arrRloan[3]={0,0,0},arrannual[3]={0,0,0},arrinterest[3]={0,0,0},arrdown[3]={0,0,0},arrmonthly[3]={0,0,0},arrmonthlyinterest[3]={0,0,0},rate_deduction;
    int i,period[3]={0,0,0},jenis;
    char *pointer1="PERSONAL INFORMATION";
    char *pointer2="NAME                ";
    char *pointer3="Information card (IC)   :";
    char *pointer4="Age                     :";
    char *pointer5="Address                 :";
    char *pointer6="Postcode                :";

    FILE *data;
    data=(fopen("information.txt","w"));
    fprintf(data,"\n\nInformation of user");
    printf("\n--------------------------------------------------------------------------");
    printf("\n\t\t\t%s",pointer1);
    printf("\n--------------------------------------------------------------------------");
    printf("\n%s:",pointer2);
    fgets(nme,19,stdin);
    printf("\n%s",pointer3);
    scanf("%s",&ic);
    printf("\n%s",pointer4);
    scanf("%s",&age);
    printf("\n%s",pointer5);
    scanf("%s",&address);
    printf("\n%s",pointer6);
    scanf("%s",&postcode);
    printf("\nCity                    :");
    scanf("%s",&city);
    printf("\nState                   :");
    scanf("%s",&state);
    printf("\nProfession             :");
    scanf("%s",&profession);
    printf("\nNumber of family members:");
    scanf("%s",&family);
    printf("\nTotal monthly income    :");
    scanf("%f",&incme);
    fprintf(data,"\n%s %s %s %s %s %s %s %s %s %s",nme,ic,age,address,postcode,city,state,profession,family);
    fprintf(data,"%f",incme);

    if (incme<=4850)
    {
        strncpy(category,"B40",11);
        rate_deduction=1.4;
    }
    else if(incme<10959)
    {
        strncpy(category,"M40",11);
        rate_deduction=1.2;
    }
    else
    {
        strncpy(category,"T20",11);
        rate_deduction=1.0;
    }
    printf("\n----------------------------------------------------------------------------");
    printf("\n\t\t\t\tLOAN SECTION");
    printf("\n----------------------------------------------------------------------------");
    floop:
    display();
    printf("\nEnter Type of loan you interest in(A/B/C):");
    fflush(stdin);
    scanf("%c",&type);

if(type=='A')
    {
    printf("\n          Type of Car                           Annual interest rate");
    printf("\n-----------------------------------------------------------------------------------");
    printf("\n Local                                                  5.1");
    printf("\n International                                          6.4");
    printf("\nEnter Type of car(International=A/Local=B):");
    fflush(stdin);
    scanf("%c",&cr);
    printf("\nEnter loan\t\t\t: ");
    scanf("%f",&arrloan[0]);
    printf("\nEnter Down Payment\t\t: ");
    scanf("%f",&arrdown[0]);
    printf("\nHow many years do you plan to pay: ");
    scanf("%d",&period[0]);
    arrRloan[0]=remaining(arrloan[0],arrdown[0]);
    if(cr=='A')
    {
        jenis=1;
        arrannual[0]=annual_interest(jenis);
    }
    else
    {
        jenis=2;
        arrannual[0]=annual_interest(jenis);
    }
    arrmonthlyinterest[0]=month_interest(arrannual[0],rate_deduction);
    arrmonthly[0]=((arrloan[0]-arrdown[0])+(((arrmonthlyinterest[0]/12)*(arrloan[0]-arrdown[0]))*period[0]*12))/(period[0]*12);
    }
else if(type=='B')
    {
    printf("\nType of House\t\t\tAnnual interest rate");
    printf("\n-----------------------------------------------------------------------------------");
    printf("\nA  Lower cost house                           5.7");
    printf("\nB  Medium cost house                          6.3");
    printf("\nC  High cost house                            6.9");

    printf("\nEnter Type of House(A/B/C)\t:");
    fflush(stdin);
    scanf("%c",&house);
    printf("\nEnter loan\t\t\t:");
    scanf("%f",&arrloan[1]);
    printf("\nEnter Down Payment\t\t:");
    scanf("%f",&arrdown[1]);
    printf("\nHow many years do you plan to pay:");
    scanf("%d",&period[1]);

    if(house=='A')
    {
     jenis=3;
     arrannual[1]=annual_interest(jenis);
    }
    else if(house=='B')
    {
     jenis=4;
     arrannual[1]=annual_interest(jenis);
    }
    else
    {
     jenis=5;
     arrannual[1]=annual_interest(jenis);
    }
    arrRloan[1]=remaining(arrloan[1],arrdown[1]);
    arrmonthlyinterest[1]=month_interest(arrannual[1],rate_deduction);
    arrmonthly[1]=((arrloan[1]-arrdown[1])+(((arrmonthlyinterest[1]/12)*(arrloan[1]-arrdown[1]))*period[1]*12))/(period[1]*12);
    }
else
    {
    printf("\nNet profit\t\t\tAnnual interest rate");
    printf("\n-------------------------------------------------------------------------");
    printf("\n<10,000                                        6.4");
    printf("\n>=10,000                                       7.2");

    printf("\nEnter Net profit for business\t:");
    fflush(stdin);
    scanf("%f",&net);
    printf("\nEnter loan\t\t:");
    scanf("%f",&arrloan[2]);
    printf("\nEnter Down Payment\t:");
    scanf("%f",&arrdown[2]);
    printf("\nHow many years do you plan to pay:");
    scanf("%d",&period[2]);

        if (net<10000)
        {
            jenis=6;
            arrannual[2]=annual_interest(jenis);
        }
        else
        {
            jenis=7;
            arrannual[2]=annual_interest(jenis);
        }
        arrRloan[2]=remaining(arrloan[2],arrdown[2]);
        arrmonthlyinterest[2]=month_interest(arrannual[2],rate_deduction);
        arrmonthly[2]=((arrloan[2]-arrdown[2])+(((arrmonthlyinterest[2]/12)*(arrloan[2]-arrdown[2]))*period[2]*12))/(period[2]*12);

    }

    printf("\nWould you like to continue another loan?(A=yes/B=no):");
    fflush(stdin);
    scanf("%c",&loop);
    if(loop=='A')
    {
    goto floop;
    }
    else
    {
    printf("\n%s",pointer1);
    printf("\n--------------------------------------------------------------------------");
    printf("\n%s%s",pointer2,nme);
    printf("\n%s%s",pointer3,ic);
    printf("\n%s%s",pointer4,age);
    printf("\n%s%s",pointer5,address);
    printf("\n%s%s",pointer6,postcode);
    printf("\nCity                    :%s",city);
    printf("\nState                   :%s",state);
    printf("\nProfession              :%s",profession);
    printf("\nNumber of family members:%s",family);
    printf("\nTotal monthly income    :%.2f",incme);
    printf("\nYou are catogarized as:%s",category);
    printf("\n\n\n                       LOAN");
    printf("\n----------------------------------------------------------------------------\n");
    printf("\t\t\tCar Loan\tHouse Loan\tBusiness Loan\n");
    printf("Loan                  :");
    fprintf(data,"\nInformation of car loan");
    fprintf(data,"\n%c %.2f %.2f %d",cr,arrloan[0],arrdown[0],period[0]);
    fprintf(data,"\nInformation of house loan");
    fprintf(data,"\n%c %.2f %.2f %d",house,arrloan[1],arrdown[1],period[1]);
    fprintf(data,"\nInformation of business loan");
    fprintf(data,"\n%.2f %.2f %.2f %d",net,arrloan[2],arrdown[2],period[2]);
    fclose(data);
    for(i=0;i<3;i++)
    {
        fflush(stdout);
        printf("|%.2f\t",arrloan[i]);
    }
    printf("\nRemaining loan        :");
    for(i=0;i<3;i++)
    {
        fflush(stdout);
        printf("|%.2f\t",arrRloan[i]);
    }
    printf("\nDown Payment          :");
    for(i=0;i<3;i++)
    {
        fflush(stdout);
        printf("|%.2f\t",arrdown[i]);
    }
    printf("\nAnnual interest rate  :");
    for(i=0;i<3;i++)
    {
        fflush(stdout);
        printf("|%.2f\t",arrannual[i]);
    }
    printf("\nMonthly interest rate :");
    for(i=0;i<3;i++)
    {
        fflush(stdout);
        printf("|%.2f\t",arrmonthlyinterest[i]);
    }
    printf("\nMonthly Payment       :");
    for(i=0;i<3;i++)
    {
        fflush(stdout);
        printf("|%.2f\t",arrmonthly[i]);
    }
  }
  view();
}
float month_interest(float annual,float rateD){
  float monthly_interest=(annual-rateD)/12;
  return monthly_interest;
}
void display(){
  printf("\nA            Car loan");
  printf("\nB            House loan");
  printf("\nC            Business loan");
}
float annual_interest(int i)
{
  float interest;
  if(i==1){
   interest=5.1;}
  else if(i==2){
   interest=6.4;}
  else if(i==3){
   interest=5.7;}
  else if(i==4){
   interest=6.3;}
  else if(i==5){
   interest=6.9;}
  else if(i==6){
   interest=6.4;}
  else{
   interest=7.2;}
  return interest;
}
float remaining(float a,float b)
{
  float back;
  back=a-b;
  return back;
}
void view()
{

    FILE * data;
    data = fopen ("information.txt","r");
    while(1)
    {
        char c = fgetc(data);
        if(c==EOF)
            break;
        else
            printf("%c", c);
    }
    fclose(data);

}
