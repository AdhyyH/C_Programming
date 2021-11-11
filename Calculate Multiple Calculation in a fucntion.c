#include <stdio.h>
#include <string.h>

int main (void)
{
    char cashbackcoin[1], shop[1], items[1],cashbackcoinfull[10],shopfull[10], itemsfull[20], purchase[1];
    int unit, floop[1];
    float totalPrice, price, coinInRM, coinEarn, finalPrice, discount, cashback, finalPriceBD;

    loop:
    printf("Via Cash Back Channel [Y: Yes, N:No]?    :");
    scanf("%c", &cashback);

    fflush(stdin);
    printf("\n Enter shop [S: Shop Pi, F:Fashion Balik]:");
    scanf("%c", &shop);

    printf("\n \n----------Items----------");
    printf("\n \n A: Sakura Dining Set");
    printf("\n \n B: Organic Cotton Bedding Set");
    printf("\n \n C: Smart TV");
    printf("\n \n -------------------------");

    fflush(stdin);
    printf("\n \n Enter code of item to be purchased      :");
    scanf("%c", &items);

    fflush(stdin);
    printf("\n \n Enter shop unit of purchased item       :");
    scanf("%d", &unit);


    if ( items == 'A')
    {
        strcpy (itemsfull, "Sakura Dining Set");
        price = 1500.00;
    }
    else if ( items == 'B')
    {
        strcpy (itemsfull, "Organic Cotton Bedding Set");
        price = 550.00;
    }
    else
    {
        strcpy (itemsfull, "Smart TV");
        price = 1999.00;
    }


    if ((items == 'B' && unit >=4))
    {
        discount = 0.15 * totalPrice;
    }
    else
    {
        discount = 0;
    }


    if ((cashbackcoin == 'Y' && cashbackcoin == 'y') && (shop == 'S' && shop == 's'))
    {
        fflush(stdin);
        strcpy (cashbackcoinfull, "Cash Back Channel");
        strcpy (shopfull, "Shop Pi");
        if (totalPrice <=1000)
        {
            coinEarn = 2 * totalPrice;
            cashback = 1.50;
        }
        else if (totalPrice <=1500)
        {
            coinEarn = 4 * totalPrice;
            cashback = 2.50;
        }
        else if (totalPrice <= 2000)
        {
            coinEarn = 6 * totalPrice;
            cashback = 3.50;
        }
        else
        {
            coinEarn = 8 * totalPrice;
            cashback = 4.50;
        }

        fflush(stdin);
        printf("Use %.2f your coin for a RM%.2f discount and RM%.2f cashback for this purchasing? [Y: Yes, N: No]", coinEarn, discount, cashback);
            if ((purchase == 'Y' || purchase == 'y'))
        {
            totalPrice = price * unit;
            coinInRM = coinEarn/1000;
            finalPrice = totalPrice - discount - cashback - coinInRM;
            finalPriceBD = finalPrice/3.07;

            printf("\n Shopping channel and shop : %s/ %s", cashbackcoinfull,shopfull );
            printf("\n Purchased item            : %s", itemsfull);
            printf("\n Number of unit            : %d", unit);
            printf("\n Total Price (RM)          : %.2f", totalPrice);
            printf("\n Go Green Discount (RM)    : %.2f", discount);
            printf("\n Final Price (RM)          : %.2f", finalPrice);
            printf("\n Final Price (BD)          : %.2f", finalPriceBD);
        }
    }
    else if ((cashbackcoin == 'Y' && cashbackcoin == 'y') && (shop == 'F' && shop == 'f'))
    {
        fflush(stdin);
        strcpy (cashbackcoinfull, "Cash Back Channel");
        strcpy (shopfull, "Fashion Balik");

        if (totalPrice <=1000)
        {
            coinEarn = 1.5 * totalPrice;
            cashback = 2.00;
        }
        else if (totalPrice <=1500)
        {
            coinEarn = 3.5 * totalPrice;
            cashback = 3.00;
        }
        else if (totalPrice <= 2000)
        {
            coinEarn = 5.5 * totalPrice;
            cashback = 4.00;
        }
        else
        {
            coinEarn = 7.5 * totalPrice;
            cashback = 5.00;
        }

        fflush(stdin);
        printf("Use %.2f your coin for a RM%.2f discount and RM%.2f cashback for this purchasing? [Y: Yes, N: No]", coinEarn, discount, cashback);
            if ((purchase == 'Y' || purchase == 'y'))
        {
            totalPrice = price * unit;
            coinInRM = coinEarn/1000;
            finalPrice = totalPrice - discount - cashback - coinInRM;
            finalPriceBD = finalPrice/3.07;

            printf("\n Shopping channel and shop :  %s/ %s", cashbackcoinfull,shopfull );
            printf("\n Purchased item            :  %s",  itemsfull);
            printf("\n Number of unit            : %d", unit);
            printf("\n Total Price (RM)          : %.2f", totalPrice);
            printf("\n Go Green Discount (RM)    : %.2f", discount);
            printf("\n Final Price (RM)          : %.2f", finalPrice);
            printf("\n Final Price (BD)          : %.2f", finalPriceBD);
        }
    }
    else if ((cashbackcoin == 'N' && cashbackcoin == 'n') && (shop == 'S' && shop == 's'))
    {
        fflush(stdin);
        strcpy (cashbackcoinfull, "Not Cash Back Channel");
        strcpy (shopfull, "Shop Pi");

        if (totalPrice <=1000)
        {
            coinEarn = 0 * totalPrice;
            cashback = 0;
        }
        else if (totalPrice <=1500)
        {
            coinEarn = 0 * totalPrice;
            cashback = 0;
        }
        else if (totalPrice <= 2000)
        {
            coinEarn = 0 * totalPrice;
            cashback = 0;
        }
        else
        {
            coinEarn = 0 * totalPrice;
            cashback = 0;
        }

        fflush(stdin);
        printf ("Not applicable for collecting coins and cashback");
        totalPrice = price * unit;
        coinInRM = coinEarn/1000;
        finalPrice = totalPrice - discount - cashback - coinInRM;
        finalPriceBD = finalPrice/3.07;

        printf("\n Shopping channel and shop : %s / %s", cashbackcoinfull, shopfull );
        printf("\n Purchased item            : %s", itemsfull);
        printf("\n Number of unit            : %d", unit);
        printf("\n Total Price (RM)          : %.2f", totalPrice);
        printf("\n Go Green Discount (RM)    : %.2f", discount);
        printf("\n Final Price (RM)          : %.2f", finalPrice);
        printf("\n Final Price (BD)          : %.2f", finalPriceBD);
    }
    else ((cashbackcoin == 'N' && cashbackcoin == 'n') && (shop == 'F' && shop == 'f'));
    {
       strcpy (cashbackcoinfull, " Not Cash Back Channel");
        strcpy (shopfull, "Fashion Balik");

        if (totalPrice <=1000)
        {
            coinEarn = 0 * totalPrice;
            cashback = 0;
        }
        else if (totalPrice <=1500)
        {
            coinEarn = 0 * totalPrice;
            cashback = 0;
        }
        else if (totalPrice <= 2000)
        {
            coinEarn = 0 * totalPrice;
            cashback = 0;
        }
        else
        {
            coinEarn = 0 * totalPrice;
            cashback = 0;
        }
        fflush(stdin);
        printf ("Not applicable for collecting coins and cashback");
        totalPrice = price * unit;
        coinInRM = coinEarn/1000;
        finalPrice = totalPrice - discount - cashback - coinInRM;
        finalPriceBD = finalPrice/3.07;

        printf("\n Shopping channel and shop : %s/ %s", cashbackcoinfull, shopfull );
        printf("\n Purchased item            : %s", itemsfull);
        printf("\n Number of unit            : %d", unit);
        printf("\n Total Price (RM)          : %.2f", totalPrice);
        printf("\n Go Green Discount (RM)    : %.2f", discount);
        printf("\n Final Price (RM)          : %.2f", finalPrice);
        printf("\n Final Price (BD)          : %.2f", finalPriceBD);
    }


    printf("\n \n Continue for next user? 1:[YES], 2:[EXIT] :");
    scanf("%d", &floop);
    if(floop==1)
        goto loop;

    return 0;
}
