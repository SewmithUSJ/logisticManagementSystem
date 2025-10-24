#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CITIES 30
#define MAX_NAME_SIZE 10

//Functions
void printMenu();
int cityManagement(int cityId[],int cityCount,char cityNames[][MAX_NAME_SIZE]);
int addCity(int cityId[],int cityCount,char cityNames[][MAX_NAME_SIZE]);
void printCity(int cityId[],int cityCount,char cityNames[][MAX_NAME_SIZE]);
void renameCity(int cityCount,char cityNames[][MAX_NAME_SIZE]);
void removeCity(int cityId[],int cityCount,char cityNames[][MAX_NAME_SIZE]);
void nameStucture(char name[]);
void distanceManagement(int cityCount,int cityId[],int distance[][MAX_CITIES],char cityName[][MAX_NAME_SIZE]);
void addCityDistance(int cityCount,int distance[][MAX_CITIES]);
void printCityDistance(int cityCount,int cityId[],int distance[][MAX_CITIES],char cityName[][MAX_NAME_SIZE]);

int main()
{
    int choice,cityId[MAX_CITIES]={},cityCount=0,distance[MAX_CITIES][MAX_CITIES]={};
    char cityNames[MAX_CITIES][MAX_NAME_SIZE]={};

    do{
        printMenu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                cityCount=cityManagement(cityId,cityCount,cityNames);break;
            case 2:
                distanceManagement(cityCount,cityId,distance,cityNames);break;
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

int cityManagement(int cityId[],int cityCount,char cityNames[][MAX_NAME_SIZE])
{
    int choice;
    do{
        printf("===City Management===\n");
        printf("1.Add City\n");
        printf("2.Print City List\n");
        printf("3.Rename City\n");
        printf("4.Remove City\n");
        printf("5.Exit\n");
        printf("=====================\n\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                cityCount=addCity(cityId,cityCount,cityNames);break;
            case 2:
                printCity(cityId,cityCount,cityNames);break;
            case 3:
                renameCity(cityCount,cityNames);break;
            case 4:
                removeCity(cityId,cityCount,cityNames);break;
            case 5:
                printf("\n    Thank You!\n");break;
            default:
                printf("\n    Invalid Input\n\n");
        }
    }while(choice!=5);
    return cityCount;
}
int addCity(int cityId[],int cityCount,char cityNames[][MAX_NAME_SIZE])
{
    printf("\nEnter City name : ");
    scanf("%s",cityNames[cityCount]);
    nameStucture(cityNames[cityCount]);
    cityId[cityCount]=cityCount+1;
    cityCount+=1;
    return cityCount;
}
void printCity(int cityId[],int cityCount,char cityNames[][MAX_NAME_SIZE])
{
    printf("\n=====City list=====\n\n");
    printf("Id City names\n");
    for(int i=0;i<cityCount;i++)
    {
        printf("0%d %s\n",cityId[i],cityNames[i]);
    }
}
void renameCity(int cityCount,char cityNames[][MAX_NAME_SIZE])
{
    int id;
    printf("Enter Rename city id : ");
    scanf("%d",&id);
    if(id>=cityCount)
    {
        printf("Invalid input!\n");
    }else{
        printf("\nEnter City new name : ");
        scanf("%s",cityNames[id-1]);
        nameStucture(cityNames[id-1]);
    }
    printf("Rename city successfully!\n");
}
void removeCity(int cityId[],int cityCount,char cityNames[][MAX_NAME_SIZE])
{
    int id;
    printf("Enter Remove city id : ");
    scanf("%d",&id);
    if(id>=cityCount)
    {
        printf("Invalid input!\n");
    }else{
        for(int i=id;i<cityCount;i++)
        {
            for(int j=0;cityNames[i][j]!='\0';j++)
            {
                cityNames[i][j]=cityNames[i+1][j];
            }
        }
    }
    printf("Remove city successfully!\n");
}
void nameStucture(char name[])
{
    name[0]=toupper(name[0]);
    for(int i=1;name[i]!='\0';i++)
    {
        name[i]=tolower(name[i]);
    }
}
void distanceManagement(int cityCount,int cityId[],int distance[][MAX_CITIES],char cityName[][MAX_NAME_SIZE])
{
    int choice;
    do{
        printf("=====Distance Management=====\n\n");
        printf("1.Add city distance\n");
        printf("2.Edit city distance\n");
        printf("3.Print city distance\n");
        printf("4.Exit\n");
        printf("=============================\n\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                addCityDistance(cityCount,distance);break;
            case 2:
                addCityDistance(cityCount,distance);break;
            case 3:
                printCityDistance(cityCount,cityId,distance,cityName);break;
            case 4:
                printf("\n    Thank You!\n");break;
            default:
                printf("\n    Invalid Input\n\n");
        }
    }while(choice!=4);
}
void addCityDistance(int cityCount,int distance[][MAX_CITIES])
{
    int city1,city2;
    printf("Enter first city id : ");
    scanf("%d",&city1);
    if(city1>=cityCount)
    {
        printf("\n    Invalid Input\n\n");
        return ;
    }
    printf("Enter second city id : ");
    scanf("%d",&city2);
    if(city2>=cityCount)
    {
        printf("\n    Invalid Input\n\n");
        return ;
    }
    printf("Enter the distance between the two cities : ");
    scanf("%d",&distance[city1-1][city2-1]);
    distance[city2-1][city1-1]=distance[city1-1][city2-1];
    printf("The distance enter successfully!\n\n");
}
void printCityDistance(int cityCount,int cityId[],int distance[][MAX_CITIES],char cityName[][MAX_NAME_SIZE])
{
    if(cityCount<9)
    {
        printf("\n=====All City Distance=====\n\n");
    }else{
        printf("\n");
        for(int i=(cityCount*4-13)/2;i!=0;i--)
        {
            printf("=");
        }
        printf("All City Distance");
        for(int i=(cityCount*4-13)/2;i!=0;i--)
        {
            printf("=");
        }
        printf("\n\n");
    }
    printf("   ");
    for (int i=0;i<cityCount;i++)
    {
        printf("%3d ",i+1);
    }
    printf("\n");
    for(int i=0;i<cityCount;i++)
    {
        printf("%3d ",i+1);
        for(int j=0;j<cityCount;j++)
        {
            if(distance[i][j] != 0)
            {
                printf("%3d ",distance[i][j]);
            }else{
                printf("N/A ");
            }
        }
        printf("\n");
    }
    printCity(cityId,cityCount,cityName);
}
