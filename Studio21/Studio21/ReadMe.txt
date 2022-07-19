Studio 21 ReadMe.txt 
1. Members: Klein Morrow, Feite Lu

2. It is important to declare a virtual destructor in the base class as it takes care of possible memory issues (memory leaks) that could occur in the superclasses derived from the base class.

3. Dependency injection makes the command prompt reusable and flexible because it avoids creating an instance of a specfic file system which would avoid hard coded dependencies and keeps the 
class independent of its dependencies. 

4. We run the command prompt object. We typed "help", "help touch", "play"(a command that does not exist), "touch test.txt" and "quit" to test if the command prompt
object works properly. We then test whether we can open the file "test.txt" that is created and added by touch when we ranthe command prompty object. If it opens,
we print out "Open file successfully." for notice. The program ran as expected.