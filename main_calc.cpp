#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"reverse_matrix_class_shape.h"
using namespace std;

int main(void)
{
	matrix m1;
	cofactor_deploy m2;
	reverse_matrix_gauss m3(m1);
	reverse_matrix_cofactor m4(m2, m1);
	int size_of_matrix;
	int run_num1 = 1;
	int run_num2 = 1;

	m1.matrix_size_get();
	size_of_matrix = m1.get_my_num();

	//==================================================================================================
	m1.new_matrix();
	//==================================================================================================
	m1.matrix_n1_Init();
	//두 행렬들의 출력
	m1.matrix_return(m1.get_my_mat_n1(), m1.get_my_num());
	m1.matrix_return(m1.get_my_mat_n2(), m1.get_my_num());
	//==================================================================================================
	//여인수 전개
	cout<<"[determinant_testing...] : " << m2.determinant_0th(m2.get_matrix(), m2.get_num()) <<" 입니다.\n" << endl;//가우스 일루미네이션에 들어간 식은 문제가 없다. cofactor_deploy가 문제였던 것.
	m2.return_matrix();
	m2.return_co_matrix();


		//역행렬 구하기
		//가우스 일루미네이션
Line1:
	cout<<"가우스 조던 소거법으로 역행렬을 출력하시겠습니까? [input : 1(yes)/0(no)] : " << endl;
	cin >> run_num1;
	if(run_num1 == 1)
	{
		m3.matrix_rev_return(m2);
		//행렬식으로 역행렬구하기
	}
	else if (run_num2 == 0)
	{
		cout << "[가우스 조던 소거법을 이용한 역행렬 연산을 건너뜁니다...]" << endl;
	}
	else {
		cout<<"[숫자를 정확히 입력해 주십시오]" << endl;
		goto Line1;
	}
Line2:
	cout << "여인수전개법으로 역행렬을 출력하시겠습니까? [input : 1(yes)/0(no)] : " << endl;
	cin >> run_num2;
	if (run_num2 == 1)
	{
		m4.cofactor_adjoint_matrix();
		
	}
	else if(run_num2 == 0)
	{
		cout<<"[여인수 전개법을 이용한 역행렬 연산을 건너뜁니다...]" << endl;
	}
	else {
		cout << "[숫자를 정확히 입력해 주십시오]" << endl;
		goto Line2;
	}
	//==================================================================================================
	m1.delete_matrix();
	//==================================================================================================
	return 0;
}

//===============================================================================================================
//여인수전개 오픈소스코드 변경하기==========================================

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
	//외부에서 멤버변수에 접근하기 위한 함수들
	void set_my_m1(double** m1)
	{
		this->matrix_n1 = m1;
	}
	double** get_my_mat_n1()
	{
		return this->matrix_n1;
	}
	//컴파일할 때 컴파일러는 this를 함수에 추가한다.
	//이 this 포인터는 멤버 함수가 호출된 객체의 주소를 가리키는 숨겨진 포인터

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

	//matrix의 크기를 가져오기 위한 function선언
	void matrix_size_get()
	{
		cout << "N_By_N행렬의 size input : ";
		cin >> this->matrix_size;
	}

	//동적할당 메모리 할당함수
	void new_matrix()
	{
		//matrix_n1의 동적할당
		this->matrix_n1 = new double* [this->matrix_size];
		for (int i = 0; i < this->matrix_size; i++)
		{
			this->matrix_n1[i] = new double[this->matrix_size];
		}

		//matrix_n2의 동적할당
		this->matrix_n2 = new double* [this->matrix_size];
		for (int i = 0; i < this->matrix_size; i++)
		{
			this->matrix_n2[i] = new double[this->matrix_size];
		}
	}


	//동적할당 메모리 해제함수
	void delete_matrix()
	{
		delete[] this->matrix_n2, this->matrix_n1;
	}

	//행렬 반환함수

	void matrix_return(double **mymatrix, int n)
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

	//행렬 값 초기화 함수

	void matrix_n1_Init()
	{
		//정방행렬의 값 지정
		for (int i = 0; i < this->matrix_size; i++)
		{
			for (int j = 0; j < this->matrix_size; j++)
			{
				cout << "정방행렬요소[" << i << "][" << j << "] : ";
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

	//행렬을 가져온다.
	matrix mymatrix;
	double** matrix_1;
	double** matrix_2;
	int n = mymatrix.get_my_num();
	//여인수 전개에서 사용할 행렬크기(바뀌어야 하므로 크기를 복사해온다.)
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
	double** matrix_rev_return(cofactor_deploy c1)
	{
		//determinant = 0이면, 0반환, 1이면 1반환
		if (c1.determinant(c1.get_matrix(), c1.get_num()) == 0)
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
		cout<<"test return : [정방행렬->단위행렬 output]\n"<<endl;
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
	//만약, rev_matrix 함수의 반환값이 0이면, main함수로 들어갈 때, 0, det!=0이면 역행렬이 반환된다.
};
*/

