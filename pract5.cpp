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
		for (Node* i = head; i != nullptr; i = i->next)
		{
			for (Node* current = head; current->next != nullptr;current = current->next)
			{
				if (current->data == current->next->data)
				{

					delete current;
				}
			}
		}
	}
};

int main()
{
	setlocale(LC_ALL,"Russian");
	DoublyLinkedList list;
	char answer[4];
	std::cout << "Хотите начать? (da/net)" << "\n";
	std::cin >> answer;
	std::cout << answer << "\n";
	if (strcmp(answer,"da")==0)
	{
		std::cout << "Меню действий:" << "\n";
		std::cout << "Добавить элемент в началo - addN" << "\n";
		std::cout << "Добавить элемент в конец - addE" << "\n";
		std::cout << "Удалить элемент с начала - deleteN" << "\n";
		std::cout << "Удалить элемент с конца - deleteE" << "\n";
		std::cout << "Отобразить список - show" << "\n";
		std::cout << "Сортировать список - sort" << "\n";
		std::cout << "Удалить дубликаты - dubl" << "\n";
		std::cout << "Выйти - end" << "\n";
		int menu;
		std::cin >> menu;
		while (menu!=8)
		{
			switch (menu)
			{
			case 1: 
				int num;
				std::cin >> num;
				list.push_front(num);
				break;
			case 2:
				list.display();
				break;
			default:
				break;
			}
		}

	}
	else {
		std::cout << "Конец";
	}
}
