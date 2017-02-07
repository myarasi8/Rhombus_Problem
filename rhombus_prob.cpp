#include <iostream>
#include <string>
using namespace std;

string makeSpaceCusion(int width, int row){
	string spaceCusion;
	for(int i=0; i < (width - row); i++)
	{
		spaceCusion += "  ";
	}
	
	return spaceCusion;
}

string reverseString(string arg)
{
	string reversed;
	for(int i = (arg.size() - 1); i >=0 ;i --)
		reversed += arg[i];

	return reversed;
}

string makeFirstHalfRow(int row)
{	
	string outRow;

	for (int i = 1; i <= row; i++)
	{
		
		outRow += std::to_string(i) + " ";
		
	}

	outRow = outRow.substr(0, outRow.size()-1);
	return outRow;
}

string makeRow(int row)
{
	if (row == 0)
	{
		return "";
	}
	if (row == 1)
	{
		return "1";
	}
	return makeFirstHalfRow(row) + " " + reverseString(makeFirstHalfRow(row-1));
	
}

string makeTopRhombus(int width)
{
	string topRhombus;
	for (int row = 1; row <= width; row++)
	{
		topRhombus += makeSpaceCusion(width, row) + makeRow(row) + "\n";
	}
	return topRhombus;
}

string makeBotRhombus(int width)
{
	string botRhombus;
	for (int row = (width-1); row > 0; row--)
	{
		botRhombus += makeSpaceCusion(width, row) + makeRow(row) + "\n";
	}
	return botRhombus;
}


string createRhombus(int width)
{
	return makeTopRhombus(width) + makeBotRhombus(width);
}

string stringifyBool(int i) {

	if (i == 0)
	{
		return "false";
	}
	else
	{
		return "true";
	}
}

int main()

{
	int num;
	cout << "Enter a number: " << endl;
	cin >> num;	

	if (num < 1 || num > 9)
	{
		cout << "Invalid entry" << endl;
		return 0;
	}

	cout << createRhombus(num) << endl;

	cout << "Our TESTS:" << endl;
	cout << "===========================" << endl;

	cout << "the right number of spaces should be 2 given width is 3 and row is 1" << endl;
	cout << stringifyBool(makeSpaceCusion(3, 1) == "    ") << endl;
	cout << "the right number of spaces should be 1 given width is 3 and row is 2" << endl;
	cout << stringifyBool(makeSpaceCusion(3, 2) == "  ") << endl;
	cout << "the right number of spaces should be 3 given width is 4 and row is 1" << endl;
	cout << stringifyBool(makeSpaceCusion(4, 1) == "      ") << endl;
	cout << "the right number of spaces should be 0 given width is 3 and row is 3" << endl;
	cout << stringifyBool(makeSpaceCusion(3, 3) == "") << endl;
	
	cout<< "The right sequence of numbers in row 0 is: (empty string)"<<endl;
	cout<< stringifyBool(makeRow(0) == "") << endl;
	cout<< "The right sequence of numbers in row 1 is: 1"<<endl;
	cout<< stringifyBool(makeRow(1) == "1") << endl;
	cout<<"The right sequence of numbers in row 2 is: 1 2 1"<< endl;
	cout<< stringifyBool(makeRow(2) =="1 2 1") << endl;
	cout<< "The right sequence of numbers in row 3 is: 1 2 3 2 1" << endl;
	cout<< stringifyBool(makeRow(3) == "1 2 3 2 1") << endl;	

	cout << "The reverse of hello should be olleh" << endl;
	cout << stringifyBool(reverseString("hello") == "olleh") << endl;

}


