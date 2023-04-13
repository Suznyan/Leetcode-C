int fib(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    int one = 1, two = 1, next;
    for (int i = 2; i <= n; i++) 
        next = one + two, one = two, two = next;
    return one;
}