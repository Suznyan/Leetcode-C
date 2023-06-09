#define SIZE 500

typedef struct {
    int r;
    int c;
} my_data;
my_data queue[SIZE * SIZE];
my_data stack[SIZE * SIZE];
my_data EMPTY = {-2147483647, -2147483647};

typedef struct {
    my_data *val;
    int head, tail, entries, size;
} queue_struct;

typedef struct {
    my_data *val;
    int top, entries, size;
} stack_struct;

int init_stack(stack_struct *s, int size) {
    s->val = &stack[0];
    s->entries = 0;
    s->size = size;
    s->top = -1;
    return 1;
}

int init_queue(queue_struct *q, int size) {
    q->val = &queue[0];
    q->entries = q->head = q->tail = 0;
    q->size = size;
    return 1;
}

int stack_empty(stack_struct *s) { return (s->entries == 0); }
int stack_full(stack_struct *s) { return (s->entries == s->size); }

int stack_push(stack_struct *s, int val1, int val2) {
    if (stack_full(s)) return -1;
    s->top++;
    s->val[s->top].r = val1;
    s->val[s->top].c = val2;
    s->entries++;
    return 1;
}

my_data stack_pop(stack_struct *s) {
    if (stack_empty(s)) return EMPTY;
    my_data value = {s->val[s->top].r, s->val[s->top].c};
    s->top--;
    s->entries--;
    return value;
}

int stack_clear(stack_struct *s) {
    while (!stack_empty(s)) {
        stack_pop(s);
    }
    return 1;
}

int queue_empty(queue_struct *q) { return (q->entries == 0); }
int queue_full(queue_struct *q) { return (q->entries == q->size); }

int enQueue(queue_struct *q, int val1, int val2) {
    if (queue_full(q)) return -1;
    q->val[q->tail].r = val1;
    q->val[q->tail].c = val2;
    q->tail = (q->tail + 1) % q->size;
    q->entries++;
    return 1;
}

my_data deQueue(queue_struct *q) {
    if (queue_empty(q)) return EMPTY;
    my_data val = {q->val[q->head].r, q->val[q->head].c};
    q->head = (q->head + 1) % q->size;
    q->entries--;
    return val;
}

int countSubIslands(int **grid1, int grid1Size, int *grid1ColSize, int **grid2,
                    int grid2Size, int *grid2ColSize) {
    queue_struct q;
    stack_struct s;
    init_queue(&q, *grid1ColSize * grid1Size);
    init_stack(&s, *grid1ColSize * grid1Size);
    int ans = 0;
    int path[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < grid2Size; i++) {
        for (int j = 0; j < *grid2ColSize; j++) {
            int flag = 0;
            if (grid2[i][j] == 1 && grid1[i][j] == 0) flag = 1;
            if (grid2[i][j] == 1) {
                grid2[i][j] = 0;
                stack_push(&s, i, j);
                enQueue(&q, i, j);
                while (!queue_empty(&q)) {
                    my_data val = deQueue(&q);
                    for (int c = 0; c < 4; c++) {
                        int R = val.r + path[c][0], C = val.c + path[c][1];
                        if (R < 0 || C < 0 || R >= grid1Size ||
                            C >= *grid1ColSize)
                            continue;
                        if (grid2[R][C] == 1 && grid1[R][C] == 0) flag = 1;
                        if (grid2[R][C] == 1) {
                            enQueue(&q, R, C);
                            stack_push(&s, R, C);
                            grid2[R][C] = 0;
                        }
                    }
                }
                if (flag == 0)
                    while (!stack_empty(&s)) {
                        my_data val = stack_pop(&s);
                        grid2[val.r][val.c] = 1;
                    }
                stack_clear(&s);
            }
        }
    }

    for (int i = 0; i < grid1Size; i++) {
        for (int j = 0; j < *grid1ColSize; j++) {
            if (grid2[i][j] != 1) continue;
            enQueue(&q, i, j);
            grid2[i][j] = 0;
            while (!queue_empty(&q)) {
                my_data val = deQueue(&q);

                for (int p = 0; p < 4; p++) {
                    int R = val.r + path[p][0], C = val.c + path[p][1];
                    if (R < 0 || C < 0 || R >= grid1Size || C >= *grid1ColSize)
                        continue;
                    if (grid2[R][C] != 1) continue;
                    enQueue(&q, R, C);
                    grid2[R][C] = 0;
                }
            }
            ans++;
        }
    }
    return ans;
}