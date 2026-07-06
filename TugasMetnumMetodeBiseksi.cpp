#include<stdio.h>
#include<conio.h>
#include<math.h>


float f(float x){
	float d;
	d=(3*x*x*x)+(2*x*x)+(1*x)-10;
	return d;
}

int main(){
	float x1,x2,xr,error,tol;
	int i=1;
	printf("\t\t**********************************************\n");
	printf("\t\t********TORIQ AS-SYARIF 11180910000024********\n");
	printf("\t\t***************Kelas 3 A Metnum***************\n");
	printf("\t\t**********Metode Biseksi - Bagi Dua***********\n");
	printf("\t\t**********************************************\n\n\n");
	printf("\tPersamaan Leonardo			: 3x^3+2x^2+x-10 = 0\n\n");
	printf("\tMasukkan batas atas persamaan untuk x1	: "); scanf("%f",&x1);
	printf("\tMasukkan batas bawah persamaan untuk x2	: "); scanf("%f",&x2);
	printf("\tMasukkan nilai galat / error: "); scanf("%f",&tol);
	printf("\tTidak ada akar di antara kedua batas persamaan\n");

	printf("\n \ti \tx1 \tx2 \txr \tf(x1) \tf(x2) \tf(xr) \terror \n");
	do{
		xr=(x1+x2)/2;
		error=fabs(x2-x1);
		printf("\t%d\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n",i,x1,x2,xr,f(x1),f(x2),f(xr),error);
		if(f(x1)*f(x2)<tol){
			x2=xr;
		}
		else{
			x1=xr;
			i++;
		}
		
	}while(error>tol);
	printf("\n \tNilai xr akhir 	: %.3f\n",xr);
	printf("\tBanyaknya iterasi : %d \n",i-1);
	getch();
	return 0;
}
