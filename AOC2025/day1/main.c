
#include <stdio.h>

int main() {
    FILE* fp = fopen("./input/input", "r");
    int pos = 50;
    int zero_times = 0;

    char * line = NULL;
    size_t len = 0;
    while(getline(&line, &len, fp) != -1){
        char dir;
        int clicks;
        sscanf(line, "%c%d", &dir, &clicks);

        if(pos == 0 && dir == 'L') {
            zero_times--;
        }

        pos += (dir == 'R') ? clicks : -clicks;

        if(pos == 0) {
            zero_times++;
        }
        while(pos < 0) {
            pos += 100;
            zero_times++;
        }
        while(pos >= 100) {
            pos -= 100;
            zero_times++;
        }
    }
    printf("%d\t%d\n", pos, zero_times);
    return 0;
}