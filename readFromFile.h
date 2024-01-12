/*
    Author: Saathvikk Muthyala,
    Date Created: 05-01-2024,
    //last Modified: 12-01-2024 (),
    No of times Modified: 3; 
    
*/
//********************************************************************************
/*
    Read into file using this module.
    
*/

void readFromItems()
{
    struct item currentItem;
    FILE *file = fopen("item.txt", "rb");
    if ( file == NULL )
    {
        printf("Error with file");
    }
    while ( fread( &currentItem, sizeof(struct item), 1, file ) == 1 )
    {
        printf( "Name: %s\n", currentItem.name );
        printf( "Description: %s\n", currentItem.description );
        printf( "Price: %.2f\n", currentItem.price );
        printf( "Quantity: %d\n", currentItem.quantity );
        printf( "ID: %d\n", currentItem.id );
        printf( "\n" );
    }
    fclose(file);
}

void readFromCart()
{
    struct cartOrder currentOrder;
    FILE *file = fopen( "cart.txt", "rb" );
    if ( file == NULL ){
        printf( "Error with file\n" );
    }
    float totalPrice = 0;
    while ( fread( &currentOrder, sizeof(struct cartOrder), 1, file ) == 1 )
    {
        totalPrice += currentOrder.totalPrice;
        printf( "ID: %d\n", currentOrder.id );
        printf( "Name: %s\n", currentOrder.name );
        printf( "Description: %s\n", currentOrder.description );
        printf( "Price: %.2f\n", currentOrder.price );
        printf( "Quantity: %d\n", currentOrder.quantity );
        printf( "Sub-total Price: %.2f\n", currentOrder.totalPrice );
        printf( "\n" );
    }
    printf( "Total Price: %.2f\n", totalPrice );
    printf( "\n" );
    fclose( file );
}

void readFromOrders()
{
    struct cartOrder currentOrder;
    FILE *file = fopen( "orders.txt", "rb" );
    if ( file == NULL )
    {
        printf( "Error with file\n" );
    }
    float totalPrice = 0;
    while ( fread( &currentOrder, sizeof(struct cartOrder), 1, file ) == 1 )
    {
        totalPrice += currentOrder.totalPrice;
        printf( "ID: %d\n", currentOrder.id );
        printf( "Name: %s\n", currentOrder.name );
        printf( "Description: %s\n", currentOrder.description );
        printf( "Price: %.2f\n", currentOrder.price );
        printf( "Quantity: %d\n", currentOrder.quantity );
        printf( "Sub-total Price: %.2f\n", currentOrder.totalPrice );
        printf( "\n" );
    }
    printf( "Total Price: %.2f\n", totalPrice );
    printf( "\n" );
    fclose( file );
}

void readFromOrdersId( int id, int flag )
{
    struct cartOrder cartOrder;
    FILE *file = fopen( "orders.txt", "rb" );
    if ( file == NULL )
    {
        printf( "Error with file\n" );
    }
    if ( flag == 1 )
    {
        float totalQuantity = 0;
        float netPrice = 0;
        while ( fread( &cartOrder, sizeof(struct cartOrder), 1, file ) == 1 )
        {
            if ( cartOrder.id == id )
            {
                totalQuantity += cartOrder.quantity;
                netPrice += cartOrder.totalPrice;
            }
        }
        printf( "Total Quantity sold: %.2f\n", totalQuantity );
        printf( "Total value: %.2f\n", netPrice );
    }
    else
    {
        float totalPrice = 0;
        while ( fread( &cartOrder, sizeof(struct cartOrder), 1, file ) == 1 )
        {
            if ( cartOrder.id == id )
            {
                printf( "Name: %s\n", cartOrder.name );
                printf( "Description: %s\n", cartOrder.description );
                printf( "Price: %.2f\n", cartOrder.price );
                printf( "Quantity: %d\n", cartOrder.quantity );
                printf( "Sub-total Price: %.2f\n", cartOrder.totalPrice );
                printf( "\n" );
                totalPrice += cartOrder.totalPrice;
            }
        }
        printf( "Total Price: %.2f\n", totalPrice );
    }
}