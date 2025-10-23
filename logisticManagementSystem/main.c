#include <stdio.h>
#include <stdlib.h>

//Functions
void printMenu();

int main()
{
    int choice;
    do{
        printMenu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:break;
            case 2:break;
            case 3:break;
            case 4:break;
            case 5:break;
            case 6:break;
            case 7:break;
            case 8:break;
            case 9:break;
            case 10:
                printf("\n    Thank You!\n");break;
            default:
                printf("\n    Invalid Input\n\n");
        }
    }while(choice!=10);
    return 0;
}
void printMenu()
{
    printf("=====Logistics Management System=====\n\n");
    printf("1.City Management\n");
    printf("2.Distance Management\n");
    printf("3.Vehicle Management\n");
    printf("4.Delivery Management\n");
    printf("5.Cost,Time and Fuel Calculations\n");
    printf("6.Delivery Records\n");
    printf("7.Find the least-cost route\n");
    printf("8.Performance Reports\n");
    printf("9.File Handling\n");
    printf("10.Exit\n\n");
    printf("======================================\n\n");
    printf("Enter your choice : ");
}
