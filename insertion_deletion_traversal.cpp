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
    //insertion element y after element x--------
    int x,y;
    cin>>x>>y;
    struct node *pp=head;
    while(pp->data!=x){
        pp=pp->next;
    }
    
    struct node *tmp4=new node();
    tmp4->data=y;
    pp->next->prev=tmp4;
    tmp4->next=pp->next;
    tmp4->prev=pp;
    pp->next=tmp4;
    
    //---deletion at start in linked list-----------------
    
    if(head==NULL){
        cout<<"linked_list is empty"<<endl;
    }
    else{
        struct node *tmpp=head;
        head=tmpp->next;
        head->prev=NULL;
        free(tmpp);
        
        //alternate way but it will not free the element at start
        //head=head->next;
        //head->prev=NULL;
        
    }
    
    
    
    //deletion of element k in middle---------------
    node *del=head;
    int k;
    cin>>k;
    
    while(del->next->data!=k){
        del=del->next;
    }
    
    node *tmp1=del->next;
    del->next=tmp1->next;
    tmp1->next->prev=del;
    free(tmp1);
    
    
    
    
    //deletion at the end of linked list-----------
    
    node *tmp2=head;
    while(tmp2->next->next!=NULL){
        tmp2=tmp2->next;
    }
    node *tmp3=tmp2->next;
    tmp2->next=NULL;
    free(tmp3);
    
    //traversal----------------------------
    node *q=head;
    while(q!=NULL){
        cout<<q->data<<" ";
        q=q->next;
    }
    
   
    
    return 0;
}
