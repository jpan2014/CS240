#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"

//Initialize the linked list
void llist_init(LinkedList * list)
{
        list->head = NULL;
}

// Prints the linked list
void llist_print(LinkedList * list) {
        
        ListNode * e;

        if (list->head == NULL) {
                printf("{EMPTY}\n");
                return;
        }

        printf("{");

        e = list->head;
        while (e != NULL) {
                printf("%d", e->value);
                e = e->next;
                if (e!=NULL) {
                        printf(", ");
                }
        }
        printf("}\n");
}

// Problem ( 1/4 ) 
/******************************************************************************
 * TODO: Return the number of elements (ListNodes) in the linked list.
 *
 * Parameters: list -- find the number of elements contained in this single
 * linked list
 *
 * Return: the number of elements 
 *
 * Return Type: integer
 *****************************************************************************/
int llist_number_elements(LinkedList * list) {
    // Write Your Code Here
    int count = 0;
    ListNode * n = list->head;
    while (n != NULL)
    {	
    	count++;
	n=n->next;
}
	return count;

}

// Problem ( 2/4 ) 
/******************************************************************************
 * TODO: Create a new ListNode and add it to the end of the single linked
 * 	 list. There is no check if the value exists in the list. 
 *
 * Parameters: list -- The single linked list to which you will insert the new
 * 		       ListNode to the end of.
 *             value -- The new ListNode will contain this value.
 *
 * Return: void
 * 
 * Return Type: void
 *****************************************************************************/
void llist_insert_last(LinkedList * list, int value) {
    // Write Your Code Here
    ListNode * n = list->head;
    ListNode * last = NULL;
    while (n != NULL)
    {
    	last = n;
    	n = n->next;
    }
    ListNode * add = (ListNode *)malloc(sizeof(ListNode));
    add->value = value;
    add->next = NULL;
    if (last == NULL)
    {
    	list->head = add;
    }
    else {
    last->next = add;
    }
}

// Problem ( 3/4 )
/******************************************************************************
 * TODO: Remove the ith entry from the single linked list.   	 
 * 
 * Parameters: list -- The single linked list to which you will be removing
 * 		       the listNode from.
 * 	       ith -- The index where you will remove the listNode from the
 * 	              single linked list. 
 *
 * Return: Return 1 if the ListNode is removed.
 * 	   Return 0 if the ith entry does not exist in the list or the list is
 * 	   empty.
 *
 * Return Type: integer
 *****************************************************************************/
int llist_remove_ith(LinkedList * list, int ith) {
    // Write Your Code Here
    int counter = 0;
    ListNode * n = list->head;
    ListNode * prev = NULL;
    while (n != NULL && counter <= ith)
    {
    	if(counter == ith)
	{
		if (counter == 0)
		{
			list->head = n->next;
			return 1;
		}
		else
		{
			prev->next = n->next;
			return 1;
		}
	}
	prev = n;
	n = n->next;
	counter++;
}
return 0;
}

// Problem ( 4/4 )
/******************************************************************************
 * TODO: Iterate through list1 and list2. Check if any values intersect between
 *       the two lists. If the values match, add the intersecting elements
 *       to list3. Use the function llist_add(LinkedList * list, int value)
 *       to add a value to the list.
 * 
 * Parameters: list1 -- singled linked list, find values that intersect with
 *                      list2
 *             list2 -- single linked list, find values that intersect with
 *                      list1
 *             list3 -- store the intersection of list1 and list2 in this list
 *
 * Return: void 
 *
 * Return Type: void
 *****************************************************************************/
void llist_intersection(LinkedList * list1, LinkedList * list2,
	LinkedList * list3) {
    // Write Your Code Here
    ListNode * n = list1->head;
    ListNode * prev = NULL;
    while (n != NULL)
    {
    	ListNode * n2 = list2->head;
	ListNode * prev2 = NULL;
	while (n2 != NULL) 
	{
		if (n->value == n2->value)
		{
			llist_add(list3, n->value);
		}
		prev2 = n2;
		n2 = n2->next;
	}
	prev = n;
	n = n->next;
}
 }
