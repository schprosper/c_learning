#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum{
    HASH_OK, // 操作成功，通用成功状态
    HASH_ERROR,//失败
    HASH_ADDED,//新元素添加成功
    HASH_REPLACED_VALUE,// key 已存在，旧 value 被新 value 替换
    HASH_ALREADY_ADDED,//元素已经存在，没有重复添加
    HASH_DELETED,//删除成功
    HASH_NOT_FOUND,//没找到对应元素
} HASH_RESULT;

//哈希表中的一个条目。Entry：条目、项、记录
typedef struct __HashEntry HashEntry;
struct __HashEntry{
    union{
        char  *str_value;
        double dbl_value;
        int       int_value; //右边是起了个别名
    } key;
    union{
        char  *str_value;
        double dbl_value;
        int       int_value;
        long   long_value;
        void  *ptr_value;
    } value;
    HashEntry *next;//处理冲突元素
};


/*union语法
：同一块内存，可以用不同类型来解释。只能保存一种值。
一个哈希表节点的 key 可以是字符串、浮点数或整数；
value 可以是字符串、浮点数、整数、长整数或指针。
*/

struct __HashTable{
    HashEntry **bucket;  
    //是一个数组的起点指针。
    //这是一个 HashEntry类型的数组（桶数组）      
    int size; // 桶数组的大小
    HASH_RESULT last_error;//最近一次操作状态
};
typedef struct __HashTable HashTable;

// 创建大小为hash_size的哈希表，创建成功后返回HashTable类型的指针，否则返回NULL。
HashTable *create_hash(int hash_size);

/*
哈希表相关说明：
HASH_RESULT 类型为相关函数的返回类型
HashEntry 为哈希表所保存元素（即键值对 《key, value》）类型
HashTable 为哈希表，其中 bucket 指向大小为size的、元素类型为 HashEntry*的指针数组
哈希表采用链地址法处理冲突
请实现 create_hash 函数，创建指定大小的哈希表。
*/
/*
哈希表数据结构：
1. bucket[0] ； bucket[1]，里面只存储 相同key值的 HashEntry指针。
2. HashEntry指针，为同key链表的头结点，指向真正的数据。

*/



HashTable* create_hash(int size) {
    if (size <= 0) {
        return NULL;
    }

    HashTable* hash_table = (HashTable*)malloc(sizeof(HashTable));
    if (hash_table == NULL) {
        return NULL;
    }

    hash_table->bucket = (HashEntry**)malloc(size * sizeof(HashEntry*));
    if (hash_table->bucket == NULL) {
        free(hash_table);
        return NULL;
    }

    memset(hash_table->bucket, 0, size * sizeof(HashEntry*));
    //批量内存初始化,针对存储内存地址的数组。
    //把 hash_table->bucket 指向的那一整片内存，全部填成 0
    //memset(起始地址, 填什么值, 总共填多少字节)

    hash_table->size = size;
    hash_table->last_error = HASH_OK;

    return hash_table;
}


//有两个错误.........见函数结尾
HashTable* create_hash(int size)
{
    if(size<=0)
    {
        return NULL;
    }
    
    HashTable* hash_table = (HashTable*)malloc(sizeof(HashTable));
    if(hash_table == NULL)
    {
        return NULL ;
    }

    hash_table->bucket = (HashEntry**)malloc(size * sizeof(HashEntry*));

    if(hash_table->bucket == NULL)
    {
        free(hash_table);
        return NULL ;
    }

    for(int i =0; i<size; i++)
    {
        hash_table->bucket[i] = NULL;
    }

    hash_table->size = size;
    hash_table->last_error = HASH_OK;

    return hash_table;
}
// 一个是 hash_table->bucket[i] == NULL;
//一个是，忘记写 size ， last_error 初始化，需要你把所有相关的变量元素都初始化一遍
// 到时候可以根据这个来检查初始化是否成立









//===============================哈希添加===========================
// 向哈希表中添加元素，其中键类型为char*， 元素类型为int。
HASH_RESULT hash_add_int(HashTable * table, const char * key, int value);
/*
请实现 hash_add_int 函数，向哈希表中添加元素.
其中键类型为char*元素类型为int。
在添加过程中，如果要添加的键值key已在哈希表中，且对应的值value也已存在，
则函数返回 HASH_ALREADY_ADDED；
如果要添加的键值key已在哈希表中，但对应的值value不同，
则函数将value值更新到哈希表中，之后返回 HASH_REPLACED_VALUE；
如果要添加的键值key不在哈希表中，则函数创建 HashEntry 类型，
并将其加入到哈希表中，且函数返回 HASH_ADDED。本题所用的哈希函数如下：
*/
long hash_string(const char *str)
{
    long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    if(hash < 0)
        hash *= -1;
    return hash;
}

/*
key 是用来查找的名字，value是key的具体数据

*/
HASH_RESULT hash_add_int(HashTable* table, const char* key, int value)
{
    long hash_value = hash_string(key);
    int index = hash_value % table->size; //取余类的哈希表，%自己的大小。

    HashEntry* p = table->bucket[index]; //节点
    // 其中index是哈希坐标,p直接存入了数据
    // 哈希坐标相同的情况下，去找具体key值——index = 4 'Tom' 174 
    while (p != NULL)
    {
        if (strcmp(p->key.str_value, key) == 0)//返回0表示相等
        {
            if (p->value.int_value == value)
            {
                return HASH_ALREADY_ADDED;
                //如果 key 相同，value 也相同：已经加过了。
            }
            else
            {
                p->value.int_value = value;
                return HASH_REPLACED_VALUE;
                //如果 key 相同，value 不同：更新旧值。
            }
        }
        p = p->next;
    }

    HashEntry* new_entry = (HashEntry*)malloc(sizeof(HashEntry));
    if (new_entry == NULL)
    {
        return HASH_ERROR;
    }

    new_entry->key.str_value = (char*)malloc(strlen(key) + 1);
    //给key单独malloc一块，因为k不一定相同
    if (new_entry->key.str_value == NULL)
    {
        free(new_entry);
        return HASH_ERROR;
    }

    strcpy(new_entry->key.str_value, key);
    //头插法
    new_entry->value.int_value = value;

    new_entry->next = table->bucket[index];
    // 你会发现这里的头结点是存值的
    
    table->bucket[index] = new_entry;

    return HASH_ADDED;
}


HASH_RESULT hash_add_int(HashTable * table, const char * key, int value)
{
    long hash = hash_string(key);
    int index = hash % table->size;

    //是否有节点
    HashEntry* p = table->bucket[index];
    while(p != NULL)
    {
        if(strcmp(p->key.str_value, key) == 0)
        {
            if(p->value.int_value == value)
            {
                return HASH_ALREADY_ADDED;
            }
            else
            {
                p->value.int_value = value;
                return HASH_REPLACED_VALUE;
            }
        }

        p = p->next;
    }

    //如果没有怎么做---新建节点，头插法（不用检测末位置，很方便）

    HashEntry* new_entry = (HashEntry*)malloc(sizeof(HashEntry));
    if(new_entry ==NULL){return HASH_ERROR;}

    new_entry->key.str_value = (char*)malloc(sizeof(strlen(key) +1 )) ;
    //你会发现，但凡用到key，后面必须跟一个东西，因为key是union，不算数据类型

    if(new_entry->key.str_value == NULL)
    {free(new_entry);return HASH_ERROR;}

    //头插法
    strcpy(new_entry->key.str_value, key);
    new_entry->value.int_value =  value;

    new_entry->next = table->bucket[index];
    table->bucket[index] = new_entry;

    return HASH_ADDED;

    
}

