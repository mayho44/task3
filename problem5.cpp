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
     vector<int>find_the_middle(){
        vector<int>arr;
      if(head==nullptr){
          cout<<"exception";
      }
      else if(head->next==nullptr){
          arr.push_back(head->data);
          return arr;
      }
      else {
          node *l = head, *r = tail;
          while (head <= tail) {
              if (head->next==tail&&tail->pre==head){
                  arr.push_back(head->data);arr.push_back(tail->data);
                  return arr;
              }
              head=head->next;
              tail=tail->pre;
          }
          arr.push_back(head->pre->data);
          return arr;
      }
    }
};
int main(){
    doubly_linked_list list;
    list.insert_end(1);
  list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);
    list.insert_end(5);
    list.insert_end(6);
    vector<int>arr;
    arr=list.find_the_middle();
    for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";
}

