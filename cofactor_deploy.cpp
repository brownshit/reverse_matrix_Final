#include "reverse_matrix_class_shape.h"
using namespace std;

/*
	���� ��Ʈ������ �޾ƿ� ���͹̳�Ʈ�� ��Ľ� ��ȯ
		->cofactor�� ��Ҹ� ä���.
			->cofactor���� matrixȭ ��Ű�� �Լ�
			->cofactor ��Ʈ���� �Լ�
			
			->0�� cofactor���� sum->����� det
*/
cofactor_deploy::cofactor_deploy()
{
	matrix temp;
	for_cofactor_matrix = temp;
	matrix_1 = for_cofactor_matrix.get_my_mat_n1();
	//���� matrix_1�� ����ϱ� ���� matrix
	n = for_cofactor_matrix.get_my_num();
	det = 0;
}

double** cofactor_deploy::get_matrix()
{
	return this->matrix_1;
}
int cofactor_deploy::get_num()
{
	return this->n;
}
//prints the determinant
//	printf("the determinant is %lf\n", determinant(n, Matrix));

//M�� ���ο��� ��� ���� ������ n-1���پ�� ���¿����� ���ο� ����� �����Լ�

//determinant ��� �Լ�
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
double cofactor_deploy::determinant_0th(double** matrix_1, int n)//�ϴ� ���� ������ �ٲ� 
{
	if (n == 1) { return matrix_1[0][0]; }
	if (n == 2) {
		return matrix_1[0][0] * matrix_1[1][1] - matrix_1[1][0] * matrix_1[0][1];
	}

	for (int x = 0; x < n; ++x) 
	{
		det += ((x % 2 == 0 ? 1 : -1) * matrix_1[0][x] * determinant_0th(Submatrix(matrix_1, n, x, 0), n - 1));
	}


	return det;
	/*
		y�� ������ ù��° ���� ������ ����.
		x��,y��
	*/
	//return det;//�긦 ��ȯ�Ѵ�.Ŭ��������
}


//submatrix->determinant->cofactor
double **cofactor_deploy::cofactor_matrix()//�갡 ���μ����� matrix�����Ѵ�. �� �ȿ� �����ڵ��� ���ԵǾ��ִ�.
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

