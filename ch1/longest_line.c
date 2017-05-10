#include <stdio.h>
#define MAXLINE 10

int my_getline(char s[], int lim) {
    int c;
    int i;

    for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c!='\n'; i++) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        i++;
    }

    s[i] = '\0';

    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}

int main() {
    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);

            if (max == MAXLINE-1) {
                char c;
                while ((c=getchar()) != EOF && c != '\n') {
                    max++;
                }
                max++;
            }
        }

    }

    if (max > 0) {
        if (max >= MAXLINE-1)
            printf("count: %d, line: %s\n", max, longest);
        else
            printf("count: %d, line: %s", max, longest);
    }

    return 0;
}
