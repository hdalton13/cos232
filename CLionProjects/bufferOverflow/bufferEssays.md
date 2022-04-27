#Buffer Overflow Attacks Essays
######By: Heather Dalton


##Integer Overflow Attack

For my first implementation of an overflow attack I have decided to write a program modeling a calculator. This code has the
basic implementations of a calculator. The functions it includes are addition, subtraction, multiplication, and division.
This code has a integer overflow vulnerability because of the fact that a if a user adds or multiplies past the limit value of an integer
the code will implement an unexpected calculation. For instance, say a user is trying to find the sum of 2147483640 and 10.
The user would expect the outcome to be 2147483650 but instead it is calculated to be -2147483646. This shows an example
of the integer overflow attack because the sum is larger than the size a typical integer variable can hold.
A way to prevent this vulnerability is to check to see if the sum or multiple of the two given values are greater than 
the largest  possible integer value. For example, this would potentially be an if statement checking to see if the sum or multiple is greater than 
2,147,483,647. Another way is somehow notify the user that an overflow has occurred and could possibly be used to exploit other areas of the code.
The potential payoff of this attack is the fact that an attacker can manipulate the data outputted and potentially find 
a way through this vulnerability to access different applications connected with it. This could range from giving a data
scientist wrong data to the wrong measurements of a prototype costing a company millions more to notify, repair, and replace.  



##Stack-Based Buffer Overflow Attack
For my second implementation of an overflow attack I have decided to create a program that compares passwords. The user
will first set the original password.Then they will enter the same password again. If the two passwords match a user
will gain access and will be able to see the secret message. Along with that the program checks to see if the password 
is equal to the administrative password. If it is the administrator, they have the ability to change the secret message
if desired. This code set has a vulnerability of a stack-based overflow. This code is vulnerable because the code does
not check to see if the input is in bounds or not. Without this check a user could submit a password that is out of 
bounds which then grants them administrative access. A way to prevent this attack is to add additional check verifying 
the length of the inputted data. The potential payoff of this attack is the ability to compromise the integrity of the 
message along with gaining access at the administrative level.
