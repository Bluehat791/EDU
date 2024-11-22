#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0),next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};


class Solution{
public:

    void mergeSort(ListNode **head){
        ListNode *curr = *head;

        ListNode * left;
        ListNode * right;

        if(curr == nullptr || curr->next == nullptr) return;

        findMiddle(curr, &left, &right);

        mergeSort(&left);

        mergeSort(&right);

        *head = merge(left,right);
    }

    void findMiddle(ListNode *curr, ListNode **left, ListNode **right){
        ListNode* slow = curr;
        ListNode* fast = curr->next;

        while (fast!=nullptr)
        {
            fast = fast->next;
            if(fast!=nullptr){
                fast = fast->next;
                slow=slow->next;
            }

        }
        *left = curr;
        *right = slow->next;

        slow-> next = nullptr;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* res = nullptr;

        if(left==nullptr) return right;
        if(right==nullptr) return left;

        if(left->val <= right->val){
            res=left;
            res->next = merge(left->next,right);
        } else {
            res = right;
            res->next = merge(left,right->next);
        }
        return res;
    }

    ListNode* sortList(ListNode* head){
        mergeSort(&head);
        return head;
    }
};


int main(){

}