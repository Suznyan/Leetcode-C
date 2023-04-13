#include <stdbool.h>
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if (n <= 0) return true;
    if (flowerbedSize <= 1) return *flowerbed == 0 ? true : false;

    for (int i = 0; i < flowerbedSize; i++) {
        if (n == 0) return true;
        if (flowerbed[i] == 0) {
            if (i == 0) {
                if (flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            } else if (i == flowerbedSize - 1) {
                if (flowerbed[i - 1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            } else {
                if (flowerbed[i + 1] == 0 && flowerbed[i - 1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
    }
    return n ? false : true;
}
