# 108_Da_Vinci
  *A text-based Da-Vinci Board Game*
  *Group 108 - Sunghyun Kim (3035603526) and Jinho Kwak (3035552129)*

## About
  This particular text-based game is inspired from **“Da Vinci code”**, a famous strategy board game. This game is for two players. In this game, there are a total of 24 tiles, either in black or white. Each color tiles show 1 to 11 and one joker tile.

  Initially, each of the two players take 4 tiles from the deck of 24 tiles regardless of each tiles’ color. In every turn (including the initial draw of 4 cards), the players should sort the tiles in ascending order from left to right. If two tiles show the same number, the white tile should go to the left. The back of the tiles is shown to the other player so that the other player cannot see any information of tiles except for their colors.

  First, player 1 takes a tile from the remaining deck and rearranges the tiles. Then, player 1 guesses a tile of player 2. If player 1 guesses wrong, player 1 should open the tile that he/she took in the current turn. If player 1 guesses correctly, player 2 opens the guessed tile and player 1 chooses whether he/she will continue to guess or not. If not, the turn goes to player 2 and player 2 does the same as what player 1 did. If yes, player 1 keeps guessing (if he/she guesses wrong, he/she should open his/her tile that is chosen in the current turn.). The players take turns until one player opens all of his/her tiles. The player who opened all of the other player’s tiles wins the game.

**Adapted from**: Da Vinci code - published in 2004, designed by Eiji Wakasugi

## Features and Functions
*This is in line with the “code requirement” of the project instruction.*

###### Generation of random game sets or events
**Function prototype:** void deal(card deck[], card cards[], int &numberofcards)
    - This will take a random selection of tiles in each draw (initialized by srand(time(NULL)) so that every game will be unique.

###### Data structures for storing game status
**Struct prototype:** struct card { char color; int number; int shown; };
    - This struct will contain information about each card to be used in the games (color, number, shown/not shown to the opponent). The tiles that players will have will be represented by arrays of this struct.

###### Dynamic memory management
**Dynamic array:** card * cards=new card [numberofcards];
    - This will contain the information about cards in the player’s deck. After choosing a new card from the deck, the size of the array will increase and the information about new tile will be added.

###### File input/output (e.g., for loading/saving game status)
**Code prototype:** \# include <fstream> ofstream fout; fout.open(“playerinfo.txt”,ios::app); ifstream fin; fin.open(“playerinfo.txt”);
    - After each turn, the program will ask players whether to save current information about the game or not. If yes, the information will be saved in an external file. Then, before executing the main function, the program will ask players whether to recall previous information about the game. If yes, the external files will be called and opened.

###### Program codes in multiple files
    - The program will make functions and codes in separate program files using appropriate headings, and compile them into one in a specified rule using makefile.

###### Proper indentation and naming styles
    - The program will assign names to the functions in accordance to their usage (i.e. function with name “deal” for enabling player to draw 1 card, function with name “sorting” to sort the card in ascending order)

###### In-code documentation
    - Before any functions in the program, the comments to explain the usage of it will be added.
