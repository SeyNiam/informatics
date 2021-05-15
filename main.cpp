#include <iostream>
#include <ctime> // Заголовочный файл с прототипом функции clock()

using namespace std; // Использование пространство имен std

void safeInput(void); // Функция, позволяющая избежать краха программы при некорректном вводе со стороны пользователя

int main()
{
	int endFlag = 1; // Флаг, останавливающий приложение
	int alg = 0, length = 0, order = 0; // Условия, определяемые пользователем
	int array_size; // Переменная, задающая размер массива
	int* array; // Объявление указателя на массив
	int tmp; // Временная переменная, исполняющая роль буфера
	int sortFlag; // Флаг отсортированности массива
	int hundreds = 999; // Размер массива, состоящего из сотен
	int thousands = 9999; // Размер массива, состоящего из тысяч

	// Глобальный цикл, предотвращающий выход из программы без желания пользователя
	do {
		// Выбор метода сортировки
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

		// Выбор длины массива
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

		// Выбор упорядоченности массива
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

		
		// Создание и заполнение массива
		if (order == 1) { // Случайный
			if (length == 1) { // Сотни
				srand(time(0));
				array_size = hundreds; // Задаётся размер одномерного массива				
			}
			else { // Тысячи
				srand(time(0));
				array_size = thousands; // Задаётся размер одномерного массива
			}
			array = new int[array_size]; // Выделение объема памяти, необходимого для хранения запрашиваемого массива
			for (int counter = 0; counter < array_size; counter++) {
				array[counter] = rand() % 50 - rand() % 50; // Заполнение массива случайными значениями в диапазоне от -49 до 49 включительно
				cout << array[counter] << " "; // Печать элементов одномерного массива array
			}
		}
		else { // Упорядоченный
			if (length == 1) { // Сотни
				array_size = hundreds; // Задаётся размер одномерного массива
				array = new int[array_size]; // Выделение объема памяти, необходимого для хранения запрашиваемого массива
			}
			else { // Тысячи
				array_size = thousands; // Задаётся размер одномерного массива
				array = new int[array_size]; // Выделение объема памяти, необходимого для хранения запрашиваемого массива
			}
			for (int counter = 0; counter < array_size; counter++) {
				array[counter] = counter;
				cout << array[counter] << " "; // Печать элементов одномерного массива array
			}
		}


		unsigned int start_time; // начальное время
		unsigned int end_time; // конечное время
		unsigned int search_time; // искомое время


		switch (alg) {
		case 1: 
			cout << "\n\nBubble sort\n"; 
			start_time = clock(); // Фрагмент кода, время выполнения которого нужно измерить

			for (int i = 1; i < array_size; i++) {
				for (int j = 1; j < array_size; j++) {
					if (array[j] < array[j - 1]) {
						tmp = array[j];
						array[j] = array[j - 1];
						array[j - 1] = tmp;
					}
				}
			}

			end_time = clock(); // Конечное время
			// Вывод отсортированного массива
			for (int counter = 0; counter < array_size; counter++){
				cout << array[counter] << " "; // печать элементов отсортированного одномерного массива array
			}
			break;
		case 2: 
			cout << "\n\nBubble sort with flag\n";
			start_time = clock(); // Фрагмент кода, время выполнения которого нужно измерить

			// Выполнение цикла, пока не обнаружится, что массив отсортирован
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

			end_time = clock(); // Конечное время
			// Вывод отсортированного массива
			for (int counter = 0; counter < array_size; counter++) {
				cout << array[counter] << " "; // печать элементов отсортированного одномерного массива array
			}
			break;
		case 3: 
			cout << "\n\nShaker sort\n";
			int left = 0, right = array_size - 1; // Левая и правая границы сортируемой области массива
			int changeFlag = 1; // Флаг наличия перемещений
			start_time = clock(); // Фрагмент кода, время выполнения которого нужно измерить

			// Выполнение цикла, пока левая граница не сомкнётся с правой и пока в массиве имеются перемещения
			while ((left < right) && changeFlag > 0)
			{
				changeFlag = 0;
				for (int i = left; i < right; i++) // Движение слева направо
				{
					if (array[i] > array[i + 1]) // Если следующий элемент меньше текущего, то они меняются местами
					{
						tmp = array[i];
						array[i] = array[i + 1];
						array[i + 1] = tmp;
						changeFlag = 1; // Флаг ставится в 1, если перемещения в этом цикле были
					}
				}
				right--; // Правая граница сдвигается на предыдущий элемент
				for (int i = right; i > left; i--) // Движение справа налево
				{
					if (array[i - 1] > array[i]) // Если предыдущий элемент больше текущег, то они меняются местами
					{
						tmp = array[i];
						array[i] = array[i - 1];
						array[i - 1] = tmp;
						changeFlag = 1; // Флаг ставится в 1, если перемещения в этом цикле были
					}
				}
				left++; // Левая граница сдвигается на следующий элемент
			}

			end_time = clock(); // Конечное время
			// Вывод отсортированного массива
			for (int counter = 0; counter < array_size; counter++) {
				cout << array[counter] << " "; // печать элементов отсортированного одномерного массива array
			}
			break;
		}


		search_time = (end_time - start_time); // Искомое время
		cout << "\nRealisation time: "<< search_time << " ms.";
		delete[] array; // Освобождение выделенной массиву памяти


		// Предложение пользователю повторно запустить программу или выйти
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
	} while (endFlag); // Выход из цикла, если флаг равен 0 
	return 0;
}

void safeInput(void) {
	if (cin.fail()) // Если предыдущее извлечение оказалось неудачным,
	{
		cin.clear(); // то cin возвращается в 'обычный' режим работы
		cin.ignore(32767, '\n'); // и значения предыдущего ввода удаляются из входного буфера
	}
}