#include"bits/stdc++.h"
using namespace std;

class node {
    public :

    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head,int val){
    //create a new node
    node* n = new node(val);
    //if only one node exists
    if(head == NULL){
        head=n;
        return;
    }

    node*temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = n;
}

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head= head->next;
    delete todelete;
}

void deletion(node* &head, int val){

    if(head==NULL){
        return;
    }

    if(head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }

    node *temp = head;
    while(temp->next->data !=val){
        temp = temp->next;

    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

node* reverseLL(node* &head){
    node* next;
    node*curr = head;
    node*prev = NULL;

 while(curr!=NULL){
     next = curr->next;
     curr->next = prev;
     prev = curr;
     curr  = next;
 }
 head = prev;
 return head;

}

bool detectLoop(node* &head){
    
    node* slowPtr= head;
    node* fastPtr =head;

    while(fastPtr!=NULL && fastPtr->next != NULL){
        
        slowPtr = slowPtr->next;
        fastPtr=fastPtr->next->next;

        if(fastPtr == slowPtr){
            return true;
        }
        

    }
    return false;

    
}

node* startingOfLoop(node* &head){
    node* slowPtr = head;
    node* fastPtr = head;

    while(slowPtr!=NULL && fastPtr!=NULL && fastPtr->next != NULL){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if(slowPtr == fastPtr){
            break;
        }

    }

    slowPtr = head;
    while(slowPtr != fastPtr){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;

    }
    return slowPtr;
}


  node* removeDuplInSorted(node* &head){
      node* temp = head;

      while(temp->next!= NULL){
          if(temp->data == temp->next->data){
              temp->next == temp->next->next;
              
          }
          else{
              temp = temp->next;
          }
        
      }
      return head;
  }

 node* removeDuplInUnsorted(node* &head){
     map<int, int> m;
     node* curr = head;
     node* prev = curr;
     m[curr->data] = 1;
     curr = curr->next;
     while(curr!=NULL){
         //if ccurr ka data is available 
         if(m[curr->data]){
             prev->next = curr->next;
             free(curr);
         }
         else{
             m[curr->data] = 1;
             prev = curr;
         }

         curr = prev->next;
     }
     return head;
 } 



int main(){

    node*head= NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtHead(head,0);
    display(head);
    deletion(head,3);
    display(head);




    return 0;
}