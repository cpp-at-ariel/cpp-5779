#include <iostream>
using namespace std;

struct file{
  string name;
  void open() {}
};

struct inputFile:   public file  {
  void read() {}
};

struct outputFile:  public file {
  void write() {}
};

struct ioFile: public inputFile, public outputFile{
};


int main(){
	ioFile f;
	//f.name= "fileA.txt"; // error!
	f.inputFile::name= "fileA.txt"; // error!
	cout << f.inputFile::name << endl;
	cout << f.outputFile::name << endl;
	cout << "---" << endl;
	f.outputFile::name="fileB.txt"; // Ok! Does not change    							inputFile::name
	cout << f.inputFile::name << endl;
	cout << f.outputFile::name << endl;
}
