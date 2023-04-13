#include <stdio.h>
#include <stdlib.h>

int numTeams(int* rating, int ratingSize) {
    int res = 0;

    for (int i = 0; i < ratingSize - 1; i++) {
        int Lgreater = 0, Lsmaller = 0, Rgreater = 0, Rsmaller = 0;
        for (int L = i - 1; L >= 0; L--) {
            if (rating[L] < rating[i])
                Lsmaller++;
            else if (rating[L] > rating[i])
                Lgreater++;
        }
        for (int R = i + 1; R < ratingSize; R++) {
            if (rating[R] > rating[i])
                Rgreater++;
            else if (rating[R] < rating[i])
                Rsmaller++;
        }
        res += (Lsmaller * Rgreater) + (Lgreater * Rsmaller);
    }
    return res;
}

int main() { return 0; }