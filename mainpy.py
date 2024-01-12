'''
    Author: Saathvikk Muthyala,
    Date Created: 12-01-2024,
    //last Modified: 12-01-2024 (),
    No of times Modified: 1; 
    

********************************************************************************
'''

from ctypes import CDLL

example = CDLL('main.so')

adminOrCustomer = int(input("Are you an admin or a customer? (1-admin/2-customer): "))
  
#one of many implementations(only showed how to use one function for admin and customer)

if (adminOrCustomer == 1):
    print( "press 0 to view all products: " )
    choice = int(input( "Enter your choice: " ))
    if ( choice == 0 ):
        example.readFromItems()
    else:
        print( "Invalid choice" )
else:
    print( "Enter id to view all orders with id: " )
    id = int(input( "Enter id of the product: " ))
    example.readFromOrders( id, adminOrCustomer )