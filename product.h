#ifndef PRODUCT_H_ 
#define PRODUCT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//---------------------- Product structure data and relative functions will be defined here -------------------------------------

typedef struct product
{
    int ID;
    char *name;
    double price;
    int Type;
    struct Product *product;
    struct Product *next;
} Product;

typedef struct ProductElement
{
    Product *product;
    struct ProductElement *next;
} ProductElement;


Product *insertProduct(int ID, char *name, double price, int Type)
{
    Product *product;
    product = (Product *)malloc(sizeof(Product));

    product->ID = ID;
    product->name = name;
    product->price = price;
    product->Type = Type;

    return product;
}
ProductElement *insertProductElement(Product *Product)
{
    ProductElement *new;
    new = (ProductElement *)malloc(sizeof(ProductElement));
    new->next = NULL;
    new->product = Product;
    return new;
}
Product *getProduct(ProductElement *productsList, int ID)
{
    if (productsList == NULL)
        return NULL;
    if (productsList->product->ID == ID)
        return productsList->product;
    return getProduct(productsList->next, ID);
}


void addProductToList(ProductElement **productsList, Product *product)
{

    ProductElement *new;
    new = insertProductElement(product);
    if (*productsList == NULL)
    {

        *productsList = new;
        return;
    }
    ProductElement *t = *productsList;
    while (t->next != NULL)
        t = t->next;
    t->next = new;
}

void deleteProductElement(ProductElement **productsList, Product *product)
{
    if (*productsList == NULL)
        return;
    ProductElement *t = *productsList, *tmp;
    if (t->product == product)
    {
        *productsList = t->next;
        free(t->product);
        free(t);
        return;
    }
    while (t->next && t->next->product != product)
        t = t->next;
    if (t->next)
    {
        tmp = t->next;
        t->next = tmp->next;
        free(tmp->product);
        free(tmp);
    }
}

void displayProduct(Product *product)
{
    if (!product)
        return;
    printf("P. ID: %d | Name: %15s | Price: %.2lf | Type: %d \n",product->ID,product->name,product->price,product->Type);
}


void diplayProductsList(ProductElement *N)
{
    printf("\n--------------------> Printing products List <----------------------\n");
    for (; N; N = N->next)
    {
        displayProduct(N->product);
    }
    printf("--------------------->      printing ends     <-----------------------\n");
}

void displayproductviaType(ProductElement *N,int Type)
{   int check=0; int sum=0;
    printf("\n-----------------> Printing products List <-------------------------\n");
    for (; N; N = N->next)
    {
    	if(N->product->Type==Type){
    	check=1; sum=sum+check;
        displayProduct(N->product);}
        else { check=0; sum=sum+check;
		} 
    }
     if(sum==0){printf("There is no such product in entered type. \n");}
    printf("------------------>      printing ends     <----------------------------\n");
}


int LastProductID(ProductElement *N)
{    int ID=0;
    for (; N; N = N->next)
    {   if(N != NULL){
	    Product *product;
        ID=N->product->ID;}
         else{ID=0; }
         
    }
          return ID;
}

double ProductPrice(ProductElement *N,int ID)
{   double price;
    for (; N; N = N->next)
    {   Product *product;
        if(N->product->ID==ID)
        price=N->product->price;
    }
          return price;
}


void displayProductSpecial(Product *product)
{
    if (product!=NULL){
    printf("P. ID: %d | Name: %15s | Price: %.2lf | ",product->ID,product->name,product->price);}
    else {
    }
}


#endif
