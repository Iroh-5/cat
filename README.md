# This is a simple program that mimics linux cat tool behaviour. 
I wrote it for educational purposes. It can operate in four modes:
* If no arguments are provided then program echoes all input
* If one of more file names are provied then their content is printed just like in cat command
* If first argument is "-n" then all lines are numbered
* If first argument is "-ne" then lines of each file are numbered

So there are usage examples:
"""
  ./cat
  ./cat file1 file2 ... filen
  ./cat -n file1 file2 ... filen
  ./cat -ne file1 file2 ... filen
"""
