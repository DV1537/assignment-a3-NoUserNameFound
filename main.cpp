#include"Point.h"
#include"Line.h"
#include"Triangle.h"
#include"Polygon.h"
#include<sstream>
using namespace std;

int main(int argc, const char * argv[])
{
	cout.unsetf(std::ios::floatfield);                // floatfield not set
	cout.precision(3);
	float x;
	int size[2];
	size[0] = 2;
	size[1] = 2;

	int number[2];
	number[0] = 0;
	number[1] = 0;
	float* numbers[2];
	numbers[0] = new float[size[0]];
	numbers[1] = new float[size[1]];
	Shape* shapes[2];
	string line;
	int p = 0;
	ifstream inFile;
	inFile.open(argv[1]);

	if (!inFile)
	{
		cout << "Could not open file!" << endl;
	}
	else
	{
		
		while (getline(inFile,line))
		{
	
			istringstream row(line);

			while (row >> x)
			{
				if (number<size)
				{

					numbers[p][number[p]] = x;
					number[p]++;
				}
				else
				{
					float* temp = new float[size[p]];
					for (int i = 0; i < size[p]; i++)
					{
						temp[i] = numbers[p][i];
					}
					delete[] numbers[p];
					size[p]++;
					numbers[p] = new float[size[p]];
					for (int i = 0; i < size[p] - 1; i++)
					{
						numbers[p][i] = temp[i];
					}
					delete[] temp;


					numbers[p][number[p]] = x;
					number[p]++;
				}
			
			


			}
			p++;

		}

		for (int i = 0; i < 2; i++)
		{
			if (number[i] == 2)
			{

				shapes[i] = new Point(numbers[i][0], numbers[i][1]);
			}
			else if (number[i] == 4)
			{

				shapes[i] = new Line(numbers[i][0], numbers[i][1], numbers[i][2], numbers[i][3]);
			}
			else if (number[i] == 6)
			{
				shapes[i] = new Triangle(numbers[i][0], numbers[i][1], numbers[i][2], numbers[i][3], numbers[i][4], numbers[i][5]);
			}
			else
			{
				shapes[i] = new Polygon(numbers[i], number[i]);
			}

			cout << "Input: ";
			for (int z = 0; z < number[i]; z++)
			{
				cout << shapes[i]->getVertices()[z] << " ";
			}
		
			cout << endl;
		}

		shapes[0] = *shapes[0] + *shapes[1];
	
		
		
		cout << "Output: ";
	
		
	
		//cout << *shapes[0];

		cout <<  shapes[0]->area();

	
		

		cout << endl;

		delete shapes[0];
		delete shapes[1];
	}
	delete[] numbers[0];
	delete[] numbers[1];
	
	system("pause");
	return 0;
}