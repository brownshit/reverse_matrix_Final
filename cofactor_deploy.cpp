#include "reverse_matrix_class_shape.h"
using namespace std;

cofactor_deploy::cofactor_deploy()
{
	matrix temp1;
	for_cofactor_matrix = temp1;
	matrix_1 = for_cofactor_matrix.get_my_mat_n1();
	//실제 matrix_1을 사용하기 위한 matrix
	n = for_cofactor_matrix.get_my_num();
}

void cofactor_deploy::return_matrix()
{
	for (int i = 0; i < this->n; i++)
	{
		for (int j = 0; j < this->n; j++)
		{
			cout << this->matrix_1[i][j] << " " << endl;
		}
		cout << "\n" << endl;
	}
}
void cofactor_deploy::return_co_matrix()
{
	for (int i = 0; i < this->n; i++)
	{
		for (int j = 0; j < this->n; j++)
		{
			cout << cofactor_matrix(for_cofactor_matrix.get_my_mat_n1(), for_cofactor_matrix.get_my_num())[i][j] << " " << endl;
		}
		cout << "\n" << endl;
	}
}

double** cofactor_deploy::get_matrix()
{
	return this->matrix_1;
}
int cofactor_deploy::get_num()
{
	return this->n;
}

double** cofactor_deploy::Submatrix(double** matrix_1, int n, int x, int y) {

	double** submatrix = new double* [n];
	int under_i = 0;

	for (int i = 0; i < n; i++)
	{
		submatrix[under_i] = new double[n];
		int under_j = 0;

		if (i == y)
		{
			continue;
		}

		for (int j = 0; j < n; j++)
		{
			if (j == x)
			{
				continue;
			}

			submatrix[under_i][under_j] = matrix_1[i][j];
			under_j++;
		}

		under_i++;
	}

	return submatrix;
}


//determinant
double cofactor_deploy::determinant_0th(double** matrix_1, int n)//일단 얘의 목적이 바뀜 
{
	double det = 0;
	if (n == 1) { return matrix_1[0][0]; }
	if (n == 2) {
		return matrix_1[0][0] * matrix_1[1][1] - matrix_1[1][0] * matrix_1[0][1];
	}

	for (int x = 0; x < n; ++x) 
	{
		det += ((x % 2 == 0 ? 1 : -1) * matrix_1[0][x] * determinant_0th(Submatrix(matrix_1, n, x, 0), n - 1));
	}


	return det;
}

//submatrix->determinant->cofactor
double **cofactor_deploy::cofactor_matrix(double**matrix_1, int n)//얘가 여인수들의 matrix생성한다. 그 안에 여인자들이 포함되어있다.
{
	double** matrix_of_cofactor = new double* [n];
	for (int i = 0; i < n; i++)
	{
		matrix_of_cofactor[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			matrix_of_cofactor[i][j]= (((i+j) % 2 == 0 ? 1 : -1) * determinant_0th(Submatrix(matrix_1, n, j, i), n - 1));
		}
	}
	
	return matrix_of_cofactor;
}

