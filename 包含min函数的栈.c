#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"
/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackMin(obj);
 
 * minStackFree(obj);
*/
typedef struct {
    int x_stack[1000];
    int min_stack[1000];
    int x_top;
    int min_top;
    int min_val;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->x_top = obj->min_top = -1;
    obj->min_val = 0;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->x_top < 999)
    {
        if(obj->x_top == -1)
            obj->min_val = x;
        obj->x_stack[++obj->x_top] = x;
        if (x < obj->min_val)
            obj->min_val = x;
        obj->min_stack[++obj->min_top] = obj->min_val;
    }

}

void minStackPop(MinStack* obj) {
    obj->x_top--;
    obj->min_top--;
    if (obj->min_top != -1)
        obj->min_val = obj->min_stack[obj->min_top];
}

int minStackTop(MinStack* obj) {
    return obj->x_stack[obj->x_top];
}

int minStackMin(MinStack* obj) {
    return obj->min_stack[obj->min_top];
}

void minStackFree(MinStack* obj) {
    free(obj);
}