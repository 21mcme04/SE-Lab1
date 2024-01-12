/*
    Author: Saathvikk Muthyala,
    Date Created: 05-01-2024,
    //last Modified: 07-01-2024 (),
    No of times Modified: 1; 
    
*/
//********************************************************************************
/*
    Edit the files using this module.
    
*/

void removeFromProducts( int id )
{
    FILE *file = fopen( "item.txt", "rb" );
    if ( file == NULL )
    {
        printf("Error with file");
    }
    FILE *tempFile = fopen( "temp.txt", "wb" );
    if ( tempFile == NULL )
    {
        printf("Error with file");
    }
    struct item item;
    int changed = 1;
    while ( fread( &item, sizeof(struct item), 1, file ) )
    {
        if ( item.id != id )
        {
            fwrite( &item, sizeof(struct item), 1, tempFile );
        }
        else if ( item.id == id )
        {
            changed = 0;
            printf("Removed item with id: %d\n", id);
        }
    }
    if ( changed )
    {
        printf("No item with id: %d\n", id);
    }
    fclose( file );
    fclose( tempFile );
    remove( "item.txt" );
    rename( "temp.txt", "item.txt" );
}

void editFromProducts( struct item *newItem)
{
    FILE *file = fopen( "item.txt", "rb" );
    if ( file == NULL )
    {
        printf("Error with file");
    }
    FILE *tempFile = fopen( "temp.txt", "wb" );
    if ( tempFile == NULL )
    {
        printf("Error with file");
    }
    struct item item;
    int changed = 1;
    while ( fread( &item, sizeof(struct item), 1, file ) )
    {
        if ( item.id != newItem->id )
        {
            fwrite( &item, sizeof(struct item), 1, tempFile );
        }
        else
        {
            changed = 0;
            item = *newItem;
            fwrite(&item, sizeof(struct item), 1, tempFile);
        }
    }
    if ( changed )
    {
        printf("No item with id: %d\n", newItem->id);
    }
    fclose( file );
    fclose( tempFile );
    remove( "item.txt" );
    rename( "temp.txt", "item.txt" );
}

void reduceFromProducts()
{
    FILE *file = fopen( "cart.txt", "rb" );
    if ( file == NULL )
    {
        printf( "Error with file\n" );
    }
    FILE *itemFile = fopen( "item.txt", "rb" );
    if ( itemFile == NULL )
    {
        printf( "Error with file\n" );
    }
    struct item item;
    struct cartOrder cartOrder;
    while ( fread( &cartOrder, sizeof(struct cartOrder), 1, file ) )
    {
        while ( fread( &item, sizeof(struct item), 1, itemFile ) )
        {
            if ( cartOrder.id == item.id )
            {
                item.quantity -= cartOrder.quantity;
                editFromProducts( &item );
            }
        }
        rewind( itemFile );
    }
}

void removeFromCart( int id ){
    FILE *file = fopen( "cart.txt", "rb" );
    if (file == NULL )
    {
        printf( "Error with file\n" );
    }
    FILE *tempfile = fopen( "temp.txt", "wb" );
    if ( tempfile == NULL )
    {
        printf( "Error with file\n" );
    }
    struct cartOrder cartOrder;
    int changed = 1;
    while ( fread( &cartOrder, sizeof(struct cartOrder), 1, file ) )
    {
        if ( cartOrder.id != id )
        {
            fwrite( &cartOrder, sizeof(struct cartOrder), 1, tempfile );
        }
        else if ( cartOrder.id == id )
        {
            changed = 0;
            printf( "Removed item with id: %d\n", id );
        }
    }
    if ( changed )
    {
        printf( "No item with id: %d\n", id );
    }
    fclose( file );
    fclose( tempfile );
    remove( "cart.txt" );
    rename( "temp.txt", "cart.txt" );
}

void modifyFromCart( int id, int quantity )
{
    FILE *file = fopen( "cart.txt", "rb" );
    if ( file == NULL )
    {
        printf( "Error with file\n" );
    }
    FILE *tempfile = fopen( "temp.txt", "wb" );
    if ( tempfile == NULL )
    {
        printf( "Error with file\n" );
    }
    FILE *prodFile = fopen( "item.txt", "rb" );
    if ( prodFile == NULL )
    {
        printf( "Error with file\n" );
    }
    struct item item;
    struct cartOrder cartOrder;
    int changed = 1;
    while ( fread( &cartOrder, sizeof(struct cartOrder), 1, file ) )
    {
        if ( cartOrder.id != id )
        {
            fwrite( &cartOrder, sizeof(struct cartOrder), 1, tempfile );
        }
        else if ( cartOrder.id == id && item.quantity >= quantity )
        {
            changed = 0;
            cartOrder.quantity = quantity;
            cartOrder.totalPrice = cartOrder.price * quantity * 1.18;//including gst
            fwrite( &cartOrder, sizeof(struct cartOrder), 1, tempfile );
        }
        else
        {
            printf( "Not available quantity\n" );
        }
    }
    if ( changed )
    {
        printf( "No item with id: %d\n", id );
    }
    fclose( file );
    fclose( tempfile );
    remove( "cart.txt" );
    rename( "temp.txt", "cart.txt" );
}