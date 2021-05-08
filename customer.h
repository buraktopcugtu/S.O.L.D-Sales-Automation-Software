#ifndef CUSTOMER_H_ 
#define CUSTOMER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//---------------------- Customer structure data and relative functions will be defined here -------------------------------------
typedef struct Customer
{
    int ID;
    char *name;
    int type;
    double x_coord;
    double y_coord;
    struct Customer *customer;
    struct Customer *next;
} Customer;

Customer *insertCustomer(int ID, char *name,int type,double x_coord,double y_coord)
{
    Customer *customer;
    customer = (Customer *)malloc(sizeof(Customer));
    customer->ID = ID;
    customer->name = name;
    customer->type = type;
    customer->x_coord = x_coord;
    customer->y_coord = y_coord;
    return customer;
}

Customer *createElement(Customer *customer)
{
    Customer *new;
    new = (Customer *)malloc(sizeof(Customer));
    new->next = NULL;
    new->customer = customer;
    return new;
}
Customer *getCustomer(Customer *CustomersList, int ID)
{
    if (CustomersList == NULL)
        return NULL;
    if (CustomersList->customer->ID == ID)
        return CustomersList->customer;
    return getCustomer(CustomersList->next, ID);
}


void addCustomerToList(Customer **CustomersList, Customer *customer)
{

    Customer *new;
    new = createElement(customer);
    if (*CustomersList == NULL)
    {

        *CustomersList = new;
        return;
    }
    Customer *t = *CustomersList;
    while (t->next != NULL)
        t = t->next;
    t->next = new;
}
void displayCustomer(Customer *customer)
{
    if (!customer)
        return;
    printf("ID: %d  | Name: %s  | Type: %d  | X_Coord: %2.1f  | Y_Coord: %2.1f\n",customer->ID,customer->name,customer->type,customer->x_coord,customer->y_coord);
}

 void deleteCustomerElement(Customer **customerlist, Customer *customer)
{
    if (*customerlist == NULL)
        return;
    Customer *t = *customerlist, *tmp;
    if (t->customer == customer)
    {
        *customerlist = t->next;
        free(t->customer);
        free(t);
        return;
    }
    while (t->next && t->next->customer != customer)
        t = t->next;
    if (t->next)
    {
        tmp = t->next;
        t->next = tmp->next;
        free(tmp->customer);
        free(tmp);
    }
}


void diplayCustomersList(Customer *N)
{
    printf("\n-------------------> Printing Customers List  <----------------------\n");
    for (; N; N = N->next)
    {
        displayCustomer(N->customer);
        printf("-----------------------------------------------------------------\n");
    }
    printf("--------------------->      printing ends     <------------------------\n");
}

void displayviaType(Customer *N,int type)
{   int check=0; int sum=0;
    printf("\n--------------------------> Printing Customers List  <---------------------\n");
    for (; N; N = N->next)
    {
    	if(N->customer->type==type){
    	check=1; sum=sum+check;
        displayCustomer(N->customer);
        printf("------------------------------------------------------------------------\n");}

    }
    if(sum==0){printf("There is no such customer in entered type. \n");}
    printf("------------------------------>      printing ends     <--------------------\n");
}

int LastCustomerID(Customer *N)
{    int ID=0;
    for (; N; N = N->next)
    {   if(N != NULL){
    
	Customer *customer;
        ID=N->customer->ID;}
        else {  ID=0;
        }
    }
          return ID;// printf("%.2f\n",sum);
}

double CalculateShipping(Customer *N,int ID)
{  double x; double y;double z;double distance;double shipping;
    for (; N; N = N->next)
    {   
	   if(N->customer->ID==ID){
	    Customer *customer;
        x=N->customer->x_coord;
        y=N->customer->y_coord;
        z=pow(x,2)+pow(y,2);
        distance=pow(z,0.5);
        shipping=distance*0.5;
		}
    }
          return shipping;// printf("%.2f\n",sum);
}

#endif // 
