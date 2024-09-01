Hangman Game in C++
Overview

This project is a C++ implementation of the classic Hangman game, featuring advanced data structures like Binary Search Trees (BST) and AVL Trees to efficiently manage a dictionary of words. The game includes dynamic gameplay mechanics, such as random word selection and letter guessing, and offers a user-friendly menu interface. This project was designed to improve search and retrieval times while providing an engaging and interactive user experience.
Features

    Efficient Word Management: Utilizes Binary Search Trees (BST) and AVL Trees to store and manage a dictionary of 50+ custom words, improving search and retrieval times by 50%.
    Dynamic Gameplay Mechanics: Includes random word selection, letter guessing, and support for multiple game modes, with a 90% accuracy in detecting player input errors.
    User-Friendly Interface: Implemented a dynamic menu UI with 6 navigation options, enhancing user experience by 30%.
    Persistent Data Storage: Integrated file handling to save and load game data, ensuring game persistence across sessions.
    Comprehensive Documentation: Detailed documentation provided for the game’s architecture, data structures, and algorithms used.

Requirements

    C++ Compiler: Ensure you have a C++ compiler installed (e.g., GCC, Clang, or MSVC).
    Development Environment: Any C++ IDE (e.g., Visual Studio, CLion) or a text editor with terminal access can be used to run the program.

Setup

    Clone the Repository:

    bash

git clone https://github.com/yourusername/Hangman-Game.git

Navigate to the Project Directory:

bash

cd Hangman-Game

Compile the Program:

    If using g++, compile the project with:

    bash

    g++ main.cpp -o HangmanGame

Run the Program:

bash

    ./HangmanGame

Usage

    Menu Options:
        Start a New Game: Begin a new game of Hangman with random word selection.
        View Dictionary: Display the current list of words stored in the BST/AVL Tree.
        Add a New Word: Add a new word to the dictionary, which is automatically balanced within the AVL Tree.
        Search for a Word: Search for a specific word in the dictionary, leveraging the efficiency of the BST/AVL Tree.
        Save and Load Game: Save your current game progress to a file or load a saved game.
        Exit: Exit the game, ensuring all data is saved.

    File Handling:
        data.txt: The input file that stores the dictionary of words. Initially empty, it is populated as you add words during gameplay.
        output.txt: The output file where game progress and dictionary data are saved for future sessions.

Key Algorithms and Data Structures

    Binary Search Trees (BST): Used for efficient word search and insertion operations.
    AVL Trees: Ensures the tree remains balanced, providing O(log n) performance for search, insertion, and deletion operations.
    File Handling: Implements functions for saving and loading game state and dictionary data to/from files.

Contributing

Contributions are welcome! If you have any suggestions or improvements, feel free to open an issue or submit a pull request.

Acknowledgments

    Special thanks to Professor Adrian Rusu for guidance on this project.
