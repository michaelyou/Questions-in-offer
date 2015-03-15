/*һ����������֪�����ȣ�дһ�����������ҵ��м�ڵ��λ��*/

/*������������һ����ʵ���ٶ����һ����������ͬʱ������
����������·�̵��е㡣���Ծ��������ԭ��д�������������*/

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

