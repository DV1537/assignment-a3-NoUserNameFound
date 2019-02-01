#include<iostream>
#include <fstream>
#include<string>

using namespace std;

int main(int argc, const char * argv[])
{
	int x;
	int sum = 0;
	int size = 2;
	int number = 0;
	int* numbers = new int[size];

	ifstream inFile;
	inFile.open(argv[1]);

	if (!inFile)
	{
		cout << "Could not open file!" << endl;
	}
	else
	{
		cout << "Input: ";
		while (inFile >> x)
		{
			if (number<size)
			{
				sum += x;
				numbers[number] = x;
				number++;
			}
			else
			{
				int* temp = new int[size];
				for (int i = 0; i < size; i++)
				{
					temp[i] = numbers[i];
				}
				delete[] numbers;
				numbers = new int[++size];
				for (int i = 0; i < size - 1; i++)
				{
					numbers[i] = temp[i];
				}
				delete[] temp;

				sum += x;
				numbers[number++] = x;
			}
			cout << to_string(x) << " ";
		}
		int avarage = sum / size;
		cout << "          Output: ";
		for (int i = 0; i < size; i++)
		{
			if (numbers[i] > avarage)
			{
				cout << to_string(numbers[i]) << " ";
			}

		}
		cout << endl;
	}

	system("pause");
	delete[] numbers;
	return 0;
}