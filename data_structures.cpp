#include "data_structures.h"
#include "data_structures/linked_list.h"
#include "data_structures/queue_list.h"
#include "data_structures/array.h"
#include "data_structures/queue.h"
#include <iostream>


template<typename T>						// Шаблонними можуть бути функції та типи (класи, структури)
void print(T arg) {							// Шаблон вводить "змінну" для типу, традиційно "T"
	std::cout << arg << std::endl;			// В самій функції (чи типі) ця "T" вживається там,
}											// де пізніще має бути реалізований тип даних
											// Далі компілятор шукає усі вжитки даного шаблону...
template<typename T>
struct fraction {
	T numerator;
	T denominator;
	void print() {
		std::cout 
			<< numerator
			<< "/"
			<< denominator
			<< std::endl;
	}
	T get_numerator() {
		return numerator;
	}
	void set_numerator(T n) {
		numerator = n;
	}
};

//Task 1
void data_structures_q() {
	QueueList<double>* doubleList = new QueueList<double>();
	doubleList->add(1.2);
	doubleList->add(23.5);
	doubleList->add(-123.6);
	doubleList->print();
	std::cout << "first: " << doubleList->peek() << std::endl;
	std::cout << "popped: " << doubleList->pop() << std::endl;
	doubleList->print();
	doubleList->add(3.6);
	doubleList->print();
	std::cout << "popped: " << doubleList->pop() << std::endl;
	doubleList->print();
	std::cout << "Clear: " << std::endl;
	doubleList->clear();
	doubleList->print();
	delete doubleList;
}
//Task 2
void data_structures_l() {
	std::cout << "Data structures" << std::endl;
	LinkedList<int>* intList1 = new LinkedList<int>();
	intList1->add(10);
	intList1->add(20);
	intList1->add(30);
	intList1->insertBefore(5, 0);
	intList1->insertBefore(15, 2);
	intList1->print();
	std::cout << "removed: " << intList1->remove(2) << std::endl;
	intList1->print();
	std::cout << "removed: " << intList1->remove(2) << std::endl;
	intList1->print();
	std::cout << "removed: " << intList1->remove(1) << std::endl;
	intList1->print();
	std::cout << "removed: " << intList1->remove(0) << std::endl;
	intList1->print();
	std::cout << "removed: " << intList1->remove(0) << std::endl;
	intList1->print();
	LinkedList<int>* intList2 = new LinkedList<int>();
	intList2->add(45);
	intList2->add(210);
	intList2->add(20);
	intList2->add(6);
	intList2->add(15);
	intList2->print();
	ListNode<int>* cpy = intList2->copy();
	while (cpy) {
		std::cout << cpy->data << " ";
		cpy = cpy->next;
	}
	std::cout << std::endl;
	ListNode<int>* summ = *intList1 + *intList2;
	while (summ) {
		std::cout << summ->data << " ";
		summ = summ->next;
	}
	std::cout << std::endl;
	ListNode<int>* mult = *intList1 * *intList2;
	while (mult) {
		std::cout << mult->data << " ";
		mult = mult->next;
	}
	std::cout << std::endl;
	
	delete intList2;
	delete intList1;
}
//Task 3
void data_structures_a() {
	Array<int>* arr1 = new Array<int>();
	arr1->SetSize(5, 5);
	if (arr1->IsEmpty()) std::cout << "Empty" << std::endl;
	std::cout << "Used size: " << arr1->GetSize() << std::endl;
	arr1->Add(10);
	arr1->Add(20);
	arr1->Add(30);
	arr1->Add(40);
	arr1->Add(50);
	arr1->print();
	std::cout << "Upper bound: " << arr1->GetUpperBound() << std::endl;
	arr1->Add(60);
	arr1->print();
	std::cout << "Used size: " << arr1->GetSize() << std::endl;
	arr1->SetAt(2, 5);
	arr1->SetAt(7, 5);
	arr1->print();
	std::cout << "Element with index 4 = " << arr1->GetAt(4) << std::endl;
	arr1->FreeExtra();
	arr1->print();

	Array<int>* arr2 = new Array<int>();
	arr2->SetSize(2, 1);
	arr2->Add(100);
	arr2->Add(200);
	arr1->Append(*arr2);
	arr1->print();

	Array<int>* arr3 = new Array<int>();
	*arr3 = *arr1;

	ListNode<int>* node = arr3->GetData();
	while (node) {
		std::cout << node->data << " ";
		node = node->next;
	}
	std::cout << std::endl;

	arr1->RemoveAll();
	arr1->print();
	arr2->RemoveAll();
	arr3->RemoveAll();
	delete arr1;
	delete arr2;
	delete arr3;
}

//CW
void data_structures() {
	std::cout << "Queue demo" << std::endl;
	Queue<int> queue;
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	std::cout << queue.dequeue() << std::endl;
	std::cout << queue.dequeue() << std::endl;
	std::cout << queue.dequeue() << std::endl;
}

