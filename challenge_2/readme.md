# Solution to Challenge DecodeDemcon2
## Descripton
Challenge description follows below. Solution created by Luciano Orlandini.  

The program will ask the user for an input and will execute the automata accordingly.

## Instructions
Compile with:

```bash
g++ -o automata automata.cpp
```

Run with:

```bash
./automata
```

# DecodeDemcon2 Challenge Description

## The Challenge
For this exercise, you are tasked with creating a linear cellular automaton*. A cellular automaton consists of a grid of cells, with each row being called a generation. Each cell is in a certain state, which is ‘occupied’ or ‘empty’ in this case. The content of each subsequent generation is changed from the previous generation according to a few simple rules.  

The rules for computing a new generation satisfy four requirements:
- The rules use only the current generation to compute the next one.
- The rules define one state value per cell.
- The rules are the same for each cell.
- The rules define the new state value based on the state values in a set of cells in fixed positions with respect to the cell the value is computed for; such a set is often referred to as the neighborhood of the cell.  

This exercise concerns linear cellular automata, i.e., automata with a one-dimensional array of cells as grid. The neighborhood of a cell consists of the immediate neighbors in the array and the cell itself. Again, there are only two different states, referred to as ‘occupied’ and ‘empty’ (i.e., not occupied). In the book “A new kind of science” by Stephen Wolfram, the creator of the Mathematica tool, shows that such simple automata can display very interesting behavior. This exercise will show the effect of some rules.  

The following three types of automaton are considered:
- An automaton of type A has the following fixed rule set:  
If a cell is currently occupied, it remains occupied only if exactly one neighbor is occupied.
If a cell is currently empty, it remains empty only if both neighbors are empty.
- An automaton of type B has the following fixed rule set:  
If a cell is currently occupied, it remains occupied only if the right neighbor is empty.
If a cell is currently empty, it becomes occupied if exactly one neighbor is occupied.
- For an automaton of type U (called a universal automaton) the rule set is defined by a table.

(NB Obviously the rule sets for automata of type A and B can also be defined in this way).
 
## Exercise Definition
You are asked to develop a program that reads the description of an automaton (including initial configuration) from standard input, and then computes and displays a specified number of generations. The input is specified as follows (all items mentioned are separated by white space):  
- The letter A, B, or U indicating the type of automaton to be executed.
- A positive integer L being the number of cells of the automaton.
- A positive integer G being the number of generations to be computed and displayed (including the initial configuration).
- The word init_start, followed by one or more positive integers, followed by the word init_end. The integers are the positions of the occupied cells in the initial configuration (the first cell in the grid has position 1). All other cells are empty in the initial configuration. When an integer is higher than the number of cells L it should be ignored.
- In case of automaton type U (universal automaton) 8 0's and 1's representing the Boolean values b0, b1, …, b7 mentioned in the description of the rule set for a universal automaton above (0 representing false, 1 representing true).  

The output should be a sequence of G rows representing the successive generations. The first row is the initial generation. Each row consists of L characters each representing the state of one cell. An empty cell is displayed as a space, an occupied cell as the character *. Each row is terminated with an end-of-line.
Input and corresponding output are illustrated in the following two examples:
 

## Specifics & Rules
Please write your solution in one of the following programming languages: Python, Matlab, C++. We will evaluate your solutions based on inventiveness, efficiency and good coding practices.  
We will only accept submissions in the form of a link to a Github project. We’ve added some instructions if you’re unfamiliar with Github. In order to help you along a bit, and to help us with evaluating everyone uniformly, we’ve written a print function for you to use.