#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cmath>//pow�Լ��� ����ϱ� ���� ��������߰�
#include"reverse_matrix_class_shape.h"

using namespace std;

//===============================================================================================================
//main �Լ�

int main(void)
{
	matrix m1;
	cofactor_deploy m2;
	reverse_matrix_gauss m3(m1);
	reverse_matrix_cofactor m4(m2, m1);

	int size_of_matrix;
	m1.matrix_size_get();
	size_of_matrix = m1.get_my_num();
	//==================================================================================================
	m1.new_matrix();
	//==================================================================================================
	m1.matrix_n1_Init();
	//�� ��ĵ��� ���
	m1.matrix_return(m1.get_my_mat_n1(), m1.get_my_num());
	m1.matrix_return(m1.get_my_mat_n2(), m1.get_my_num());
	//==================================================================================================
	//���μ� ����
	cout<<"[determinant_testing...] : " << m2.determinant_0th(m2.get_matrix(), m2.get_num()) <<" �Դϴ�.\n" << endl;//���콺 �Ϸ�̳��̼ǿ� �� ���� ������ ����. cofactor_deploy�� �������� ��.
	
		//����� ���ϱ�
		//���콺 �Ϸ�̳��̼�
	m3.matrix_rev_return(m2);
		//��Ľ����� ����ı��ϱ�

	//==================================================================================================
	m1.delete_matrix();
	//==================================================================================================
	return 0;
}

//===============================================================================================================
//���μ����� ���¼ҽ��ڵ� �����ϱ�==========================================

/*
	int main()
{
	int n, k = 0;


	printf("how many rows does the matrix have");
	scanf("%d", &n);
	double Matrix[n][n];
	printf("enter the numbers in order with an enter after each one");
	//Taking user input for 2D array
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%lf", &Matrix[i][j]);
		}
	}

	//prints the determinant
	printf("the determinant is %lf\n", determinant(n, Matrix));

	return 0;
}
*/

/*
class matrix {
	double** matrix_n1;
	double** matrix_n2;
	int matrix_size;

public:
	matrix() {};
	//�ܺο��� ��������� �����ϱ� ���� �Լ���
	void set_my_m1(double** m1)
	{
		this->matrix_n1 = m1;
	}
	double** get_my_mat_n1()
	{
		return this->matrix_n1;
	}
	//�������� �� �����Ϸ��� this�� �Լ��� �߰��Ѵ�.
	//�� this �����ʹ� ��� �Լ��� ȣ��� ��ü�� �ּҸ� ����Ű�� ������ ������

	void set_my_m2(double **m2)
	{
		this->matrix_n2 = m2;
	}
	double** get_my_mat_n2()
	{
		return this->matrix_n2;
	}

	void set_my_num(int num_val)
	{
		this->matrix_size = num_val;
	}
	int get_my_num()
	{
		return this->matrix_size;
	}

	//matrix�� ũ�⸦ �������� ���� function����
	void matrix_size_get()
	{
		cout << "N_By_N����� size input : ";
		cin >> this->matrix_size;
	}

	//�����Ҵ� �޸� �Ҵ��Լ�
	void new_matrix()
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
	void delete_matrix()
	{
		delete[] this->matrix_n2, this->matrix_n1;
	}

	//��� ��ȯ�Լ�

	void matrix_return(double **mymatrix, int n)
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

	//��� �� �ʱ�ȭ �Լ�

	void matrix_n1_Init()
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
};
*/

/*
class reverse_matrix_gauss {

	//����� �����´�.
	matrix mymatrix;
	double** matrix_1;
	double** matrix_2;
	int n = mymatrix.get_my_num();
	//���μ� �������� ����� ���ũ��(�ٲ��� �ϹǷ� ũ�⸦ �����ؿ´�.)
	int u_matrix_n = n;

public:
	reverse_matrix_gauss(matrix temp1)
	{
		mymatrix = temp1;
		matrix_1 = mymatrix.get_my_mat_n1();
		matrix_2 = mymatrix.get_my_mat_n2();
	}

	void matrix_return(double** mymatrix, int n)
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
	double** matrix_rev_return(cofactor_deploy c1)
	{
		//determinant = 0�̸�, 0��ȯ, 1�̸� 1��ȯ
		if (c1.determinant(c1.get_matrix(), c1.get_num()) == 0)
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
		cout<<"test return : [�������->������� output]\n"<<endl;
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
	//����, rev_matrix �Լ��� ��ȯ���� 0�̸�, main�Լ��� �� ��, 0, det!=0�̸� ������� ��ȯ�ȴ�.
};
*/

