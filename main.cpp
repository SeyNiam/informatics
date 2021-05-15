#include <iostream>
#include <ctime> // ������������ ���� � ���������� ������� clock()

using namespace std; // ������������� ������������ ���� std

void safeInput(void); // �������, ����������� �������� ����� ��������� ��� ������������ ����� �� ������� ������������

int main()
{
	int endFlag = 1; // ����, ��������������� ����������
	int alg = 0, length = 0, order = 0; // �������, ������������ �������������
	int array_size; // ����������, �������� ������ �������
	int* array; // ���������� ��������� �� ������
	int tmp; // ��������� ����������, ����������� ���� ������
	int sortFlag; // ���� ����������������� �������
	int hundreds = 999; // ������ �������, ���������� �� �����
	int thousands = 9999; // ������ �������, ���������� �� �����

	// ���������� ����, ��������������� ����� �� ��������� ��� ������� ������������
	do {
		// ����� ������ ����������
		cout << "\nPlease choose the algorithm:\n 1) Bubble sort.\n 2) Bubble sort with flag.\n 3) Shaker.\n";
		do {
			cout << "\n>> ";
			cin >> alg;
			safeInput();
			if (alg != 1 && alg !=2 && alg !=3) { 
				cout << "Incorrect answer. Please try again."; 
				alg = 0; 
			}
		} while (alg == 0);

		// ����� ����� �������
		cout << "\nPlease choose the length:\n 1) Hundreds.\n 2) Thousands.\n";
		do {
			cout << "\n>> ";
			cin >> length;
			safeInput();
			if (length != 1 && length != 2) {
				cout << "Incorrect answer. Please try again.";
				length = 0;
			}
		} while (length == 0);

		// ����� ��������������� �������
		cout << "\nPlease choose the array ordering:\n 1) Random.\n 2) Ordered.\n";
		do {
			cout << "\n>> ";
			cin >> order;
			safeInput();
			if (order != 1 && order != 2) {
				cout << "Incorrect answer. Please try again.";
				order = 0;
			}
		} while (order == 0);

		
		// �������� � ���������� �������
		if (order == 1) { // ���������
			if (length == 1) { // �����
				srand(time(0));
				array_size = hundreds; // ������� ������ ����������� �������				
			}
			else { // ������
				srand(time(0));
				array_size = thousands; // ������� ������ ����������� �������
			}
			array = new int[array_size]; // ��������� ������ ������, ������������ ��� �������� �������������� �������
			for (int counter = 0; counter < array_size; counter++) {
				array[counter] = rand() % 50 - rand() % 50; // ���������� ������� ���������� ���������� � ��������� �� -49 �� 49 ������������
				cout << array[counter] << " "; // ������ ��������� ����������� ������� array
			}
		}
		else { // �������������
			if (length == 1) { // �����
				array_size = hundreds; // ������� ������ ����������� �������
				array = new int[array_size]; // ��������� ������ ������, ������������ ��� �������� �������������� �������
			}
			else { // ������
				array_size = thousands; // ������� ������ ����������� �������
				array = new int[array_size]; // ��������� ������ ������, ������������ ��� �������� �������������� �������
			}
			for (int counter = 0; counter < array_size; counter++) {
				array[counter] = counter;
				cout << array[counter] << " "; // ������ ��������� ����������� ������� array
			}
		}


		unsigned int start_time; // ��������� �����
		unsigned int end_time; // �������� �����
		unsigned int search_time; // ������� �����


		switch (alg) {
		case 1: 
			cout << "\n\nBubble sort\n"; 
			start_time = clock(); // �������� ����, ����� ���������� �������� ����� ��������

			for (int i = 1; i < array_size; i++) {
				for (int j = 1; j < array_size; j++) {
					if (array[j] < array[j - 1]) {
						tmp = array[j];
						array[j] = array[j - 1];
						array[j - 1] = tmp;
					}
				}
			}

			end_time = clock(); // �������� �����
			// ����� ���������������� �������
			for (int counter = 0; counter < array_size; counter++){
				cout << array[counter] << " "; // ������ ��������� ���������������� ����������� ������� array
			}
			break;
		case 2: 
			cout << "\n\nBubble sort with flag\n";
			start_time = clock(); // �������� ����, ����� ���������� �������� ����� ��������

			// ���������� �����, ���� �� �����������, ��� ������ ������������
			do {
				sortFlag = 0;
				for (int i = 1; i < array_size; i++) {
					if (array[i] < array[i - 1]) {
						tmp = array[i];
						array[i] = array[i - 1];
						array[i - 1] = tmp;
						sortFlag = 1;
					}
				}
			} while (sortFlag);

			end_time = clock(); // �������� �����
			// ����� ���������������� �������
			for (int counter = 0; counter < array_size; counter++) {
				cout << array[counter] << " "; // ������ ��������� ���������������� ����������� ������� array
			}
			break;
		case 3: 
			cout << "\n\nShaker sort\n";
			int left = 0, right = array_size - 1; // ����� � ������ ������� ����������� ������� �������
			int changeFlag = 1; // ���� ������� �����������
			start_time = clock(); // �������� ����, ����� ���������� �������� ����� ��������

			// ���������� �����, ���� ����� ������� �� �������� � ������ � ���� � ������� ������� �����������
			while ((left < right) && changeFlag > 0)
			{
				changeFlag = 0;
				for (int i = left; i < right; i++) // �������� ����� �������
				{
					if (array[i] > array[i + 1]) // ���� ��������� ������� ������ ��������, �� ��� �������� �������
					{
						tmp = array[i];
						array[i] = array[i + 1];
						array[i + 1] = tmp;
						changeFlag = 1; // ���� �������� � 1, ���� ����������� � ���� ����� ����
					}
				}
				right--; // ������ ������� ���������� �� ���������� �������
				for (int i = right; i > left; i--) // �������� ������ ������
				{
					if (array[i - 1] > array[i]) // ���� ���������� ������� ������ �������, �� ��� �������� �������
					{
						tmp = array[i];
						array[i] = array[i - 1];
						array[i - 1] = tmp;
						changeFlag = 1; // ���� �������� � 1, ���� ����������� � ���� ����� ����
					}
				}
				left++; // ����� ������� ���������� �� ��������� �������
			}

			end_time = clock(); // �������� �����
			// ����� ���������������� �������
			for (int counter = 0; counter < array_size; counter++) {
				cout << array[counter] << " "; // ������ ��������� ���������������� ����������� ������� array
			}
			break;
		}


		search_time = (end_time - start_time); // ������� �����
		cout << "\nRealisation time: "<< search_time << " ms.";
		delete[] array; // ������������ ���������� ������� ������


		// ����������� ������������ �������� ��������� ��������� ��� �����
		cout << "\n\nPlease choose from the following:\n\t1 - Run program again.\n\t2 - Exit.\n";

		do {
			cout << "\n>> ";
			cin >> endFlag;
			safeInput();
			if (endFlag != 1 && endFlag != 2) {
				cout << "Incorrect answer. Please try again.";
				endFlag = 0;
			}
		} while (endFlag == 0);

		switch (endFlag) {
		case 1: endFlag = 1; break;
		case 2: endFlag = 0; break;
		default: printf("Incorrect answer. The program will be closed."); endFlag = 0; break;
		}
	} while (endFlag); // ����� �� �����, ���� ���� ����� 0 
	return 0;
}

void safeInput(void) {
	if (cin.fail()) // ���� ���������� ���������� ��������� ���������,
	{
		cin.clear(); // �� cin ������������ � '�������' ����� ������
		cin.ignore(32767, '\n'); // � �������� ����������� ����� ��������� �� �������� ������
	}
}