/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head{nullptr};
        ListNode* tail{nullptr};

        if(list1 == nullptr) return  list2;
        if(list2 == nullptr) return  list1;

        if(list1->val < list2->val){
            head = list1;
            list1 = list1->next;
        }
        else{
            head = list2;
            list2 = list2->next;
        }
        tail = head;
        cout<<"head == tail:"<<head->val<<endl;


        //important learning: this 2 can be extracted out! - this while continues till   BOTH  ARE NOT NULLPTR!
        while(list1 != nullptr && list2 != nullptr){
#if 0
        if(list1 == nullptr){
            tail->next = list2;
            //list2 = nullptr; => continue replaced with break.This is unnecessary
            //continue;
            //continue;
            break; //important :When job is DONE, just break - No need of continue to exit while!
        }
        else if(list2 == nullptr){
            tail->next = list1;
            //list1 = nullptr; => continue replaced with break.This is unnecessary
            //continue;
            break; //important :When job is DONE, just break - No need of continue to exit while!
        }
#endif
        if(list1->val < list2->val){
            tail->next = list1;
            list1 = list1->next;      
        }
        else{
            tail->next = list2;
            list2 = list2->next;     
        }
        tail = tail->next;
        cout<<"next tail:"<<tail->val<<endl;
        };

        tail->next = (list1 == nullptr) ? list2:list1;
        
        return head;
    }
};
