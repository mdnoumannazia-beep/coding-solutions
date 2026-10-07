#include <stdio.h>

int main() {
    int a, b;
    float x, y;

    // Read the two integers and two floats
    if (scanf("%d %d", &a, &b) != 2) return 0;
    if (scanf("%f %f", &x, &y) != 2) return 0;

    // Output integer sum and difference
    printf("%d %d\n", a + b, a - b);

    // Output float sum and difference rounded to 1 decimal place
    printf("%.1f %.1f\n", x + y, x - y);

    return 0;
}
