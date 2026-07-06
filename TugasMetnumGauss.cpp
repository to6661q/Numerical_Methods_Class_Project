#include <iostream>
using namespace std;

void matrix_33();
void matrix_44();
float hasil44[4][5];
float hasil[3][4];

int main(){
	int pilih;
	do{
		system("cls");
		cout << "Silahkan pilih orde matriks : " << endl;
		cout << "1. Matriks Orde 3 x 3\n2. Matriks Orde 4 x 4\n3. Keluar\nInput : ";
		cin >> pilih;
		
		switch(pilih){
			case 1:{
				system("cls");
				matrix_33();
				system("pause");
				break;
			}
			case 2:{
				system("cls");
				matrix_44();
				system("pause");
				break;
			}
			case 3:{
				system("cls");
				cout << "Terimakasih";
				return 0;
				break;
			}
			default :{
				cout << "=======================================================" << endl;
				cout << "Pilihan tidak tersedia" << endl;
				break;
			}
		}
	}while(pilih != 3);
}

void matrix_33(){
	double x1, x2, x3;
	
	cout << "Format input : " << endl;
	cout << "mnx1 + mnx2 + mnx3 = mn" << endl;
	cout << "=======================================================" << endl;
	
	//Meminta input matrix dari user
	for(int i = 0; i <= 2; i++){
		for(int j = 0; j <= 3; j++){
			cout << "Masukkan nilai ke - " << i << j << " : ";
			cin >> hasil[i][j];
		}
	}
	cout << "=======================================================" << endl;
	
	//output versi fungsi
	cout << "Output versi fungsi : " << endl;
	for(int i = 0; i <= 2; i++){
		for(int j = 0; j <= 3; j++){
			if(j == 3){
				cout << "	=	" << hasil[i][j];
				break;
			}
			cout << hasil[i][j];
			
			if(j < 2){
				cout << "x" << j+1 << "	+	";	
			}else if(j == 2){
				cout << "x" << j+1;
			}
		}
		cout << endl;
	}
	cout << "=======================================================" << endl;
	
	//Output versi Matrix
	cout << "Output versi matrix : " << endl;
	for(int i = 0; i <= 2; i++){
		cout << "|";
		for(int j = 0; j <= 3; j++){
			cout << hasil[i][j];
			if(j < 2){
				cout << "	";	
			}if(j == 2){
				cout << "	||	";
			}else if(j == 3){
				cout << "	|";
			}
		}
		cout << endl;
	}
	cout << "=======================================================" << endl;
	
	//Proses perhitungan menggunakan metode gauss
	int iTemp_kanan, iTemp_kiri; 
	float temp[4], m[3];
	
	m[0] = hasil[1][0] / hasil[0][0];
	m[1] = hasil[2][0] / hasil[0][0];
	
	for(int i = 0; i <= 2; i++){
		
		//proses gauss
		if(i == 2){
			//Proses perbaikan gaus (Jika ada 0 di diagonal akan ditukar dengan yang tidak 0)
			if(hasil[0][0] == 0){
				if(hasil [2][2] != 0){
					for(int j = 0; j <= 3; j++){
						temp[j] = hasil[2][j];
						hasil[2][j] = hasil[0][j];
						hasil[0][j] = temp[j];
					}
				}
			}else if(hasil [1][1] == 0){
				if(hasil [2][2] != 0){
					for(int j = 0; j <= 3; j++){
						temp[j] = hasil[2][j];
						hasil[2][j] = hasil[1][j];
						hasil[1][j] = temp[j];
					}
				}
			}else if(hasil [2][2] == 0){
				if(hasil [0][0] != 0){
					for(int j = 0; j <= 3; j++){
						temp[j] = hasil[0][j];
						hasil[0][j] = hasil[2][j];
						hasil[2][j] = temp[j];
					}
				}
			}
			m[2] = hasil[2][1] / hasil[1][1];
		}
		for(int j = 0; j <= 3; j++){
			if(i == 0){
				iTemp_kiri = 1;
				iTemp_kanan = 0;
			}else if(i == 1){
				iTemp_kiri = 2;
				iTemp_kanan = 0;
			}else if(i == 2){
				iTemp_kiri = 2;
				iTemp_kanan = 1;
			}
			hasil[iTemp_kiri][j] -= (hasil[iTemp_kanan][j])*m[i];
		}
	}
	
	//Output versi Matrix
	cout << "Output versi matrix setelah metode gauss : " << endl;
	for(int i = 0; i <= 2; i++){
		cout << "|";
		for(int j = 0; j <= 3; j++){
			cout << hasil[i][j];
			if(j < 2){
				cout << "	";	
			}if(j == 2){
				cout << "	||	";
			}else if(j == 3){
				cout << "	|";
			}
		}
		cout << endl;
	}
	cout << "=======================================================" << endl;
	
	//proses penyulihan dan output
	x3 = hasil[2][3] / hasil[2][2];
	x2 = (hasil[1][3] - (hasil[1][2]*x3)) / hasil[1][1];
	x1 = (hasil[0][3] - (hasil[0][1]*x2 + hasil[0][2]*x3)) / hasil[0][0];
	cout << "Hasil akhir x3, x2, dan x1 : " << endl;
	cout << "x3 = " << hasil[2][3] << "/" << hasil[2][2] << " = " << x3 << endl;
	cout << "x2 = " << "(" << hasil[1][3] << " - " << "(" << hasil[1][2] << " * " << x3 << ")) " << "/ " << hasil[1][1] << " = " << x2 << endl;
	cout << "x1 = " << "(" << hasil[0][3] << " - " << "(" << "("<<hasil[0][1] << " * " << x2 << ") + (" << hasil[0][2] << " * " << x3 << "))) " << "/ " << hasil[0][0] << " = " << x1 << endl;
}

