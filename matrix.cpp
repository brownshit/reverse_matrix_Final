#include "reverse_matrix_class_shape.h"
using namespace std;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

matrix::matrix(){}


//�ܺο��� ��������� �����ϱ� ���� �Լ���
void matrix::set_my_m1(double** m1)
{
	this->matrix_n1 = m1;
}
double** matrix::get_my_mat_n1()
{
	return this->matrix_n1;
}
//�������� �� �����Ϸ��� this�� �Լ��� �߰��Ѵ�.
//�� this �����ʹ� ��� �Լ��� ȣ��� ��ü�� �ּҸ� ����Ű�� ������ ������

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
//matrix�� ũ�⸦ �������� ���� function����
void matrix::matrix_size_get()
{
	cout << "N_By_N����� size input : ";
	cin >> this->matrix_size;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//�����Ҵ� �޸� �Ҵ��Լ�
void matrix::new_matrix()
{
	//matrix_n1�� �����Ҵ�
	this->matrix_n1 = new double* [this->matrix_size];
	for (int i = 0; i < this->matrix_size; i++)
	{
		this->matrix_n1[i] = new double[this->matrix_size];
	}

	//matrix_n2�� �����Ҵ�
	this->matrix_n2 = new double* [this->matrix_size];
	for (int i = 0; i < this->matrix_size; i++)
	{
		this->matrix_n2[i] = new double[this->matrix_size];
	}
}


//�����Ҵ� �޸� �����Լ�
void matrix::delete_matrix()
{
	delete[] this->matrix_n2, this->matrix_n1;
}

//��� ��ȯ�Լ�

void matrix::matrix_return(double** mymatrix, int n)
{
	cout << "[��� ���]" << endl;
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
//��� �� �ʱ�ȭ �Լ�

void matrix::matrix_n1_Init()
{
	//��������� �� ����
	for (int i = 0; i < this->matrix_size; i++)
	{
		for (int j = 0; j < this->matrix_size; j++)
		{
			cout << "������Ŀ��[" << i << "][" << j << "] : ";
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