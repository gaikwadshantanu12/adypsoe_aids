#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
struct n // node declaration
{
   int p;
   char  info;
   struct n *l;
};
class Priority_Queue {
   private:
      //Declare a front pointer f and initialize it to NULL.
      n *f;
   public:
      Priority_Queue() //constructor 
      {
         f = NULL;
      }
      void insert(char  sd, int p) 
      {
         n *t, *q;
         t = new n;
         t->info =sd;
         t->p = p;
         if (f == NULL || p < f->p)
         {
            t->l= f;
            f = t;
         } else
         {
            q = f;
            while (q->l != NULL && q->l->p <= p)
               q = q->l;
               t->l = q->l;
               q->l = t;
         }
      }
      
      
      void show() //print queue
      {
         n *ptr;
         ptr = f;
         if (f == NULL)
            cout<<"Queue is empty\n";
         else 
         {
            cout<<"Queue is :\n";
            cout<<"Priority Item\n";
            while(ptr != NULL) 
            {
               cout<<ptr->p<<" "<<ptr->info<<endl;
               ptr = ptr->l;
            }
         }
      }
};
int main() {
   int c, i, p;
 char pc;
   Priority_Queue pq;
   do 
   {
   
      cout<<"1.Insert\n";
      cout<<"2.Display\n";
      cout<<"3.Exit\n";
      cout<<"Enter your choice : ";
      cin>>c;
      switch(c) 
      {
         case 1:
            cout<<"kinds of patients  : ";
            cin>>pc;
            cout<<"Enter its priority : ";
            cin>>p;
            pq.insert(pc, p);
            break;
         case 2:
            pq.show();
            break;
         case 3:
            break;
         default:
         cout<<"Wrong choice\n";
      }
   }   while(c != 3);
   return 0;
}