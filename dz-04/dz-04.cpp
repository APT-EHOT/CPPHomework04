#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

void task1() {
	srand(time(0));
	int sum = 0;

	cout << "\nЧисла, записанные в файл: ";
	ofstream fileOnWriting("myfile.bin");
	for (int i = 0; i < 10; i++) {
		int randomN = 1 + rand() % 100;
		fileOnWriting << randomN << " ";
		cout << randomN << " ";
	}
	fileOnWriting.close();
	cout << "\n";

	ifstream fileOnReading("myfile.bin");
	if (fileOnReading.is_open()) {
		while (!fileOnReading.eof()) {
			int inp;
			fileOnReading >> inp;
			sum += inp;
		}
		cout << "\nСумма чисел в файле: " << sum << "\n";
		fileOnReading.close();
	}
	else {
		cout << "Error of file reading";
	}
}

int sign(double x) {
	if (x > 0)
		return 1;
	else if (x == 0)
		return 0;
	else
		return -1;
}
void task2() {
	double x;
	cout << "\nВведите число: ";
	cin >> x;
	switch (sign(x)) {
	case -1:
		cout << "\nЧисло отрицательно\n";
		break;
	case 0:
		cout << "\nЧисло равно нулю\n";
		break;
	case 1:
		cout << "\nЧисло положительно\n";
		break;
	}
}

double areaRectangle(double a, double b) {
	return a * b;
}
double areaTriangle(double a, double b, double c) {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
double areaCircle(double r) {
	const double PI = 3.14;
	return PI * r * r;
}
void task3() {
	double inp1, inp2, inp3;
	cout << "\nВведите ширину и высоту прямоугольника через пробел: ";
	cin >> inp1 >> inp2;
	cout << "\nПлощадь прямоугольника: " << areaRectangle(inp1, inp2) << "\n\n";

	cout << "\nВведите стороны A, B и C треугольника через пробел: ";
	cin >> inp1 >> inp2 >> inp3;
	cout << "\nПлощадь треугольника: " << areaTriangle(inp1, inp2, inp3) << "\n\n";

	cout << "\nВведите радиус круга: ";
	cin >> inp1;
	cout << "\nПлощадь круга: " << areaCircle(inp1) << "\n\n";
}

void task4() {
	for (int i = 0; i < 13; i++) {
		if (i < 6) {
			if (i % 2 == 1)
				cout << " ";
			for (int j = 0; j < 48; j++) {
				
				if (j < 16) {
					
					if (j % 2 == 0)
						cout << "*";
					else
						cout << " ";
				}
				else {
					if (i % 2 == 0)
						cout << "#";
				}
			}
			cout << "\n";
		}
		else {
			for (int j = 0; j < 48; j++) {
				if (i % 2 == 0)
					cout << "#";
			}
			cout << "\n";
		}
	}
}

double itoy(int i) {
	const int ny = 13;
	if (i == ny)
		return 0;
	else if (i > ny)
		return (i - ny) / 10;
	else
		return (ny - i) / 10;
}
double jtox(int j) {
	const int nx = 63;
	if (j == nx)
		return 0;
	else if (j > nx)
		return (j - nx) / 10.0;
	else
		return (nx - j) / 10.0;
}
int ytoi(double y) {
	const int ny = 13;
	if (y == 0)
		return ny;
	else if (y > 0)
		return int(ny - y * 10);
	else
		return int(abs(y) * 10 + ny);
}
void task5() {

	int func[25][125];

	for (int i = 1; i <= 25; i++) {
		for (int j = 1; j <= 125; j++) {
			func[i - 1][j - 1] = 0;
		}
	}

	for (int j = 1; j <= 125; j++) {
		double y;
		if (j < 63)
			y = round(cos(-jtox(j)) * 10) / 10;
		else
			y = round(cos(jtox(j)) * 10) / 10;

		func[ytoi(y) - 1][j - 1] = 1;
	}

	for (int i = 1; i <= 25; i++) {
		
		for (int j = 1; j <= 125; j++) {
			if (j == 63) {
				if (i == 1)
					cout << "^";
				else if (i == 3)
					cout << "1";
				else if (i == 13)
					cout << 0;
				else if (i == 23) {
					cout << "-1";
					j++;
				}
				else {
					cout << "|";
				}
			}
			else if (i == 13) {
				if (j == 3 || j == 13 || j == 23 || j == 33 || j == 43 || j == 53) {
					cout << "-" << int(jtox(j));
					j++;
				} else if (j == 73 || j == 83 || j == 93 || j == 103 || j == 113 || j == 123)
					cout << int(jtox(j));
				else if (j == 125)
					cout << ">";
				else
					cout << "=";
			}
			else if (func[i - 1][j - 1] == 1)
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}
}

void task6() {
	string input;
	vector<int> encoded;
	int output = 0;
	cout << "\nВведите число в римской СС: ";
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		switch (input[i])
		{
		case 'M':
			encoded.push_back(1000);
			break;
		case 'D':
			encoded.push_back(500);
			break;
		case 'C':
			encoded.push_back(100);
			break;
		case 'L':
			encoded.push_back(50);
			break;
		case 'X':
			encoded.push_back(10);
			break;
		case 'V':
			encoded.push_back(5);
			break;
		case 'I':
			encoded.push_back(1);
			break;
		default:
			break;
		}
	}
	int cnt = 0;
	int num = 9;
	bool error = 0;
	for (int i = 0; i < encoded.size()-1; i++) {
		if ((cnt > 1) && (encoded[i] > num)) {
			error = 1;
			break;
		} else if (cnt > 3) {
			error = 1;
			break;
		}

		if (num == encoded[i]) {
			cnt++;
		} else {
			cnt = 1;
			num = encoded[i];
		}
		if (encoded[i] < encoded[i + 1])
			output -= encoded[i];
		else
			output += encoded[i];
	}
	if (num == encoded[input.size() - 1]) {
		cnt++;
	}
	else {
		if ((cnt > 1) && (encoded[input.size() - 1] > num)) {
			error = 1;
		}
		cnt = 1;
		num = encoded[input.size() - 1];
	}
	 
	
	if (cnt > 3) {
		error = 1;
	}

	if (!error) {
		output += encoded.back();
		cout << "\nВ арабской СС оно записывается как: " << output << "\n\n";
	}
	else {
		cout << "\nНеправильный формат ввода числа!\n\n";
	}
}

int pseudoRandomGen(int m, int i, int c) {
	int s;
	ifstream helperOnReading("randomHelper.bin");
	helperOnReading >> s;
	helperOnReading.close();
	return (m * s + i) % c;
}
void task7() {
	int var;
	cout << "\nВведите вариант генерации (1 или 2): ";
	cin >> var;
	int output = 0;
	(var == 1) ?  output = pseudoRandomGen(37, 3, 64) : output = pseudoRandomGen(25173, 13849, 65537);
	cout << "\nСлучайное число: "<< output << "\n\n";
}

void task8() {
	ifstream matrixOnReading("inputMatrix.bin");

	int matrixA[3][4];
	double matrixB[4][2];
	double matrixC[3][2];

	double maxprofit = -1, minprofit = 100000, maxprofiter, minprofiter;
	double maxpay = -1, minpay = 100000, maxpayer, minpayer;
	double allprofit = 0;
	double allpay = 0;
	double exchange = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			matrixOnReading >> matrixA[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			matrixOnReading >> matrixB[i][j];
		}
	}

	matrixOnReading.close();

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			matrixC[i][j] = 0;
			for (int q = 0; q < 4; q++)
				matrixC[i][j] += (double) matrixA[i][q] * matrixB[q][j];
			if (j == 0) {
				if (matrixC[i][j] > maxprofit) {
					maxprofit = matrixC[i][j];
					maxprofiter = i + 1;
				}
				if (matrixC[i][j] < minprofit) {
					minprofit = matrixC[i][j];
					minprofiter = i + 1;
				}
				allprofit += matrixC[i][j];
				exchange += matrixC[i][j];
			} else {
				if (matrixC[i][j] > maxpay) {
					maxpay = matrixC[i][j];
					maxpayer = i + 1;
				}
				if (matrixC[i][j] < minpay) {
					minpay = matrixC[i][j];
					minpayer = i + 1;
				}
				allpay += matrixC[i][j];
				exchange += matrixC[i][j];
			}
		}
	}
	cout << "\nМатрица C: \t" << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << matrixC[i][j] << "\t";
		}
		cout << "\n";
	}

	cout << "\nМаксимальная выручка у продавца: \t" << maxprofiter << "\n";
	cout << "Минимальная выручка у продавца: \t" << minprofiter << "\n\n";

	cout << "Максимальные комиссионные у продавца: \t" << maxpayer << "\n";
	cout << "Минимальные комиссионные у продавца: \t" << minpayer << "\n\n";

	cout << "Всего выручено: \t\t\t" << allprofit << "\n";
	cout << "Всего комиссионных: \t\t\t" << allpay << "\n";
	cout << "Всего в обороте: \t\t\t" << exchange << "\n";
}

