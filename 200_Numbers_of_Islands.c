#define SIZE 300

typedef struct {
    int val1;
    int val2;
} location;
location queue[SIZE * SIZE];
location QUEUE_EMPTY = {-2147483647, -2147483647};

typedef struct {
    location *val;
    int head, tail, entries, size;
} queue_struct;

void initQueue(queue_struct *q, int size) {
    q->val = &queue[0];
    q->head = 0;
    q->tail = 0;
    q->entries = 0;
    q->size = size;
}

int queue_empty(queue_struct *q) { return (q->entries == 0); }
int queue_full(queue_struct *q) { return (q->entries == q->size); }

int enQueue(queue_struct *q, int val1, int val2) {
    if (queue_full(q)) return -1;
    q->val[q->tail].val1 = val1;
    q->val[q->tail].val2 = val2;
    q->tail = (q->tail + 1) % q->size;
    q->entries++;
    return 1;
}

location deQueue(queue_struct *q) {
    if (queue_empty(q)) return QUEUE_EMPTY;
    location dQval = {q->val[q->head].val1, q->val[q->head].val2};
    q->head = (q->head + 1) % q->size;
    q->entries--;
    return dQval;
}

int numIslands(char **grid, int gridSize, int *gridColSize) {
    int path[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int ans = 0;
    queue_struct Queue;
    location out;
    initQueue(&Queue, (*gridColSize * gridSize));
    for (int r = 0; r < gridSize; r++) {
        for (int c = 0; c < *gridColSize; c++) {
            if (grid[r][c] != '1') continue;
            ans++;
            enQueue(&Queue, r, c);
            grid[r][c] = '0';
            while (!queue_empty(&Queue)) {
                out = deQueue(&Queue);
                int R = out.val1, C = out.val2;
                for (int i = 0; i < 4; i++) {
                    int R = out.val1 + path[i][0], C = out.val2 + path[i][1];
                    if (R < gridSize && R >= 0 && C >= 0 && C < *gridColSize &&
                        grid[R][C] == '1') {
                        enQueue(&Queue, R, C);
                        grid[R][C] = '0';
                    }
                }
            }
        }
    }
    return ans;
}