#include <stdio.h>

int
main() {
    int N;
    scanf("%d", &N);
    for (int t=0; t<=N; t += 5) {
        for (int p=0; p/2 <= t/5 && t+p <= N ; p += 2) {
            int left = N - t - p;
            if ( left % 3 == 0)
                printf("%d %d %d\n", t/5, p/2, left/3);
        }
    }
}