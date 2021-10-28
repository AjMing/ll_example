// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <iostream>
using namespace std;
#include "ll.h"


int main( void )
{ 
   LLPtr startPtr = NULL; // initially there are no nodes
   unsigned int choice; // user's choice
   int item; // char entered by user

   instructions(); // display the menu
   cout<< "? " ;
   cin>> choice ;

   // loop while user does not choose 3
   while ( choice != 3 ) { 

      switch ( choice ) { 
         case 1:
            cout<<"Enter a number: " ;
            cin>> item ;
            insert( startPtr, item ); // insert item in list
            printList( startPtr );
            break;
         case 2: // delete an element
            // if list is not empty
            if ( !isEmpty( startPtr ) ) { 
               cout<< "Enter number to be deleted: " ;
               cin>>item ;

               // if character is found, remove it
               if ( item==deletes( startPtr, item ) ) { // remove item
                 cout<<item << " deleted.\n";
                  printList( startPtr );
               } // end if
               else {
                  cout<<item<<" not found.\n\n";
               } // end else
            } // end if
            else {
               cout<<"List is empty."<<endl;
            } // end else

            break;
         default:
           cout<< "Invalid choice." <<endl;
            instructions();
            break;
      } // end switch

      cout<< "? " ;
     cin>>choice ;
   } // end while

   puts( "End of run." );
} // end main

