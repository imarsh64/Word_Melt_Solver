# Word_Melt_Solver
Program for Data Structures class to solve a word melt puzzle. Project uses circular queues, maps, and sets. Written completely in c++.

##Word Melt Puzzles
A word melt puzzle takes in a start word, goal word, and a dictionary of valid words. The goal is to get from the start word to the goal word changing one character at a time (by changing a character, inserting a character, or deleting a character). For example, a valid word list may contain "but, bat, bar, barn, yarn, yearn." If the start word is "but," and the end word is "yearn," then the following sequence would be a solution: "but, bat (change u to a), bar (change t to r), barn (insert n at the end), yarn (change b to y), yearn (insert e before the second letter)".


