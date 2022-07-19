studio 19 answers here
1.Team Members: Feite Lu, Klein Morrow, Jessica Sheldon, Kevin Zou

2. I ran tests on both concrete file types of ImageFile and TextFile. 
Each test I did I put printed the file before I wrote (which was empty as I used basic constructor) and the file after I wrote some input into it.
Since I am changing the read() functions of the concrete classes to simply return their contents, I expect that the file after I write something into will simply return the contents I wrote in.
TextFile read() tests:

The first test I wrote nothing into the file and both the before and after printed nothing (as expected).
The second test I wrote a singluar character into the file. The before was empty and the after returned the character I input (as expected).
The third test I wrote a long string and pushed back each character of the string into an input vector which I used as my write() parameter. The before was empty and the after returned the string I entered.

ImageFile read() tests:
 
The first test I wrote nothing into the file and both the before and after printed nothing (as expected).
The second test I wrote just 'X' and '1' into the file. Since the last element ('1') represents size and matches the expected amount of characters it return the 'X' and '1' in the ouput 
"X" (as expected).
The second test I did the same as the second but replaced 'X' with ' '. It was the same ouput except the space replaced the X. The output was " " (as expected).
The fourth test I wrote 'R' and '1' into the file, but since 'R' does not match 'X' or ' ' the file after printed nothing (as expected).
The fifth test I wrote 'X' and '5' into the file. Since the last element ('5') which represents the size did not match the amount of characters in the input vector the file after
returned nothing (as expected).
The sixth test I wrote 'X' 'X' 'X' ' ' '2' into the file. Since each character before the last element was either 'X' or ' ' the file after returned the ouput "XXX " (as expected).
The seventh test I wrote the same input as the sixth test, but ended the input with 5. Since the last element ('5') didn't match the amount of characters entered it returned nothing
(as expected).


3. The communication between a visitor and the object it is visiting starts with the template we created for visitor (AbstractFileVisitor). AbstractFileVisitor will have a visit() function
which takes in a pointer to the object it would like to visit. The object we will be visiting is a concrete file type that is a super class of AbstractFile. AbstractFile declares
a pure virtual function accept() which takes a pointer to an AbstractFileVisitor. The accept() funciton will be implemented in the super class source files for the concrete file types
(ImageFile.cpp and TextFile.cpp). This will take in the AbstractFileVisitor pointer and call the visit function on "this" which will give the allow the AbstractFileVisitor to know
what object it is being called on. Then we will implement the functionality we would like the visitor to add to the specific object (TextFile or Image File) in the concrete visitor 
source files. 

4. As delegation is the concept of one entity passing information to another, the visitor pattern clearly falls under this concept. The visitor pattern uses delegation by adding specific
unique functionality to the TextFile and ImageFile without writing specific member functions for those concrete objects. The visitor pattern accomplishes this through the relationship 
between visitor and object and the access that the visitor gets.

5. I belive the visitor pattern is not an ideal behavioral pattern to follow when the number of objects you would like to add 
functionality to are not fixed. In this case you would have to create visitor implementation for all the objects you would like to add functionality to which would be much more than 
if you were to add functionality through member functions.



