#ifndef PURCHASE_H_ 
#define PURCHASE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------------------- Purchase structure data and relative functions will be defined here -------------------------------------

typedef struct Purchase
{
    int ID;
    int invoice_ID;
    int customer_ID;
    int product_ID;
    double cost;
    struct Purchase *purchase;
    struct Purchase *next;
} Purchase;

typedef struct PurchaseElement
{
    Purchase *purchase;
    struct PurchaseElement *next;
} PurchaseElement;

Purchase *createPurchase( int ID, int invoice_ID, int customer_ID, int product_ID,double cost)
{
    Purchase *purchase;
    purchase = (Purchase *)malloc(sizeof(Purchase));
    purchase->ID = ID;
    purchase->invoice_ID = invoice_ID;
    purchase->customer_ID = customer_ID;
    purchase->product_ID = product_ID;
    purchase->cost = cost;
    return purchase;
}

Purchase *createElementforPurchase(Purchase *purchase)
{
    Purchase *new;
    new = (Purchase *)malloc(sizeof(Purchase));
    new->next = NULL;
    new->purchase = purchase;
    return new;
}
Purchase *getPurchase(Purchase *PurchasesList, int ID)
{
    if (PurchasesList == NULL)
        return NULL;
    if (PurchasesList->purchase->ID == ID)
        return PurchasesList->purchase;
    return getPurchase(PurchasesList->next, ID);
}

void addPurchaseToList(Purchase **PurchasesList, Purchase *purchase)
{

    Purchase *new;
    new = createElementforPurchase(purchase);
    if (*PurchasesList == NULL)
    {

        *PurchasesList = new;
        return;
    }
    Purchase *t = *PurchasesList;
    while (t->next != NULL)
        t = t->next;
    t->next = new;
}
void displayPurchase(Purchase *purchase)
{
    if (!purchase)
        return;
    printf("ID: %d  | Invoice ID: %d  | Customer ID: %d  | Product ID: %d  | Cost: %.2f\n",purchase->ID,purchase->invoice_ID,purchase->customer_ID,purchase->product_ID,purchase->cost);
}

void diplayPurchasesList(Purchase *N)
{
    printf("\n---------------------> Printing Purchases List  <------------------------\n");
    for (; N; N = N->next)
    {
        displayPurchase(N->purchase);
        printf("-------------------\n");
    }
    printf("----------------------->      printing ends     <--------------------------\n");
}

void display(Purchase *N,int ID)
{
    printf("\n-----------------------------> Printing Purchases List  <---------------------\n");
    for (; N; N = N->next)
    {
    	if(N->purchase->ID==ID)
        displayPurchase(N->purchase);
        printf("-----------------------------------------------------------------------------\n");
    }
    printf("----------------------------->      printing ends     <--------------------------\n");
}

void CustomerIN(Purchase *N,int customer_ID) // that function listing customer purchases
{
    printf("\n-----------------> Printing Purchases List of Customer <-------------------\n");
    for (; N; N = N->next)
    {   if(N!=NULL){
    
    	if(N->purchase->customer_ID==customer_ID)
        displayPurchase(N->purchase);}
      else {
      }
    }
    printf("------------------------->      printing ends     <--------------------------\n");
}

 void deletePurchaseElement(Purchase **purchaselist, Purchase *purchase)
{
    if (*purchaselist == NULL)
        return;
    Purchase *t = *purchaselist, *tmp;
    if (t->purchase == purchase)
    {
        *purchaselist = t->next;
        free(t->purchase);
        free(t);
        return;
    }
    while (t->next && t->next->purchase != purchase)
        t = t->next;
    if (t->next)
    {
        tmp = t->next;
        t->next = tmp->next;
        free(tmp->purchase);
        free(tmp);
    }
}


