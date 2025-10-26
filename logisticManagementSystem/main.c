#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_CITIES 30
#define MAX_NAME_SIZE 10
#define MAX_RECODES 50

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
void vehicaleManagement();
int deliveryManagement(int cityCount,char cityName[][MAX_NAME_SIZE],int distance[][MAX_CITIES],int vehicaleDetails[][4],int deliveryCount,float deliveryRecodes[][13]);
void calculation(int deliveryNumber,float deliveryRecodes[][13],int vehicaleDetails[][4]);
void printBill(char cityNames[][MAX_NAME_SIZE],float deliverRecodes[][13],int deliveryNumber,int vehicaleDetails[][4]);

int main()
{
    int choice,cityId[MAX_CITIES]={},cityCount=0,distance[MAX_CITIES][MAX_CITIES]={};
    int vehicaleDetails[3][4]={{1000,30,60,12},{5000,40,50,6},{10000,80,45,4}};
    int deliveryCount=0;
    float deliveryRecodes[MAX_RECODES][13]={};
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
            case 3:
                vehicaleManagement();break;
            case 4:
                deliveryCount=deliveryManagement(cityCount,cityNames,distance,vehicaleDetails,deliveryCount,deliveryRecodes);break;
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
    printf("4.Delivery Oder\n");
    printf("5.Delivery Records\n");
    printf("6.Performance Reports\n");
    printf("7.File Handling\n");
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
void vehicaleManagement()
{
    printf("+-----+------------+----------------+---------------+---------------------+\n");
    printf("|Type |Capacity(kg)|Rate Per km(LKR)|Avg Speed(km/h)|Fuel Efficiency(km/l)|\n");
    printf("+-----+------------+----------------+---------------+---------------------+\n");
    printf("|Van  |1000        |30              |60             |12                   |\n");
    printf("+-----+------------+----------------+---------------+---------------------+\n");
    printf("|Truck|5000        |40              |50             |6                    |\n");
    printf("+-----+------------+----------------+---------------+---------------------+\n");
    printf("|Lorry|10000       |80              |45             |4                    |\n");
    printf("+-----+------------+----------------+---------------+---------------------+\n");
}
int deliveryManagement(int cityCount,char cityName[][MAX_NAME_SIZE],int distance[][MAX_CITIES],int vehicaleDetails[][4],int deliveryCount,float deliveryRecodes[][13])
{
    int sourceCity,destinationCity,weight,vehicalType;
    printf("Enter Source city id : ");
    scanf("%d",&sourceCity);
    if(sourceCity>=cityCount)
    {
        printf("\n    Invalid Input\n\n");
        return deliveryCount;
    }
    printf("Enter Destination city id : ");
    scanf("%d",&destinationCity);
    if(destinationCity>=cityCount)
    {
        printf("\n    Invalid Input\n\n");
        return deliveryCount;
    }
    if(sourceCity==destinationCity)
    {
        printf("Locations is same.we can't continue this oder!\n\n");
        return deliveryCount;
    }
    if(distance[sourceCity-1][destinationCity-1]==0)
    {
        printf("You didn't enter cities distance.Please enter distance first.\n\n");
        return deliveryCount;
    }
    printf("Enter the weight being transported (in Kg): ");
    scanf("%d",&weight);
    printf("\n==vehicle types==\n");
    printf("1.Van\n2.Truck\n3.Lorry\n\n");
    do{
        printf("Enter vehicle type : ");
        scanf("%d",&vehicalType);
        if(vehicalType!=1||vehicalType!=2||vehicalType!=3)
        {
            printf("\n    Invalid Input\n\n");
        }
    }while(vehicalType!=1||vehicalType!=2||vehicalType!=3);
    if(weight>vehicaleDetails[vehicalType-1][0])
    {
        printf("The entered weight cannot be transported by the given type of transport.we can't continue this oder!\n\n");
    }
    if(deliveryCount>=50)
    {
        for(int i=0;i<MAX_RECODES-1;i++)
        {
            for(int j=0;j<12;j++)
            {
                deliveryRecodes[i][j]=deliveryRecodes[i+1][j];
            }
        }
            deliveryRecodes[49][0]=sourceCity;
            deliveryRecodes[49][1]=destinationCity;
            deliveryRecodes[49][2]=weight;
            deliveryRecodes[49][3]=vehicalType-1;
            deliveryRecodes[49][4]=distance[sourceCity-1][destinationCity-1];
            calculation(49,deliveryRecodes,vehicaleDetails);
            printBill(cityName,deliveryRecodes,49,vehicaleDetails);
    }else{
        deliveryRecodes[deliveryCount][0]=sourceCity;
        deliveryRecodes[deliveryCount][1]=destinationCity;
        deliveryRecodes[deliveryCount][2]=weight;
        deliveryRecodes[deliveryCount][3]=vehicalType-1;
        deliveryRecodes[deliveryCount][4]=distance[sourceCity-1][destinationCity-1];
        calculation(deliveryCount,deliveryRecodes,vehicaleDetails);
        printBill(cityName,deliveryRecodes,deliveryCount,vehicaleDetails);
    }
    deliveryCount+=1;
    return deliveryCount;
}
void calculation(int deliveryNumber,float deliveryRecodes[][13],int vehicaleDetails[][4])
{
    //Calc cost
    deliveryRecodes[deliveryNumber][5]=deliveryRecodes[deliveryNumber][4]*vehicaleDetails[(int)deliveryRecodes[deliveryNumber][3]][1]*(1+deliveryRecodes[deliveryNumber][2]/10000);
    //Calc astimate time
    deliveryRecodes[deliveryNumber][6]=deliveryRecodes[deliveryNumber][4]/vehicaleDetails[(int)deliveryRecodes[deliveryNumber][3]][2];
    //calc fuel consumption
    deliveryRecodes[deliveryNumber][7]=deliveryRecodes[deliveryNumber][4]/vehicaleDetails[(int)deliveryRecodes[deliveryNumber][3]][3];
    //fuel cost
    deliveryRecodes[deliveryNumber][8]=deliveryRecodes[deliveryNumber][7]*310;
    //total operation cost
    deliveryRecodes[deliveryNumber][9]=deliveryRecodes[deliveryNumber][8]+deliveryRecodes[deliveryNumber][5];
    //calc profit
    deliveryRecodes[deliveryNumber][10]=deliveryRecodes[deliveryNumber][9]*0.25;
    //Final charge
    deliveryRecodes[deliveryNumber][11]=deliveryRecodes[deliveryNumber][10]+deliveryRecodes[deliveryNumber][9];
}
void printBill(char cityNames[][MAX_NAME_SIZE],float deliverRecodes[][13],int deliveryNumber,int vehicaleDetails[][4])
{
    char vehicalType[3][6]={{"Van"},{"Truck"},{"Lorry"}};
    printf("\n=============================================================\n\n");
    printf("DELIVERY COST ESTIMATION\n\n");
    printf("-------------------------------------------------------------\n\n");
    printf("From : %s\n",cityNames[(int)deliverRecodes[deliveryNumber][0]-1]);
    printf("To : %s\n",cityNames[(int)deliverRecodes[deliveryNumber][1]-1]);
    printf("Minimum Distance : %.0f km\n",deliverRecodes[deliveryNumber][4]);
    printf("Vehicle : %s\n",vehicalType[(int)deliverRecodes[deliveryNumber][3]]);
    printf("Weight : %.0f kg\n\n",deliverRecodes[deliveryNumber][2]);
    printf("-------------------------------------------------------------\n\n");
    printf("Base Cost : %.0f * %d * ( 1 + %.0f/10000) = %.2f LKR\n",deliverRecodes[deliveryNumber][4],vehicaleDetails[(int)deliverRecodes[deliveryNumber][3]][1],deliverRecodes[deliveryNumber][2],deliverRecodes[deliveryNumber][5]);
    printf("Fuel Used : %.2f L\n",deliverRecodes[deliveryNumber][7]);
    printf("Fuel Cost : %.2f LKR\n",deliverRecodes[deliveryNumber][8]);
    printf("Operational Cost : %.2f LKR\n",deliverRecodes[deliveryNumber][9]);
    printf("Profit : %.2f LKR\n",deliverRecodes[deliveryNumber][10]);
    printf("Customer Charge : %.2f LKR\n",deliverRecodes[deliveryNumber][11]);
    printf("Estimated Time : %.2f hours\n",deliverRecodes[deliveryNumber][6]);
    printf("\n=============================================================\n\n");
}
void printDeliveryRecodes(float deliverRecodes[][13],int deliveryCount,char cityNames[][MAX_NAME_SIZE])
{
    int count=0;
    char vehicalType[3][6]={{"Van"},{"Truck"},{"Lorry"}};
    char status[]={};
    if(deliveryCount>50)
    {
        count=50;
    }else{
        count=deliveryCount;
    }
    printf("%-10s %-12s %-17s %-11s %-13s %-10s %-16s %-10s","Oder Num","Source city","Destination city","Weight(kg)","Vehicle Type","Distance","Bill Total(LKR)","Status");
    for(int i=0;i<count;i++)
    {
        if(deliverRecodes[i][12]==0)
        {
            strcpy(status, "Pending");
        }else{
            strcpy(status, "Delivered");
        }
        printf("%-10d %-12s %-17s %-11.2f %-13s %-10.2f %-16.2f %-10s",i+1,cityNames[(int)deliverRecodes[i][0]],cityNames[(int)deliverRecodes[i][1]],deliverRecodes[i][2],vehicalType[(int)deliverRecodes[i][3]],deliverRecodes[i][4],deliverRecodes[i][11],status);
    }
}
