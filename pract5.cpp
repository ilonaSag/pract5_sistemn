#include <iostream>
class DoublyLinkedList {
	struct Node {
		int data;
		Node* next;
		Node* prev;

		Node(int value) : data(value), next(nullptr), prev(nullptr) {}
	};
	Node* head;
	Node* tail;
public:
	DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
	}
	void push_front(int value) {
		Node* newNode = new Node(value);
		if (head == nullptr)
		{
			head = tail = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}
	void push_back(int value) {
		Node* newNode = new Node(value);
		if (head == nullptr)
		{
			head = tail = newNode;
		}
		else {
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
	}
	void pop_front() {
		Node* oldNode = head;
		if (head == tail)
		{
			head = tail = nullptr;
		}
		else {
			head = head->next;
			head->prev = nullptr;
		}
		delete oldNode;
	}
	void pop_back() {
		Node* oldNode = tail;
		if (head == tail)
		{
			head = tail = nullptr;
		}
		else {
			tail = tail->prev;
			tail->next = nullptr;
		}
		delete oldNode;
	}
	void display() {
		for (Node* current = head; current != nullptr; current = current->next)
		{
			std::cout << current->data << " ";
		}
		std::cout << "\n";
	}
	void sort() {
		if (head == nullptr)
		{
			std::cout << "Список пуст";
			return;
		}
		for (Node* i = head; i != nullptr; i = i->next)
		{
			for (Node* current = head; current->next != nullptr;current=current->next)
			{
				if (current->data > current->next->data)
				{
					int temp = current->data;
					current->data = current->next->data;
					current->next->data = temp;
				}
			}
		}
	}
	void remove_duplicates() {
		Node* current = head;

		while (current != nullptr) {
			Node* temp = current->next;

			while (temp != nullptr) {
				Node* dubl = temp->next;

				if (temp->data == current->data) {
					if (temp->prev != nullptr) {
						temp->prev->next = temp->next;
					}
					if (temp->next != nullptr) {
						temp->next->prev = temp->prev;
					}

					if (temp == tail) {
						tail = temp->prev;
					}

					if (temp == head) {
						head = temp->next;
					}
					if (temp == tail) {
						tail = temp->prev;
					}
					delete temp;
				}

				temp = dubl;
			}
			current = current->next;
		}
	}
};

int main()
{
	setlocale(LC_ALL,"Russian");
	DoublyLinkedList list;
		std::cout << "Меню действий:" << "\n";
		std::cout << "1. Добавить элемент в началo" << "\n";
		std::cout << "2. Добавить элемент в конец" << "\n";
		std::cout << "3. Удалить элемент с начала" << "\n";
		std::cout << "4. Удалить элемент с конца" << "\n";
		std::cout << "5. Отобразить список" << "\n";
		std::cout << "6. Сортировать список" << "\n";
		std::cout << "7. Удалить дубликаты" << "\n";
		std::cout << "8. Выйти" << "\n";
		int menu;
		do
		{

			std::cin >> menu;
			switch (menu)
			{
			case 1: 
				int num1;
				std::cout << "Введите число, чтобы добавить в начало:" << "\n";
				std::cin >> num1;
				list.push_front(num1);
				break;
			case 2:
				int num2;
				std::cout << "Введите число, чтобы добавить в конец:" << "\n";
				std::cin >> num2;
				list.push_back(num2);
				break;
			case 3: 
				std::cout << "Число удалено с начала" << "\n";
				list.pop_front();
				break;
			case 4:
				std::cout << "Число удалено с конца" << "\n";
				list.pop_back();
				break;
			case 5:
				std::cout << "Список:" << "\n";
				list.display();
				break;
			case 6:
				std::cout << "Сортированный список:" << "\n";
				list.sort();
				list.display();
				break;
			case 7:
				std::cout << "Дубликаты удалены:" << "\n";
				list.remove_duplicates();
				list.display();
				break;
			case 8:
				break;
			default:
				break;
			}
		} while (menu != 8);
}
