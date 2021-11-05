#define     HASH_SIZE   11
#define     ABS(a)      ((a) > 0 ? (a) : (0 - (a)))
//元素定义
struct HashListNode {
	int key;                //key值
	int val;                //value值
};

/*1.链表定义*/
typedef struct Hash_Node 
{
	struct HashListNode*    pNode;              //当前值
	struct Hash_Node*       pNext;              //下一个指针
}HashNode;

/*2.哈希表定义*/
typedef struct Hash_Table 
{
	int  iNodeSize;					//存入元素个数
	struct Hash_Node** pHashHead;   //Hash表指针
}HashTable,*LinkHashTable;

/*3.哈希链表初始化*/
bool HashTableInit(LinkHashTable * pHashTable) 
{
	(*pHashTable) = (HashTable*)malloc(sizeof(HashTable));
	if (NULL == (*pHashTable)) return false;

	(*pHashTable)->iNodeSize = 0;
	(*pHashTable)->pHashHead = (HashNode**)malloc(sizeof(HashNode*) * HASH_SIZE);
	if (NULL == (*pHashTable)->pHashHead) return false;
	memset((*pHashTable)->pHashHead, 0x00, sizeof(HashNode*) * HASH_SIZE);
	return true;
}

/*4.哈希表元素插入*/
bool HashTableInsert(LinkHashTable pHashTable, int key, int value) 
{
	long                    iKey = 0;
	HashNode*				pTmpNode = NULL;
	struct HashListNode*    pNode = NULL;

	pNode = (struct HashListNode*)malloc(sizeof(struct HashListNode));
	if (NULL == pNode) return false;
	pNode->key = key;
	pNode->val = value;

	iKey = (long)key;
	iKey = ABS(iKey) % HASH_SIZE;
	if (NULL == pHashTable->pHashHead[iKey])
	{
		pHashTable->pHashHead[iKey] = (HashNode*)malloc(sizeof(HashNode));
		if (NULL == pHashTable->pHashHead[iKey]) return false;

		pHashTable->pHashHead[iKey]->pNode = pNode;
		pHashTable->pHashHead[iKey]->pNext = NULL;
	}
	else
	{
		pTmpNode = pHashTable->pHashHead[iKey];
		while ((NULL != pTmpNode) && (NULL != pTmpNode->pNext))
		{
			if (key == pTmpNode->pNode->key)
			{
				pTmpNode->pNode->val = value;
				return true;
			}
			pTmpNode = pTmpNode->pNext;
		}

		if (key == pTmpNode->pNode->key)
		{
			pTmpNode->pNode->val = value;
			return true;
		}
		else
		{
			pTmpNode->pNext = (HashNode*)malloc(sizeof(HashNode));
			if (NULL == pTmpNode->pNext) return false;

			pTmpNode = pTmpNode->pNext;
			pTmpNode->pNode = pNode;
			pTmpNode->pNext = NULL;
		}
	}
	pHashTable->iNodeSize += 1;
	return true;
}

/*5.取出哈希表元素*/
struct Hash_Node* GetHashNode(LinkHashTable pHashTable, int key) {
	long                iKey = 0;
	HashNode*   pTmpNode = NULL;

	iKey = (long)key;
	iKey = ABS(iKey) % HASH_SIZE;
	pTmpNode = pHashTable->pHashHead[iKey];

	while (NULL != pTmpNode)
	{
		if ((NULL != pTmpNode->pNode) && (key == pTmpNode->pNode->key))
		{
			return pTmpNode;
		}
		else
		{
			pTmpNode = pTmpNode->pNext;
		}
	}

	return NULL;
}

/*6.哈希表元素删除*/
bool hashTableDel(LinkHashTable pHashTable, int key) {
	long                iKey = 0;
	HashNode*   pTmpNode = NULL;
	HashNode*   pNextNode = NULL;

	if (NULL == pHashTable) return false;

	iKey = (long)key;
	iKey = ABS(iKey) % HASH_SIZE;
	pTmpNode = pHashTable->pHashHead[iKey];

	while (NULL != pTmpNode)
	{
		if ((NULL != pTmpNode->pNode) && (key == pTmpNode->pNode->key))
		{
			pNextNode = pTmpNode->pNext;
			free(pTmpNode->pNode);
			pTmpNode->pNode = NULL;
			pTmpNode->pNext = pNextNode;
			pHashTable->iNodeSize -= 1;
			break;
		}
		else
		{
			pTmpNode = pTmpNode->pNext;
		}
	}

	return true;
}

/*7.哈希表的释放*/
void freeHashTable(LinkHashTable pHashTable) {
	int                 i = 0;
	HashNode*   pTmpNode = NULL;
	HashNode*   pNextNode = NULL;

	if (NULL == pHashTable) return;

	for (i = 0; i < HASH_SIZE; i++)
	{
		pTmpNode = pHashTable->pHashHead[i];
		while (NULL != pTmpNode)
		{
			pNextNode = pTmpNode->pNext;
			if (NULL != pTmpNode->pNode)
			{
				free(pTmpNode->pNode);
				pTmpNode->pNode = NULL;
			}
			free(pTmpNode);
			pTmpNode = pNextNode;
		}
		pHashTable->pHashHead[i] = NULL;
	}
	return;
}
int majorityElement(int* nums, int numsSize)
{
    int     i = 0;
	int     iRet = 0;

	HashNode*       pTmpNode = NULL;
	HashTable*      pHashTable = NULL;

	if (false == HashTableInit(&pHashTable)) return -1;

	if (NULL == nums) return -1;
	if (numsSize < 2) return nums[0];

	for (i = 0; i < numsSize; i++)
	{
		pTmpNode = GetHashNode(pHashTable, nums[i]);
		if (NULL == pTmpNode)
		{
			HashTableInsert(pHashTable, nums[i], 1);
		}
		else
		{
			pTmpNode->pNode->val += 1;

			if (pTmpNode->pNode->val > (numsSize / 2))
			{
				iRet = nums[i];
				break;
			}
		}
	}

	freeHashTable(pHashTable);
	pHashTable = NULL;
	return iRet;
}