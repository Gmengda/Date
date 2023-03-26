

typedef struct {
    int* m;
    int top;
    int tail;
    int size;
    int capacity;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* sz = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if(sz == NULL)
    {
        perror("create malloc fail");
        return NULL;
    }
    sz->m = (int*)malloc(sizeof(int) * (k + 1));
    sz->top = 0;
    sz->tail = 0;
    sz->size = 0;
    sz->capacity = k;
    return sz;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    assert(obj);
    if(obj->size == obj->capacity)
    {
        return false;
    }
    else
    {
        obj->m[obj->tail] = value;
        obj->tail++;
        obj->size++;
        obj->tail %= obj->capacity;
    }
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);
    if(obj->size == 0)
    {
        return false;
    }
    else
    {
        obj->top++;
        obj->size--;
        obj->top %= obj->capacity;
    }
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    assert(obj);
    if(obj->size == 0)
    {
        return -1;
    }
    else
    {
        return obj->m[obj->top];
    }
}

int myCircularQueueRear(MyCircularQueue* obj) {
    assert(obj);
    if(obj->size == 0)
    {
        return -1;
    }
    else
    {
        if(obj->tail == 0)
        {
            return obj->m[obj->capacity - 1];
        }
        return obj->m[obj->tail - 1];
    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    assert(obj);
    if(obj->size == 0)
    {
        return true;
    }
    return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    assert(obj);
    if(obj->size == obj->capacity)
    {
        return true;
    }
    return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {

}
