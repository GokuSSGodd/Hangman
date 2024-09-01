#include "BinarySearchTree.hpp"
#include "avltree.hpp"
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
#define INF "words_alpha.txt"
#define OUTF "words_alpha.txt"
#define INF2 "body_parts.txt"
#define OUTF2 "body_parts.txt"

void computermode();
void playermode();
void about();
void UserManual();
vector<string> creature();
void addWord(Node *&root);
void inOrderTraversalToFile(Node *node, ofstream &outputFile);

int main() {

  int gamemode;

  ifstream inputFile(INF);

  if (!inputFile) {
    cerr << "Can't open " << INF << " for input" << endl;
    return 1; // Exit if the file cannot be opened
  }

  Node *root = nullptr;

  string word;

  while (inputFile >> word) {
    root = insert(root, word);
  }

  inputFile.close();

Menu:

  cout << "Welcome to Hangman!\n";
  cout << "1. Computer Mode\n2. Player Mode\n3. Add Word\n4. About\n5. User "
          "Manual\n6. Quit\n"
       << endl;

  cin >> gamemode;

  switch (gamemode) {
  case 1:
    computermode();
    break;
  case 2:
    playermode();
    break;
  case 3:
    addWord(root);
    break;
  case 4:
    about();
    break;
  case 5:
    UserManual();
    break;
  case 6:
    (void)system("clear");
    cout << "Game has ended." << endl;
    cout << "Thanks for playing!" << endl;
    exit(1);
  default:
    cout << "Invalid Input, please try again\n" << endl;
    goto Menu;
  }

  cout << "\nWould you like to go back to the Menu?\n";

  string restart;
  cin >> restart;

  if (restart == "yes") {
    (void)system("clear");
    goto Menu;
  }
  if (restart == "no") {
    (void)system("clear");
    cout << "Game has ended." << endl;
    cout << "Thanks for playing!" << endl;
    exit(1);
  }
  return 0;
}

void computermode() {

  (void)system("clear");

  cout << "Welcome to Computer Mode" << endl;

  ifstream inputFile(INF);
  if (!inputFile) {
    cerr << "Can't open " << INF << " for input" << endl;
    exit(1);
  }

  struct node *root = nullptr;
  string word;
  vector<string> randomWords;

  while (inputFile >> word) {
    root = insert(root, word);
    randomWords.push_back(word);
  }

  inputFile.close();

  vector<string> chosenCreature = creature();

  string word2guess;

  int index = rand() % randomWords.size();

  word2guess = randomWords[index];

  string wordguessed(word2guess.size(), '_');
  cout << "Word guessed: " << wordguessed << endl;

  set<char> lettersguessed;
  int wrongGuesses = 0;
  const int maxWrongGuesses = 11; // Maximum allowed incorrect guesses

  while (wrongGuesses < maxWrongGuesses && wordguessed != word2guess) {
    char lettersguess;
    cout << "_______________________________________________" << endl;
    cout << "\nPlease guess a letter: ";
    cin >> lettersguess;

    if (lettersguessed.count(lettersguess)) {
      cout << "You have already guessed this letter, please try again." << endl;
      continue;
    }

    lettersguessed.insert(lettersguess);
    bool letterfound = false;

    for (size_t i = 0; i < word2guess.size(); i++) {
      if (word2guess[i] == lettersguess) {
        wordguessed[i] = lettersguess;
        letterfound = true;
      }
    }

    if (!letterfound) {
      wrongGuesses++;
    }
    
    (void)system("clear");
    cout << "\nWord Guessed: " << wordguessed << endl;

    // Display the parts of the creature for each wrong guess
    for (int i = 0; i < wrongGuesses; i++) {
      cout << chosenCreature[i] << endl;
    }

    // Display remaining letters
    cout << "\nRemaining Letters: ";
    for (char c = 'a'; c <= 'z'; ++c) {
      if (!lettersguessed.count(c)) {
        cout << c << " ";
      }
    }
    cout << "\n" << endl;
  }

  if (wordguessed == word2guess) {
    (void)system("clear");
    cout << "Congratulations! You guessed the word correctly: " << word2guess
         << endl;
  } else {
    (void)system("clear");
    cout << "You have lost the game. The correct word was: " << word2guess
         << endl;
  }
}

