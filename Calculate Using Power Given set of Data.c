#include <stdio.h>
#include <math.h>

int main()
{
    float milkproduction[5],c,sellvalue,total=0;
    int weight[5],i;

    printf("\nWeight Information (in kilogram):\n");

    for (i=0;i<5;i++)
    {
      printf(" Enter Weight %d:",i+1);
      scanf("%d",&weight[i]);

        if(weight[i]<600)
        {
            c=0.2;
        }
        else
        {
            c=0.5;
        }
      milkproduction[i]=(1.15*pow(weight[i],0.54)+0.25)*c;
      total=total+milkproduction[i];
      sellvalue = total*4.5;
    }

    printf("\nTotal milk produce in Liter = %.2f Liter",total);
    printf("\nSell value of milk = RM%.2f",sellvalue);
}

//Example of calculate using power with input set of weights