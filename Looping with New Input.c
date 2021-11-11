#include <stdio.h>
#include <strings.h>

float LongestJump(float,float,float,float,float);
float AverageJump(float,float,float,float,float);
void DisplayResult(char[],char[],char[],float,float,float,float,float,float,float);

int main()
{
    char name[15],participantNum[4],participantTeam[10];
    float jumpAttempt[5]={0,0,0,0,0},longestAttempt,averageAttempt, jumping,average;
    int i;

    printf("Participant Name:");
    scanf("%s",&name);

    printf("Participant No:");
    scanf("%s",&participantNum);

    printf("Participant Team:");
    scanf("%s",&participantTeam);

    printf("\nJumping Information (in meter):\n");
    for (i=0;i<5;i++)
  {
      printf(" Attempt %d:",i+1);
      scanf("%f",&jumpAttempt[i]);
  }
  longestAttempt=LongestJump(jumpAttempt[0],jumpAttempt[1],jumpAttempt[2],jumpAttempt[3],jumpAttempt[4]);
  averageAttempt=AverageJump(jumpAttempt[0],jumpAttempt[1],jumpAttempt[2],jumpAttempt[3],jumpAttempt[4]);
  DisplayResult(name,participantNum,participantTeam,jumpAttempt[0],jumpAttempt[1],jumpAttempt[2],jumpAttempt[3],jumpAttempt[4],longestAttempt,averageAttempt);
  return 0;
}
float LongestJump(float Jump1,float Jump2,float Jump3,float Jump4,float Jump5)
{
  float Jump[5]={Jump1,Jump2,Jump3,Jump4,Jump5};
  for (int i =0; i<5; ++i) {
    if (Jump[0]<Jump[i])
    {
      Jump[0] = Jump[i];
    }
  }
  return Jump[0];
}
float AverageJump(float Jumping1,float Jumping2,float Jumping3,float Jumping4,float Jumping5)
{
    float average;
    average=(Jumping1+Jumping2+Jumping3+Jumping4+Jumping5)/5;
    return average;
}
void DisplayResult(char name[15], char participantNum[4], char participantTeam[10], float J1, float J2, float J3, float J4, float J5, float highestJump, float averageJump)
{
    printf("\n----------Result Information----------");
    printf("\n\n Participant Information");
    fflush(stdout);
    printf("\nName: %s",name);
    fflush(stdout);
    printf("\nNo. : %s", participantNum);
    fflush(stdout);
    printf("\nTeam: %s",participantTeam);
    float jump[5]={J1,J2,J3,J4,J5};
    for(int i =0; i<5; ++i)
    {
        printf("\nAttempt %d:%.2f meter",i+1,jump[i]);
    }
    printf("\n\nHighest Jump:%.2f meter",highestJump);
    printf("\nAverage Jump:%.2f meter",averageJump);
}
