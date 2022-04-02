#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
using namespace std;

double real_vals[11];
double learnRate;
double accuracyVar;

void questions(){
	for(int i=0; i<11; i++){
		cout << "Please Insert the Y Value for X = " << i << ": " << endl;
		cin >> real_vals[i];
	}
	cout << "What learning rate do you want to apply? (reccommended around 0.01-0.1)" << endl;
	cin >> learnRate;
	cout << "What level of accuracy? (Range: 1-inf, reccommended above 20, lower is better)" << endl;
	cin >> (accuracyVar);
	accuracyVar = accuracyVar/100;

}

double  return_reg_equation_vals(double a, double b, double c, double reg_vals[11], int iVal){
	for(int i = 0; i<11; i++){
		reg_vals[i] = (a * pow(i, 2)) + b*i + c;
	}
	return reg_vals[iVal];
}

double a_coefficient = 0;
double b_coefficient = 0;
double c_coefficient = 0;
double errorPrevA = numeric_limits<double>::infinity();
double errorPrevB = numeric_limits<double>::infinity();
double errorPrevC = numeric_limits<double>::infinity();
double preva = 0;
double prevb = 0;
double prevc = 0;

void findEquationDriver(double learning_rate, double accVar){
	double reg_vals[11];
	double errorValA = 0;
	double errorValB = 0;
    double errorValC = 0;
	for(int i = 0; i<11; i++){
		double regRunner = return_reg_equation_vals(a_coefficient, b_coefficient, c_coefficient, reg_vals, i);
		reg_vals[i] = regRunner;
	}
	for(int i = 0; i<11; i++){
		errorValA = ((reg_vals[i]-real_vals[i])*i) + errorValA;
		errorValB = ((reg_vals[i]-real_vals[i])*i) + errorValB;
        errorValC = ((reg_vals[i]-real_vals[i])) + errorValC;
	}
	if((abs(errorValA)>accVar)){
		if((abs(errorValA)<=abs(errorPrevA)) && abs(errorValA)>accVar){
			a_coefficient = a_coefficient - (errorValA * (1.00/11.00) * learning_rate);
		}
		errorPrevA = errorValA;
		errorPrevB = errorValB;
        errorPrevC = errorValC;
		preva = a_coefficient;
		prevb = b_coefficient;
        prevc = c_coefficient;
        cout << a_coefficient << endl;
		findEquationDriver(learnRate, accVar);
	}
	else{
		cout << preva << "x^2 + " << b_coefficient << "x + " << c_coefficient << endl;
	}
}

int main(){
	questions();
	findEquationDriver(learnRate, accuracyVar);
	return 0;
}