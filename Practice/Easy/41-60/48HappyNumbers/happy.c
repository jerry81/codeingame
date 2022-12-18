#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


struct nlist2 { /* table entry: */
    struct nlist2 *next; /* next entry in chain */
    int name; /* defined name */
    int defn; /* replacement text */
};

#define HASHSIZE 101
struct nlist2 *hashtab2[HASHSIZE];
struct nlist2 *orig[HASHSIZE];

unsigned hash2(int i) {
  return i%HASHSIZE;
}

void reset_ht() {
  memcpy( hashtab2, orig, sizeof hashtab2 );
}

/* lookup: look for s in hashtab */
struct nlist2 *lookup2(int i)
{
    struct nlist2 *np;
    for (np = hashtab2[hash2(i)]; np != NULL; np = np->next) // NULL in C is null pointer
        if (i == np->name)
          return np; /* found */
    // printf("not found!");
    return NULL; /* not found */
}

struct nlist2 *install2(int name, int defn)
{
    struct nlist2 *np;
    unsigned hashval;
    if ((np = lookup2(name)) == NULL) { /* not found */
        np = (struct nlist2 *) malloc(sizeof(*np)); // malloc:
        /*
        void *malloc(size_t size)   <- void * means pointer of any type and is castable like the call above
        */
        if (np == NULL) // not exactly sure what this check is for
          return NULL;
        np->name = name;
        np->defn = defn;
        hashval = hash2(name);
        np->next = hashtab2[hashval];
        hashtab2[hashval] = np;
    } else
        np->defn = defn;
    return np;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 struct Answer {
   char label[129];
   char smiley[3];
 };

int main()
{
    int N;
    scanf("%d", &N); fgetc(stdin);
    struct Answer answers[N];
    char xs[N][129]; // TIL 2d array
    for (int i = 0; i < N; i++) {
        char x[129];
        scanf("%[^\n]", x); fgetc(stdin);
        strcpy(xs[i],x);
    }
    for (int i = 0; i < N; i++) {
        int firstsum = -1;
        struct Answer a;
        strcpy(a.label, xs[i]);
        int curi = 0;
        int sum = 0;
        while (xs[i][curi]) {
            int multiplier = xs[i][curi] - '0';
            int sq =  multiplier * multiplier;
            sum += sq;
            ++curi;
            // sum created
        }
        firstsum = sum;


        // options to convert to string
        // sprintf
        // log10 loop with modulo 10
        // itoa?
        // until firstsum reached again or sum becomes 1
        reset_ht();
        install2(firstsum,firstsum);
        bool repeat = false;
        while (sum != 1) {
        //   // must convert int, sum to chararr
          curi = 0;
          char asC[129];
          sprintf(asC,"%d", sum);
          sum = 0;
          while (asC[curi]) {
            int multiplier = asC[curi] - '0';
            int sq =  multiplier * multiplier;
            sum += sq;
            ++curi;
          }
          if (lookup2(sum) != NULL) {
            repeat = true;
            break;
          }
          install2(sum,sum);
        }
        char s1[3];

        strcpy(s1, repeat ? ":(" : ":)");
        strcpy(a.smiley,s1);
        answers[i] = a;
    }
    for (int i = 0; i < N; ++i) {
    struct Answer a = answers[i];
    printf("%s %s\n", a.label, a.smiley);
    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");


    return 0;

    // 4, 9 = 13
    // 1 9 = 10
    // 1

    // 4 16 20
    // 4 0 4
    // 4 16
    // 2 36 38
    // 9 64 73
    // 49 9 58
    // 25 64 89
    // 64 81  145
    // 1 16 25 42
    // 16 4 20 - only have to store one
}

// linux provides hcreate hsearch hdestroy! hash search and hashcreate
