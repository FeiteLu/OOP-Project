Answer studio 16 questions here

1.Team members: Kevin Zou, Jessica Sheldon, Feite Lu, Klein Morrow

2. The process of declaring an interface in C++ involves creating a base class which has the required member variables shared by the derived classes. The public functions are also declared as virtual in 
order to support polymorphism and allow for derived classes to implement their own versions of the virtual functions in the base class. 

3a. This is an example of interface inheritence as there is no implementation for the methods in the base class (AbstractFile). The derived class (TextFile) implements its public functions later.
b. These member variables should be private. There is no reason for them to be protected as there are no classes which inherit from TextFile. They also can't be public as that presents security issues.

4. We tested appending a string into contents. The program behaved correctly by returning the correct size, name, and printed the contents. We then tried appending an empty vector<char> and the program 
behaved correctly by returning the correct name, size (0), and contents (nothing). We also tried the same cases with the write() method instead of the append() and each returned the correct output. 
UnitTest passes all conditions. 

5.Main method:
int main()
{
	TextFile test("test");
	AbstractFile* ab = &test;
	cout << "name: " << ab->getName() << endl;
	vector<char> in;
	ab->append(in);
	cout << "size: " << ab->getSize() << endl;
	ab->read();
}

We ran the same tests as with the main method that interacted with TextFile (regular input, no input for write() and append()) and the program behaved as expected for each method. Read(), getName(), and
getSize() all returned the correct outputs. Write() and append() also run as expected by changing the value of contents. UnitTest passes all conditions. 