Answer the studio 17 questions here.
1) Feite Lu, Klein Morrow
2) Once we finished the code, we tested the ImageFile class by creating an ImageFile object and passing
it into various functions of our SimpleFileSystem. We passed a right vector of characters and it returned
0 for success, indidcating that this function and the ImageFile class worked correctly. When we tried
testing badly formed inputs, our code returned wrongCharType. For the append() function, it returned an
enum of appendNotSupported to indicate that a textFile could not use this. For the read() function, it is
printing out correctly.
3) It allows you to use functions that you don't have to define more
than once by using inheritance.
4) We would need to add code to the addFile() and createFile() functions because they currently only support
a text file and an image file, whereas the other functions of this source file do not need to know the
specific file type in order to opperate.