void playermode() {

  (void)system("clear");

  cout << "Welcome to Player Mode" << endl;

  ifstream inputFile(INF);
  if (!inputFile) {
    cerr << "Can't open " << INF << " for input" << endl;
    exit(1);
  }

  struct node *root = nullptr;
  string word;
  vector<string> randomWords;

  while (inputFile >> word) {
    root = insert(root, word);
    randomWords.push_back(word);
  }

  inputFile.close();

  vector<string> chosenCreature = creature();

  string word2guess;
  cout << "\nWhat is your word to guess: " << endl;
  cin >> word2guess;

  struct node *NodeInTree = search(root, word2guess);

  if (NodeInTree == nullptr) {
    cout << "\nNot a legitimate word. I suggest using some of the following "
            "words: "
         << endl;

    for (int i = 0; i < 5; i++) {
      int index = rand() % randomWords.size();
      cout << randomWords[index] << endl;
    }

    cout << "\nWhich word would you like to use?" << endl;
    cin >> word2guess;
  }

  string wordguessed(word2guess.size(), '_');
  cout << "Word guessed: " << wordguessed << endl;

  set<char> lettersguessed;
  int wrongGuesses = 0;
  const int maxWrongGuesses = 11; // Maximum allowed incorrect guesses

  while (wrongGuesses < maxWrongGuesses && wordguessed != word2guess) {
    char lettersguess;
    cout << "_______________________________________________" << endl;
    cout << "\nPlease guess a letter: ";
    cin >> lettersguess;

    if (lettersguessed.count(lettersguess)) {
      cout << "You have already guessed this letter, please try again." << endl;
      continue;
    }

    lettersguessed.insert(lettersguess);
    bool letterfound = false;

    for (size_t i = 0; i < word2guess.size(); i++) {
      if (word2guess[i] == lettersguess) {
        wordguessed[i] = lettersguess;
        letterfound = true;
      }
    }

    if (!letterfound) {
      wrongGuesses++;
    }
    (void)system("clear");
    cout << "\nWord Guessed: " << wordguessed << endl;

    // Display the parts of the creature for each wrong guess
    for (int i = 0; i < wrongGuesses; i++) {
      cout << chosenCreature[i] << endl;
    }

    // Display remaining letters
    cout << "\nRemaining Letters: ";
    for (char c = 'a'; c <= 'z'; ++c) {
      if (!lettersguessed.count(c)) {
        cout << c << " ";
      }
    }
    cout << "\n" << endl;
  }

  if (wordguessed == word2guess) {
    (void)system("clear");
    cout << "Congratulations! You guessed the word correctly: " << word2guess
         << endl;
  } else {
    (void)system("clear");
    cout << "You have lost the game. The correct word was: " << word2guess
         << endl;
  }
}

vector<string> creature() {

  string bodyparts;
  vector<string> creature;

  cout << "What body parts would you like on your creature?" << endl;

  ofstream outputFile(OUTF2);

  if (!outputFile) {
    cerr << "Can't open" << OUTF << "for output" << endl;
  }

  for (int i = 0; i < 11; i++) {
    cin >> bodyparts;
    outputFile << bodyparts << endl;
  }

  outputFile.close();

  ifstream inputFile(INF2);

  if (!inputFile) {
    cerr << "Can't open" << INF2 << "for input" << endl;
  }

  string bodypart;

  while (inputFile >> bodypart) {
    creature.push_back(bodypart);
  }

  inputFile.close();

  cout << "The player has chosen the following body parts: " << endl;

  for (int i = 0; i < creature.size(); i++) {
    cout << creature[i] << endl;
  }
  return creature;
}

void about() {

  (void)system("clear");

  cout << "Author: Murtaza Amjad" << endl;
  cout << "email: mamaja3@unh.newhaven.edu" << endl;
  cout << "Date: November 29, 2022" << endl;
}

void UserManual() {
  (void)system("clear");
  cout << "_________________________ USER MANUAL ___________________________"
       << endl;
  cout << "The computer mode will select a random word from the dictionary and "
          "you will try and guess it.\n"
       << endl;
  cout << "The player mode will let you type in a word and if it is not in the "
          "dictionary then you have to choose another word from. They will "
          "also suggest a few words.\n"
       << endl;
  cout << "About option shows the information about the author, his contact "
          "email, and the date the game was created.\n"
       << endl;
  cout << "AddWord option allows the user to add a word into the dictionary\n"
       << endl;
  cout << "Quitting will end the game and give a little thank you message\n"
       << endl;
}

void inOrderTraversalToFile(Node *node, ofstream &outputFile) {
  if (node != nullptr) {
    inOrderTraversalToFile(node->left, outputFile);
    outputFile << node->key << endl;
    inOrderTraversalToFile(node->right, outputFile);
  }
}

void addWord(Node *&root) {
  string word;
  cout << "Enter a word to add: ";
  cin >> word;

  root = insert(root, word);

  // Optionally write the updated tree to a file
  ofstream outputFile("words_alpha.txt");
  if (!outputFile.is_open()) {
    cerr << "Error opening file for output." << endl;
    return;
  }
  inOrderTraversalToFile(root, outputFile);
  outputFile.close();
}
