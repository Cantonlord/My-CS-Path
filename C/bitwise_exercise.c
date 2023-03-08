#include <stdio.h>
#include <stdlib.h>

int bitcount(unsigned x) {
    int i;
    for (i = 0; x != 0; x >>= 1) {
        if (x & 1)
            i++;
    }
    return i;
}

void setbit(int *num, int pos) {
    *num |= (1 << pos);
}

void unsetbit(int *num, int pos) {
    *num &= ~(1 << pos);
}

char *lower_bitwise(char *s) {
    for (int i = 0; s[i] != '\0'; i++)
        s[i] = s[i] | ' ';
    return s;
}

char *upper_bitwise(char *s) {
    for (int i = 0; s[i] != '\0'; i++)
        s[i] = s[i] & ~' '; // ' ' is SPACE and 32 in decimal
    return s;
}

char *mix_upper_lower(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] | ' ';
        else if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] & ~' ';
    }
    return s;
}

/*
Toggling means to turn bit ‘on'(1) if it was ‘off'(0) 
and to turn ‘off'(0) if it was ‘on'(1) previously.
*/
void togglebit(int *num, int pos) {
    *num ^= (1 << pos);
}

/*Stripping off the lowest set bit*/
void strip_last_set_bit(int *num) {
    *num &= (*num - 1);
}

/*Getting the lowest set bit of a number*/
void lowest_set_bit(int *num) {
    *num &= -*num; // Or *num &= -(~*num + 1)
}

void twos_complement(int *num) {
    *num = (~*num + 1);
}



int main() {
    int num = 255;
    printf("%d\n", bitcount(num));
}