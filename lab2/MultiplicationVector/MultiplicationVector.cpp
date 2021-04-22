// MultiplicationVector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Multiplication.h"


int main()
{
	cout << ENTERVECTOR << endl;
	vector<float> vec_num = ReatText();
	if (vec_num.empty())
	{
		cout << INCORRECTDATA;
		return 1;
	}	
	VectorMultiplication(vec_num);
	return 0;
}
