#include <iostream>
#include <iomanip>
#include <cmath>
#include <numeric>
#include<bits/stdc++.h>
#include <string>
using namespace std;
#define endl '\n'
//#define haha cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define ll long long
struct node{
    int data;
    node*next=nullptr;
    node*pre=nullptr;
    node(int data):data(data){}
};
class doubly_linked_list{
private:node*tail{};
    node*head{};
    int length=0;
public:
    node* delete_and_link(node*cur){
        node*before=cur->pre;
        node*after=cur->next;
        link(before,after);
        delete cur;
        return before;
        length--;
    }
    void link(node*first,node*second){
        if(first!=nullptr){
            first->next=second;
        }
        if(second !=nullptr)second->pre=first;
    }
    void print(){
        for(node*cur=head;cur;cur=cur->next)cout<<cur->data<<" ";
    }
    void insert_sorted(int value) {
        if (length == 0 || value <= head->data)insert_front(value);
        else if (tail->data <= value)insert_end(value);
        else {
            for (node *cur = head; cur; cur=cur->next) {
                if (value <= cur->data) {
                    embed_after(value,cur);
                    break;
                }
            }
        }
    }
    void embed_after(int value,node*cur){
        swap(value,cur->data);
        node *after=cur->next;
        node *ele=new node(value);
        if(cur->next==nullptr){
            insert_end(value);
        }
        else {
            link(cur, ele);
            link(ele,after);
            length++;
        }
    }
    void insert_front(int value){
        node *ele =new node(value);
        if(head==nullptr){
            head=tail=ele;
        }
        else{
            link(ele,head);
            head=ele;
        }
        length++;
    }
    void insert_end(int value){
        node *ele =new node(value);
        if(head==nullptr){
            head=tail=ele;
        }
        else {
            link(tail,ele);
            tail=ele;
            tail->next=nullptr;
        }
        length++;
    }
    void delete_front(){
        if(length==0){
            cout<<"exception occurred"<<" ";
            return;
        }
        else if(length==1){
            delete head;
            head=nullptr;
        }
        else{
            node*after=head->next;
            delete head;
            head=after;
        }
        length--;
    }
    void delete_end(){
        length--;
        if(head== nullptr)return;
        else if(length==1){
            delete tail;
            tail=nullptr;
        }
        else{
            node*before=tail->pre;
            delete tail;
            tail=before;
            tail->next=nullptr;
        }
    }
   void swap_forward(int k){
       if(head==nullptr||head->next==nullptr)return;
        node*l=head,*r=tail;
        k--;
while(k){
    if(l->next!=nullptr){
        l=l->next;
        r=r->pre;
    }
k--;
}
       swap(r->data,l->data);
if(l==r)return;
else{
    node*before=l->pre,*after=l->next;
    if(l->pre!=nullptr){
        link(l,r->next);
        link(r->pre,l);
        link(r,after);
        link(before,r);
    }
    else{
        link(r->pre,l);
        l->next=nullptr;
        link(r,after);
    }
}
    }
    void merge_lists(doubly_linked_list &list){
        node*cur1=head,*cur2=list.head,*last{};
        while(cur1,cur2){
            node*next{};
            if(cur1->data<=cur2->data){
                next=cur1;
                cur1=cur1->next;
            }
            else {
                next=cur2;
                cur2=cur2->next;
            }
            link(last,next);
            last=next;
            if(!head)head=last;
            if(cur2){
                tail=list.tail;
                link(last,cur2);
            }
            else if(cur1){
                link(last,cur1);
            }
            else {
                head=list.head;tail=list.head;
            }
        }
    }
};
int main(){
    doubly_linked_list list;
    list.insert_end(10);
  list.insert_end(20);
    list.insert_end(30);
   list.insert_end(40);
    list.insert_end(50);
    doubly_linked_list list2;
    list2.insert_end(15);
    list2.insert_end(17);
    list2.insert_end(22);
    list2.insert_end(24);
    list2.insert_end(35);
    list.merge_lists(list2);
    list.print();
}

