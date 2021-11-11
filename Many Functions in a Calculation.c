#include <stdio.h>

float MasukHarga();
float KiraHarga(float,float);
void Diskaun(float);
void Jumlah(float);

int main()
{
    int loop=1,billtype,typecomp;
    float price,total=0,discount,JumlahHarga;

    while (loop==1)
    {
        printf("Enter Bill Type (1: Utilities, 2: Internet): ");
        scanf("%d",&billtype);
        if(billtype==1)
        {
           printf("Enter 1: TNB or 2: SYABAS: ");
           scanf("%d",&typecomp);
           if(typecomp==1)
            {
                discount=0.05;
            }
            else
            {
                discount=0.10;
            }
        }
        else
        {
            printf("Enter 1: DIGI, 2: UNIFI or 3: MAXIS FIBRE: ");
            scanf ("%d",&typecomp);
            discount=0.05;
        }

        price=MasukHarga();
        JumlahHarga=KiraHarga(price,discount);
        total=total+JumlahHarga;
        Diskaun(JumlahHarga);

        printf("\n\nContinue? 1=yes, 0=no:");
        scanf("%d",&loop);
    }
    Jumlah(total);

    return 0;
}

float MasukHarga()
{
    float price;
    printf ("Enter amount to pay: ");
    scanf ("%f",&price);

    return price;
}


float KiraHarga(float price,float discount)
{
    float JumlahHarga;
    JumlahHarga=price-(price*discount);

    return JumlahHarga;
}

void Diskaun(float JumlahHarga)
{
    printf("Total after discount = RM%.2f",JumlahHarga);
}

void Jumlah(float total)
{
    printf("Total paid : RM%.2f",total);
    printf("\nThank you for using TickNGo");
}

//Example of functions with different function, function calculate, function of printing and callback value function
