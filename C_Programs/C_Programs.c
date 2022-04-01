#include <stdio.h>
#include <math.h>

void PrintStar() {
    int n, star;

    printf("Enter number of rows: ");
    scanf("%d", star);

    for(int i = 1; i < 2*n; i++) {
        if(i < n)
            star = i;
        else
            star = abs(2*n-i); // Ensure we don't go negative
        for(int j = 0; j < star; j++)
            putchar('*');
        putchar('\n');
    }
}

void TwoPoints() {
    int x1, y1, x2, y2, x, y, distance;

    printf("Enter coordiantes of FIRST point: ");
    scanf("%d", "%d", &x1, &y1);

    printf("Enter coordiantes of SECOND point: ");
    scanf("%d", "%d", &x2, &y2);

    x = (x2-x1);
    y = (y2-y1);

    distance = sqrt((x*x) + (y*y));

    printf("Distance = %d", distance);
}

void Swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void ReverseString(const char * str) {
    int left = 0, right = strlen(str);
    while(left < right) {
        Swap(&str[left], &str[right]);
        left++;
        right--;
    }
}

int main() {
    // Enter function here:


    return 0;
}