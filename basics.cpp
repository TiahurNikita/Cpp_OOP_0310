#include "basics.h"
#include <iostream>
#include <conio.h>

void basics() {
	std::cout << "OOP Basics" << std::endl;
	//LinkedList<Product*> stock;						  // Перелік покажчиків (stock - статичний об'єкт LinkedList, який вже є)
	// + автоматично знищиться після виконання ф-ції basics
	// - весь об'єкт stock розмішується у стеку
	//LinkedList<Product*>* stock;					  // Покажчик на перелік покажчиків (stock - покажчик на об'єкт LinkedList, якого ще нема)
	// + економія стекової пам'яті, у стеку тільки адруса
	// - необхідно створити об'єкт: stock = new LinkedList<Product*>();
	//	 та не забути видалити (delete stock) оскільки автоматично звільниться
	//	 тілки адреса, а не об'єкт за нею
	// 
	//LinkedList<std::unique_ptr<Product>> stock;		  // Перелік розумних покажчиків
	// невдалий варіант - як збільшення пам'яті, так і непотрібні розумні покажчики

	//std::unique_ptr<LinkedList<Product*>> stock =
	//	std::make_unique<LinkedList<Product*>>();	  // Розумний покажчик на перелік
	// оптимальний варіант - покажчик всередині розумного покажчика та
	// автоматичне видалення після роботи
	LinkedList<Product*> stock; // = new LinkedList<Product*>();
	int N = 0;

	stock.add((new Laptop())
		->setHardware("Intel Core 5, RAM 16GB, SSD 512GB")
		->setPower(90)
		->setName("Acer Nitro")
		->setPrice(60499));
	N++;
	stock.add((new Laptop())
		->setHardware("Intel Core 9, RAM 32GB, SSD 1024GB")
		->setPower(90)
		->setName("Acer Nitro")
		->setPrice(60499));
	N++;
	stock.add((new Monitor())
		->setDiagonal(32)
		->setPower(120)
		->setName("Dell Vision")
		->setPrice(5000));
	N++;
	stock.add((new Monitor())
		->setDiagonal(27)
		->setPower(90)
		->setName("ASUS")
		->setPrice(9000));
	N++;
	stock.add((new Mouse())
		->setDPI(1600)
		->setConnection("USB")
		->setName("Logitech G Pro")
		->setPrice(6000));
	N++;
	stock.add((new Mouse())
		->setDPI(1600)
		->setConnection("USB-C")
		->setName("Logitech G Lite")
		->setPrice(8000));
	N++;
	stock.add((new Keyboard())
		->setType("Magnetic")
		->setConnection("2.4 GHz")
		->setName("Logitech G")
		->setPrice(7500));
	N++;
	stock.add((new Keyboard())
		->setType("Mechanical")
		->setConnection("2.4 GHz")
		->setName("ASUS")
		->setPrice(6700));
	N++;

	// Задача: реалізувати меню користувача
	
	int choice;
	do{
		std::cout << std::endl << "=== MAIN MENU ===" << std::endl;
		std::cout << "Stock has " << N << " products. Select an action:" << std::endl
			<< "1.Show all" << std::endl
			<< "2.Find by name" << std::endl
			<< "3.Find by price" << std::endl
			<< "4.Show all from cheap to expensive" << std::endl
			<< "5.Show all from expensive to cheap" << std::endl
			<< "0.Exit" << std::endl << std::endl;
		choice = _getch();
		bool swapped;
		if (choice == 0 || choice == 224) choice = _getch();
		switch (choice) {
			case '0': break;
			case '1': 
				for (int i = 0; i < N; ++i) {
					std::cout << stock[i] << std::endl;
				}
				break;
			case '3':
				bool found;
				double max, min, t, max_a, min_a;
				size_t counter;
				if (N <= 0) { 
					std::cout << "Empty stock. Nothing to search" << std::endl;
					break; 
				}
				max_a = min_a = stock[0]->getPrice();
				for (size_t i = 1; i < N; ++i) {
					double p = stock[i]->getPrice();
					if (p < min_a) min_a = p;
					if (p > max_a) max_a = p;
				}
				std::cout << "Price from (min:"<< min_a <<"): " << std::endl; std::cin >> min;
				std::cout << "Price to (max:"<< max_a <<"): " << std::endl; std::cin >> max;
				if (min < 0) min = 0;
				if (max < 0) max = 0;
				if (min > max) {
					std::cout << "You were probably looking for products in range " << min << " - " << max << " hrn" << std::endl;
					t = max;
					max = min;
					min = max;
				}
				else{
				std::cout << "Searching in range " << min << " - " << max << " hrn" << std::endl;
				}
				counter = 0;
				
				for (size_t i = 0; i < N; ++i) {
					double p = stock[i]->getPrice();
					if(p>=min && p<=max){
						counter += 1;
						std::cout << counter << ": " << stock[i] << std::endl;
					}
				}
				if (counter>0) {
					std::cout << "Found " << counter << " product(s)" << std::endl;
				}
				else{
					std::cout << "No product found in this price range" << std::endl;
				}
				break;
			case '4':
				if (N <= 0) {
					std::cout << "Empty stock. Nothing to sort" << std::endl;
					break;
				}
				do {
					swapped = false;
					for (int i = 0; i < N-1; ++i) {
						if (stock[i]->getPrice() > stock[i+1]->getPrice()) {
							std::swap(stock[i], stock[i+1]);
							swapped = true;
						}
					}
				} while (swapped);
				for (int i = 0; i < N; ++i) {
					std::cout << stock[i] << std::endl;
				}
				break;
			case '5':
				if (N <= 0) {
					std::cout << "Empty stock. Nothing to sort" << std::endl;
					break;
				}
				do {
					swapped = false;
					for (int i = 0; i < N-1; ++i) {
						if (stock[i]->getPrice() < stock[i+1]->getPrice()) {
							std::swap(stock[i], stock[i+1]);
							swapped = true;
						}
					}
				} while (swapped);
				for (int i = 0; i < N; ++i) {
					std::cout << stock[i] << std::endl;
				}
				break;
			default: std::cout << "Wrong choice" << std::endl;
		}

	}while (choice != '0');
	
}

