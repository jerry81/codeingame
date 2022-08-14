#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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
