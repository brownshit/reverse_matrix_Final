#include "reverse_matrix_class_shape.h"

using namespace std;

reverse_matrix_gauss::reverse_matrix_gauss(cofactor_deploy temp2, matrix temp1)
{
	mymatrix1 = temp1;
	mymatrix2 = temp2;
	matrix_1 = mymatrix1.get_my_mat_n1();
	matrix_2 = mymatrix1.get_my_mat_n2();
	n = mymatrix1.get_my_num();
}


//가우스 조던함수
double** reverse_matrix_gauss::matrix_rev_return(double det, double**matrix_1, double**matrix_2, int n)
{
	//matrix연산 후에도 그 값이 바뀌어 다음연산에 지장을 주지 않게 하기 위해서
	double** matrix_temp = new double* [n];
	for (int i = 0; i < n; i++)
	{
		matrix_temp[i] = new double[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix_temp[i][j] = matrix_1[i][j];
		}
	}


	//determinant_0th 내부의 인자들은 무조건 matrix에서 가져와야 한다.

	cout << "[det] = " << det << endl;

	//determinant = 0이면, 0반환, 1이면 1반환
	if (det == 0)
	{
		cout << "행렬식의 값이 0. 역행렬 연산을 진행할 수 없습니다." << endl;
		return 0;
	}

	//가우스 조던 소거법을 이용할때, 연산은 matrix_1, matrix_2모두 같이 진행되어야 한다.
		//for문을 통해 연산

    double r2 = 0;
    int i_flag = 0;
    for (int a = 0; a < n; a++) 
    {
        for (int b = 0; b < n; b++) 
        {
            if (matrix_1[b][b] != 1) 
            {
                if (matrix_1[b][b] == 0) 
                {
                    for (int i = b; i < n; i++) 
                    {
                        if (matrix_1[i][b] != 0) 
                        {
                            i_flag = i;
                        }
                    }

                    for (int i = 0; i < n; i++) 
                    {
                        if (b == n - 1) 
                        {
                            r2 = matrix_1[b - 1][i];
                            matrix_1[b][i] = matrix_1[b][i] + r2;
                            matrix_2[b][i] = matrix_2[b][i] + r2;
                        }
                        else 
                        {
                            r2 = matrix_1[i_flag][i];
                            matrix_1[b][i] = matrix_1[b][i] + r2;
                            matrix_2[b][i] = matrix_2[b][i] + r2;
                        }
                    }
                }

                double k = matrix_1[b][b];
                for (int i = 0; i < n; i++) 
                {
                    matrix_1[b][i] = matrix_1[b][i] / k;
                    matrix_2[b][i] = matrix_2[b][i] / k;
                }
            }
        }
    }

    for (int j = 0; j < n; j++) 
    {
        for (int i = j; i < n - 1; i++) 
        {
            double k = 0;
            if (matrix_1[i + 1][j] == 0) 
            {
                continue;
            }
            k = (1 / matrix_1[i + 1][j]);

            for (int l = 0; l < n; l++) 
            {
                matrix_1[i + 1][l] = k * matrix_1[i + 1][l] - matrix_1[j][l];
                matrix_2[i + 1][l] = k * matrix_2[i + 1][l] - matrix_2[j][l];
            }

            double r2 = 0;
            int i_flag = 0;

            for (int a = 0; a < n; a++) 
            {
                for (int b = 0; b < n; b++) 
                {
                    if (matrix_1[b][b] != 1) 
                    {
                        if (matrix_1[b][b] == 0) 
                        {
                            for (int i = b; i < n; i++) 
                            {
                                if (matrix_1[i][b] != 0) 
                                {
                                    i_flag = i;
                                }
                            }
                            for (int i = 0; i < n; i++) 
                            {
                                if (b == n - 1) 
                                {
                                    r2 = matrix_1[b - 1][i];
                                    matrix_1[b][i] = matrix_1[b][i] + r2;
                                    matrix_2[b][i] = matrix_2[b][i] + r2;
                                }
                                else 
                                {
                                    r2 = matrix_1[i_flag][i];
                                    matrix_1[b][i] = matrix_1[b][i] + r2;
                                    matrix_2[b][i] = matrix_2[b][i] + r2;
                                }
                            }
                        }

                        double k = matrix_1[b][b];
                        for (int i = 0; i < n; i++) 
                        {
                            matrix_1[b][i] = matrix_1[b][i] / k;
                            matrix_2[b][i] = matrix_2[b][i] / k;
                        }
                    }
                }
            }

        }
    }


    for (int j = 0; j < n; j++) 
    {
        for (int i = j; i < n - 1; i++) 
        {
            double r = matrix_1[n - 2 - i][n - 1 - j];

            for (int l = 0; l < n; l++) 
            {
                matrix_1[n - 2 - i][l] = matrix_1[n - 2 - i][l] - r * matrix_1[n - 1 - j][l];
                matrix_2[n - 2 - i][l] = matrix_2[n - 2 - i][l] - r * matrix_2[n - 1 - j][l];
            }
        }
    }

	cout << "[matrix return : gauss_jordan_reverse_matrix output]\n" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix_2[i][j] << " ";
		cout << endl;
	}
	cout << endl;


//cofactor 연산을 하기 위한 필연적인 코드

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix_1[i][j] = matrix_temp[i][j];
		}
	}

	delete[]matrix_temp;

	return this->matrix_2;
}
