// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/ImageFile.h"
#include "../..//SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include "../../SharedCode/MetadataDisplayVisitor.h"
#include <iostream>
using namespace std;

int main()
{
	ImageFile image_file_test("test");
	vector<char> output;
	vector<char> input_vec;
	input_vec.push_back(' ');
	input_vec.push_back(' ');
	input_vec.push_back(' ');
	input_vec.push_back('X');
	input_vec.push_back('2');
	image_file_test.write(input_vec);
	BasicDisplayVisitor* v = new BasicDisplayVisitor;
	image_file_test.accept(v);
	

}
