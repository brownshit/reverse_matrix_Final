#include "reverse_matrix_class_shape.h"

using namespace std;

//�������Լ�
reverse_matrix_cofactor::reverse_matrix_cofactor(cofactor_deploy temp1, matrix temp2)
{
	mymatrix1 = temp1;
	mymatrix2 = temp2;
	matrix_1 = mymatrix1.cofactor_matrix();
	n = mymatrix2.get_my_num();

}

double** reverse_matrix_cofactor::cofactor_adjoint_matrix()
{
	double det = mymatrix1.determinant_0th(mymatrix1.get_matrix(), mymatrix1.get_num());
	if (det == 0)
	{
		cout << "��Ľ��� ���� 0. ����� ������ ������ �� ����." << endl;
		return 0;
	}
	else//���� adjoint�� �̿��� ����� ������ �����Ѵ�.
	{
		double itemp;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j){}
				else
				{
					itemp = matrix_1[i][j];
					matrix_1[i][j] = matrix_1[j][i];
					matrix_1[j][i] = itemp;
				}
				//matrix_1[i][j]
			}
		}
		//���� ���� ������ �����ϸ� ��ġ ��ķ� �ٲ��.
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix_1[i][j] = matrix_1[i][j] / det;
				//matrix_1[i][j]
			}
		}
		return matrix_1;
	}
	/*
		���μ� ���������� �� �����͵鸸 ���ߴ� .
		(1���� �����͵鸸 ���߱� ������ �߰������� �� ������ �����͵���� �����ش�.)
		�߿��Ѱ��� , det�� �������� �Ͱ�,
	*/
}