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

//가우스 조던함수
double** reverse_matrix_gauss::matrix_rev_return(cofactor_deploy c1)
{
	//determinant = 0이면, 0반환, 1이면 1반환
	if (c1.determinant_0th(c1.get_matrix(), c1.get_num()) == 0)
	{
		cout << "행렬식의 값이 0. 역행렬 연산을 진행할 수 없다." << endl;
		return 0;
	}

	//가우스 조던 소거법을 이용할때, 연산은 matrix_1, matrix_2모두 같이 진행되어야 한다.
		//for문을 통해 연산

		//행 계산 후에 열이 변경되므로, 1차원 요소들을 먼저 사용해준다.  
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			//i==j경우에 연산을 먼저 진행해줘야 한다.
			//대각행렬이 1이 되도록 바꿔줘야 한다.
			if (i == j)
			{
				//matrix_1[i][j]
				//i==j인 경우에서 같은 행을 다 나눠준다.
				//이 경우 피봇들을 1로 만들어준다.
				if (i == 0)//이 if문은 피봇의 값이 0인경우 계산오류가 나지 않도록하는 계산이다. 
				{
					//i==0인 경우에는 주변행들을 해당행에 더해서 피봇이 0이 아닌수로 만들어줘야한다.
						//단위행렬에도 같은 연산 적용해야함.
					if (i > 0)
					{
						//바로 아래 행들을 피봇행에 더해주는 연산진행
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
						//i==n-1인 경우 바로 위의 행들을 피봇행에 더해주는 연산진행

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
				else//i가 0이 아닌경우! -> 그냥 실행해도된다
				{
					for (int jk = 0; jk < n; jk++)
					{
						//i==j인 경우에서 같은 행을 다 나눠준다.
						//이 경우 피봇들을 1로 만들어준다.
						this->matrix_1[i][jk] = this->matrix_1[i][jk] / this->matrix_1[i][j];
						this->matrix_2[i][jk] = this->matrix_2[i][jk] / this->matrix_1[i][j];
					}
				}

				//i==j아래의 요소들을 0으로 만들어주는 과정
				//조건 : i = j가 격자를 벗어나면 안된다.
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
				//i==j위의 요소들을 0으로 만들어주는 과정
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
	//위의 과정을 통해 matrix_1에는 단위행렬, matrix_2에는 역행렬이 저장되었을 것이다.
	cout << "test return : [정방행렬->단위행렬 output]\n" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << this->matrix_1[i][j] << " ";
		cout << endl;
	}
	cout << "test return : [단위행렬->역행렬 output]\n" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << this->matrix_2[i][j] << " ";
		cout << endl;
	}

	return this->matrix_2;
}
