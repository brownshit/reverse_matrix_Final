#include "reverse_matrix_class_shape.h"

using namespace std;

//생성자함수
reverse_matrix_cofactor::reverse_matrix_cofactor(cofactor_deploy temp1, matrix temp2)
{
	mymatrix1 = temp1;
	mymatrix2 = temp2;
	matrix_1 = mymatrix1.cofactor_matrix(mymatrix2.get_my_mat_n1(), mymatrix2.get_my_num());
	n = mymatrix2.get_my_num();

}

double** reverse_matrix_cofactor::cofactor_adjoint_matrix(double det, double** matrix_1, int n)
{
	//matrix_1은 cofactor_matrix이다.

	//determinant_0th 내부의 인자들은 무조건 matrix에서 가져와야 한다.

	cout << "[det] = " << det << endl;

	if (det == 0)
	{
		cout << "행렬식의 값이 0. 역행렬 연산을 진행할 수 없습니다." << endl;
		return 0;
	}
	else//이제 adjoint를 이용한 역행렬 연산을 진행한다.
	{
		double itemp;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j) {}
				else
				{
					itemp = matrix_1[i][j];
					matrix_1[i][j] = matrix_1[j][i];
					matrix_1[j][i] = itemp;
				}
				//matrix_1[i][j]
			}
		}
		//위의 이중 포문을 실행하면 전치 행렬로 바뀐다.
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix_1[i][j] = matrix_1[i][j] / det;
				//matrix_1[i][j]
			}
		}

		cout << "[matrix return : adjoint_reverse_matrix output]\n" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << matrix_1[j][i] << " ";
			cout << endl;
		}
		cout << endl;

		return matrix_1;
	}
}
