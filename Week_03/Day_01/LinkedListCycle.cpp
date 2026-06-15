// using HashMap
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        unordered_map<ListNode*, int> nodeMap;
        while(temp != NULL) {
            if(nodeMap.find(temp) != nodeMap.end()) {
                return true;
            }
            nodeMap[temp] = 1;
            temp = temp->next;
        } 
        return false;
    }
};

//Using Two Pointers
class Solution {
public:
    bool hasCycle(ListNode *head) {
      if(head == NULL || head->next == NULL) return false;
      ListNode* slow = head;
      ListNode* fast = head;
      while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
      } 
      return false; 
    }
};
