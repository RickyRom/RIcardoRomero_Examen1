#include <iostream>

using namespace std;

void Attax();
void imprimirMatriz(char**, int);
void liberarMatriz(char**&, int&);
void turnoJ1(char**, int, int, int, int, int);
void turnoJ2(char**, int, int, int, int, int);

int main () {
	int opcion;

	do{
		cout<<"Bienvenido a Attax"<<endl;
		cout<<"1.- Jugar Attax"<<endl;
		cout<<"2.- Salir"<<endl;
		cin>> opcion;

		switch(opcion) {
			case 1:
				Attax();
				break;
			case 2:
				cout<<"TENGA BUEN DIA!"<<endl;	
		}
	}while(opcion != 2);

	return 0;
}

void imprimirMatriz(char** matrix, int size) {
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			cout<<"["<<matrix[i][j]<<"]";
		}
		cout<<endl;
	}
}

void liberarMatriz(char**& matrix, int& size) {
	if(matrix != NULL) {
		for(int i = 0; i < size; i++) {
			delete[] matrix[i];
		        matrix[i] = NULL;	
		}

		delete[] matrix;
		matrix = NULL;
		size = 0;
	}
}

void Attax() {
	
	int size = 11;
	int x, y, x2, y2;
	bool gameover = false;
	int opn;	

	char** mainmatrix = new char*[size];
	for(int i = 0; i < size; i++) {
		mainmatrix[i] = new char[size];
	}

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			mainmatrix[i][j] = ' ';
		}
	}
	
	mainmatrix[0][5] = '+';
	mainmatrix[10][5] = '+';
	mainmatrix[5][0] = '#';
	mainmatrix[5][10] = '#';
	imprimirMatriz(mainmatrix, size);
	
	while(!gameover){
		
		turnoJ1(mainmatrix, size, x, y, x2, y2);

		turnoJ2(mainmatrix, size, x, y, x2, y2);


	}
	liberarMatriz(mainmatrix, size);
}

void turnoJ1(char** matrix, int size, int x, int y, int x2, int y2) {
	
	cout<<"Jugador 1"<<endl;
	cout<<"Ingrese X: "<<endl;
	cin>> x;
	cout<<"Ingrese Y: "<<endl;
	cin>> y;
	cout<<"A donde lo quiere mover"<<endl;
	cout<<"Ingrese X: "<<endl;
	cin>> x2;
	cout<<"Ingrese Y: "<<endl;
	cin>> y2;


	if(x < 0 || x > 10 || y < 0 || y > 10) {
		cout<<"Se salio del Rango de la Matriz"<<endl;
	}else{

		if(matrix[x][y] == '+' && (x+1 == x2) || 
		   matrix[x][y] == '+' && (x-1 == x2) ||
		   matrix[x][y] == '+' && (y+1 == y2) || 
		   matrix[x][y] == '+' && (y-1 == y2) || 
		   matrix[x][y] == '+' && (x+1 == x2 && y+1 == y2) ||
		   matrix[x][y] == '+' && (x+1 == x2 && y-1 == y2) || 
		   matrix[x][y] == '+' && (x-1 == x2 && y-1 == y2) ||
		   matrix[x][y] == '+' && (x-1 == x2 && y+1 == y2)){
			matrix[x2][y2] = '+';

			/*if(matrix[x+1][y] == '#') {
				matrix[x+1][y] = '+';
			}
			if(matrix[x-1][y] == '#') {
				matrix[x-1][y] = '+';
			}
			if(matrix[x][y+1] == '#') {
				matrix[x][y+1] = '+';
			}
			if(matrix[x][y-1] == '#') {
				matrix[x][y-1] = '+';
			}
			if(matrix[x+1][y+1] == '#') {
				matrix[x+1][y+1] = '+';
			}
			if(matrix[x+1][y-1] == '#') {
				matrix[x+1][y-1] = '+';
			}
			if(matrix[x-1][y-1] == '#') {
				matrix[x-1][y-1] = '+';
			}
			if(matrix[x-1][y+1] == '#') {
				matrix[x-1][y+1] = '+';
			}*/

		}else{
			cout<<"No puede mover pieza"<<endl;
		}


		if(matrix[x][y] == '+' && (x+2 == x2) || 
		   matrix[x][y] == '+' && (x-2 == x2) ||
		   matrix[x][y] == '+' && (y+2 == y2) || 
		   matrix[x][y] == '+' && (y-2 == y2) || 
		   matrix[x][y] == '+' && (x+2 == x2 && y+2 == y2) ||
		   matrix[x][y] == '+' && (x+2 == x2 && y-2 == y2) || 
		   matrix[x][y] == '+' && (x-2 == x2 && y-2 == y2) ||
		   matrix[x][y] == '+' && (x-2 == x2 && y+2 == y2)){
				matrix[x][y] = ' ';
				matrix[x2][y2] = '+';

				/*if(matrix[x+2][y] == '#') {
					matrix[x+2][y] = '+';
				}
				if(matrix[x-2][y] == '#') {
					matrix[x-2][y] = '+';
				}
				if(matrix[x][y+2] == '#') {
					matrix[x][y+2] = '+';
				}	
				if(matrix[x][y-2] == '#') {
					matrix[x][y-2] = '+';
				}
				if(matrix[x+2][y+2] == '#') {
					matrix[x+2][y+2] = '+';
				}
				if(matrix[x+2][y-2] == '#') {
					matrix[x+2][y-2] = '+';
				}
				if(matrix[x-2][y-2] == '#') {
					matrix[x-2][y-2] = '+';
				}
				if(matrix[x-2][y+2] == '#') {
					matrix[x-2][y+2] = '+';
				}*/
			}else{
				cout<<"No puede mover pieza"<<endl;
	
			
			imprimirMatriz(matrix, size);
			
 		}
		
	}		
}

