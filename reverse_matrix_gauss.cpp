#include "reverse_matrix_class_shape.h"

using namespace std;

reverse_matrix_gauss::reverse_matrix_gauss(matrix temp1)
{
	mymatrix = temp1;
	matrix_1 = mymatrix.get_my_mat_n1();
	matrix_2 = mymatrix.get_my_mat_n2();
	n = mymatrix.get_my_num();
}

void reverse_matrix_gauss::matrix_return(double** mymatrix, int n)
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

//���콺 �����Լ�
double** reverse_matrix_gauss::matrix_rev_return(cofactor_deploy c1)
{
	//determinant = 0�̸�, 0��ȯ, 1�̸� 1��ȯ
	if (c1.determinant_0th(c1.get_matrix(), c1.get_num()) == 0)
	{
		cout << "��Ľ��� ���� 0. ����� ������ ������ �� ����." << endl;
		return 0;
	}

	//���콺 ���� �ҰŹ��� �̿��Ҷ�, ������ matrix_1, matrix_2��� ���� ����Ǿ�� �Ѵ�.
		//for���� ���� ����

		//�� ��� �Ŀ� ���� ����ǹǷ�, 1���� ��ҵ��� ���� ������ش�.  
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			//i==j��쿡 ������ ���� ��������� �Ѵ�.
			//�밢����� 1�� �ǵ��� �ٲ���� �Ѵ�.
			if (i == j)
			{
				//matrix_1[i][j]
				//i==j�� ��쿡�� ���� ���� �� �����ش�.
				//�� ��� �Ǻ����� 1�� ������ش�.
				if (i == 0)//�� if���� �Ǻ��� ���� 0�ΰ�� �������� ���� �ʵ����ϴ� ����̴�. 
				{
					//i==0�� ��쿡�� �ֺ������ �ش��࿡ ���ؼ� �Ǻ��� 0�� �ƴѼ��� ���������Ѵ�.
						//������Ŀ��� ���� ���� �����ؾ���.
					if (i > 0)
					{
						//�ٷ� �Ʒ� ����� �Ǻ��࿡ �����ִ� ��������
						for (int jx = 0; jx < n; jx++)
						{
							this->matrix_1[i][jx] += this->matrix_1[i + 1][jx];
							this->matrix_2[i][jx] += this->matrix_2[i + 1][jx];
						}

						for (int jk = 0; jk < n; jk++)
						{

							this->matrix_1[i][jk] = this->matrix_1[i][jk] / this->matrix_1[i][j];
							this->matrix_2[i][jk] = this->matrix_2[i][jk] / this->matrix_1[i][j];
						}
					}
					else if (i = (n - 1))
					{
						//i==n-1�� ��� �ٷ� ���� ����� �Ǻ��࿡ �����ִ� ��������

						for (int jx = 0; jx < n; jx++)
						{
							this->matrix_1[i][jx] += this->matrix_1[i - 1][jx];
							this->matrix_2[i][jx] += this->matrix_2[i - 1][jx];
						}

						for (int jk = 0; jk < n; jk++)
						{

							this->matrix_1[i][jk] = this->matrix_1[i][jk] / this->matrix_1[i][j];
							this->matrix_2[i][jk] = this->matrix_2[i][jk] / this->matrix_1[i][j];
						}
					}

				}
				else//i�� 0�� �ƴѰ��! -> �׳� �����ص��ȴ�
				{
					for (int jk = 0; jk < n; jk++)
					{
						//i==j�� ��쿡�� ���� ���� �� �����ش�.
						//�� ��� �Ǻ����� 1�� ������ش�.
						this->matrix_1[i][jk] = this->matrix_1[i][jk] / this->matrix_1[i][j];
						this->matrix_2[i][jk] = this->matrix_2[i][jk] / this->matrix_1[i][j];
					}
				}

				//i==j�Ʒ��� ��ҵ��� 0���� ������ִ� ����
				//���� : i = j�� ���ڸ� ����� �ȵȴ�.
				if (i > 0)
				{
					for (int ik = i + 1; ik < n; ik++)
					{
						for (int jk = 0; jk < n; jk++)
						{
							this->matrix_1[ik][jk] -= this->matrix_1[ik][jk] * this->matrix_1[i][jk];
							this->matrix_2[ik][jk] -= this->matrix_2[ik][jk] * this->matrix_2[i][jk];
						}
					}
				}
				//i==j���� ��ҵ��� 0���� ������ִ� ����
				if (i < n)
				{
					for (int ik = n - 1; ik > (-1); ik--)
					{
						for (int jk = 0; jk < n; jk++)
						{
							this->matrix_1[ik][jk] -= this->matrix_1[ik][jk] * this->matrix_1[i][jk];
							this->matrix_2[ik][jk] -= this->matrix_2[ik][jk] * this->matrix_2[i][jk];
						}
					}
				}
			}
		}
	}
	//���� ������ ���� matrix_1���� �������, matrix_2���� ������� ����Ǿ��� ���̴�.
	cout << "test return : [�������->������� output]\n" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << this->matrix_1[i][j] << " ";
		cout << endl;
	}
	cout << "test return : [�������->����� output]\n" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << this->matrix_2[i][j] << " ";
		cout << endl;
	}

	return this->matrix_2;
}
