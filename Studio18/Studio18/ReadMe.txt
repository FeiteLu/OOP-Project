studio 18 answers here
1.Team Members: Feite Lu, Klein Morrow

2.To create a new file system implementation, we just need the same functions as the abstract file system and override the
functions in the new file system declaration. In the new function definition, we use the new file types we want to use in this
file system instead of the ones in the SimpleFileSystem.
If we want to create a new file type that is used by different file system implementations, we need to include it in the 
that needs the specification of the file type like the createFile function to help the file system implementation include
this new type of file.

3.The abstract factory pattern can avoid having too many functions in the same class, comply with single responsibility
principle and enhance the reusability of the code. The new function for creating files will be quite simple because it only
has the responsibility of create a new file. The disadvantage is that it introduces new interfaces and classes and this will
enhance the overfall complexity of the code and the relationship between classes and interfaces. If two file system implementations
manage the same types of files, the same factory can be used to create files for both. If two file system implementations
manage different types of files, the same factory can still be used to create files for both, we just need to modify the code
when we are doing operations like addFile or deleteFile.

4.test code:
	AbstractFileSystem* s = new SimpleFileSystem;
	AbstractFileFactory* f = new SimpleFileFactory;
	s->addFile("text1.txt", f->createFile("text1.txt"));
	s->addFile("text2.txt", f->createFile("text2.txt"));
	s->addFile("image1.img", f->createFile("image1.img"));
	s->addFile("image2.img", f->createFile("image2.img"));
	
	AbstractFile* t1 = s->openFile("text1.txt");
	t1->write({ 'H','e','l','l','o',','});
	t1->read();
	s->closeFile(t1);
	
	AbstractFile* t2 = s->openFile("text2.txt");
	t2->write({ 'w','o','r','l','d','!' });
	t2->read();
	s->closeFile(t2);

	cout << endl;

	AbstractFile* i1 = s->openFile("image1.img");
	i1->write({ 'X','X','X','X','2' });
	i1->read();
	s ->closeFile(i1);

	AbstractFile* i2 = s->openFile("image2.img");
	i2->write({ 'X',' ','X',' ','X',' ','X',' ', 'X','3'});
	i2->read();
	s->closeFile(i2);

	return 0;

Output:
Hello,world!
XX
XX
X X
 X
X X

5.The SimpleFileSystem new depends on the AbstractFile interface only.



