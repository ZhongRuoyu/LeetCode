// Solved 2021-01-10 16:14
// Runtime: 28 ms (86.16%)
// Memory Usage: 12.8 MB (72.77%)

typedef struct MinStackElement {
    int val;
    int min;
    struct MinStackElement* prev;
} MinStackElement;

typedef struct {
    MinStackElement* top;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = (MinStackElement*)NULL;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    MinStackElement* nodeToPush = (MinStackElement*)malloc(sizeof(MinStackElement));
    nodeToPush->val = x;
    nodeToPush->prev = obj->top;
    nodeToPush->min = (!obj->top || x < obj->top->min) ? x : obj->top->min;
    obj->top = nodeToPush;
}

void minStackPop(MinStack* obj) {
    MinStackElement* nodeToPop = obj->top;
    obj->top = nodeToPop->prev;
    free(nodeToPop);
}

int minStackTop(MinStack* obj) {
    return obj->top->val;
}

int minStackGetMin(MinStack* obj) {
    return obj->top->min;
}

void minStackFree(MinStack* obj) {
    MinStackElement *curr = obj->top, *next;
    while (curr) {
        next = curr->prev;
        free(curr);
        curr = next;
    }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