/*void basics_2() {
	std::cout << "OOP Basics" << std::endl;
	// Поліморфізм - поєднання до єдиного масиву (колекції)
	// об'єктів різного типу. Формально, об'єкти мають один
	// тип (базового класу), при цьому фактично є об'єктами
	// похідних (дочірніх) типів

	Product* stock[2];

	stock[0] = (new Laptop())
		->setHardware("Intel Core 5, RAM 16GB, SSD 512GB")
		->setPower(90)
		->setName("Acer Nitro")
		->setPrice(60499);

	stock[1] = (new Monitor())
		->setDiagonal(32)
		->setPower(120)
		->setName("Dell Vision")
		->setPrice(7950);

	std::unique_ptr<Product> ptr = std::make_unique<Laptop>(
		(new Laptop())
		->setHardware("Intel Core 5, RAM 16GB, SSD 512GB")
		->setPower(90)
		->setName("Acer Nitro")
		->setPrice(60499)
	);
	//std::unique_ptr<Product> ptr2 = ptr; - не можна
	std::unique_ptr<Product> ptr2 = std::move(ptr);

	std::shared_ptr<Product> s1 = std::make_shared<Monitor>(
		(new Monitor())
		->setDiagonal(32)
		->setPower(120)
		->setName("Dell Vision")
		->setPrice(7950)
	);
	std::shared_ptr<Product> s2 = s1;

	for (auto product : stock) {
		std::cout << product->toString() << std::endl;
	}
}

/*
Основні принципи ООП.
Абстрагування, спадкування, поліморфізм, інкапсуляція

Абстракція - термін, що означає поєднання деякої множини сутностей.
Приклад - природна мова. Майже будь-яке слово значить множину.
"Телефон" - множина реальних речей
Машинним мовам абстракція не властива, інструкції мають чітке вираження.
Абстрагування - побудова мовних конструкцій, здатних поєднувати
множинні властивості (сутності та інші абстракції).

Створення абстракцій передбачає вивчення (аналіз) предметної області
(чому присвячена програма). Наприклад, крамниця. Виписуємо усі товари,
що мають бути в крамниці, з усіма їх важливими характеристиками.

Ноутбук				 Монітор			 Миша 				 Клавіатура
 - назва			  - назва			  - назва			  - назва
 - ціна				  - ціна			  - ціна			  - ціна
 - "залізо"			  - діагональ		  - DPI				  - тип
 - потужність		  - потужність		  - підключення		  - підключення 

1) Знаходимо, що є спільного у ВСІХ стуностей: назва та ціна
формуємо вищу абстракцію: товар (Product), що поєднує все, що в нас є
							Product
							- назва	   -- інкапсуляція - переміщення спільних
							- ціна		  властивостей до абстракцій
	  /					  /				  \					   \
Ноутбук				 Монітор			 Миша 				 Клавіатура
 - "залізо"			  - діагональ		  - DPI				  - тип
 - потужність		  - потужність		  - підключення		  - підключення
2) Знаходимо групи зі спільними властивостями і будуємо наступний рівень абстракцій
 Електротовари (-потужність)				 Периферія (-підключення)
							  Product
							- назва - ціна
						/					\
				  Електротовари			   Периферія
				   - потужність				- підключення
				/				\		     /			   \
			 Ноутбук		Монітор			 Миша		   Клавіатура
			  - "залізо"	 - діагональ	  - DPI			- тип
повторюємо п.2) для всіх можливих групувань
-----------------------
Спадкування - механізм реалізації абстрагування - створення класів на
базі інших класів з їх розширенням. Дочірній клас (нащадок) повністю
включає в себе батьківський клас і може додавати власні елементи.
Спадкування може бути каскадним, тобто Елктротовари спадкуються від Товару,
а Ноутбук - від Електротовару (а значить і від Товару). Але на відміну
від простого розширення, спадкування зберігає типізацію, тобто Ноутбук
окрім того, що сам є типом, також є типом Електротовар і Товар.

Д. З. Обрати предметну галузь для програмування (взяти з прикладів
популярних сайтів - формуи, оренда житла/автівок тощо)
Виписати основні стуності, провести абстрагування - побудувати
ієрархію класів з абстракціями. Основний результат - діаграма класів.


Віртуальні методи
Різниця між віртуальними та невіртуальними методами виникає коли тип
даних посилання на об'єкт та тип самого об'єкта не є однаковими.
(посилання через батьківський тип)
Electrical* stock = new Laptop()
тип посилання (stock) - Electrical*
тип об'єкту - Laptop*
Віртуальні методи викликаються у об'єкта
  stock->v() -- Laptop::v
Невіртуальні методи - за типом даних
  stock->nv() -- Electrical::nv
Невіртуальні методи створюються за замовчанням,
для створення віртуальних необхідно додати оператор "virtual"
*/
/*
"Розумні покажчики" (Smart Pointers_ - спеціальні покажчики, які дозволяють 
автоматично контролювати правильне знищення об'єктів. Їх можна розуміти, як
"оболонки" над об'єктами, які не змінюють правила роботи з ними, але додають
спостереження за їх використанням: якщо об'єкт перестає використовуватись, то
він знищується.
unique_ptr — унікальний покажчик, мається на увазі, що неможна створити другий 
покажчик на вже створений об'єкт. Якщо потрібно перенести посилання, 
то слід скористатись std::move. Створюється командою std::make_unique

shared_ptr — розподілений покажчик, дозволяє створювати кілька посилань 
на один об'єкт. Створюється командою std::make_shared

Ідея роботи в тому, що розумні покажчики насправді не є покажчиками, 
а є звичайними змінними, що в середині зберігають покажчик. Змінні, що 
виходять з області видності, видаляються програмою автоматично, тоді як 
виділена пам'ять (для покажчиків) закріплюється за всією програмою і не 
керується при виході змінних з областей видності.

*/ 