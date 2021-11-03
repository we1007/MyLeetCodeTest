//用哈希表（除留余数法+拉链法）
#define HASH_SIZE 99
#define ABS(a) ((a) > 0?(a):(0-(a)))
/*1.链表定义*/
typedef struct HashNode
{
    int key;
    int val;
    struct HashNode *next;
}HashNode,*LinkHashNode;

/*2.哈希表定义*/
typedef struct HashTable
{
    int iNodeSize; //存入元素个数
    struct HashNode **pHashHead;
}HashTable,*LinkHashTable;

/*3.哈希链表初始化*/
bool HashTableInit(LinkHashTable *pHashTable)
{
    pHashTable = (LinkHashTable)malloc(sizeof(HashTable)); //创建哈希表头节点
    if(pHashTable == NULL)return -1;
    pHashTable->iNodeSize = 0;
    pHashTable->pHashHead = (LinkHashNode)malloc(sizeof(HashNode*)*HASH_SIZE); //创建哈希表中的元素的链表头节点
    if(pHashTable->pHashHead == NULL)return -1;
    memset(pHashTable->pHashHead,0x00,sizeof(HashNode*)*HASH_SIZE);
    return 1;
} 

/*4.哈希表元素插入*/
bool HashTableInsert(LinkHashTable pHashTable,int key,int value)
{
    long iKey = 0;
    HashNode *pN = NULL; //新结点

    pN = (HashNode*)malloc(sizeof(HashNode));  //新建结点
    if(pN == NULL)return -1;

    iKey = (long)key;
    iKey = ABS(iKey) % HASH_SIZE;

    if(pHashTable->pHashHead[iKey] == NULL)
    {
        pHashTable->pHashHead[iKey] = (HashNode*)malloc(sizeof(HashNode)); //根据关键字新建节点
        if(pHashTable->pHashHead[iKey] == NULL)return -1;

        pHashTable->pHashHead[iKey]->key = key;
        pHashTable->pHashHead[iKey]->val = val;
        pHashTable->pHashHead[iKey]->next = NULL; 
    }
    else
    {
        pN = pHashTable->pHashHead[iKey];
        while((pN !== NULL)&&(pN->next != NULL))
        {
            if(key == pN->key)
            {
                pN->val = value;
                return 1;
            }
            pN = pN->next;
        }

        if(key = pN->key)
        {
            pN->val = value;
            return 1;
        }
        else 
        {
            pN-next = (HashNode*)malloc(sizeof(HashNode));
            if(pN == NULL)return -1;

            pN = pN-next;
            pN->val = value;
            pN->key = key;
            pN->next = NULL;
        }
    }
    pHashTable->iNodeSize += 1;
    return 1;
}

/*5.取出哈希表元素*/
struct LinkHashNode GetHashNode(LinkHashTable pHashTable,int key)
{
    long iKey = 0;
    HashNode *pN = NULL;

    iKey = (long)key;
    iKey = ABS(iKey) % HASH_SIZE;
    pN = pHashTable->pHashHead[iKey];

    while(pN != NULL)
    {
        if(pN->key == key)
            return pN;
        else 
            pN = pN->next;
    }
    return NULL;
}


int majorityElement(int* nums, int numsSize)
{
    int size,i;
    size = numsSize/2; 
    


}
