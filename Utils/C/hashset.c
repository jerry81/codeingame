#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct nlist { /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
};

struct nlist2 { /* table entry: */
    struct nlist2 *next; /* next entry in chain */
    int name; /* defined name */
    int defn; /* replacement text */
};

#define HASHSIZE 101
struct nlist *hashtab[HASHSIZE]; /* pointer table */
struct nlist2 *hashtab2[HASHSIZE];
struct nlist2 *orig[HASHSIZE];

unsigned hash2(int i) {
  return i%HASHSIZE;
}

/* hash: form hash value for string s */
unsigned hash(char *s) // goal: convert string into an index in the hash table
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
      hashval = *s + 31 * hashval;
    return hashval % HASHSIZE; // hash function always ends with this line
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

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
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

// char *strdup(char *);
/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
          return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval]; // adds to the head of the list
        hashtab[hashval] = np;
    } else /* already there */
        free((void *) np->defn); /*free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
       return NULL;
    return np;
}

// char *strdup(char *s) /* make a duplicate of s */
// {
//     char *p;
//     p = (char *) malloc(strlen(s)+1); /* +1 for ’\0’ */
//     if (p != NULL)
//        strcpy(p, s);
//     return p;
// }

int main() {
  struct nlist2* entry;
  install2(20, 20);
  install2(22, 22);
  entry = lookup2(20);
  if (entry == NULL) {
    printf("not found!");
  } else {
    printf("entry is %i\n", entry->defn);
  }

  if (lookup2(33) == NULL) {
    printf("key3 was not found!\n");
  }

  reset_ht();

  if (lookup2(20) == NULL) {
    printf("reset was successful\n");
  } else {
    printf("key1's val is still %i\n", lookup2(20) -> defn);
  }

  // printf("lookup done ");
  // if (entry2.defn == NULL) {
  //   printf("not found!");
  // } else {
  //   printf("entry2 is %s", entry2.defn);
  // }
  return 0;
}

// TIL: run c program on mac
/*
gcc hashset.c
./a.out
*/