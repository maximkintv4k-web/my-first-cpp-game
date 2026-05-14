#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

	srand(time(0));
	setlocale(LC_ALL, "Russian");

	int distance = 1000;
	int fuel = 100;
	int shield = 100;
	int day = 1;
	bool isFlying = true;
	char choice;
	short random = 0;
	short damage;
	short anomaly;

	while (isFlying == true && distance > 0 && fuel > 0 && shield > 0) {
		std::cout << "------------------" << std::endl;
		std::cout << "сегодня: " << day << " день полёта" << std::endl;
		std::cout << "лететь осталось: " << distance << " км" << std::endl;
		std::cout << "топлива осталось: " << fuel << " литров" << std::endl;
		std::cout << "прочность щита: " << shield << std::endl;
		std::cout << "------------------" << std::endl;
		std::cout << "выберите ваше действие:" << std::endl;
		std::cout << "1 - полная скорость" << std::endl;
		std::cout << "2 - экономный режим" << std::endl;
		std::cout << "3 - ремонт корабля" << std::endl;
		std::cin >> choice;
		switch (choice) {
			case '1':
				day++;
				distance -= 250;
				fuel -= 30;
				random = 1 + rand() % 3;
				break;
			case '2':
				day++;
				distance -= 100;
				fuel -= 10;
				random = 1 + rand() % 3;
				break;
			case '3':
				if(shield>76){
					std::cout << "действие невозможно." << std::endl;
					break;
				}
				else {
					shield += 25;
					fuel -= 5;
					day++;
					random = 1 + rand() % 3;
					break;
				}
			default:
				std::cout << "корабль разбился из за того что командир не читал руководство для чайников" << std::endl;
				distance = -1000000000;
		}

		switch (random) {
		case 1:
			std::cout << "космическая ночь была сегодня спокойной..." << std::endl;
			random = 0;
			break;
		case 2:
			damage = 1 + rand() % 99;
			std::cout << "осторожно астероиды!" << std::endl;
			shield -= damage;
			random = 0;
			break;
		case 3:
			std::cout << "ого... Ночью была аномалия! Путь сокращён ещё сильнее!" << std::endl;
			anomaly = 1 + rand() % 50;
			distance -= anomaly;
			random = 0;
			break;
		}
	}
	if (distance == -1000000000) {
		std::cout << "Игра окончена по глупости капитана." << std::endl;
	}
	else if (fuel <= 0) {
		std::cout << "ПОРАЖЕНИЕ: Топливо закончилось. Корабль затерялся в космосе..." << std::endl;
	}
	else if (shield <= 0) {
		std::cout << "ПОРАЖЕНИЕ: Метеориты уничтожили обшивку корабля!" << std::endl;
	}
	else if (distance <= 0) {
		std::cout << "ПОБЕДА! Вы успешно долетели до Марса за " << day << " дней!" << std::endl;
	}

}