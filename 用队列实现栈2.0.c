
typedef struct queuenode
{
    struct queuenode* next;
    int m;
}Qnode;

typedef struct que
{
    Qnode* head;
    Qnode* tail;
    int size;
}Queue;

typedef struct {
    Queue q1;
    Queue q2
} MyStack;

void Queueinit(Queue* m)
{
	assert(m);
	m->head = NULL;
	m->tail = NULL;
	m->size = 0;
}

MyStack* myStackCreate() {
    MyStack* tack = (MyStack*)malloc(sizeof(MyStack)); 
    if(tack == NULL)
    {
        perror("creat malloc");
        return NULL;
    }
    Queueinit(&tack->q1);
    Queueinit(&tack->q2);
    
    return tack;
}

void myStackPush(MyStack* obj, int x) {
    assert(obj);
    Qnode* tem = (Qnode*)malloc(sizeof(Qnode));
    if(tem == NULL)
    {
        perror("push malloc");
        return;
    }
    tem->next = NULL;
    tem->m = x;
    if(obj->q1.head == NULL)
    {
        obj->q1.head = obj->q1.tail = tem;
    }
    else
    {
        obj->q1.tail->next = tem;
        obj->q1.tail = tem;
    }
    obj->q1.size++;
}

int myStackPop(MyStack* obj) {
    assert(obj);
    assert(obj->q1.head != NULL);
    obj->q2.head = obj->q2.tail = NULL;
    obj->q2.size = 0;
    if(obj->q1.size == 1)
    {
        obj->q2.head = obj->q1.head;
        obj->q1.head = NULL;
        obj->q1.size = 0;
    }
    else
    {
        Qnode* move;
        while(obj->q1.size > 1)
        {
            move = obj->q1.head;
            if(obj->q2.head == NULL)
            {
                obj->q2.head = obj->q2.tail = move;
            }
            else
            {
                obj->q2.tail->next = move;
                obj->q2.tail = move;
            }
            obj->q1.head = obj->q1.head->next;
            obj->q1.size--;
            obj->q2.size++;
        }
        Queue c;
        c = obj->q1;
        obj->q1 = obj->q2;
        obj->q2 = c;
    }
    return obj->q2.head->m;
}

int myStackTop(MyStack* obj) {
    assert(obj);
    assert(obj->q1.head != NULL);

    return obj->q1.tail->m;

}

bool myStackEmpty(MyStack* obj) {
    assert(obj);
    if(obj->q1.size == 0)
    {
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {

}