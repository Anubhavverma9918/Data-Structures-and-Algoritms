//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/*
   // Redirecting input from file
  freopen("/Users/debojyoti.mandal/expt/input.txt", "r", stdin);

  // Redirecting output to file
  freopen("/Users/debojyoti.mandal/expt/output.txt", "w", stdout);
*/

struct node {
    int data;
    struct node* next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    struct node *reverseIt(struct node *head, int k) {
        // Complete this method
        node *curr = head;
        node *prev = NULL;
        node *nextHead = NULL;
        int count = 0;

        /* previous k loop head. It will become tail and link to next k loop*/
        node *prevTail = NULL;
        /* get the head from first k loop */
        head = NULL;

        while(curr)
        {
            count = 0;
            /* start node will be tail*/
            node* startHead = curr;

            while(count < k && curr) 
            {
                /* reverse */
                nextHead = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextHead;
                count++;
            }

            if (!head) {
                /* save first head to return */
                head = prev;
            }

            /* connect */
            if (prev && prevTail) {
                /* prev here the last item of current k loop */
                prevTail->next = prev;
            }

            prev = NULL;
            /* save tail point*/
            prevTail = startHead;
        }

        return head;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        node* head = new node(data);
        node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseIt(head, k);
        printList(head);
    }

    return (0);
}

// } Driver Code Ends