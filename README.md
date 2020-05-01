# 1340 Group Project
A text-based role-playing game written in C++.

## Group Members
1. **Tsoi Ming Hung 3035684946**
2. **Chan Kam Wa 3035693935**

## Introduction
This is a role-playing game based in an ancient Japanese village. You will be casting a ninja assassin who has given a mission to eliminate the infamous emperor of the country. The game starts as you has reached the enemies' base - 'the Himeji Castle'. There are mutiple stages to play before you can finally meet the emperor. The game's difficulty gradually increases as you reach higher stages. Like normal RPG, the key to win is to carefully decide which action to take at different stages.

## How to play
In general, there are 3 actions to choose from at each round: 
1. **Attack**: deal damage to the enemy based on your attack power
2. **Items**: Use items you have collected from enemies to heal, deal damage, or increase attack power/defense
3. **Guard**: Reduce damage taken for the next round

## List of Functions/Features
1. rand() and srand(time(0)) - Generation of random game sets or events
2. ifstream & ofstream - File input/output (e.g., for loading/saving game status)
3. printstatus - output the current status of the player (hp, def, atk etc)
4. battle - a function implementing the cycle of player actions and enemy actions
5. sleep and clear screen - improves text outputting
