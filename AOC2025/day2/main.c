#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const char *const re = "/d*-/d*";

int main() {
    FILE* fp = fopen("./input/input", "r");
    long sum = 0;
    long a, b;
    long ah = -1;
    long bh = -1;
    while(fscanf(fp, "%ld-%ld,", &a, &b) > 0){
	    printf("%ld\t%ld\n", a, b);
	    int a_str_len;
	    char a_str[50];
	    a_str_len = sprintf(a_str, "%ld", a);
	    if(a_str_len % 2 == 0) {
		int a_half_len = a_str_len / 2;
		memcpy(a_str + a_half_len, a_str, a_half_len);
		ah = atol(a_str);
		if(ah >= a && ah <= b) {
			sum += ah;
			printf("%ld\n", ah);
		}
  	    }
 	    int b_str_len;
	    char b_str[50];
	    b_str_len = sprintf(b_str, "%ld", b);
	    if(b_str_len % 2 == 0) {
		int b_half_len = b_str_len / 2;
		memcpy(b_str + b_half_len, b_str, b_half_len);
		bh = atol(b_str);
		if(bh >= a && bh <= b && bh != ah) {
			sum += bh;
			printf("%ld\n", bh);
		}
  	    }   
    }
    printf("%ld\n", sum);
    return 0;
}