void turnoJ2(char** matrix, int size, int x, int y, int x2, int y2) {
	
	cout<<"Jugador 2"<<endl;
	cout<<"Ingrese X: "<<endl;
	cin>> x;
	cout<<"Ingrese Y: "<<endl;
	cin>> y;
	cout<<"A donde lo quiere mover"<<endl;
	cout<<"Ingrese X: "<<endl;
	cin>> x2;
	cout<<"Ingrese Y: "<<endl;
	cin>> y2;
	
	if(x < 0 || x > 10 || y < 0 || y > 10) {
		cout<<"Se salio del Rango de la Matriz"<<endl;
	}else{
		if(matrix[x][y] == '#' && (x+1 == x2) || 
		   matrix[x][y] == '#' && (x-1 == x2) ||
		   matrix[x][y] == '#' && (y+1 == y2) || 
		   matrix[x][y] == '#' && (y-1 == y2) || 
		   matrix[x][y] == '#' && (x+1 == x2 && y+1 == y2) ||
		   matrix[x][y] == '#' && (x+1 == x2 && y-1 == y2) || 
		   matrix[x][y] == '#' && (x-1 == x2 && y-1 == y2) ||
		   matrix[x][y] == '#' && (x-1 == x2 && y+1 == y2)){
			matrix[x2][y2] = '#';

			if(matrix[x+1][y] == '+') {
				matrix[x+1][y] = '#';
			}
			if(matrix[x-1][y] == '+') {
				matrix[x-1][y] = '#';
			}
			if(matrix[x][y+1] == '+') {
				matrix[x][y+1] = '#';
			}
			if(matrix[x][y-1] == '+') {
				matrix[x][y-1] = '#';
			}
			if(matrix[x+1][y+1] == '+') {
				matrix[x+1][y+1] = '#';
			}
			if(matrix[x+1][y-1] == '+') {
				matrix[x+1][y-1] = '#';
			}
			if(matrix[x-1][y-1] == '+') {
				matrix[x-1][y-1] = '#';
			}
			if(matrix[x-1][y+1] == '+') {
				matrix[x-1][y+1] = '#';
			}
		}else{
			cout<<"No puede mover pieza"<<endl;
		}
			
		if(matrix[x][y] == '#' && (x+2 == x2) || 
		   matrix[x][y] == '#' && (x-2 == x2) ||
		   matrix[x][y] == '#' && (y+2 == y2) || 
		   matrix[x][y] == '#' && (y-2 == y2) || 
		   matrix[x][y] == '#' && (x+2 == x2 && y+2 == y2) ||
		   matrix[x][y] == '#' && (x+2 == x2 && y-2 == y2) || 
		   matrix[x][y] == '#' && (x-2 == x2 && y-2 == y2) ||
		   matrix[x][y] == '#' && (x-2 == x2 && y+2 == y2)){

			matrix[x][y] = ' ';
			matrix[x2][y2] = '#';
			
			if(matrix[x+2][y] == '+') {
				matrix[x+2][y] = '#';
			}
			if(matrix[x-2][y] == '+') {
				matrix[x-2][y] = '#';
			}
			if(matrix[x][y+2] == '+') {
				matrix[x][y+2] = '#';
			}
			if(matrix[x][y-2] == '+') {
				matrix[x][y-2] = '#';
			}
			if(matrix[x+2][y+2] == '+') {
				matrix[x+2][y+2] = '#';
			}
			if(matrix[x+2][y-2] == '+') {
				matrix[x+2][y-2] = '#';
			}
			if(matrix[x-2][y-2] == '+') {
				matrix[x-2][y-2] = '#';
			}
			if(matrix[x-2][y+2] == '+') {
				matrix[x-2][y+2] = '#';
			}
		}else{
			cout<<"No puede mover pieza"<<endl;
		imprimirMatriz(matrix, size);
		}

 	}		
	
}
