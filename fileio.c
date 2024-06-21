#include "fileio.h"
#include <string.h>

bool save_trie(TrieNode *root, FILE *fp) {
    if (root == NULL) {
        return true;
    }

    fprintf(fp, "%d\n", root->is_end_of_word);
    fprintf(fp, "%s\n", root->meaning);

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (root->children[i]) {
            fprintf(fp, "%c\n", i + 'a');
            save_trie(root->children[i], fp);
        }
    }
    fprintf(fp, "!\n");
    return true;
}

bool load_trie(TrieNode *root, FILE *fp) {
    int end_of_word;
    char ch;

    if (fscanf(fp, "%d", &end_of_word) != 1) {
        return false;
    }

    root->is_end_of_word = end_of_word ? true : false;

    if (fgets(root->meaning, MAX_MEANING_LENGTH, fp) == NULL) {
        return false;
    }

    root->meaning[strcspn(root->meaning, "\n")] = '\0';

    while (fscanf(fp, " %c", &ch) == 1 && ch != '!') {
        root->children[ch - 'a'] = create_trie_node();
        if (!load_trie(root->children[ch - 'a'], fp)) {
            return false;
        }
    }
    return true;
}
