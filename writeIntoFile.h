/*
    Author: Saathvikk Muthyala,
    Date Created: 05-01-2024,
    //last Modified: 07-01-2024 (),
    No of times Modified: 1; 
    
*/
//********************************************************************************
/*
    Write into file using this module.
    
*/

void writeIntoProducts( struct item *item )
{
    FILE *file = fopen( "item.txt", "ab+" );
    if ( file == NULL )
    {
        printf( "Error with file" );
    }
    fwrite( item, sizeof(struct item), 1, file );
    fclose( file );
}

void writeIntoCart( struct cartOrder *cartOrder )
{
    FILE *file = fopen( "cart.txt", "a+" );
    if ( file == NULL )
    {
        printf( "Error with file\n" );
    }
    fwrite( cartOrder, sizeof(struct cartOrder), 1, file );
    fclose( file );
}

void addToCart( int id, int quantity )
{
    FILE *file = fopen( "item.txt", "rb" );
    if (file == NULL )
    {
        printf( "Error with file\n" );
    }
    struct item item;
    int changed = 1;
    while ( fread( &item, sizeof(struct item), 1, file ) )
    {
        if ( item.id == id )
        {
            changed = 0;
            if ( item.quantity >= quantity )
            {
                struct cartOrder cartOrder;
                strcpy( cartOrder.name, item.name );
                strcpy( cartOrder.description, item.description );
                cartOrder.id = item.id;
                cartOrder.quantity = quantity;
                cartOrder.price = item.price;
                cartOrder.totalPrice = item.price * quantity * 1.18;//including gst
                writeIntoCart( &cartOrder );
            }
            else
            {
                printf( "Not available quantity\n" );
            }
        }
    }
    if ( changed )
    {
        printf( "No item with id: %d\n", id );
    }
}

void writeIntoOrders(){
    FILE *file = fopen( "cart.txt", "rb" );
    if ( file == NULL )
    {
        printf( "Error with file\n" );
    }
    FILE *ordersFile = fopen( "orders.txt", "ab+" );
    if ( ordersFile == NULL )
    {
        printf( "Error with file\n" );
    }
    struct cartOrder cartOrder;
    while ( fread( &cartOrder, sizeof(struct cartOrder), 1, file ) )
    {
        fwrite( &cartOrder, sizeof(struct cartOrder), 1, ordersFile );
    }
    fclose( file );
    fclose( ordersFile );
    file = fopen( "cart.txt", "w" );
    if ( file != NULL )
    {
        fclose( file );
    }
    else
    {
        printf( "Error with file\n" );
    }
}