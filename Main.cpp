#include <iostream>
#include <iomanip>
#include <ctime>


using namespace std;

const int SizeArray = 6;
int a[SizeArray];

void CreatingAnArray()
{
	for (int i = 0; i < SizeArray; i++)
	{
		for (int j = 0; j < SizeArray; j++)
		{
			a[i, j] = i + j;
			cout << a[i, j] << " ";
		}
		cout << "\n";
	}
}

void SumElements()
{
	struct tm buf;
	time_t t = time(NULL);
	localtime_s(&buf, &t);

	int Modulo = buf.tm_mday % SizeArray;
	int SumEl = 0;
	
	for (int i = 0; i < SizeArray; i++)
		SumEl = SumEl + static_cast<int>(a[i, Modulo]);

	cout << "Остаток деления равен: " << Modulo << "\nСумма элементов равна: " << SumEl;
}

int main() 
{
	setlocale(LC_ALL, "Russian");
	
	CreatingAnArray();
	SumElements();
}