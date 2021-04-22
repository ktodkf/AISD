#include "Multiplication.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <iomanip>
using namespace std;

vector<float> ReatText()
{
	vector<float> vec_num;
	copy(istream_iterator<float>(cin), istream_iterator<float>(), back_inserter(vec_num));
	return vec_num;
}

float MinElement(vector <float>&vec_num)
{
	return *min_element(vec_num.begin(), vec_num.end());
}

vector<float> VectorMultiplication(vector<float>& vec_num)
{

	float min_element = MinElement(vec_num);
	vector<float> result_vec;
	for (float number: vec_num)
	{
		number = number * min_element;
		result_vec.push_back(number);
	}	
	sort(result_vec.begin(), result_vec.end());
	for (int i=0; i<size(result_vec);i++)
	{
		cout << fixed << showpoint;
		cout << setprecision(3);
		cout << result_vec[i] << " ";
	}
	return result_vec;
}

