# Digital Dictionary
Digital Dictionary is a command-line program written in C that allows users to manage and interact with a dictionary implemented using a Trie data structure. It supports functionalities such as inserting words with meanings, searching for words, displaying all words in the dictionary, loading sample or full dictionaries, saving the dictionary to a file, and exiting the program.

## Features
Insert a Word: Add a new word along with its meaning to the dictionary.
Search for a Word: Look up the meaning of a word in the dictionary.
Display All Words: View all words currently stored in the dictionary.
Load Sample Dictionary: Populate the dictionary with a predefined set of words and meanings.
Save Dictionary: Save the current state of the dictionary to a file.
Exit: Terminate the program.
Getting Started

## Prerequisites
GCC compiler (or any C compiler) to build the program.
Basic understanding of C programming language.
Command line interface (CLI) to run the program.
## Installation
Clone the repository:

```shell
git clone https://github.com/your-username/digital-dictionary.git
cd digital-dictionary
```

## Compile the program:

```shell
gcc -o dictionary main.c dictionary.c fileio.c trie.c
```

## Usage
Insert a Word: Choose option 1, enter the word followed by its meaning.
Search for a Word: Choose option 2, enter the word to search.
Display All Words: Choose option 3.
Load Sample Dictionary: Choose option 4.
Save Dictionary: Choose option 5, enter the filename to save.
Exit: Choose option 6.
Example usage:

```shell
./dictionary
```

## File Structure
main.c: Contains the main program logic, menu display, and user input handling.
dictionary.c: Implements dictionary operations such as inserting words, searching, and displaying.
fileio.c: Handles file input and output operations for saving and loading dictionaries.
trie.c: Implements the Trie data structure and related operations.
dictionary.h, fileio.h, trie.h: Header files declaring functions and structures used across different source files.

## Contributing
Contributions are welcome! Please fork the repository, create a new branch, make your changes, and submit a pull request.

## License
This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments
The implementation of the Trie data structure is based on standard algorithms and data structures principles.
Inspiration for this project came from the need to build a simple yet functional dictionary application.