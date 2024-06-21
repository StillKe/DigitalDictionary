#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "trie.h"

void load_sample_dictionary(TrieNode *root);
void load_full_dictionary(TrieNode *root);
void add_word(TrieNode *root);
void save_dictionary(TrieNode *root, const char *filename);

#endif /* DICTIONARY_H */
