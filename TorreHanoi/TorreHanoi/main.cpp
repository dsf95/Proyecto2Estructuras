#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <dos.h>
#include <time.h>
#include <math.h>
#include <stdio.h>  
#include <windows.h> 

using namespace std;
//-----------------------------------------------------------------------------
struct HANOI
{
	int tope;
	int disco[10];
};
//-----------------------------------------------------------------------------
//									INICIALIZAR PILA
//-----------------------------------------------------------------------------
void inicializar(struct HANOI *pila)
{
	int i;
	pila->tope = 0;
	for (i = 0; i<11; i++)
		pila->disco[i] = 0;
}
//-----------------------------------------------------------------------------
//									    EMPEZAR
//-----------------------------------------------------------------------------
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void empezar(int n, struct HANOI *pila)
{
	int y;
	int i;
	y = n;
	for (i = 0; i<n; i++)
	{
		pila->disco[pila->tope] = y; pila->tope++; y--;
	}
}
//-----------------------------------------------------------------------------
void imprimir(int n, struct HANOI *pila1, struct HANOI *pila2, struct HANOI *pila3)
{
	system("cls");
	int y = 17;
	int cont1 = 0;
	int cont2 = 0;
	int cont3 = 0;
	int a = 219;
	int x1 = 5;
	int x2 = 30;
	int x3 = 55;
	for (int i = 0; i<n; i++)
	{
		gotoxy(x1, y);

		for (int k = 0; k < pila1->disco[cont1]; k++)
		{
			cout << a << a;
		}
		cont1++;
		x1++;


		gotoxy(x2, y);
		for (int m = 0; m < pila2->disco[cont2]; m++)
		{
			cout << a << a;
		}
		cont2++;
		x2++;

		gotoxy(x3, y);
		for (int r = 0; r < pila3->disco[cont3]; r++)
		{
			cout << a << a;
		}
		cont3++;
		x3++;

		y--;

		gotoxy(x1, (y - 2));
	}
	getchar();

}


//-----------------------------------------------------------------------------
//									    HANOI
//-----------------------------------------------------------------------------

