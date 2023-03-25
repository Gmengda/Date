
typedef struct stack
{
    int* top;
    int capacity;
    int size;
}ST;

typedef struct {
    ST t1;
    ST t2;
} MyQueue;

void queueinit(ST* m)
{
    assert(m);
    m->top = (int*)malloc(sizeof(int) * 4);
    m->size = 0;
    m->capacity = 4;
}

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    if(queue == NULL)
    {
        perror("create malloc fail");
        return NULL;
    }
    queueinit(&queue->t1);
    queueinit(&queue->t2);
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    assert(obj);
    if(obj->t2.size != 0)
    {
        while(obj->t2.size)
        {
            if(obj->t1.size == obj->t1.capacity)
            {
                int* tem = (int*)realloc(obj->t1.top,sizeof(int)*obj->t1.capacity*2);
                if(tem == NULL)
                {
                    perror("push malloc");
                    return;
                }
                obj->t1.top = tem;
            }
            obj->t1.top[obj->t1.size] = obj->t2.top[obj->t2.size];
            obj->t1.size++;
            obj->t2.size--;
        }
    }
    if(obj->t1.size == obj->t1.capacity)
    {
        int* tem = (int*)realloc(obj->t1.top,sizeof(int)*obj->t1.capacity*2);
        if(tem == NULL)
        {
            perror("push malloc");
            return;
        }
        obj->t1.top = tem;
    }
    obj->t1.top[obj->t1.size] = x;
    obj->t1.size++;

}

int myQueuePop(MyQueue* obj) {
    assert(obj);
    int m = obj->t1.top[0];
    for(int i = 0; i < obj->t1.size - 1; i++)
    {
        obj->t1.top[i] = obj->t1.top[i + 1];
    }
    obj->t1.size--;

    return m;
}

int myQueuePeek(MyQueue* obj) {
    assert(obj);
    return obj->t1.top[0];
}

bool myQueueEmpty(MyQueue* obj) {
    assert(obj);
    if(obj->t1.size == 0)
    {
        return true;
    }
    return false;
}

void myQueueFree(MyQueue* obj) {

}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/