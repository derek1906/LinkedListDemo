#include <iostream>
#include <string>
using namespace std;

class List{
    private:
    class ListNode{
        public: 
        ListNode(int d){
			data = d;
			next = NULL;
		}
		ListNode* next;
		int data;
    };
    
    public:
    List(){
		head = NULL;
	};
    
    void print(ostream& s){
        ListNode** curr = &head;
        s << "<";
        while(*curr){
            s << " " << (*curr)->data;
            curr = &(*curr)->next;
        }
        s << " >" << endl;
    }
    
    void insertBack(int d){
        ListNode** curr = &head;
        while(*curr){
            curr = &(*curr)->next;
        }
		*curr = new ListNode(d);
    }

	ListNode** find(int offset){
		return find(head, offset);
	}

	ListNode** find(ListNode* &link, int offset){
		return !link ? NULL : offset ? find(link->next, --offset) : &link;
	}

	void insertAt(int offset, int d){
		ListNode** node = find(offset);
		ListNode* newN = new ListNode(d);
		newN->next = *node;
		*node = newN;
	}
    
    ListNode* head;
};

int main()
{
  List l;
  l.insertBack(0);
  l.insertBack(1);
  l.insertBack(2);
  l.insertBack(3);
  l.insertBack(4);
  l.insertBack(5);
  l.print(cout);
  cout << (*l.find(2))->data << endl;
  l.insertAt(3, 10);
  l.insertAt(0, 100);
  l.print(cout);
}
