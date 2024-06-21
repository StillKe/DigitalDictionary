#include "dictionary.h"
#include "fileio.h"
#include <stdio.h>
#include <string.h>

void load_sample_dictionary(TrieNode *root) {
    insert(root, "hello", "A greeting or expression of goodwill.");
    insert(root, "world", "The earth, together with all of its countries and peoples.");
    insert(root, "trie", "A type of search tree used to store a dynamic set or associative array where the keys are usually strings.");
    insert(root, "data", "Facts and statistics collected together for reference or analysis.");
    insert(root, "structure", "The arrangement of and relations between the parts or elements of something complex.");
}

void load_full_dictionary(TrieNode *root) {
    insert(root, "apple", "A fruit that is typically round, red or green, and has sweet flesh.");
    insert(root, "banana", "A long curved fruit that grows in clusters and has soft pulpy flesh and yellow skin when ripe.");
    insert(root, "cat", "A small domesticated carnivorous mammal with soft fur, a short snout, and retractile claws.");
    insert(root, "cat", "A small domesticated carnivorous mammal with soft fur, a short snout, and retractile claws.");
    insert(root, "dog", "A domesticated carnivorous mammal that typically has a long snout, an acute sense of smell, and a barking, howling, or whining voice.");
    insert(root, "elephant", "A large herbivorous mammal noted for its large ears, tusks made of ivory, and long trunk.");
    insert(root, "fish", "A limbless cold-blooded vertebrate animal with gills and fins living wholly in water.");
    insert(root, "giraffe", "A large African mammal with a very long neck and forelegs, having a coat patterned with brown patches separated by lighter lines.");
    insert(root, "house", "A building for human habitation, especially one that is lived in by a family or small group of people.");
    insert(root, "igloo", "A type of dome-shaped shelter built from blocks of solid snow, traditionally used by Inuit people.");
    insert(root, "jungle", "An area of land overgrown with dense forest and tangled vegetation, typically in the tropics.");
    insert(root, "kite", "A toy consisting of a light frame with thin material stretched over it, flown in the wind at the end of a long string.");
    insert(root, "lion", "A large tawny-colored cat that lives in prides, found in Africa and northwestern India.");
    insert(root, "mountain", "A large natural elevation of the earth's surface rising abruptly from the surrounding level; a large steep hill.");
    insert(root, "notebook", "A small book with blank or ruled pages for writing notes in.");
    insert(root, "ocean", "A very large expanse of sea.");
    insert(root, "piano", "A large keyboard musical instrument with a wooden case enclosing a soundboard and metal strings, which are struck by hammers when the keys are pressed.");
    insert(root, "quilt", "A warm bed covering made of padding enclosed between layers of fabric and kept in place by lines of stitching, typically applied in a decorative design.");
    insert(root, "river", "A large natural stream of water flowing in a channel to the sea, a lake, or another river.");
    insert(root, "sun", "The star around which the earth orbits.");
    insert(root, "tree", "A woody perennial plant, typically having a single stem or trunk growing to a considerable height and bearing lateral branches at some distance from the ground.");
    insert(root, "umbrella", "A device consisting of a circular canopy of cloth on a folding metal frame supported by a central rod, used as protection against rain or sometimes sun.");
    insert(root, "vase", "A decorative container, typically made of glass or china and used as an ornament or for displaying cut flowers.");
    insert(root, "whale", "A very large marine mammal with a streamlined hairless body, a horizontal tail fin, and a blowhole on top of the head for breathing.");
    insert(root, "xylophone", "A musical instrument played by striking a row of wooden bars of graduated length with one or more small wooden or plastic mallets.");
    insert(root, "yacht", "A medium-sized sailboat equipped for cruising or racing.");
    insert(root, "zebra", "An African wild horse with black-and-white stripes and an erect mane.");
}

void add_word(TrieNode *root) {
    char word[MAX_WORD_LENGTH];
    char meaning[MAX_MEANING_LENGTH];

    printf("Enter word to add: ");
    scanf("%s", word);
    printf("Enter meaning of the word: ");
    getchar(); // Consume newline character left by scanf
    fgets(meaning, MAX_MEANING_LENGTH, stdin);
    // Remove newline character from the meaning if present
    size_t len = strlen(meaning);
    if (len > 0 && meaning[len - 1] == '\n') {
        meaning[len - 1] = '\0';
    }

    insert(root, word, meaning);
    printf("Word '%s' added with meaning '%s'.\n", word, meaning);
}

void save_dictionary(TrieNode *root, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s for writing.\n", filename);
        return;
    }

    save_trie(root, fp);

    fclose(fp);
}

