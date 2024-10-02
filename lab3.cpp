#include <iostream>
#include <string>
#include <vector>
#include <locale>

class Node {
public:
    std::string inf;
    Node* next;

    Node(const std::string& info) : inf(info), next(nullptr) {}
};

class Queue {
private:
    Node* head;
    Node* last;

public:
    Queue() : head(nullptr), last(nullptr) {}

    void enqueue(const std::string& info) {
        Node* newNode = new Node(info);
        if (head == nullptr) {
            head = last = newNode; 
        }
        else {
            last->next = newNode; 
            last = newNode;
        }
    }

    void dequeue() {
        if (head == nullptr) {
            std::cout << "Очередь пуста.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void display() const {
        Node* current = head;
        if (current == nullptr) {
            std::cout << "Очередь пуста.\n";
            return;
        }
        while (current) {
            std::cout << "Имя - " << current->inf << "\n";
            current = current->next;
        }
    }

    ~Queue() {
        while (head) {
            dequeue();
        }
    }
};

int main() {
    setlocale(LC_ALL, "RUS");

    int coloch;
    std::cout << "Введите количество очередей: ";
    std::cin >> coloch;

    std::vector<Queue> queues(coloch);

    while (true) {
        int choice, queueNum;
        std::cout << "-------------------------------------------------\n";
        std::cout << "1. Добавить элемент в очередь\n2. Удалить элемент из очереди\n3. Просмотреть очередь\n4. Выйти\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        if (choice == 4) break;

        std::cout << "Выберите номер очереди (от 1 до " << coloch << "): ";
        std::cin >> queueNum;
        queueNum--;

        if (queueNum < 0 || queueNum >= coloch) {
            std::cout << "Неверный номер очереди.\n";
            continue;
        }

        if (choice == 1) {
            std::string name;
            std::cout << "Введите название объекта: ";
            std::cin >> name; // Считывание информации
            queues[queueNum].enqueue(name); // Добавление элемента в очередь
        }
        else if (choice == 2) {
            queues[queueNum].dequeue(); // Удаление элемента из очереди
        }
        else if (choice == 3) {
            queues[queueNum].display(); // Просмотр содержимого очереди
        }
    }
    return 0;
}