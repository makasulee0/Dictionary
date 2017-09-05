# Dictionary
School Project for 242

How to get it to work?

PATCH 1
Run script with: ./compiledfile dictionary.txt -r (or whether operand)
Non-urgent issues: assignment makes pointer from integer without a cast [-Wint-conversion] for red black tree or flexarray (but it
still runs)


PATCH 2 - Relationship between hTable and container classes
Step 1: Create container object which can either be a flexarray or a rbt

Step 2: Append key / data values in the flexarray or rbt class and return the container object
note: rbt and flexarray need to be modified for string values, and include an important print function (-p)

Step 3: Create a hTable object in main

Step 3: Append return container / or c->contents as a parameter to the hTable. Use (-i) to print related statistics
based on hashing algorithm. Hashing key is just value of the string % (mod) size of the table.

Step 4: Patch commands to do the related stuff in main.
