#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Creates a new TrieNode and initializes it
TrieNode *create_trie_node(void) {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    if (node) {
        node->is_end_of_word = false;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            node->children[i] = NULL;
        }
        node->meaning[0] = '\0';
    }
    return node;
}

// Inserts a word with its meaning into the Trie
void insert(TrieNode *root, const char *word, const char *meaning) {
    TrieNode *current = root;
    int index;
    for (int level = 0; word[level] != '\0'; ++level) {
        if (isalpha(word[level])) {
            index = tolower(word[level]) - 'a';
            if (!current->children[index]) {
                current->children[index] = create_trie_node();
            }
            current = current->children[index];
        }
    }
    current->is_end_of_word = true;
    strncpy(current->meaning, meaning, MAX_MEANING_LENGTH - 1);
    current->meaning[MAX_MEANING_LENGTH - 1] = '\0';
}

// Searches for a word in the Trie and retrieves its meaning
bool search(TrieNode *root, const char *word, char *meaning) {
    TrieNode *current = root;
    int index;
    for (int level = 0; word[level] != '\0'; ++level) {
        if (isalpha(word[level])) {
            index = tolower(word[level]) - 'a';
            if (!current->children[index]) {
                return false;
            }
            current = current->children[index];
        }
    }
    if (current != NULL && current->is_end_of_word) {
        strncpy(meaning, current->meaning, MAX_MEANING_LENGTH);
        meaning[MAX_MEANING_LENGTH - 1] = '\0';
        return true;
    }
    return false;
}

// Displays all words and their meanings in the Trie
void display_all_words_util(TrieNode *root, char *buffer, int depth) {
    if (root->is_end_of_word) {
        buffer[depth] = '\0';
        printf("%s: %s\n", buffer, root->meaning);
    }
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (root->children[i]) {
            buffer[depth] = i + 'a';
            display_all_words_util(root->children[i], buffer, depth + 1);
        }
    }
}

void display_all_words(TrieNode *root) {
    char buffer[MAX_WORD_LENGTH];
    display_all_words_util(root, buffer, 0);
}

// Recursively destroys the Trie nodes
void destroy_trie(TrieNode *root) {
    if (root) {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            destroy_trie(root->children[i]);
        }
        free(root);
    }
}
