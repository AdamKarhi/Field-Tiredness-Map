#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main() {
	int sizeX = 0, sizeY = 0;
	int** newField = nullptr;
	int** prevField = nullptr;
	int year = 0, plantations;
	int startx,endx, starty,endy;
	string file;
	cout << "Enter File Name" << endl;
	cin >> file;
	//Open file
	ifstream fin(file);
	//read sizeX and sizeY from file
	fin >> sizeX;
	fin >> sizeY;

	//Allocate memory
	prevField = new int* [sizeY];
	newField = new int* [sizeY];
	for (int i = 0; i <sizeY ; i++)
	{
		prevField[i] = new int[sizeX]{0};
		newField[i] = new int[sizeX]{0};
	}
	//plant all years until 2017
	do 
	{
		fin >> year;
		fin >> plantations;
		//plant in small patches
		for (int i = 0; i < plantations; i++){
			fin >> startx >> starty >> endx >> endy;
			for (int i2 = starty; i2 <= endy; i2++){
				for (int i3 = startx; i3 <= endx; i3++){
					newField[i2][i3] = newField[i2][i2] + 1;
				}
			}
		}
		//TiredNess
		for (int i = 0; i < sizeY; i++) {
			for (int j = 0; j < sizeX; j++) {
				if (prevField[i][j] == newField[i][j] && newField[i][j] > 0)
				{
					newField[i][j] = newField[i][j] - 1;
				}
				prevField[i][j] = newField[i][j];
			}
		}

	} while (year != 2017);
	//Print output
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			cout << prevField[i][j] << " ";
		}
		cout << endl;
	}
	fin.close();

	for (int i = 0; i < sizeY; i++)
	{
		delete[] newField[i];
		delete[] prevField[i];
	}
	delete[] newField;
	delete[] prevField;
	return 0;
}
