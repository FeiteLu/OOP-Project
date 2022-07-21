File Name: Lab 5
Email: feite@wustl.edu & k.morrow@wustl.edu
Author: Feite Lu, Klein Morrow
We ran into no errors in the development of this program but we ran into bugs, such as the program not recognizing when -a or -d was passed into the command line. This was circumvented by making a substring of the string passed to the program and having an if statement on this substring. 
Another bug we ran into was the command being executed twice when a flag of the command was passed this was fixed by changing the order of our while loop in commandprompt.cpp.
Another bug we found was the program not recognizing a file was not within the system when calling display cat and copy this was fixed by checking if the file was a nullptr when called with one of the commands we also added a enum for each of these commands for this error.
Some of the tests we ran were trying to display cat remove and copy a file that did not exist this resulted in the function returning the apporpiate error number and asking for another command. 
Another test we ran was testing display on a file with no contents which resulted in nothing being printed. 
We tested the functionality of all the methods with correct inputs they all produced expected outcomes, such as remove being called on a valid file and that file not showing up when ls was called after.
We tested if each of the functions displayed their information when the function was called with help, which they did.