int decoder(char x) {
	switch (x) {
	case '0':
		return 0;
		break;
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break;
	case '7':
		return 7;
		break;
	case '8':
		return 8;
		break;
	case '9':
		return 9;
		break;
	case 'A':
		return 10;
		break;
	case 'B':
		return 11;
		break;
	case 'C':
		return 12;
		break;
	case 'D':
		return 13;
		break;
	case 'E':
		return 14;
		break;
	case 'F':
		return 15;
		break;
	default:
		return -1;
	break;
	}
}
void task9() {

	int oldSC, newSC;

	int dec = 0;

	char digits[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	string input;
	string output; 
	cout << "\nВведите число (поддерживаются СС с основанием от 2 до 16): ";
	cin >> input; 
	cout << "Введите изначальную CC: ";
	cin >> oldSC; 
	cout << "Введите конечную CC: ";
	cin >> newSC;
	int j = input.size() - 1;
	for (int i = 0; i < input.size(); i++) {
		dec += decoder(input[i]) * pow(oldSC, j);
		j--;
	}

	cout << "\n\nРезультат перевода: ";
	if (newSC != 10) {
		while (dec > newSC) {
			int digit = dec % newSC;
			dec /= newSC;
			output += digits[digit];
		}
		output += to_string(dec);
		for (int i = output.size() - 1; i >= 0; i--) {
			cout << output[i];
		}
	}
	else {
		cout << dec;
	}
	cout << "\n";
}

int main()
{
	int randomHelper;
	ifstream helperOnReading("randomHelper.bin");
	helperOnReading >> randomHelper;
	helperOnReading.close();
	setlocale(0, "");
	int n;
	cout << "\nДомашняя работа 4. Введите номер задания (0 - выход): ";
	cin >> n;
	while (n != 0) {
		randomHelper++;
		ofstream helperOnWriting("randomHelper.bin");
		helperOnWriting << randomHelper;
		helperOnWriting.close();
		switch (n) {
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		case 4:
			task4();
			break;
		case 5:
			task5();
			break;
		case 6:
			task6();
			break;
		case 7:
			task7();
			break;
		case 8:
			task8();
			break;
		case 9:
			task9();
			break;
		}
		cout << "\n========================\n\nДомашняя работа 4. Введите номер задания (0 - выход): ";
		cin >> n;
	}
	return 0;
}