void matrix_44(){
	double x1, x2, x3, x4;
	
	cout << "Format input : " << endl;
	cout << "mnx1 + mnx2 + mnx3 + mnx4 = mn" << endl;
	cout << "=======================================================" << endl;
	
	//Meminta input matrix dari user
	for(int i = 0; i <= 3; i++){
		for(int j = 0; j <= 4; j++){
			cout << "Masukkan nilai ke - " << i << j << " : ";
			cin >> hasil[i][j];
		}
	}
	cout << "=======================================================" << endl;
	
	//output versi fungsi
	cout << "Output versi fungsi : " << endl;
	for(int i = 0; i <= 3; i++){
		for(int j = 0; j <= 4; j++){
			if(j == 4){
				cout << "	=	" << hasil[i][j];
				break;
			}
			cout << hasil[i][j];
			
			if(j < 3){
				cout << "x" << j+1 << "	+	";	
			}else if(j == 3){
				cout << "x" << j+1;
			}
		}
		cout << endl;
	}
	cout << "=======================================================" << endl;
	
	//Output versi Matrix
	cout << "Output versi matrix : " << endl;
	for(int i = 0; i <= 3; i++){
		cout << "|";
		for(int j = 0; j <= 4; j++){
			cout << hasil[i][j];
			if(j < 3){
				cout << "	";	
			}if(j == 3){
				cout << "	||	";
			}else if(j == 3){
				cout << "	|";
			}
		}
		cout << endl;
	}
	cout << "=======================================================" << endl;
	
	//Proses perhitungan menggunakan metode gauss
	int iTemp_kanan, iTemp_kiri; 
	float temp[5], m[4];
	
	m[0] = hasil[1][0] / hasil[0][0];
	m[1] = hasil[2][0] / hasil[0][0];
	m[2] = hasil[3][0] / hasil[0][0];
	
	for(int i = 0; i <= 3; i++){
		
		//proses gauss
		if(i == 3){
			//Proses perbaikan gaus (Jika ada 0 di diagonal akan ditukar dengan yang tidak 0)
			if(hasil[0][0] == 0){
				if(hasil [3][3] != 0){
					for(int j = 0; j <= 3; j++){
						temp[j] = hasil[3][j];
						hasil[3][j] = hasil[2][j];
						hasil[2][j] = hasil[0][j];
						hasil[0][j] = temp[j];
					}
				}
			}else if(hasil [1][1] == 0){
				if(hasil [3][3] != 0){
					for(int j = 0; j <= 3; j++){
						temp[j] = hasil[3][j];
						hasil[3][j] = hasil[2][j];
						hasil[2][j] = hasil[1][j];
						hasil[1][j] = temp[j];
					}
				}
			}else if(hasil [3][3] == 0){
				if(hasil [0][0] != 0){
					for(int j = 0; j <= 3; j++){
						temp[j] = hasil[0][j];
						hasil[0][j] = hasil[2][j];
						hasil[2][j] = hasil[3][j];
						hasil[3][j] = temp[j];
					}
				}
			}
			m[3] = hasil[3][2] / hasil[2][2];
		}
		for(int j = 0; j <= 3; j++){
			if(i == 0){
				iTemp_kiri = 1;
				iTemp_kanan = 0;
			}else if(i == 1){
				iTemp_kiri = 2;
				iTemp_kanan = 0;
			}else if(i == 2){
				iTemp_kiri = 3;
				iTemp_kanan = 0;
			}else if(i == 3){
				iTemp_kiri = 3;
				iTemp_kanan = 1;
			}
			hasil[iTemp_kiri][j] -= (hasil[iTemp_kanan][j])*m[i];
		}
	}
	
	//Output versi Matrix
	cout << "Output versi matrix setelah metode gauss : " << endl;
	for(int i = 0; i <= 3; i++){
		cout << "|";
		for(int j = 0; j <= 4; j++){
			cout << hasil[i][j];
			if(j < 3){
				cout << "	";	
			}if(j == 3){
				cout << "	||	";
			}else if(j == 4){
				cout << "	|";
			}
		}
		cout << endl;
	}
	cout << "=======================================================" << endl;
	
	//proses penyulihan dan output
	x4 = hasil[3][4] / hasil[3][3];
	x3 = (hasil[2][4] - (hasil[2][3]*x3)) / hasil[2][2];
	x2 = (hasil[0][4] - (hasil[0][1]*x2 + hasil[0][2]*x3)) / hasil[0][0];
	x1 = (hasil[0][4] - (hasil[0][1]*x2 + hasil[0][2] - hasil[0][3]*x4)) / hasil[0][0];
	cout << "Hasil akhir x4, x3, x2, dan x1 : " << endl;
	cout << "x4 = " << hasil[3][4] << "/" << hasil[3][3] << " = " << x4 << endl;
	cout << "x3 = " << hasil[2][4] << "/" << hasil[2][2] << " = " << x3 << endl;
	cout << "x2 = " << "(" << hasil[0][4] << " - " << "(" << hasil[0][2] << " * " << x3 << ")) " << "/ " << hasil[0][0] << " = " << x2 << endl;
	cout << "x1 = " << "(" << hasil[0][4] << " - " << "(" << "("<<hasil[0][1] << "* " << x2 << ")" "+" "(" << hasil[0][2] << " * " << x3 << ")" "-" "(" << hasil[0][3]<<"*"<<x4<<"))) " << "/ " << hasil[0][0] << " = " << x1 << endl;
}
