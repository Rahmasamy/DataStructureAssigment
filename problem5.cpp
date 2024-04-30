#include <iostream>
/* name of groups rahma samy mohamed 20198035
doha khaled 20198126
mahmoud samy razek 20198075*/
using namespace std;
struct ele
{
    int prio;

    ele * next;

    string val;
};
class Priorityqueue
{
private:
    ele  *head= NULL;
public:
    Priorityqueue()
    {

    }

    ~Priorityqueue()
    {
        delete head;
    }

    void dequeue()
    {

        if (head==NULL)
        {
            cout<< "Empty queue!! \n";
        }
        else
        {
            cout<<head->val;

            ele *ptr=head;

            head=head->next;

            free(ptr);
        }
    }
    void enqueue(string data, int prio)
    {
        ele *temp, *ptr;

        temp = new ele;

        temp->val = data;

        temp->prio = prio;

        if (head == NULL || prio < head->prio)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            ptr = head;

            while (ptr->next != NULL && ptr->next->prio <= prio)

                ptr=ptr->next;

            temp->next = ptr->next;

            ptr->next = temp;
        }
    }

};
int main()
{
   Priorityqueue q;

    q.enqueue("name:", 1);

    q.enqueue("Mahmoud", 2);

    q.enqueue("Samy", 3);

    q.enqueue("Rizk", 4);

    q.dequeue();

    q.dequeue() ;

    q.dequeue() ;

    q.dequeue() ;
    return 0;
}
