/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
*/

 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}     ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) {// 0 node
            return nullptr;
        }
        ListNode* second = head->next;
        if (second == nullptr) { // 1 node
            return head;
        }
        // >=2 node
        head->next = swapPairs(second->next);
        second->next = head;
        return second;
    }
};