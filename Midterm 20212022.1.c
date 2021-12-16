#include <stdio.h>

//Structure Declaration (Template)
struct House{

    char nameOwner[50];
    char address[50];
    float totalBillUndiscounted;
    float totalBill;

    struct Bill{

        struct Electric{
            int unitCurrent;
            int unitPrevious;
            int unitUsed;
            float totalBillOriginal;
            float totalBillDiscount;}electric;

        struct Water{
            int unitCurrent;
            int unitPrevious;
            int unitUsed;
            float totalBillOriginal;
            float totalBillDiscount;}water;

    }bill;
};

//Function Declaration (Prototype)
struct House getInfo();
struct House calculateBill(struct House house);
float calculateTotalBillsAfterDiscount(struct House house);
void display(struct House house[]);

int main(void){

    //Structure Variable
    struct House house[3];

    for(int i=0;i<3;i++)
    {
        house[i]=getInfo();
        house[i]=calculateBill(house[i]);
        house[i].totalBill=calculateTotalBillsAfterDiscount(house[i]);
    }

    display(house);

return 0;}

//Function Definition: getInfo
struct House getInfo(){

    struct House house;

        printf("\nEnter House Owner Name              : ");
        scanf(" %[^\n]s", &house.nameOwner);

        printf("Enter House Address                 : ");
        scanf(" %[^\n]s", &house.address);

        printf("Enter Current Unit for Electric     : ");
        scanf(" %d", &house.bill.electric.unitCurrent);

        printf("Enter Previous Unit for Electric    : ");
        scanf(" %d", &house.bill.electric.unitPrevious);

        printf("Enter Current Unit for Water        : ");
        scanf(" %d", &house.bill.water.unitCurrent);

        printf("Enter Previous Unit for Water       : ");
        scanf(" %d", &house.bill.water.unitPrevious);

    return house;}

//Function Definition: calculateBill
struct House calculateBill(struct House house){

    house.bill.electric.unitUsed=house.bill.electric.unitCurrent-house.bill.electric.unitPrevious;

    if(house.bill.electric.unitUsed<100){
        house.bill.electric.totalBillOriginal=house.bill.electric.unitUsed*0.10;}

    else if(house.bill.electric.unitUsed<200){
        house.bill.electric.totalBillOriginal=house.bill.electric.unitUsed*0.20;}

    else{
        house.bill.electric.totalBillOriginal=house.bill.electric.unitUsed*0.40;}

    house.bill.water.unitUsed=house.bill.water.unitCurrent-house.bill.water.unitPrevious;

    if(house.bill.water.unitUsed<20){
        house.bill.water.totalBillOriginal=house.bill.water.unitUsed*0.50;}

    else{
        house.bill.water.totalBillOriginal=house.bill.water.unitUsed*1;}

    house.totalBillUndiscounted+=house.bill.electric.totalBillOriginal+house.bill.water.totalBillOriginal;

    return house;}

//Function Definition: calculateTotalBillsAfterDiscount
float calculateTotalBillsAfterDiscount(struct House house){

    if(house.bill.electric.totalBillOriginal<100){
        house.bill.electric.totalBillDiscount=house.bill.electric.totalBillOriginal*0.8;}

    else{
        house.bill.electric.totalBillDiscount=house.bill.electric.totalBillOriginal*0.9;}

    if(house.bill.water.totalBillOriginal<10){
        house.bill.water.totalBillDiscount=house.bill.water.totalBillOriginal*0.8;}

    else{
        house.bill.water.totalBillDiscount=house.bill.water.totalBillOriginal*0.9;}

    house.totalBill=house.bill.electric.totalBillDiscount+house.bill.water.totalBillDiscount;

    return house.totalBill;}

//Function Definition: display
void display(struct House house[]){

    int loop;

    printf("\n\tHOUSE BILL REPORT");

    for(loop=0;loop<3;loop++){
        printf("\n\nHouse Owner Name              : %s", house[loop].nameOwner);
        printf("\nHouse Address                 : %s", house[loop].address);
        printf("\nElectric bill                 : RM%.2f", house[loop].bill.electric.totalBillOriginal);
        printf("\nWater bill                    : RM%.2f", house[loop].bill.water.totalBillOriginal);
        printf("\nTotal bills                   : RM%.2f", house[loop].totalBillUndiscounted);
        printf("\nTotal bills after discount    : RM%.2f", house[loop].totalBill);}

    printf("\n");}
