/*一个单链表，不知道长度，写一个函数快速找到中间节点的位置*/

/*物理中有这样一个事实，速度相差一倍的两辆车同时出发，
慢车总是在路程的中点。所以就利用这个原理写了下面这个程序。*/

typedef struct node
{
    int data;
    struct node *next;
}*Node_t;

Node_t find_mid_of_list(Node_t head) {
    if(head == NULL || head->next == NULL)
        return NULL;

    Node_t p_fast = head->next;
    Node_t p_slow = head->next;

    while(p_fast->next != NULL && p_fast != NULL) {
        p_slow = p_slow->next;
        p_fast = p_fast->next->next;
    }

    return p_slow;
}

