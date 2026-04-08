# The calculation of suffix_expression 
## What's the project do?
The project performs the calculation of suffix expression.

When you input a suffix expression, the program will output the result.
- **In suffix_expression.cpp**,You can perform single-digit calculate, without spaces to seperate.
- **In suffix_expression_plus.cpp**,You can perform multi-digit and minus calculate, with spaces to seperate.
---
## What did I learn from the project?
Several grammars:
1. Input handling with 'fgets'
```c
fgets(str,MAXSIZE,stdin);
str[strcspn(str,"\n")] = '\0';
```
- fgets means input,assigning the string to str, stdin means input through keyboard.
Function fgets will record "\n".
- We use function strcspn to solve.
strcspn(str,"\n") means gain the index of "\n" in str.
- **Why not use scanf()?** Because scanf() will pause when meeting space.
2. string to integer with 'atoi'
```c
#include <stdlib.h>
char *s;
int a = atoi(s);
```
- The function atoi(s) means transforming string s to int.
3. seperating str with spaces using 'strtok'
```c
char *s = strtok(str," ");
char *s = strtok(NULL," ");
```
- The function strtok can seperate the characters of str with space.
- The function can memorize the index of each seperation.
- When you need to gain the next characters, you shouldn't use strtok(str," "), you use strtok(NULL," ") instead.

