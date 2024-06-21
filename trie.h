#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>

#define ALPHABET_SIZE 26
#define MAX_WORD_LENGTH 100
#define MAX_MEANING_LENGTH 200

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool is_end_of_word;
    char meaning[MAX_MEANING_LENGTH];
} TrieNode;

TrieNode *create_trie_node(void);
void insert(TrieNode *root, const char *word, const char *meaning);
bool search(TrieNode *root, const char *word, char *meaning);
void display_all_words(TrieNode *root);
void destroy_trie(TrieNode *root);

#endif /* TRIE_H */
