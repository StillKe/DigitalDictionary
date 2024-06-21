#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Include for tolower()

#include "trie.h"
#include "dictionary.h"
#include "fileio.h"

#define MAX_WORD_LENGTH 100
#define MAX_MEANING_LENGTH 200

void print_menu() {
    printf("\nChoose an option:\n");
    printf("1. Insert a word\n");
    printf("2. Search for a word\n");
    printf("3. Display all words\n");
    printf("4. Load sample dictionary\n");
    printf("5. Save dictionary\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    TrieNode *root = create_trie_node();
    int choice;
    char filename[100];
    bool loaded = false;

    while (1) {
        print_menu();
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                add_word(root);
                break;
            case 2: {
                char word[MAX_WORD_LENGTH];
                char meaning[MAX_MEANING_LENGTH];
                printf("Enter word to search: ");
                scanf("%s", word);
                if (search(root, word, meaning)) {
                    printf("Meaning of '%s': %s\n", word, meaning);
                } else {
                    printf("Word '%s' not found in the dictionary.\n", word);
                }
                break;
            }
            case 3:
                printf("Words in the dictionary:\n");
                display_all_words(root);
                break;
            case 4:
                load_sample_dictionary(root);
                loaded = true;
                printf("Sample dictionary loaded.\n");
                break;
            case 5:
                if (!loaded) {
                    printf("Please load a dictionary first.\n");
                    break;
                }
                printf("Enter filename to save: ");
                scanf("%s", filename);
                save_dictionary(root, filename);
                printf("Dictionary saved to %s.\n", filename);
                break;
            case 6:
                destroy_trie(root);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
                break;
        }
    }

    return 0;
}
