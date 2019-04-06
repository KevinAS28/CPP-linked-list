#include <iostream>
#include <map>
template <typename any>
class Linked_List
{
 public:
  Linked_List(){}
  Linked_List **next = new Linked_List*; //harus pointer
  any data=0;
  int initialized = 0;
  void add_Data(Linked_List<any> *obj)
  {
   if (!(this->initialized)){this->data = (*obj).data;this->initialized=1;return;}
   (*((this->next))) = obj;
  }  
  Linked_List(any to_add)
  {
   this->data = to_add;
   this->initialized = 1;
  }
  void printLast()
  {
      std::cout << (*((this->next)))->data;
  }
};
int main0()
{
 Linked_List<int> yay(100), oke(500), eko(200);
 yay.add_Data(&oke);
 std::cout << yay.data << "\n";
 std::cout << (*(yay.next))->data << "\n";
 yay.printLast();
 
 return 0;
}
template <typename any>
class Linked_List2
{
 public:
  Linked_List2(){}
  int size = 0;
  std::map<int, any*> *pointer_table = new std::map<int, any*>;
  
  void add_Data(any *ptr)
  {
   (*(this->pointer_table))[size] = ptr;
  }
  Linked_List2(any *to_add)
  {
   this->add_Data(to_add);
  }
  any operator[](int x)
  {
   return (*(this->pointer_table[x]));
  }
  void printLast()
  {
   std::cout << (*((*(this->pointer_table))[this->size]));
  }
};

int main()
{
 
 int x = 10, y = 20;
 Linked_List2<int> yay(&x);
 yay.add_Data(&y);
 yay.printLast();
 return 0;
}
