# Corewar

What is it ?
Core War is a programming game created by D. G. Jones and A. K. Dewdney in which two or more battle programs (called "warriors") compete for control of a virtual computer. These battle programs are written in an abstract assembly language.

At the beginning of a game, each battle program is loaded into memory, after which each program executes one instruction simultaneously in a turn. The object of the game is to cause the processes of opposing programs to terminate, leaving the victorious program in sole possession of the machine.

The corewar is a first year project at Epitech

Here is an exemple of classic display:
![alt tag](https://raw.githubusercontent.com/usernameHed/Corewar/master/CorewarClassicDisplay)

project created by a group of 4 students:

Matheo Msa - ASM, for Abstract State Machine
Jules Palluau - https://github.com/palluau - Project body and Virtual Machine
Cristopher Toozs-Hobson - Project body and Virtual Machine
Myself - Ugo Belfiore - Graphics part

My goal was to represent the game graphically.

I did some precursory research on how to display the game in an innovative way.
This example involves a simple particle physics engine I programmed and developped myself
![alt tag](https://raw.githubusercontent.com/usernameHed/Corewar/master/CorewarMoteur.gif)

Presentation video
![alt tag](https://raw.githubusercontent.com/usernameHed/Corewar/master/CorewarPres.gif)


Graphic rendering !
 - multithreaded, dividing the particle rendering into 4 groups
 - music
 - clean HUD which displays informations about the game, progress bar and custom text (which is not handled by the graphic librairy used for this exercice !)
 - animation and particle effects
![alt tag](https://raw.githubusercontent.com/usernameHed/Corewar/master/Corewar.gif)

