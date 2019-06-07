#include <iostream>
using namespace std;

struct node{
    
    struct node *next;
    int data;
    struct node *prev;
};

int main()
{
    
    node *head=NULL;
    int n;
    cin>>n;
    //insertion---------
    while(n--){
        int tmp;
        cin>>tmp;
        if(head==NULL){
           head=new node();
           head->prev=NULL;
           head->data=tmp;
           head->next=NULL;
           
        }
        else{
            struct node *p=head;
            while(p->next!=NULL){
                p=p->next;
            }
            node *tm=new node();
            
            tm->data = tmp;
            tm->next=NULL;
            p->next=tm;
            tm->prev=p;
            
        }
    }
    
    //traversal----------------------------
    cout<<"list before reversal----"<<endl;
    node *q=head;
    while(q!=NULL){
        cout<<q->data<<" ";
        q=q->next;
    }
    
    
    //reversal nonrecursive----------------
    
    node *p1=head,*p2;
    p2=p1->next;
    p1->next=NULL;
    p1->prev=p2;
    
    while(p2!=NULL){
        
        p2->prev=p2->next;
        p2->next=p1;
        p1=p2;
        
        p2=p2->prev;
        
        
    }
    cout<<endl;
    
    head=p1;

    
    //traversal----------------------------
    cout<<"list after reversal-----"<<endl;
    q=head;
    while(q!=NULL){
        cout<<q->data<<" ";
        q=q->next;
    }
    
   
    
    return 0;
}
