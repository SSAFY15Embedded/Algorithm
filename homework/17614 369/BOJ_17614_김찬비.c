#include <stdio.h>
#include <string.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int cnt = 0;
    char buf[12];

    for (int i = 1; i <= N; i++) {
        sprintf(buf, "%d", i);         
        for (int j = 0; buf[j]; j++) { 
            if (buf[j] == '3' || buf[j] == '6' || buf[j] == '9')
                cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}
