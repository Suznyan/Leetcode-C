typedef struct {
    int *val;
    int top, entries, size;
} Stack;
void Stack_init(Stack *S, int maxSize) {
    S->val = malloc(sizeof(int) * maxSize);
    S->top = -1;
    S->entries = 0;
    S->size = maxSize;
}
bool Stack_empty(Stack *S) { return (S->entries == 0); }
bool Stack_full(Stack *S) { return (S->entries == S->size); }
int Stack_push(Stack *S, int a) {
    if (Stack_full(S)) return -1;
    S->val[++S->top] = a;
    S->entries++;
    return 1;
}
int Stack_pop(Stack *S) {
    if (Stack_empty(S)) return INT_MIN;
    int temp = S->val[S->top--];
    S->entries--;
    return temp;
}
int Stack_peek(Stack *S) {
    if (Stack_empty(S)) return INT_MIN;
    int temp = S->val[S->top];
    return temp;
}
void Stack_destroy(Stack *S) { free(S->val); }

bool validateStackSequences(int *pushed, int pushedSize, int *popped, int poppedSize) {
    if (pushedSize != poppedSize) return false;
    Stack s;
    Stack_init(&s, pushedSize);
    int pushedIdx = -1;
    for (int i = 0; i < poppedSize; i++) {
        while (Stack_empty(&s) ||
               Stack_peek(&s) != popped[i] && pushedIdx < pushedSize - 1)
            Stack_push(&s, pushed[++pushedIdx]);
        if (Stack_peek(&s) == popped[i]) Stack_pop(&s);
    }
    bool ans = Stack_empty(&s);
    Stack_destroy(&s);
    return ans;
}