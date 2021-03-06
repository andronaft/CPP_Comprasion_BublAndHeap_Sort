// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
//#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

int64_t comparison = 0;
int64_t appropriation = 0;
void bubbleSort(int *, int );
void siftDown(int *, int, int);
void heapSort(int *, int);
/*void input_in_file(int *, int);
void input_in_file(int* arrayPtr, int length_array) 
{
	ofstream fout_1("arr_1.txt",ios_base::app);
	for (int i = 0; i < length_array; i++) {
		fout_1 << arrayPtr[i] << " ";
		if (!((i + 1) % (length_array/10))) {
			fout_1 << "\n";
		}
	}
	fout_1 << "\n\n";
}
*/

void bubbleSort(int* arrayPtr, int length_array) 
{
	int temp = 0; 
	int64_t comprasion = 0;
	int64_t appropiation = 0;
	bool exit = false; 
	ofstream fout_2("result_bulb.txt",ios_base::app);
	//time_t end = 0, start = time(0);
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	while (!exit)
	{
		exit = true;
		for (int int_counter = 0; int_counter < (length_array - 1); int_counter++)
		{

			if (arrayPtr[int_counter] > arrayPtr[int_counter + 1])
			{
				appropiation++;
				temp = arrayPtr[int_counter];
				arrayPtr[int_counter] = arrayPtr[int_counter + 1];
				arrayPtr[int_counter + 1] = temp;
				exit = false;
			}
			comprasion++;
		}
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	//end = time(0) - start;
	fout_2 <<"bulb  //  size : " << length_array<<", comprasion : " << comprasion << " , appropiation : " << appropiation << " , time : " << duration_cast<microseconds>(t2 - t1).count() << " microsec." << "\n";
	cout <<"bulb  //  size : " << length_array<<", comprasion : " <<comprasion  << " , appropiation : " << appropiation << " , time : " << duration_cast<microseconds>(t2 - t1).count() << " microsec." << "\n";
}


void filling_array(int *, int,int ,int);


void filling_array(int* arrayPtr, int length_array,int min ,int max)
{
	for (int i = 0; i < length_array; i++) {
		arrayPtr[i] = rand() % (max - min + 1) + min;
	}

}


void arrpr(int *, int *, int);


void arrpr(int* arrayPtr, int* arrayPrt_2, int lenght_array)
{
	for (int i = 0; i < lenght_array; i++) {
		arrayPrt_2[i] = arrayPtr[i];
	}
}




int main()
{
	remove("arr.txt");
	remove("result_bulb.txt");
	remove("result_pir.txt");
	ofstream fout("arr.txt",ios_base::app);
	
	int arr_1[100], arr_2[1000], arr_3[100000];
	int arr_1_1[100], arr_2_1[1000], arr_3_1[100000];
	
	int min, max;
	do {
		
			cout <<  "input the min of elements\n" ;
			cin >> min;
			cout <<  "input max of elements\n" ;
			cin >> max;
		
		if (max < min) {
			cout << "max must be > min\n";
		}
	} while (max < min);

	/////////////////////////// filling arr_1//////////////////////////////////////////////////

	cout << "please dont exist programinng ws run\n";
	int i;
	
	cout << "was going filling the arrays by randoms numbers for "<<min<<" to "<< max<<"\n";
	cout << "filling 1 array(arr_1)...\n";
	filling_array(arr_1, 100, min, max);
	fout << "not sort firsr arraay arr_1\n\n";
	cout << "input arr_1 in arr.txt\n";
	for (int i = 0; i < 100; i++) {
		fout << arr_1[i] << " ";
		if (!((i + 1) % 10)) {
			fout << "\n";
		}
	}
	fout << "\n\n";
	


	/////////////////////////// filling  arr_2//////////////////////////////////////////////////

	cout << "filling 2 array(arr_2)...\n";
	filling_array(arr_2, 1000, min, max);
	cout << "input arr_2 in arr.txt\n";
	fout << "not sort 2 arraay arr_2\n\n";
	for (int i = 0; i < 1000; i++) {
		fout << arr_2[i] << " ";
		if (!((i + 1) % 100)) {
			fout << "\n";
		}
	}
	fout << "\n\n";

	/////////////////////////// filling  arr_3//////////////////////////////////////////////////

	cout << "fillinf 3 array(arr_3)...\n";
	filling_array(arr_3, 100000, min, max);
	cout << "input arr_3 in arr.txt\n";
	fout << "not sort 3 arraay arr_3\n\n";
	for (int i = 0; i < 100000; i++) {
		fout << arr_3[i] << " ";
		if (!((i + 1) % 10000)) {
			fout << "\n";
		}
	}
	fout << "\n\n";

	arrpr(arr_1, arr_1_1, 100);
	arrpr(arr_2, arr_2_1, 1000);
	arrpr(arr_3, arr_3_1, 100000);
	
	

	/////////////////////////// sorting arr_1 bulb//////////////////////////////////////////////////

	cout << "sorting arr_1 with bulb\n///\n";
	
	bubbleSort(arr_1, 100);
	
	cout << "///\n input sorting arr_1 with bulb in arr.txt\n";

	fout << "sort array arr_1 with bulb \n\n";
	
	for (int i = 0; i < 100; i++) {
		fout << arr_1[i] << " ";
		if (!((i + 1) % 10)) {
			fout << "\n";
		}
	}
	fout << "\n\n";
	


	/////////////////////////// sorting arr_2 bulb//////////////////////////////////////////////////

	cout << "sorting arr_2 with bulb\n///\n";
	
		
	bubbleSort(arr_2, 1000);
	
	cout << "///\n input sorting arr_2 with bulb in arr.txt\n";
	fout << "sort  array arr_2 with bulb\n\n";
	for (int i = 0; i < 1000; i++) {
		fout << arr_2[i] << " ";
		if (!((i + 1) % 100)) {
			fout << "\n";
		}
	}
	fout << "\n\n";

	/////////////////////////// sorting arr_3 bulb//////////////////////////////////////////////////

	cout << "sorting arr_3 with bulb\n///\n";
	
	bubbleSort(arr_3, 100000);
	
	cout << "///\n input sorting arr_3 with bulb in arr.txt\n";
	fout << "sort array arr_3 with bulb\n\n";
	for (int i = 0; i < 100000; i++) {
		fout << arr_3[i] << " ";
		if (!((i + 1) % 10000)) {
			fout << "\n";
		}
	}
	fout << "\n\n";
	/////////////////////////// sorting arr_1 pir//////////////////////////////////////////////////
	cout << "sorting arr_1 with pir\n///\n";
	
	heapSort(arr_1_1, 100);
	cout << "///\n input sorting arr_1 with pir in arr.txt\n";

	fout << "sort array arr_1 with pir \n\n";

	for (int i = 0; i < 100; i++) {
		fout << arr_1_1[i] << " ";
		if (!((i + 1) % 10)) {
			fout << "\n";
		}
	}
	fout << "\n\n";
	/////////////////////////// sorting arr_2 pir//////////////////////////////////////////////////

	cout << "sorting arr_2 with pir\n///\n";


	heapSort(arr_2_1, 1000);

	cout << "///\n input sorting arr_2 with pir in arr.txt\n";
	fout << "sort  array arr_2 with pir\n\n";
	for (int i = 0; i < 1000; i++) {
		fout << arr_2_1[i] << " ";
		if (!((i + 1) % 100)) {
			fout << "\n";
		}
	}
	fout << "\n\n";
	/////////////////////////// sorting arr_3 bulb//////////////////////////////////////////////////

	cout << "sorting arr_3 with pir\n///\n";

	heapSort(arr_3_1, 100000);

	cout << "///\n input sorting arr_3 with pir in arr.txt\n";
	fout << "sort array arr_3 with pir\n\n";
	for (int i = 0; i < 100000; i++) {
		fout << arr_3_1[i] << " ";
		if (!((i + 1) % 10000)) {
			fout << "\n";
		}
	}
	fout << "\n\n";
	
	cout << "thats all\n";
	system("pause");
	
	return 0;
}

void siftDown(int *numbers, int root, int bottom)
{
	int maxChild; // индекс максимального потомка
	int done = 0; // флаг того, что куча сформирована
				  // Пока не дошли до последнего ряда
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom) {    // если мы в последнем ряду, 
			comparison++;	maxChild = root * 2;    // запоминаем левый потомок
		}	// иначе запоминаем больший потомок из двух
		else if (numbers[root * 2] > numbers[root * 2 + 1]) {
			maxChild = root * 2; comparison++;
		}
		else
			maxChild = root * 2 + 1;
		// если элемент вершины меньше максимального потомка
		comparison++;
		if (numbers[root] < numbers[maxChild])
		{
			appropriation++;
			int temp = numbers[root]; // меняем их местами
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = temp;
			root = maxChild;
		}
		else // иначе
			done = 1; // пирамида сформирована
	}
}
// Функция сортировки на куче
void heapSort(int *numbers, int array_size)
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	ofstream fout_3("result_pir.txt", ios_base::app);
	// Формируем нижний ряд пирамиды
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		siftDown(numbers, i, array_size);
	// Просеиваем через пирамиду остальные элементы
	for (int i = array_size - 1; i >= 1; i--)
	{
		appropriation++;
		int temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		siftDown(numbers, 0, i - 1);
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	fout_3 << "pir  //  size : " << array_size << ", comprasion : " << comparison << " , appropiation : " << appropriation << " , time : " << duration_cast<microseconds>(t2 - t1).count() << " microsec." << "\n";
	cout << "pir  //  size : " << array_size << ", comprasion : " << comparison << " , appropiation : " << appropriation << " , time : " << duration_cast<microseconds>(t2 - t1).count() << " microsec." << "\n";

	comparison = 0; appropriation = 0;

}