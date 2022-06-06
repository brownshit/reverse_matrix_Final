#include "reverse_matrix_class_shape.h"
using namespace std;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

matrix::matrix(){}

//외부에서 멤버변수에 접근하기 위한 함수들
void matrix::set_my_m1(double** m1)
{
	this->matrix_n1 = m1;
}
double** matrix::get_my_mat_n1()
{
	return this->matrix_n1;
}
void matrix::set_my_m2(double** m2)
{
	this->matrix_n2 = m2;
}
double** matrix::get_my_mat_n2()
{
	return this->matrix_n2;
}

void matrix::set_my_num(int num_val)
{
	this->matrix_size = num_val;
}
int matrix::get_my_num()
{
	return this->matrix_size;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//matrix의 크기를 가져오기 위한 function선언
void matrix::matrix_size_get()
{
	cout << "N_By_N행렬의 size input : ";
	cin >> this->matrix_size;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//동적할당 메모리 할당함수
void matrix::new_matrix()
{
	//matrix_n1의 동적할당
	this->matrix_n1 = new double* [this->matrix_size];
	for (int i = 0; i < this->matrix_size; i++)
	{
		this->matrix_n1[i] = new double[this->matrix_size];
	}

	//matrix_n2의 동적할당
	this->matrix_n2 = new double* [this->matrix_size];
	for (int i = 0; i < this->matrix_size; i++)
	{
		this->matrix_n2[i] = new double[this->matrix_size];
	}
}


//동적할당 메모리 해제함수
void matrix::delete_matrix()
{
	delete[] this->matrix_n2, this->matrix_n1;
}

//행렬 반환함수

void matrix::matrix_return(double** mymatrix, int n)
{
	cout << "[행렬 출력]" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mymatrix[i][j] << " ";
		}
		cout << endl;
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//행렬 값 초기화 함수

void matrix::matrix_n1_Init()
{
	//정방행렬의 값 지정
	for (int i = 0; i < this->matrix_size; i++)
	{
		for (int j = 0; j < this->matrix_size; j++)
		{
			cout << "정방행렬요소[" << i << "][" << j << "] : ";
			cin >> this->matrix_n1[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < this->matrix_size; i++)
	{
		for (int j = 0; j < this->matrix_size; j++)
		{
			if (i == j)
				this->matrix_n2[i][j] = 1;
			else
				this->matrix_n2[i][j] = 0;
		}
	}
}
