#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot)
{
    //small recursive case tryna attack is adding to linked list based on if less than or bigger
    // base case is when head is null, as that is what head needs to end at
    if (head == nullptr)
    {
        smaller = nullptr;
        larger = nullptr;
        return;
    }
    // if the value is less than or equal to pivot, 
    // add to pivot list and go to next in head. 
    //change what smaller points to to make it start of new list since there can be garbage values
    // make head go to next as at the end we need head to be null at the end
    // pass smaller->next, not smaller, so aren't overwriting same pointer continually since is passed by pointer and are instead creating list. Only works because are passed reference to a pointer. 
    else if (head->val <= pivot)
    {
        smaller = head;
        head = head->next;
        llpivot (head, smaller->next, larger, pivot);
    }
    //same as above but for case where value is larger than pivot
    else
    {
        larger = head;
        head = head->next;
        llpivot (head, smaller, larger->next, pivot);
    }
}
