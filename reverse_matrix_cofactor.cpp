#include "reverse_matrix_class_shape.h"

using namespace std;

//생성자함수
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
		cout << "행렬식의 값이 0. 역행렬 연산을 진행할 수 없다." << endl;
		return 0;
	}
	else//이제 adjoint를 이용한 역행렬 연산을 진행한다.
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
		//위의 이중 포문을 실행하면 전치 행렬로 바뀐다.
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
		여인수 전개에서는 각 코펙터들만 구했다 .
		(1행의 코펙터들만 구했기 때문에 추가적으로 그 다음의 코펙터들까지 구해준다.)
		중요한것은 , det값 가져오는 것과,
	*/
}