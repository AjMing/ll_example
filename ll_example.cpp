// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <iostream>
using namespace std;

// self-referential structure                       
struct Node {                                      
   int data; // each listNode contains a character 
   Node *nextPtr; // pointer to next node
}; // end structure listNode                        
typedef struct Node LLnode; // synonym for struct listNode
typedef LLnode *LLPtr; // synonym for ListNode*

// prototypes

int deletes( LLPtr &sPtr, int value );
int isEmpty( LLPtr sPtr );
void insert( LLPtr &sPtr, int value );
void printList( LLPtr currentPtr );
void instructions( void );

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

// display program instructions to user
void instructions( void )
{ 
   cout<< "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end."<<endl ;
} // end function instructions

// insert a new value into the list in sorted order
void insert( LLPtr &sPtr, int value )
{ 
   LLPtr newPtr; // pointer to new node
   LLPtr previousPtr; // pointer to previous node in list
   LLPtr currentPtr; // pointer to current node in list

   newPtr =new LLnode; // create node

   if ( newPtr != NULL ) { // is space available
      newPtr->data = value; // place value in node
      newPtr->nextPtr = NULL; // node does not link to another node

      previousPtr = NULL;
      currentPtr = sPtr;

      // loop to find the correct location in the list       
      while ( currentPtr != NULL && value > currentPtr->data ) {
         previousPtr = currentPtr; // walk to ...               
         currentPtr = currentPtr->nextPtr; // ... next node 
      } // end while                                         

      // insert new node at beginning of list
      if ( previousPtr == NULL ) { 
         newPtr->nextPtr = sPtr;
         sPtr = newPtr;
      } // end if
      else { // insert new node between previousPtr and currentPtr
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
      } // end else
   } // end if
   else {
      cout<<value <<" not inserted. No memory available."<<endl;
   } // end else
} // end function insert

// delete a list element
int deletes( LLPtr &sPtr, int value )
{ 
   LLPtr previousPtr; // pointer to previous node in list
   LLPtr currentPtr; // pointer to current node in list
   LLPtr tempPtr; // temporary node pointer

   // delete first node
   if ( value == sPtr->data ) { 
      tempPtr = sPtr; // hold onto node being removed
      sPtr = sPtr->nextPtr; // de-thread the node
      free( tempPtr ); // free the de-threaded node
      return value;
   } // end if
   else { 
      previousPtr = sPtr;
      currentPtr = sPtr->nextPtr;

      // loop to find the correct location in the list
      while ( currentPtr != NULL && currentPtr->data != value ) { 
         previousPtr = currentPtr; // walk to ...  
         currentPtr = currentPtr->nextPtr; // ... next node  
      } // end while

      // delete node at currentPtr
      if ( currentPtr != NULL ) { 
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free( tempPtr );
         return value;
      } // end if
   } // end else

   return '\0';
} // end function delete

// return 1 if the list is empty, 0 otherwise
int isEmpty( LLPtr sPtr )
{ 
   return sPtr == NULL;
} // end function isEmpty

// print the list
void printList( LLPtr currentPtr )
{ 
   // if list is empty
   if ( isEmpty( currentPtr ) ) {
      cout<< "List is empty."<<endl;
   } // end if
   else { 
       cout<< "The list is:" <<endl;

      // while not the end of the list
      while ( currentPtr != NULL ) { 
         printf( "%d --> ", currentPtr->data );
         currentPtr = currentPtr->nextPtr;   
      } // end while

      puts( "NULL\n" );
   } // end else
} // end function printList