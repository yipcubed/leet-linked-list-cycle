#include <iostream>
#include <map>

using namespace std;

/**
 * Definition for singly-linked list.
 */

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head) {
      map<ListNode*, int> seen;
      int count = 0;
      while (head && seen.count(head) == 0) {
          seen[head] = count++;
          head = head->next;
      }
      return head != NULL;
    }
};

int main() {

  Solution S;

  cout << boolalpha;

  // [3,2,0,-4]
  ListNode *l1 = new ListNode(3);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(0);
  l1->next->next->next = new ListNode(-4);
  l1->next->next->next->next = l1->next;

  cout << "true? " << S.hasCycle(l1) << endl;

  // [1, 2]
  ListNode *l2 = new ListNode(1);
  l2->next = new ListNode(2);
  l2->next->next = l2;
  cout << "true? " << S.hasCycle(l2) << endl;

  // [1]
  ListNode *l3 = new ListNode(1);
  cout << "false? " << S.hasCycle(l3) << endl;

  std::cout << "Hello World!\n";
}