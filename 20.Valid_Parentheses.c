#define STACK_EMPTY INT_MIN

typedef struct{
    char *val;
    int top, size;
}stack;

void init_stack(stack *st, int max_size){
    st->val = malloc(sizeof(char)*max_size);
    st->top = 0;
    st->size = max_size;
}

int stack_empty(stack *st) {return (st->top==0);}
int stack_full(stack *st) {return (st->top == st->size);}

int push(stack *st, char value){
    if(stack_full(st)) return -1; 
    st->top++;
    st->val[st->top] = value;
    return 1;
}

char pop(stack *st){
    if(stack_empty(st)) return '\0';
    char value = st->val[st->top];
    st->top--;
    return value;
}

bool isValid(char * s){
    stack Stack;
    init_stack(&Stack,100000);
    while(*s != '\0'){
        if(*s == '{' || *s == '(' || *s == '[') 
            push(&Stack, *s);
        if(*s == '}' && pop(&Stack) != '{') 
            return false;
        if(*s == ')' && pop(&Stack) != '(') 
            return false;
        if(*s == ']' && pop(&Stack) != '[') 
            return false;
        s++;
    }
    if(!stack_empty(&Stack)) return false;
    return true;
}