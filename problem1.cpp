#include <iostream>
#include <algorithm>

using namespace std;
/* name of groups rahma samy mohamed 20198035
doha khaled 20198126
mahmoud samy razek 20198075*/
template<class x>
struct node
{
    x data;
    node<x> *next;
};

template<class x>
class list
{
private:
    node<x> *head, *tail;
public:

    list()
    {
        head=NULL;
        tail=NULL;
    }

    list(x value, int initialsize){
        node<x> *tmp=new node<x>;
        tmp->data=value;
        tmp->next=NULL;
        head=tmp;
        tail=tmp;
        tmp=NULL;
        for(int i=0;i<initialsize-1;++i){
            node<x> *tmp=new node<x>;
            tmp->data=value;
            tmp->next=NULL;
            tail->next=tmp;
            tail=tmp;
        }
    }

    list<x>& operator = (list<x>list2){
        if( this == &list2 )
            return *this;
        iterator itr =list2.begin( );
        this->push_back(*itr);
        do{
            ++itr;
            this->push_back(*itr);
        }while(itr != list2.end());
        return *this;
    }

    class iterator {
    public:
        node<x> *nodeitr;
        node<x> *headitr;
    public:
        iterator(){
            nodeitr=nullptr;
            headitr=nullptr;
        }
        iterator(node<x> *Ptrnode,node<x> *h){
            nodeitr=Ptrnode;
            headitr=h;
        }

        void operator++() {
            if (nodeitr->next == NULL ){
                cout << "Out of Range"<<endl;
                return;
            }
            nodeitr = nodeitr->next;
        }

        void operator -- (){
            list<x>:: iterator i;
            i.nodeitr=this->headitr;
            i.headitr=this->headitr;
            if (this->headitr == this->nodeitr ){
                cout<<"Out of Range"<<endl;
            }
            else {
                while (i.nodeitr->next != NULL ){
                    if(i.nodeitr->next == this->nodeitr){
                        this->nodeitr = i.nodeitr;
                        return;
                    }
                    ++i;
                }
            }
        }

        x& operator*() const {
            return nodeitr->data;
        }

        bool operator==(const iterator& y) const {
            return nodeitr== y.nodeitr;
        }

        bool operator!=(const iterator& y) const {
            return nodeitr != y.nodeitr;
        }

    };

    iterator erase(iterator pos) {
        node<x> *Delete = pos.nodeitr->next;
        pos.nodeitr->next = pos.nodeitr->next->next;
        if (Delete == tail) tail = pos.nodeitr;
        delete Delete;
        return pos;
    }

    void push_back(x value)
    {
        node<x> *temp=new node<x>;
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }

    void insert(int l, x value)
    {
        node<x> *p=new node<x>;
        node<x> *c=new node<x>;
        node<x> *temp=new node<x>;
        c=head;
        for(int i=1; i<l; i++)
        {
            p=c;
            c=c->next;
        }
        temp->data=value;
        p->next=temp;
        temp->next=c;
    }

    void display()
    {
        node<x> *temp=new node<x>;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void insert_start(x value)
    {
        node<x> *temp=new node<x>;
        temp->data=value;
        temp->next=head;
        head=temp;
    }

    void delete_first()
    {
        node<x> *temp=new node<x>;
        temp=head;
        head=head->next;
        delete temp;
    }

    void delete_last()
    {
        node<x> *cur=new node<x>;
        node<x> *pre=new node<x>;
        cur=head;
        while(cur->next!=NULL)
        {
          pre=cur;
          cur=cur->next;
        }
        tail=pre;
        pre->next=NULL;
        delete cur;
    }

    void delete_position(int pos)
    {
        node<x> *current=new node<x>;
        node<x> *previous=new node<x>;
        current=head;
        for(int i=1;i<pos;i++)
        {
          previous=current;
          current=current->next;
        }
        previous->next=current->next;
    }

    bool search(x value){
        node<x> *temp=new node<x>;
        temp=head;
        while(temp!=NULL)
        {

            if(temp->data == value) return 1;
            temp=temp->next;

        }
        return 0;
        cout<<endl;
    }

    iterator begin() {
      return iterator(head,head);
    }

    iterator end() {
      return iterator(tail,head);
    }

    int size(){
        int count = 0;
        node<x> *temp=new node<x>;
        temp=head;
        while(temp!=NULL)
        {
            ++count;
            temp=temp->next;
        }
        return count;
    }

    ~list(){
        do{
            delete_last();
        }while(head != tail);
        delete head;
        delete tail;
        //cout<<"destructor called"<<endl;
    }

};

int main()
{
    list<int> link(8,5);
    link.push_back(6);
    link.push_back(9);
    link.push_back(8);
    cout<<link.size()<<endl;
    link.display();
    link.insert(6,9);
    link.display();
    link.insert_start(2);
    link.display();
    link.delete_first();
    link.display();
    link.delete_last();
    link.display();
    link.delete_position(4);
    link.display();
    cout<<link.search(7)<<endl;
    cout<<link.search(3);
    cout<<"\n\n\n\n";
    list<int>:: iterator itr = link.begin();
    list<int>:: iterator itr2 = link.begin();
    cout<<*itr;
    ++itr;
    cout<<*itr;
    ++itr;
    cout<<*itr;
    ++itr;
    cout<<*itr;

    ++itr;       ///out of range

    --itr;
    cout<<*itr;
    ++itr;
    cout<<*itr;

    link.erase(itr2);

    cout<<endl;

    list<int> l2;
    l2 = link;
    l2.display();

    return 0;
}
