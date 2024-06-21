#ifndef FILEIO_H
#define FILEIO_H

#include "trie.h"
#include <stdio.h>

bool save_trie(TrieNode *root, FILE *fp);
bool load_trie(TrieNode *root, FILE *fp);

#endif /* FILEIO_H */
