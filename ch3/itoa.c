#include <stdio.h>
#include <string.h>

void reverse(char* s) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0)
        n = -n;

    i = 0;
    do {
        s[i++] = n %10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[100];

    itoa(5026, s);

    char c;
    for (int i = 0; (c = s[i]) != '\0'; i++) {
        printf("%c", s[i]);
    } printf("\n");
}

