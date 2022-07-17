# Solution to Challenge DecodeDemcon3
## Descripton
Challenge description follows below. Solution created by Luciano Orlandini.  

This script will try to solve a Mine Sweeper grid provided by Demcon. Starting from a random tile probe, the logic will press all tiles which is certain to not contain a mine. Where the logic is sure there is a mine, it will place an 'f' to flag it.  
If the logic finds itself in a position where it cannot possibly tell if there is a safe tile or a mine, it will probe a random one to progress the game. That's where an explosion may occur!
The script can be ran in three difficulty levels: Beginner, Intermediate or Expert. Indicated by the command line arguments 1, 2 or 3.  

## Instructions
As an example, to run the script with the Intermediate difficulty, type:

```bash
python3 solver.py 2
```

## Output
The logic will constantly print the most up to date grid, the number of tiles left to probe and mines left to find.  
If an error is made, the exploded tile will show a '*'.




# DecodeDemcon3 Challenge Description

You are tasked with creating a Minesweeper Solver. Your Solver is presented with a MineField Object, the interface of which is defined below. The Solver will start the process with a random guess. After the first guess, the MineField object will fill in the field automatically, and return the number of mines that are adjacent to that cell. Your software will keep sweeping (In whatever way you decide is best) until it is either solved or it failed. To help you along, we have provided a MineField class for you. It generates a random MineField of a defined number of rows, columns, and number of mines. You can play Minesweeper with it by calling its member functions. You can also construct a MineField object with predefined configurations called BEGINNER_FIELD, INTERMEDIATE_FIELD and EXPERT_FIELD.

## Minesweeper Class Interface Definition

### Functions
#### def __init__(self, width: int, height: int, number_of_mines: int)
The constructor.
#### def sweep_cell(self, column: int, row: int)
returns the number of adjacent mines. Throws a ExplosionException if the guess was a bomb.

## Specifics
1.	Please write your solution in Python. 
2.	Please add information (in the README) on how to execute the code.
3.	Your solution should be able to output the location of all the bombs. If it fails, it should output the location of the bombs that it found.
4.	We will evaluate your solutions based on inventiveness, efficiency, and good coding practices. 
5.	We will only accept submissions in the form of a link to a Github repository. 
6.	Please send your submission to [communication@demcon.com](mailto:communication@demcon.com).
