/*
    Author: Saathvikk Muthyala,
    Date Created: 05-01-2024,
    //last Modified: 07-01-2024 (),
    No of times Modified: 1; 
    

********************************************************************************
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"
#include "writeIntoFile.h"
#include "readFromFile.h"
#include "editFiles.h"

int main()
{
    int select = 1;
    printf( "Press:\n" 
        "1. if you are admin\n"
        "2. if you are customer\n" 
        "any other number to exit\n" );

    int adminOrCustomer;
    scanf( "%d", &adminOrCustomer );
    while ( select == 1 )
    {
        if ( adminOrCustomer == 1 )
        {
            printf( "Press:\n"
            "0. to view all products\n"
            "1. to add a product\n"
            "2. to remove a product\n"
            "3. to modify a product\n"
            "4. to see report according to id\n"
            "any other number to exit\n" );
            
            int choice;
            scanf( "%d", &choice );
            if ( choice == 0 )
            {
                readFromItems();
            }
            else if ( choice == 1 )
            {
                struct item item;
                printf( "Enter name of product: " );
                getchar();
                fgets( item.name, 40, stdin );
                printf( "Enter description of product: " );
                // getchar();
                fgets( item.description, 40, stdin );
                printf( "Enter price of product: " );
                scanf( "%f", &item.price );
                printf( "Enter quantity of product: " );
                scanf( "%d", &item.quantity );
                srand( time( NULL ) );//using this statement because every time 
                //i compiled and run,  it gives same set of values
                item.id = rand() % 1000;
                writeIntoProducts( &item );
            }
            else if ( choice == 2)
            {
                printf( "Enter id to remove: " );
                int id;
                scanf( "%d", &id );
                removeFromProducts( id );
            }
            else if ( choice == 3 )
            {
                struct item item;
                printf( "Enter id to edit: " );
                scanf( "%d", &item.id );
                printf( "Enter name of product: ");
                getchar();
                fgets( item.name, 40, stdin );
                printf( "Enter description of product: " );
                fgets( item.description, 40, stdin );
                printf("Enter price of product: ");
                scanf( "%f", &item.price );
                printf( "Enter quantity of product: " );
                scanf( "%d", &item.quantity );
                editFromProducts( &item );
            }
            else if ( choice == 4)
            {
                printf( "Enter id to see report: " );
                int id;
                scanf( "%d", &id );
                readFromOrdersId( id, 1 );
            }
            else{
                exit(0);
            }
        }
        else if ( adminOrCustomer == 2 )
        {
            printf( "Press:\n"
            "0. to view all products\n"
            "1. to add a product to cart\n"
            "2. to view cart\n"
            "3. to remove a product from cart\n"
            "4. to modify a product in cart\n"
            "5. to place your order\n"
            "6. to view all orders\n"
            "7. to view orders with id\n"
            "any other number to exit\n" );

            int choice;
            scanf( "%d", &choice );
            if ( choice == 0 )
            {
                readFromItems();
            }
            else if ( choice == 1 )
            {
                printf( "Enter id to add to cart: ");
                int id;
                scanf( "%d", &id );
                printf( "Enter quantity to add to cart: ");
                int quantity;
                scanf( "%d", &quantity );
                addToCart( id, quantity );
            }
            else if ( choice == 2 )
            {
                readFromCart();
            }
            else if ( choice == 3 )
            {
                printf( "Enter id to remove from cart: " );
                int id;
                scanf( "%d", &id );
                removeFromCart( id );
            }
            else if ( choice == 4 )
            {
                printf( "Enter id to edit: " );
                int id;
                scanf( "%d", &id );
                printf( "Enter quantity to edit: " );
                int quantity;
                scanf( "%d", &quantity );
                modifyFromCart( id, quantity );
            }
            else if ( choice == 5 )
            {
                reduceFromProducts();
                writeIntoOrders();
            }
            else if ( choice == 6 )
            {
                readFromOrders();
            }
            else if ( choice == 7 )
            {
                printf( "Enter id to see report: " );
                int id;
                scanf( "%d", &id );
                readFromOrdersId( id, 2 );
            }
            else
            {
                exit(0);
            }
        }
        else
        {
            exit(0);
        }
    }
    return 0;
}