double GetCost(Purchase *N,int customer_ID,int product_ID)
{   double cost=0;
    for (; N; N = N->next)
    
    {   if(N->purchase->customer_ID==customer_ID)
    	if(N->purchase->product_ID==product_ID)
		cost=cost+N->purchase->cost;
    }
    return cost;
}


int GetCustomerID(Purchase *N,int invoice_ID)
{   int customer_ID;
    for (; N; N = N->next)
    
    {   if(N->purchase->invoice_ID==invoice_ID){
		customer_ID=N->purchase->customer_ID;   }
    }
    return customer_ID;
}

int GetPurchaseID(Purchase *N,int customer_ID)
{    int invoice_ID;int ID;
    for (; N; N = N->next)
    
    {   if(N->purchase->customer_ID==customer_ID){
		ID=N->purchase->ID;   }
    }
    return ID;
}

int GetPurchaseIDforProduct(Purchase *N,int product_ID)
{    int ID;
    for (; N; N = N->next)
    
    {   if(N->purchase->product_ID==product_ID){
		ID=N->purchase->ID;   }
    }
    return ID;
}





double ProductTotal(Purchase *N,int product_ID)
{    double sum=0;
    for (; N; N = N->next)
    {    if(N!=NULL){
    
	     Purchase *purchase;
     	if(N->purchase->product_ID==product_ID)
     	
     	sum=sum+N->purchase->cost;}
    }
          return sum;// printf("%.2f\n",sum);
}

double CustomerTotal(Purchase *N,int customer_ID)
{    double sum=0;
    for (; N; N = N->next)
    {if(N!=NULL)  {
    
	Purchase *purchase;
     	if(N->purchase->customer_ID==customer_ID)
     	
     	sum=sum+N->purchase->cost;}
    }
          return sum;// printf("%.2f\n",sum);
}



int CustomerSaleCount(Purchase *N,int customer_ID)
{    int sum=0; int temp_id=0;
    for (; N; N = N->next)
    {   Purchase *purchase;
     	if(N->purchase->customer_ID==customer_ID){
     	if(temp_id!=N->purchase->invoice_ID){
     	temp_id=N->purchase->invoice_ID;
     	sum=1+sum;}}
    }
          return sum;// printf("%.2f\n",sum);
}


int ProductSaleCount(Purchase *N,int product_ID)
{    int sum=0; int temp_id=0;
    for (; N; N = N->next)
    {   Purchase *purchase;
     	if(N->purchase->product_ID==product_ID){
     	sum=1+sum;}
    }
          return sum;// printf("%.2f\n",sum);
}

int LastInvoiceID(Purchase *N)
{    int ID=0;
    for (; N; N = N->next)
    {    if(N != NULL){
	     Purchase *purchase;
        ID=N->purchase->invoice_ID;}
        else{ID=0;
        }
    }
          return ID;// printf("%.2f\n",sum);
}

double InvoiceTotal(Purchase *N,int invoice_ID)
{    double sum=0;
    for (; N; N = N->next)
    {   Purchase *purchase;
    if(N->purchase->invoice_ID==invoice_ID)
     	sum=sum+N->purchase->cost;
    }
          return sum;// printf("%.2f\n",sum);
}


double PurchaseTotal(Purchase *N)
{    double sum=0;
    for (; N; N = N->next)
    {   Purchase *purchase;    	
     	sum=sum+N->purchase->cost;
    }
          return sum;// printf("%.2f\n",sum);
}

double largest(double arr[], int n)
{
    int i;
    double max = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

double smallest(double arr[], int n)
{
    int i;
    double min = arr[1];
   for (i = 1; i < n; i++) {
      if (arr[i] < min) {
         min = arr[i];
      }
   }
    return min;
}





int LastPurchaseID(Purchase *N)
{    int ID=0;
    for (; N; N = N->next)
    {   if(N != NULL){
	    Purchase *purchase;
        ID=N->purchase->ID;}
        else{ ID=0;
        }
    }
          return ID;// printf("%.2f\n",sum);
}
                
                
#endif