void data_structures_t() {
	std::cout << "Templates" << std::endl;
	print("Template function demo");		// ... і для кожного конкретного вжитку 
	print(42);								// створює копію шаблона під даний "T"
	print(true);
	print('A');
	print<short>(42);

	fraction<int> f1{ 1, 2 };
	fraction<float> f2{ 1.5, 2.5 };
	fraction<short> f3{ 2, 3 };
	f1.print(); std::cout<<std::endl;
	f2.print();	std::cout<<std::endl;
	f3.print();	std::cout<<std::endl;
}
/*
Структури даних та шаблонне програмування
1.	Структури даних - типові способи організації даних,
	поширені в різних практичних задачах
- Стек (Stack) - спосіб, за якого дані накопичуються
	в одному порядку, а виводяться в іншому (First In Last Out - FILO)
	3 -> 2 -> 1 -> [Stack]
	[Stack] -> 3
	Вживається, зокрема, у механізмі виклику функцій
	a(b(c(x))): 1) c(x), 2) b(res), 3) a(res)
- Черга (Queue) - (First In First Out - FIFO) - прямий
	порядок передачі накопичених даних.
	Може вживатись для буферизації, коли швидкість обробки
	не точно дорівнює швидкості передачі даних.
	File -> 1 -> 2 -> 3 -> [Queue] -> 1 -> [Process]
- Списки (Lists) - колекції з можливістю додавння, вставлення,,
	вилучення даних. На відміну від стека та черги, доступ можливий
	до довільного елементу списка. Розрізняють зв'язні списки та
	списки-масиви:
	= зв'язні списки (Linked List) зберігають дані та посилання
	  на інші "вузли" списку (або тільки на наступний, або і на 
	  наступний і на попередній)
	= списки-масиви (Array List) "тримають" масив із запасом,
	  за потреби більшого розширення масив перекопійовується
	  у більший масив
  Порівняння: масиви дозволяють швидко одержати елемент з довільним
	індексом, тоді як зв'язні списки мають "шукати" елементи переходячи
	до сусідніх певну кількість разів -- пошук швидший у масивів.
	Недолік масивів полягає в операціях вставки елементів в середину або
	вилучення з середини. В такому разі решта елементів має "посунутись"
	1 2 3 4 5 6 7  тоді як в зв'язних списків необхідно лише
		^		   переставити покажчики на інших сусідів
	1 2 - 4 5 6 7		 1 <-> 2 <-> 3 <-> 4 <-> 5
		<-							 ^
	1 2 4 5 6 7			 1 <-> 2 <-------> 4 <-> 5
		 10
			->			 1 <-> 2 <-> 3 <-> 4 <-> 5
	1 2 4 10 5 6 7					   10
						 1 <-> 2 <-> 3     4 <-> 5
									  \	  /
									<->	10 <->
  Вибір між видами списків робиться з аналізу операцій, що з ними виконуються:
  якщо список будується один раз, а далі тільки одержуються елементи
   (наприклад, зчитати файл і потім працювати з даними), тоді краще масив
  якщо список весь час змінюється (наприклад, ігрові елементи - спавняться,
   збиваються, зникають), тоді краще зв'язний список.

- Множина (Set) - набір з унікальними значеннями (що не повторюється)
	зазвичай в множинах реалізується швидкий пошук завдяки організації
	бінарним деревом. Структура схожа з за'язним списком, але має два
	покажчики - на лівий вузол (з меншим значенням) та правий вузол (з
	більшим значенням)
	Медіана - елемент множини, який ділить її навпіл: як менших, так і більших
	елементів є порівну. Якщо в множини непарна кількість елементів, то медіана
	є середнім елементом. Якщо парна, то середнє від центральних.
	(0 1 2 3 4 5 6 7 8 9 10)
			   ^
						  5
					/       	 \
			  (0 1 2 3 4)	  (6 7 8 9 10)
				   ^			   ^
						  5 
						/	\
					   2	 8
					  /	\	/ \
					 1	4  6   9
					/	/   \	\
				   0   3	 7	 10
2^3 = 8; 2^4 = 16; 2^5 = 32; 2^10 = 1024
1000 елементів - пошук до 10 разів
1 млн елементів - до 20
1млрд - до 30

- Асоціативні масиви (Map, Dictionary, Hash-Table) - структури даних,
	в яких індексація може бути не числова. Їх також називають
	"множинами ключ-значення", вживаючи замість терміну "індекс" термін "ключ".
	Вживаються при введенні доменних імен (імен вузлів мережі, які в
	самій мережі адресуються числом)
	"itstep.org" => 123.3.16.7
*/
/*
Узагальнене (шаблонне) програмування
Структури данних передбачають організацію даних, але нічого не
зазначають про типи даних. Якщо потрібна організація для
даних різного типу, то складаєьбся враження, що необхідно
створювати декілька однакових за схемою структур, але з різними
типами даних в середині: список для цілих чисел, список для дробових,
список для рядків тощо.
Узагальнене програмуваня дозволяє зробити структури даних, що 
можуть працювати з різними типами внутрішніх даних: описати 
шаблон, який буде реалізовуватись для конкретних типів у програмі.
*/