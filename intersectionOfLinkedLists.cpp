/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ta = headA, *tb = headB ,*temp;
        while(ta!=NULL && tb!=NULL){
            ta = ta->next;
            tb = tb->next;
        }
        if(ta == NULL){
            temp = headB;
            while(tb!=NULL){
                temp = temp->next;
                tb = tb->next;
            }
            tb = temp;
            ta = headA;
        }    
        else{
            temp = headA;
            while(ta!=NULL){
                temp = temp->next;
                ta = ta->next;
            }
            ta = temp;
            tb = headB;
        }
        while(ta!=NULL && tb!=NULL){
            if(ta == tb)
                return ta;
            ta = ta->next;
            tb = tb->next;
        }
        return NULL;
    }
};

// concise code, squeezed two while loops into one. 
class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ta = headA, *tb = headB ,*temp;
        while(ta!=NULL && tb!=NULL){
            if(ta == tb)
                return ta;
            ta = ta->next;
            tb = tb->next;
            if(ta==NULL && tb==NULL)
                return NULL;
            if(ta==NULL)
                ta = headB;
            if(tb==NULL)
                tb = headA;
        }
        return NULL;
    }
};
