

#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

typedef struct {
    int stack1[1000];
    int stack2[1000];
    int top1;
    int top2;
} CQueue;


CQueue* cQueueCreate() {
    CQueue *obj = (CQueue*) malloc(sizeof(CQueue));
    obj->top1 = 0;
    obj->top2 = 0;
    return obj;
}

void cQueueAppendTail(CQueue* obj, int value) {
    obj->stack1[obj->top1++] = value;
}

int cQueueDeleteHead(CQueue* obj) {
      if (obj->top2 > 0)
        return obj->stack2[--obj->top2];

    if (obj->top1 == 0)
        return -1;
  
    while (obj->top1 > 0)
    {
        obj->stack2[(obj->top2)++] = obj->stack1[--obj->top1];
    }
    return obj->stack2[--obj->top2];
}

void cQueueFree(CQueue* obj) {
    free(obj);
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/