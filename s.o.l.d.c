#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer.h"
#include "product.h"
#include "purchase.h"

int main()
{

//----------- Required variables will be defined this part -----------------------//
	double sum=0; double ptotal=0; double pcost=0;
    int ID;
    double max[50]; int count[50];
    double quantify=0;
    double price;
    int new_invoice_ID;
    double new_quantify;int i;
	int new_purchase_id;
    double temp_amount=0;
    double temp;
    double temp_quantify=0; double temp_quantify1; double temp_quantify2;
    int temp_ID;
    int temp_ID1;
    int temp_ID2;
    int Type;
    double totalship;    double temp_total;
    char c;
    int product_ID;
    double x_temp; double y_temp;
    double cost; 
    double temp_cost;double temp_cost1;double temp_cost2;
    char *name; char *user_input;  char temp_name[50];  
    ProductElement *ProductsList = NULL;
    Customer *CustomersList = NULL;
    Purchase *PurchasesList = NULL;
    double temporary_cost;Purchase *N;
    Purchase *purchase;
    Product *product;
    Customer *customer;
    int choice;int y;
    int customer_ID;
//--------------------------------------Ended-----------------------------------------------//


//------------------------Test data will be imported here -----------------------------------------------//
ID = 1;
price = 5.99;
Type = 1;
name = (char *)malloc(sizeof(char) * 20);
strcpy(name, "Portakal Sikma");
addProductToList(&ProductsList, insertProduct(ID, name, price, Type));
ID = 2;
price = 12.95;
Type = 1;
name = (char *)malloc(sizeof(char) * 20);
strcpy(name, "Muz Yerli");
addProductToList(&ProductsList, insertProduct(ID, name, price, Type));
ID = 3;
price = 7.45;
Type = 2;
name = (char *)malloc(sizeof(char) * 20);
strcpy(name, "Sogan");
addProductToList(&ProductsList, insertProduct(ID, name, price, Type));
ID = 4;
price = 3.95;
Type = 2;
name = (char *)malloc(sizeof(char) * 20);
strcpy(name, "Pirasa");
addProductToList(&ProductsList, insertProduct(ID, name, price, Type));
ID = 5;
price = 5.95;
Type = 2;
name = (char *)malloc(sizeof(char) * 20);
strcpy(name, "Lahana");
addProductToList(&ProductsList, insertProduct(ID, name, price, Type));
ID = 6;
price = 7.45;
Type = 1;
name = (char *)malloc(sizeof(char) * 20);
strcpy(name, "Limon");
addProductToList(&ProductsList, insertProduct(ID, name, price, Type));
ID = 7;
price = 15;
Type = 3;
name = (char *)malloc(sizeof(char) * 20);
strcpy(name, "Hamsi");
addProductToList(&ProductsList, insertProduct(ID, name, price, Type));
// -----

ID = 1;
name = (char *)malloc(sizeof(char) * 20);
strcpy(name, "Ali Karaman");
int type=1;double x_coord=16.8;double y_coord=10;
addCustomerToList(&CustomersList, insertCustomer(ID, name,type,x_coord,y_coord));
ID = 2;
name = (char *)malloc(sizeof(char) * 20);
strcpy(name, "Zehra Cilek");
type=0;x_coord=12.4;y_coord=6.9;
addCustomerToList(&CustomersList, insertCustomer(ID, name,type,x_coord,y_coord));
ID = 3;
name = (char *)malloc(sizeof(char) * 20);
strcpy(name, "Mehmet Derin");
type=0;x_coord=10.55;y_coord=15.4;
addCustomerToList(&CustomersList, insertCustomer(ID, name,type,x_coord,y_coord));
ID = 4;
name = (char *)malloc(sizeof(char) * 20);
strcpy(name, "Veli Ortanca");
type=1;x_coord=5.1;y_coord=1.2;
addCustomerToList(&CustomersList, insertCustomer(ID, name,type,x_coord,y_coord));
ID = 5;
name = (char *)malloc(sizeof(char) * 20);
strcpy(name, "Menekse Serin");
type=1;x_coord=2;y_coord=7.9;
addCustomerToList(&CustomersList, insertCustomer(ID, name,type,x_coord,y_coord));

///////////////////////
ID = 1;
int invoice_ID=1; customer_ID=5; product_ID=7;cost=123.50;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
ID = 2;
invoice_ID=1; customer_ID=5; product_ID=2;cost=12.40;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
ID = 3;
invoice_ID=1; customer_ID=5; product_ID=3;cost=23.45;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
ID = 4;
invoice_ID=1; customer_ID=5; product_ID=4;cost=56.75;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
ID = 5;
invoice_ID=2; customer_ID=1; product_ID=1;cost=45.50;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
ID = 6;
invoice_ID=2; customer_ID=1; product_ID=2;cost=30.60;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
ID = 7;
invoice_ID=2; customer_ID=1; product_ID=5;cost=25.50;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
ID = 8;
invoice_ID=2; customer_ID=1; product_ID=5;cost=30;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
ID = 9;
invoice_ID=2; customer_ID=1; product_ID=3;cost=23.78;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
ID = 10;
invoice_ID=3; customer_ID=3; product_ID=5;cost=34.50;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
ID = 11;
invoice_ID=3; customer_ID=3; product_ID=1;cost=567;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
ID = 12;
invoice_ID=3; customer_ID=3; product_ID=2;cost=45;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
ID = 13;
invoice_ID=3; customer_ID=3; product_ID=7;cost=32;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
ID = 14;
invoice_ID=3; customer_ID=3; product_ID=6;cost=40.95;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
ID = 15;
invoice_ID=3; customer_ID=3; product_ID=2;cost=34.50;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
ID = 16;
invoice_ID=4; customer_ID=5; product_ID=6;cost=71.20;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
ID = 17;
invoice_ID=4; customer_ID=5; product_ID=3;cost=63.30;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
ID = 18;
invoice_ID=5; customer_ID=4; product_ID=2;cost=17.30;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
ID = 19;
invoice_ID=5; customer_ID=4; product_ID=7;cost=29.40;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
ID = 20;
invoice_ID=5; customer_ID=4; product_ID=3;cost=20.05;
addPurchaseToList(&PurchasesList, createPurchase(ID,invoice_ID,customer_ID,product_ID,cost));
//--------------------------------------Ended-----------------------------------------------//

printf("Welcome to S.O.L.D \n");
//--------------------------------------Menu Creation Process-----------------------------------------------//
    while (1)
    {   RMA:
        printf("Menu  : \n");
        printf("1-> Customer Information \n");
        printf("2-> Product Information \n");
        printf("3-> Sales Menu \n");
        printf("4-> Product Analyze \n");
        printf("5>  Customer Analyze \n");
        printf("6> Exit \n");
        printf("Choose : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // Customer Menu
ABD:
    printf("Customers Menu : \n");
    printf("1-> print customer \n");
    printf("2-> print customers list \n");
    printf("3-> print customers list via type \n");
    printf("4-> add customer \n");
    printf("5-> delete customer \n");
    printf("6-> Back to main menu \n");
    printf(" Choose : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter the ID of customer you want to print: ");
        scanf("%d", &ID);
        customer = getCustomer(CustomersList, ID);
        if (!customer)
        {
            printf("This customer ID does not exist.\n");
        }
        else
        {
            printf("----------------->    Printing customer info     <----------------\n");
            displayCustomer(customer);
            printf("-------------------------------------------------------------------\n");
        }
        goto ABD;
    case 2:
        diplayCustomersList(CustomersList);
        goto ABD;
    case 3:
    	printf("Enter the Type of customer you want to print:\n");
    	printf("for Corporate Customer -> Enter 1 \n");
        printf("for Individual Customer - > Enter 0 \n");
    	int type;
    	scanf("%d", &type);
        displayviaType(CustomersList,type);
        printf("-------------------------------------------------------------------------\n");
        goto ABD;
    case 4:
         ID=LastCustomerID(CustomersList)+1;
         printf("Assigned ID for Customer is: %d \n",ID);
         printf("Enter name of Customer : \n");
         name = (char *)malloc(sizeof(char) * 50);
         scanf(" %100[^\n]", temp_name);
         strcpy(name,temp_name);
         printf("Enter type of Customer: \n");
         printf("Enter 1 Corporate, 0 for Invidual... \n");
         scanf("%d",&type);
         printf("Enter X Coordinate of Customer : \n");
         scanf("%lf",&x_temp);
         printf("Enter Y Coordinate of Customer : \n");
         scanf("%lf",&y_temp);
          printf("%s",temp_name);
         addCustomerToList(&CustomersList, insertCustomer(ID,name,type,x_temp,y_temp));
    	goto ABD;
    case 5:
    	 printf("Enter ID of customer you want to delete: \n");
    	 printf("Warning! Sales records of customer will be deleted too.\n");
    	 scanf("%d",&ID);
    	 customer = getCustomer(CustomersList,ID);
    	 if(customer!=NULL){
    	 
    	 deleteCustomerElement(&CustomersList,customer);
    	 while(CustomerSaleCount(PurchasesList,ID)>=1){
		 if(CustomerSaleCount(PurchasesList,ID)>=1){
    	 	temp_ID1=GetPurchaseID(PurchasesList,ID);
    	 	purchase=getPurchase(PurchasesList,temp_ID1);
	       deletePurchaseElement(&PurchasesList, purchase);
    	 }}}
    	 else{ printf("Customer doesn't exist.\n");
    	 }
    	 
    	goto ABD;
    case 6:
        goto RMA;
    }
        case 2:
ABC:      // Product Menu
    printf("Products Menu : \n");
    printf("1-> Find and print product \n");
    printf("2-> Print all products\n");
    printf("3-> Print products according to the type\n");
    printf("4-> Add New Product\n");
    printf("5-> Delete Product\n");
    printf("6-> Back to main menu \n");
    printf(" Choose : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter the ID of Product you want to print: ");
        scanf("%d", &ID);
        product = getProduct(ProductsList, ID);
        if (!product)
        {
            printf("This Product does not exist.\n");
        }
        else
        {
            printf("------------------>      Printing Product info       <----------------------\n");
            displayProduct(product);
            printf("----------------------------------------------------------------------------\n");
        }
        goto ABC;
    case 2:
        diplayProductsList(ProductsList);
        goto ABC;
    case 3:
    	printf("Enter the Type of Product you want to print:\n");
    	printf("Enter 1 for fruit, 2 for vegetable, 3 for meat... \n");
    	scanf("%d", &Type);
        displayproductviaType(ProductsList,Type);
        printf("----------------------------------------------------------------------------\n");
        goto ABC;
    case 4: 
    ID=LastProductID(ProductsList)+1;
    printf("Assigned ID for product is: %d \n",ID);
    printf("Enter name of product : \n");
    name = (char *)malloc(sizeof(char) * 50);
    scanf(" %100[^\n]", temp_name);
    strcpy(name,temp_name); 
    printf("Enter price of product : \n");
    scanf("%lf",&price);
    printf("Enter type of product: \n");
    printf("Enter 1 for fruit, 2 for vegetable, 3 for meat... \n");
	scanf("%d",&Type);
    addProductToList(&ProductsList, insertProduct(ID, name, price, Type));
	goto ABC;  
	case 5:  
	    printf("Enter ID of product you want to delete: \n");
	    printf("Warning! Sales records of product will be deleted too.\n");
	    scanf("%d",&ID);
	    product = getProduct(ProductsList, ID);
	    if(product !=NULL){
	    
	    deleteProductElement(&ProductsList, product);
    	 while(ProductSaleCount(PurchasesList,ID)>=1){
		 if(ProductSaleCount(PurchasesList,ID)>=1){
    	 	temp_ID1=GetPurchaseIDforProduct(PurchasesList,ID);
    	 	purchase=getPurchase(PurchasesList,temp_ID1);
	       deletePurchaseElement(&PurchasesList, purchase);
    	 }}} else{  printf("This Product does not exist.\n");
    	 }
	   goto ABC;
    case 6:
      goto RMA;
    }
        case 3:   // Sale Menu
         RMD:
        	    printf("1 -> Start new sale\n");
        	    printf("2 -> Print all recent sales\n");
        	    printf("3 -> Delete a sale record\n");
                printf("4 -> Back to main menu\n");
             	scanf("%d",&choice);
                switch(choice){
              	case 1:
              		
              printf("Last Invoice ID: %d\n",LastInvoiceID(PurchasesList));
              printf("Invoice ID for current sale: %d\n",LastInvoiceID(PurchasesList)+1);
              printf("Do you know  ID of customer?\n");
              printf("Press Y if you know or N for list all customers.\n");
              scanf("%s",&c);
              if(c == 'Y' || c =='y'){ 
			       goto TRB;         }
              else{ diplayCustomersList(CustomersList); goto TRB;}
              TRB:
              printf("Enter Customer ID: \n");
              scanf("%d",&customer_ID);
              customer = getCustomer(CustomersList,customer_ID);
    	      if(customer!=NULL){customer_ID=customer_ID;}
    	      else{printf("Enter a valid customer ID: \n");scanf("%d",&customer_ID);}
              new_invoice_ID=LastInvoiceID(PurchasesList)+1;
              RME:
              new_purchase_id=LastPurchaseID(PurchasesList)+1;
              printf("Do you know the ID of the product you are selling?\n");
              printf("Press Y if you know or N for list all products.\n");
              scanf("%s",&c);
              if(c == 'Y' || c =='y'){ 
			       goto TRT;         }
              else{diplayProductsList(ProductsList); goto TRT;}
              TRT:
              printf("Enter Product ID: \n");
              scanf("%d",&product_ID);
              product = getProduct(ProductsList, product_ID);
              if(product !=NULL){  product_ID=product_ID; }
              else{printf("Enter a valid Product ID: \n"); scanf("%d",&product_ID);}
              printf("Enter Quantify: \n");
              scanf("%lf",&new_quantify);
              cost=new_quantify*(ProductPrice(ProductsList,product_ID));
              addPurchaseToList(&PurchasesList, createPurchase(new_purchase_id,new_invoice_ID,customer_ID,product_ID,cost));
              printf("Selected product added Invoice.\n");
              printf("Do you want to add more product (to same Invoice) ? (y/n)\n");
              scanf("%s",&c);
              if(c == 'Y' || c =='y'){ 
               goto RME;}
               else{
               	printf("-----------------------------------\n");
               printf("Your invoice total is: %.2f \n ",InvoiceTotal(PurchasesList,new_invoice_ID));
               printf("Shipping cost calculating.......\n");
			   printf("Your shipping cost is %.2f\n",CalculateShipping(CustomersList,customer_ID)); 
			   printf("Sum of invoice total and shipping cost is: %.2f \n",CalculateShipping(CustomersList,customer_ID)+InvoiceTotal(PurchasesList,new_invoice_ID));
			   printf("-----------------------------------\n");
			   goto RMD; }
			  case 2:
			  diplayPurchasesList(PurchasesList); 
			  goto RMD;
			  case 3:
			   printf("Enter Purchase ID of record you want to delete.\n");
	           scanf("%d",&ID);
	           purchase=getPurchase(PurchasesList,ID);
	           if(purchase!=NULL){
	           
	          deletePurchaseElement(&PurchasesList, purchase);}
	          else{ printf("Doesn't exist a record with that Purchase ID.'\n");
	          }
			  goto RMD;
              case 4: 
              goto RMA;}
        case 4:  // Product Analyze Menu
		        RMC:
        	    printf(" 1-> Print Total Amount of Product\n");
                printf(" 2-> Print Total Amount of Product Type\n");
                printf(" 3-> Print Total Amount of All Products\n");
                printf(" 4-> Back to Main Menu\n");
             	scanf("%d",&choice);
                switch(choice){
              	case 1:
              	printf("Enter Product ID: \n");
                scanf("%d",&product_ID);
                ptotal=ProductTotal(PurchasesList,product_ID);
                if(ptotal!=0){
                
                printf("Total Amount of Product is: %.2f \n",ptotal);
                product = getProduct(ProductsList, product_ID); 
                pcost=product->price;
                printf("Total purchased quantify is: %.2f \n",ptotal/pcost);}
                else{ printf("Product dont exist or not sold\n");
                }
                goto RMC;
                case 2:
                cost=0;
                printf("Enter Product Type: \n");
                scanf("%d",&Type);
                for(ID=1;ID<=LastPurchaseID(PurchasesList);ID++){
                purchase = getPurchase(PurchasesList, ID);
                if(purchase!=NULL){
                product_ID=purchase->product_ID;
                product = getProduct(ProductsList, product_ID);
                if(product->Type==Type){
                temporary_cost=purchase->cost;
                cost=cost+temporary_cost;
                  }}else {
                  }
                 }
               if(cost==0){ printf("Product type dont exist or not sold\n");}
                else{
                
				printf("Total Amount of Product Type is: %.2f\n",cost);}
                goto RMC; 
                case 3:
                printf("List of total purchased amount and quantify of products: \n");
                printf("-----------------------------------------------------------------------\n");
                for(ID=1;ID<=LastProductID(ProductsList);ID++){
                ptotal=ProductTotal(PurchasesList,ID);
                 if(ptotal!=0){
                product = getProduct(ProductsList, ID); 
                pcost=product->price;
                quantify=ptotal/pcost;
				if(quantify>temp_quantify){
				temp_quantify=quantify;temp_ID=ID;}
                printf("P. ID:%d | P.Name:%s | Total P. Amount:%.2f | Total P. Quantity:%.2f\n",ID,product->name,ptotal,quantify);}
                else{     }
                
                } 
                product = getProduct(ProductsList, temp_ID); 
                if(product!=NULL){
                
                printf("-----------------------------------------------------------------------\n");
                printf("-----------------------------------------------------------------------\n");
                printf("Most preferred product and total amount sum of all products: \n");
                printf("Most sold product (in quantify) is: %s with quantify: %.2f\n",product->name,temp_quantify);
                printf("Sum of Total amount of all Products is %.2f\n",PurchaseTotal(PurchasesList));
                printf("-------------------------------------------------------------------------\n");}
                goto RMC; 
                case 4:
                goto RMA;
              }   
        case 5:  // Customer Analyze Menu
		        RMB:
        	    printf(" 1-> Products purchased by a customer\n");
                printf(" 2-> Total amount of purchase by a customer\n");
                printf(" 3-> Total amount of products\n");
                printf(" 4-> Total shipping cost of all customers\n");
                printf(" 5-> Back to Main Menu\n");
             	scanf("%d",&choice);
                switch(choice){
                case 1: 
                printf("Enter Customer ID: \n"); int y=0;
                scanf("%d",&customer_ID);
                CustomerIN(PurchasesList,customer_ID);
               printf("Customer bought that products: \n");quantify=0;temp_quantify=0;temp_quantify1=0;
                for(ID=1;ID<=LastPurchaseID(PurchasesList);ID++){
                purchase = getPurchase(PurchasesList, ID);
                if(purchase!=NULL){
                product_ID=purchase->product_ID;
                product = getProduct(ProductsList, product_ID);
                if(product!=NULL){
                if(purchase->customer_ID==customer_ID){
                if(product_ID!=temp_ID){
                temp_ID=product_ID; y=y+1;
                ptotal=GetCost(PurchasesList,customer_ID,temp_ID);
                pcost=product->price;temp_quantify1=quantify;
                quantify=ptotal/pcost;
                max[y]=quantify;
                displayProductSpecial(product); 
                printf("P. Quantify: %.2f\n",quantify);
				}}}}}
				for(ID=1;ID<=LastProductID(ProductsList);ID++){
				ptotal=GetCost(PurchasesList,customer_ID,ID);
				product_ID=ID;
                product = getProduct(ProductsList, product_ID);
                if(product!=NULL){
                pcost=product->price;
                quantify=ptotal/pcost;
				if(quantify==largest(max, y+1))  {
				    temp_ID1=ID;  } 
				if(quantify==smallest(max, y+1))  {
				    temp_ID2=ID;  } 
				   } }
				  
				  if(largest(max, y+1)!=0){
				  
                product = getProduct(ProductsList, temp_ID1); 
                if (product!=NULL){
                printf( "Most preferred product (in quantify) is: %s with quantify: %.2f\n",product->name,largest(max, y+1));
                product = getProduct(ProductsList, temp_ID2); 
                 if (product!=NULL){
                printf( "Less preferred product (in quantify) is: %s with quantify: %.2f\n",product->name,smallest(max, y+1));}}}
                max[0]=0;
                goto RMB; 
        case 2:
        	printf("Enter Customer ID: \n");
            scanf("%d",&customer_ID);
        	printf("Total amount of purchased by a customer: %.2f\n",CustomerTotal(PurchasesList,customer_ID));
        	if(CustomerTotal(PurchasesList,customer_ID)!=0){
        	
			temp_ID1=0;temp_ID2=0;temp_cost=0;temp_cost1=0;temp_cost2=0;cost=0;
        	for(ID=1;ID<=LastInvoiceID(PurchasesList);ID++){
        	temp_cost1=cost;	
			cost=InvoiceTotal(PurchasesList,ID);
			temp_ID=GetCustomerID(PurchasesList,ID);
			if(temp_ID==customer_ID){
			if(cost>temp_cost){
			temp_cost=cost; temp_ID1=ID;}
			if(cost<temp_cost1){
			temp_cost2=cost; temp_ID2=ID;}
			}} 
			if(temp_cost2!=0 && temp_cost!=temp_cost2){
			printf ("Maximum invoice amount of Customer: Invoice ID: %d Amount: %.2f\n",temp_ID1,temp_cost);
			printf ("Minimum invoice amount of Customer: Invoice ID: %d Amount: %.2f\n",temp_ID2,temp_cost2);}}
			else{ printf("Customer don't exist or not purchased any product.\n");
			}
        	goto RMB; 
        case 3:
        	printf("Sum of Total amount of all Products is %.2f\n",PurchaseTotal(PurchasesList));
        	for(ID=1;ID<=LastInvoiceID(PurchasesList);ID++){
			cost=InvoiceTotal(PurchasesList,ID);
				if(cost>temp_cost){
			temp_cost=cost; temp_ID1=ID;}
			if(cost<temp_cost){
			temp_cost1=cost; temp_ID2=ID;}}
        	printf ("Maximum invoice amount is: Invoice ID: %d Amount: %.2f\n",temp_ID1,temp_cost);
			printf ("Minimum invoice amount is: Invoice ID: %d Amount: %.2f\n",temp_ID2,temp_cost1);
			printf("Detailed list of total purchased amount of all customers: \n");
			for(ID=1;ID<=LastCustomerID(CustomersList);ID++){
				if(CustomerTotal(PurchasesList,ID)!=0){
				
			printf("Customer ID: %d| Total Amount: %.2f\n",ID,CustomerTotal(PurchasesList,ID));}}
			goto RMB; 
		case 4:
			    totalship=0;
			    printf("List of all customer's total shipping fee: \n");
			    for(ID=1;ID<=LastCustomerID(CustomersList);ID++){
			    temp=CalculateShipping(CustomersList,ID)*CustomerSaleCount(PurchasesList,ID);
		     	if(temp!=0)
				printf("Customer ID: %d | Total Shipping Cost: %.2f\n",ID,temp);}
				for(ID=1;ID<=LastInvoiceID(PurchasesList);ID++){
				temp_ID=GetCustomerID(PurchasesList,ID);
				temp_total=CalculateShipping(CustomersList,temp_ID);
				totalship=totalship+temp_total;	}
				printf("Total shipping fee of customers is %.2f: \n",totalship);
				goto RMB; 
		case 5:
			goto RMA; }
		case 6:
        return 0;
        }
    }
    return 0;
}

//--------------------------------------Ended----------------------------------------------//