void funcion_hanoi(int n, struct HANOI *pila1, struct HANOI *pila2, struct HANOI *pila3)
{
	int vacio, mayor, menor;
	int cuenta_mov = 0;
	if (n % 2 == 0)
	{
		char x = '1';
		do
		{
			switch (x)
			{
			case '1':
				pila2->disco[pila2->tope] = pila1->disco[(pila1->tope) - 1];
				pila1->disco[(pila1->tope) - 1] = 0;
				pila2->tope = (pila2->tope) + 1;
				pila1->tope = (pila1->tope) - 1;
				x = '2';
				imprimir(n, pila1, pila2, pila3);
				cuenta_mov++;
				break;

			case '2':
				pila3->disco[pila3->tope] = pila2->disco[(pila2->tope) - 1];
				pila2->disco[(pila2->tope) - 1] = 0;
				pila3->tope = (pila3->tope) + 1;
				pila2->tope = (pila2->tope) - 1;
				x = '3';
				imprimir(n, pila1, pila2, pila3);
				cuenta_mov++;
				if (pila3->tope == n)
				{
					gotoxy(37, 20); cout << "LISTO!";
					gotoxy(33, 21); cout << cuenta_mov << " MOVIMIENTOS";
				
					exit(1);
				}

				break;
			case '3':
				pila1->disco[pila1->tope] = pila3->disco[(pila3->tope) - 1];
				pila3->disco[(pila3->tope) - 1] = 0;
				pila1->tope = (pila1->tope) + 1;
				pila3->tope = (pila3->tope) - 1;
				x = '1';
				imprimir(n, pila1, pila2, pila3);
				cuenta_mov++;
				break;
			};
			char aux = x;
			switch (aux)
			{
			case '1':

				if ((pila2->disco[(pila2->tope) - 1] < pila3->disco[(pila3->tope) - 1]) || pila3->tope == 0)
				{
					pila3->disco[pila3->tope] = pila2->disco[(pila2->tope) - 1];
					pila2->disco[(pila2->tope) - 1] = 0;
					pila3->tope = (pila3->tope) + 1;
					pila2->tope = (pila2->tope) - 1;

				}
				else
				{
					pila2->disco[pila2->tope] = pila3->disco[(pila3->tope) - 1];
					pila3->disco[(pila3->tope) - 1] = 0;
					pila3->tope = (pila3->tope) - 1;
					pila2->tope = (pila2->tope) + 1;
				}
				imprimir(n, pila1, pila2, pila3);
				cuenta_mov++;
				break;
			case '2':
				if ((pila1->disco[(pila1->tope) - 1] < pila3->disco[(pila3->tope) - 1]) || pila3->tope == 0)
				{
					pila3->disco[pila3->tope] = pila1->disco[(pila1->tope) - 1];
					pila1->disco[(pila1->tope) - 1] = 0;
					pila3->tope = (pila3->tope) + 1;
					pila1->tope = (pila1->tope) - 1;
				}
				else
				{
					pila1->disco[pila1->tope] = pila3->disco[(pila3->tope) - 1];
					pila3->disco[(pila3->tope) - 1] = 0;
					pila1->tope = (pila1->tope) + 1;
					pila3->tope = (pila3->tope) - 1;
				}
				cuenta_mov++;
				imprimir(n, pila1, pila2, pila3);
				break;

			case '3':
				if (((pila1->disco[(pila1->tope) - 1] < pila2->disco[(pila2->tope) - 1]) && pila1->tope != 0) || pila2->tope == 0)
				{
					pila2->disco[pila2->tope] = pila1->disco[(pila1->tope) - 1];
					pila1->disco[(pila1->tope) - 1] = 0;
					pila2->tope = (pila2->tope) + 1;
					pila1->tope = (pila1->tope) - 1;
				}
				else
				{
					pila1->disco[pila1->tope] = pila2->disco[(pila2->tope) - 1];
					pila2->disco[(pila2->tope) - 1] = 0;
					pila1->tope = (pila1->tope) + 1;
					pila2->tope = (pila2->tope) - 1;
				}
				imprimir(n, pila1, pila2, pila3);
				cuenta_mov++;
				break;

			};

		} while (pila3->tope != n);
	}
	else
	{
		char x = '1';
		while (pila3->tope != n)
		{
			switch (x)
			{
			case '1':
				pila3->disco[pila3->tope] = pila1->disco[(pila1->tope) - 1];
				pila1->disco[(pila1->tope) - 1] = 0;
				pila3->tope = (pila3->tope) + 1;
				pila1->tope = (pila1->tope) - 1;
				x = '3';
				imprimir(n, pila1, pila2, pila3);
				cuenta_mov++;
				if (pila3->tope == n)
				{
					gotoxy(37, 20); cout << "LISTO!";
					gotoxy(33, 21); cout << cuenta_mov << " MOVIMIENTOS";
			
					exit(1);
				}

				break;

			case '2':
				pila1->disco[pila1->tope] = pila2->disco[(pila2->tope) - 1];
				pila2->disco[(pila2->tope) - 1] = 0;
				pila1->tope = (pila1->tope) + 1;
				pila2->tope = (pila2->tope) - 1;
				x = '1';
				imprimir(n, pila1, pila2, pila3);
				cuenta_mov++;
				break;
			case '3':
				pila2->disco[pila2->tope] = pila3->disco[(pila3->tope) - 1];
				pila3->disco[(pila3->tope) - 1] = 0;
				pila2->tope = (pila2->tope) + 1;
				pila3->tope = (pila3->tope) - 1;
				x = '2';
				imprimir(n, pila1, pila2, pila3);
				cuenta_mov++;
				break;
			};
			char aux = x;
			switch (aux)
			{
			case '1':

				if ((pila2->disco[(pila2->tope) - 1] < pila3->disco[(pila3->tope) - 1]) || pila3->tope == 0)
				{
					pila3->disco[pila3->tope] = pila2->disco[(pila2->tope) - 1];
					pila2->disco[(pila2->tope) - 1] = 0;
					pila3->tope = (pila3->tope) + 1;
					pila2->tope = (pila2->tope) - 1;
				}
				else
				{
					pila2->disco[pila2->tope] = pila3->disco[(pila3->tope) - 1];
					pila3->disco[(pila3->tope) - 1] = 0;
					pila3->tope = (pila3->tope) - 1;
					pila2->tope = (pila2->tope) + 1;
				}
				cuenta_mov++;
				imprimir(n, pila1, pila2, pila3);
				break;
			case '2':
				if ((pila1->disco[(pila1->tope) - 1] < pila3->disco[(pila3->tope) - 1]) || pila3->tope == 0)
				{
					pila3->disco[pila3->tope] = pila1->disco[(pila1->tope) - 1];
					pila1->disco[(pila1->tope) - 1] = 0;
					pila3->tope = (pila3->tope) + 1;
					pila1->tope = (pila1->tope) - 1;
				}
				else
				{
					pila1->disco[pila1->tope] = pila3->disco[(pila3->tope) - 1];
					pila3->disco[(pila3->tope) - 1] = 0;
					pila1->tope = (pila1->tope) + 1;
					pila3->tope = (pila3->tope) - 1;
				}
				cuenta_mov++;
				imprimir(n, pila1, pila2, pila3);
				break;

			case '3':
				if (((pila1->disco[(pila1->tope) - 1] < pila2->disco[(pila2->tope) - 1]) && pila1->tope != 0) || pila2->tope == 0)
				{
					pila2->disco[pila2->tope] = pila1->disco[(pila1->tope) - 1];
					pila1->disco[(pila1->tope) - 1] = 0;
					pila2->tope = (pila2->tope) + 1;
					pila1->tope = (pila1->tope) - 1;
				}
				else
				{
					pila1->disco[pila1->tope] = pila2->disco[(pila2->tope) - 1];
					pila2->disco[(pila2->tope) - 1] = 0;
					pila1->tope = (pila1->tope) + 1;
					pila2->tope = (pila2->tope) - 1;
				}
				cuenta_mov++;
				imprimir(n, pila1, pila2, pila3);
				break;

			};

		}
	}
}


//-----------------------------------------------------------------------------
//									   PRINCIPAL
//-----------------------------------------------------------------------------

void main()
{
	int n;
	struct HANOI p1;
	struct HANOI p2;
	struct HANOI p3;
	inicializar(&p1);
	inicializar(&p2);
	inicializar(&p3);
otra_vez:

	
	cout << "TORRES DE HANOI";
	cout << "\n CON CUANTOS DISCOS ??? \n ";
	cin >> n;
	if (n<11)
	{
		empezar(n, &p1);
		imprimir(n, &p1, &p2, &p3);
		funcion_hanoi(n, &p1, &p2, &p3);
		imprimir(n, &p1, &p2, &p3);
		getchar();
	}
	else
	{
	
		goto otra_vez;
	}
	
}