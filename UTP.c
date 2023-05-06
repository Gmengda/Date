typedef struct DulNode {
    int key;
    int value;
    struct DulNode* pre;
    struct DulNode* next;
} DulNode;

typedef int(*hash_cal_f)(int capicity, int val);

typedef struct HashTableNode {
    DulNode* node;
    struct HashTableNode* next;
} HashTableNode;

typedef struct HashTable {
    int capacity;
    hash_cal_f hash_func;
    HashTableNode** bucket;
} HashTable;

typedef struct {
    int cur_node;
    HashTable* hash_table;
    DulNode* head;
    DulNode* tail;
} LRUCache;

int hash_cal(int capicity, int val)
{
    return val % capicity;
}

void InitHashTable(LRUCache* lruCache, int capacity)
{
    HashTable* hash_table = (HashTable*)malloc(sizeof(HashTable));
    if (hash_table == NULL)
    {
        printf("%s Malloc mem failed.\n", __func__);
        return;
    }
    hash_table->capacity = capacity;
    hash_table->hash_func = hash_cal;
    hash_table->bucket = (HashTableNode**)calloc(capacity, sizeof(HashTableNode*));
    if (hash_table->bucket == NULL)
    {
        printf("%s Malloc mem failed.\n", __func__);
        return;
    }
    lruCache->hash_table = hash_table;
}

void InitDoubleList(LRUCache* lruCache)
{
    // initialize Double link list header
    lruCache->head = (DulNode*)malloc(sizeof(DulNode));
    lruCache->head->key = -1;
    lruCache->head->value = -1;

    // initialize double link list tail node
    lruCache->tail = (DulNode*)malloc(sizeof(DulNode));
    lruCache->tail->key = -1;
    lruCache->tail->value = -1;

    lruCache->head->pre  = lruCache->tail;
    lruCache->head->next = lruCache->tail;

    lruCache->tail->pre  = lruCache->head;
    lruCache->tail->next = lruCache->head;
}

LRUCache* lRUCacheCreate(int capacity)
{
    LRUCache* lruCache = (LRUCache*)malloc(sizeof(LRUCache));
    if (lruCache == NULL)
    {
        printf("%s Malloc mem failed.\n", __func__);
        return NULL;
    }
    lruCache->cur_node = 0;
    InitHashTable(lruCache, capacity);
    InitDoubleList(lruCache);
    return lruCache;
}

void DulLinkLinkUpdateNode(DulNode* head, DulNode* node)
{
    if (node->pre == head)
    {
        return;
    }

    // delete node
    node->pre->next = node->next;
    node->next->pre = node->pre;

    // insert to the head of the double link list
    node->pre = head;
    node->next = head->next;
    node->next->pre = node;
    node->pre->next = node;
}

int lRUCacheGet(LRUCache* obj, int key)
{
    if (obj->cur_node == 0) {
        return -1;
    }

    // if have this element
    // 1. get this element
    int capacity = obj->hash_table->capacity;
    int h_index = (obj->hash_table->hash_func)(capacity, key);

    HashTableNode** bucket = obj->hash_table->bucket;
    HashTableNode* hash_node = bucket[h_index];

    while (hash_node && hash_node->node->key != key) {
        hash_node = hash_node->next;
    }

    if (hash_node && hash_node->node->key == key) {
        // 2. update double link list
        DulLinkLinkUpdateNode(obj->head, hash_node->node);
        return hash_node->node->value;
    }

    // if not have this element
    return -1;
}

void LRUCacheUpdateNode(LRUCache* obj, int key, int value)
{
    int cappacity = obj->hash_table->capacity;

    int index = (obj->hash_table->hash_func)(cappacity, key);
    HashTableNode** bucket = obj->hash_table->bucket;
    HashTableNode* hash_node = bucket[index];

    while (hash_node && hash_node->node->key != key) {
        hash_node = hash_node->next;
    }

    if (hash_node && hash_node->node->key == key)
    {
        hash_node->node->value = value;
        DulLinkLinkUpdateNode(obj->head, hash_node->node);
    }
}

void LRUCacheDelLastNode(LRUCache* obj)
{
    DulNode* del_node = obj->tail->pre;
    int key = del_node->key;

    // delete tail node from hashTable
    int capacity = obj->hash_table->capacity;
    int h_index = (obj->hash_table->hash_func)(capacity, key);
    HashTableNode** bucket = obj->hash_table->bucket;
    HashTableNode* hash_node = bucket[h_index];
    HashTableNode* pre_node = NULL;
    while (hash_node && hash_node->node->key != key) {
        pre_node = hash_node;
        hash_node = hash_node->next;
    }

    if (hash_node && hash_node->node->key == key) {
        if (pre_node != NULL) {
            pre_node->next = hash_node->next;
        } else {
            bucket[h_index] = hash_node->next;
        }

        // delete tail node from double link list
        del_node->pre->next = del_node->next;
        del_node->next->pre = del_node->pre;
        free(del_node);
        free(hash_node);
        --(obj->cur_node);
    }
}

void lRUCachePut(LRUCache* obj, int key, int value)
{
    // if cur LRUCache is full, update LRUCache
    int capacity = obj->hash_table->capacity;
    // if have this key, update value
    int ret = lRUCacheGet(obj, key);
    if (ret != -1) {
        LRUCacheUpdateNode (obj, key, value);
        return;
    }

    // if not find key and cache is full, delete oldest one
    if (ret == -1 && obj->cur_node >= capacity) {
        LRUCacheDelLastNode (obj);
    }

    // if not have this key, insert int the LRU
    // 1. insert to the Double Link List
    DulNode* node = (DulNode*) malloc (sizeof (DulNode) );
    node->key = key;
    node->value = value;

    DulNode* head = obj->head;
    node->pre = head;
    node->next = head->next;
    node->next->pre = node;
    node->pre->next = node;

    // 2. insert to the hashTable
    HashTableNode* new_node = (HashTableNode*) malloc (sizeof (HashTableNode) );
    if (!new_node) {
        free (node);
        printf ("Malloc mem failed.\n");
        return;
    }
    new_node->node = node;
    new_node->next = NULL;

    int h_index = (obj->hash_table->hash_func) (capacity, key);
    HashTableNode** bucket = obj->hash_table->bucket;
    HashTableNode* hash_node = bucket[h_index];
    if (hash_node == NULL) {
        bucket[h_index] = new_node;
    } else {
        new_node->next = hash_node->next;
        hash_node->next = new_node;
    }        // 3. add cur_node;
    (obj->cur_node)++;
}

void DulLinkLinkFree(DulNode* head)
{
    DulNode* cur_node = head->next;
    while (cur_node && cur_node != head->pre) {
        DulNode* del_node = cur_node;
        cur_node = cur_node->next;

        del_node->pre->next = del_node->next;
        del_node->next->pre = del_node->pre;
        free (del_node);
    }
    free(head->pre);
    free(head);
}

void HashTableNodeFree(LRUCache* obj)
{
    int capacity = obj->hash_table->capacity;
    int i = 0;
    for (; i < capacity; ++i) {
        HashTableNode* hash_node = obj->hash_table->bucket[i];
        while (hash_node) {
            HashTableNode* cur_node = hash_node->next;
            if (cur_node) {
                hash_node = cur_node->next;
                free (cur_node);
            } else {
                free(hash_node);
                break;
            }
        }
        obj->hash_table->bucket[i] = NULL;
    }
}

void lRUCacheFree (LRUCache* obj)
{
    DulLinkLinkFree(obj->head);
    HashTableNodeFree(obj);
    free(obj->hash_table->bucket);
    free(obj->hash_table);
}