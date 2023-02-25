#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>


// 2-4
void squeeze(char s1[], char s2[]) {
    int i, j;
    for (i = j =0; s1[i] != '\0'; i++) {
        int match = 0;
        for (int n = 0; s2[n] != '\0'; n++) {
            if (s1[i] == s2[n]) {
                match = 1;
                break;
            }
        }
        if (!match)
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}

// 2-5
char* any(char* s1[], char* s2[]) {
    int i;
    for (i = 0; s1[i] != '\0'; i++) {
        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j])
                return s1[i];
        }
    }
    return NULL;
}

// Exercise 2.6 - Setting bits at a position n
int setbits(unsigned x, int p, int n, unsigned y) {
    int mask = ~(~0 << n);
    int shift = p + 1 - n;
    return x & ~(mask << shift) | (y & mask) << shift;
}

// int main(void)
// {
//   char *leftstr[] =
//   {
//     "",
//     "a",
//     "antidisestablishmentarianism",
//     "beautifications",
//     "characteristically",
//     "deterministically",
//     "electroencephalography",
//     "familiarisation",
//     "gastrointestinal",
//     "heterogeneousness",
//     "incomprehensibility",
//     "justifications",
//     "knowledgeable",
//     "lexicographically",
//     "microarchitectures",
//     "nondeterministically",
//     "organizationally",
//     "phenomenologically",
//     "quantifications",
//     "representationally",
//     "straightforwardness",
//     "telecommunications",
//     "uncontrollability",
//     "vulnerabilities",
//     "wholeheartedly",
//     "xylophonically", /* if there is such a word :-) */
//     "youthfulness",
//     "zoologically"
//   };
//   char *rightstr[] =
//   {
//     "",
//     "a",
//     "the",
//     "quick",
//     "brown",
//     "dog",
//     "jumps",
//     "over",
//     "lazy",
//     "fox",
//     "get",
//     "rid",
//     "of",
//     "windows",
//     "and",
//     "install",
//     "linux"
//   };

//   char buffer[32];
//   size_t numlefts = sizeof leftstr / sizeof leftstr[0];
//   size_t numrights = sizeof rightstr / sizeof rightstr[0];
//   size_t left = 0;
//   size_t right = 0;

//   for(left = 0; left < numlefts; left++)
//   {
//     for(right = 0; right < numrights; right++)
//     {
//       strcpy(buffer, leftstr[left]);

//       squeeze(buffer, rightstr[right]);

//       printf("[%s] - [%s] = [%s]\n", leftstr[left], rightstr[right], buffer);
//     }
//   }
//   return 0;
// }