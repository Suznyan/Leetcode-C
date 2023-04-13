#include <stdio.h>
#include <stdlib.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int* map = malloc(sizeof(int) * gasSize);
    for (int start = 0; start < gasSize;) {
        int currGas = 0, currPos = start;
        map[currPos] = 0;
        for (;;) {
            if (map[currPos] == 1) break;
            map[currPos] = 1;
            currGas += gas[currPos] - cost[currPos];
            currPos = (currPos + 1) % gasSize;
            if (currGas < 0) break;
            if (currPos == start) {
                free(map);
                map = NULL;
                return start;
            }
        }
        if (map[currPos] == 1) break;
        start = currPos;
    }
    free(map);
    map = NULL;
    return -1;
}

int main() { return 0; }