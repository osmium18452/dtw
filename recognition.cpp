#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

const int MAXNFRAME = 300; // max number of frames. A piece of audio contains 300 frames at most, that is, 300ms
const int DVECTOR = 39; // dimension of a frame

#include "binaryread.h"
#include "recognition.h"

float TemplateVectors[10][MAXNFRAME + 1][DVECTOR + 1]; // stores 10 template.
int NFTemplate[10]; // number of frames in each template vector

int main(int argc, char *argv[])
{
	if (argc < 3) {
		cout << "Too few arguments." << endl;
		exit(0);
	}
//	printf("%s %s %s\n",argv[0],argv[1],argv[2]);
//	exit(0);
	string TemplateFolder = argv[1];
	string TestFileList = argv[2];
	ofstream f;
	if (argc == 3) {
	}
	else {
		f.open(argv[3], ios::out);
	}
	/*---------------- read data from template ---------------------*/
	for (int i = 0; i < 10; i++) {
		ostringstream number;
		number << i;
		string template_file = TemplateFolder + '\\' + number.str() + "_template.mfc";
		NFTemplate[i] = ReadHtk(template_file, TemplateVectors[i]);
	}

	/*---------------- read the test data and compare it with the template.---------------*/
	string *fileInfos = new string[100];
	int nfiles = get_strs_from_file(TestFileList, fileInfos);
	float TestVector[MAXNFRAME + 1][DVECTOR + 1];
	int NFTest = 0; // number of frames of test
	for (int j = 1; j <= nfiles; j++) {
		float re = 0;
		int k = 1;
		float result = 1e+38f;
		NFTest = ReadHtk(fileInfos[j], TestVector);
		for (int i = 0; i < 10; i++) {
			re = Run_DTW(TemplateVectors[i], NFTemplate[i], TestVector, NFTest);
			if (result > re) {
				result = re;
				k = i;
			}
		}
//		cout<<fileInfos[j] << '\t' << k << endl;
		if (argc==3) cout << fileInfos[j] << '\t' << k << endl;
		else f << fileInfos[j] << '\t' << k << endl;
	}
	delete[] fileInfos;
	return 0;
}

//CMake Error: The current CMakeCache.txt directory
// C:/Users/17110/Desktop/dtw/cmake-build-debug/CMakeCache.txt
// is different than the directory
// f:/dtw/cmake-build-debug where CMakeCache.txt
// was created. This may result in binaries being created in the wrong place.
// If you are not sure, reedit the CMakeCache.txt