#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct House
{
    char name[100];
    char address[100];
    float totalBill;
    float discountBill;
    struct unit
    {
        float currentElectric;
        float previousElectric;
        float currentWater;
        float previousWater;
    }unit;
    struct unitBill
    {
        float electricBill;
        float waterBill;
    }bill;

};

struct House getInfo();
struct House calculateBill();
float calculateTotalBillsAfterDiscount();
void display(struct House house);

int main()
{
    struct House house[3];
    for(int i=0;i<3;i++)
    {
        house[i]=getInfo();
        house[i]=calculateBill(house[i]);
        house[i].totalBill=calculateTotalBillsAfterDiscount(house[i]);
    }
        display(house);
    return 0;
}

struct House getInfo()
{
    struct House house;
    printf("\nEnter House Owner Name:");
    scanf("%s",&house.name);
    printf("\nEnter House Address:");
    scanf("%s",&house.address);
    printf("\nEnter Current Unit for Electric:");
    scanf("%.2f",&house.unit.currentElectric);
    printf("\nEnter Previous Unit for Electric:");
    scanf("%.2f",&house.unit.previousElectric);
    printf("\nEnter Current Unit for Water:");
    scanf("%.2f",&house.unit.currentWater);
    printf("\nEnter Previous Unit for Water:");
    scanf("%.2f",&house.unit.previousWater);
    return house;
}

struct House calculateBill(struct House bill)
{
    float electric, water;

    electric=house.unit.currentElectric-house.unit.previousElectric;
    if(electric<100)
    {
      house.bill.electricBill=electric*0.1;
    }
    else if (electric<200)
    {
      house.bill.electricBill=electric*0.2;
    }
    else
    {
       house.bill.electricBill=electric*0.4;
    }

    water=house.unit.currentWater-house.unit.previousWater;
    if(water<100)
    {
      house.bill.waterBill=water*0.1;
    }
    else if (electric<200)
    {
      house.bill.waterBill=water*0.2;
    }
    else
    {
       house.bill.waterBill=water*0.4;
    }

    bill.totalBill=house.bill.waterBill+house.bill.electricBill;
    return bill;
};

struct House calculateTotalBillsAfterDiscount(struct House calculateBill)
{
  int electricDisc, waterDisc;

  electricDisc=house.bill.electricBill;
  if(electricDisc<100)
  {
    house.bill.electricBill=electricDisc*0.2;
  }
  else
  {
    house.bill.electricBill=electricDisc*0.1;
  }

  waterDisc=house.bill.waterBill
  if(waterDisc<10)
  {
    house.bill.waterBill=waterDisc*0.2;
  }
  else
  {
    house.bill.waterBill=waterDisc*0.1;
  }

  house.discountBill=house.bill.electricBill+house.bill.waterBill;
  return discount;
};

void display(struct House house)
{
    for(int i=0;i<3;i++)
    {
    printf("\n \t \t HOUSE BILL REPORT");
    printf("\nHouse Owner Name           :%s",house[i].name);
    printf("\nHouse Address              :%s",house[i].address);
    printf("\nElectric Bill              :%.2f",house[i].bill.electricBill);
    printf("\nWater Bill                 :%.2f",house[i].bill.waterBill);
    printf("\nTotal Bills                :%.2f",house[i].totalBill);
    printf("\nTotal Bills after discount :%.2f",house[i].discountBill);
    }
}
