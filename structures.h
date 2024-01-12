/*
    Author: Saathvikk Muthyala,
    Date Created: 05-01-2024,
    //last Modified: 05-01-2024 (),
    No of times Modified: 0; 
    
*/
//********************************************************************************
/*
    This header file consists structures to be used in other files.
    These structures store details aobut product, cart and orders.
    
*/

struct item
{
    char name[40];
    char description[40];
    float price;
    int quantity;
    int id;
};

struct cartOrder
{
    int id;
    char name[40];
    char description[40];
    int quantity;
    float price;
    float totalPrice;
};
