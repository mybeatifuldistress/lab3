#include <iostream>
#include <locale>
#include <memory>

struct Node {
    int data;
    int priority;
    Node* next;
};

class PriorityQueue {
private:
    Node* head;

public:
    PriorityQueue() : head(nullptr) {}

    void push(int data, int priority) {
        Node* temp = new Node{ data, priority, nullptr };

        if (head == nullptr || head->priority < priority) {
            temp->next = head;
            head = temp;
        }
        else {
            Node* current = head;
            while (current->next != nullptr && current->next->priority >= priority) {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
        }
    }

    int popHighestPriority() {
        if (head == nullptr) {
            std::cout << "Очередь пуста.\n";
            return -1;
        }
        Node* temp = head;
        head = head->next;
        int data = temp->data;
        delete temp;
        return data;
    }

    int popLowestPriority() {
        if (head == nullptr) {
            std::cout << "Очередь пуста.\n";
            return -1;
        }
        Node* current = head;
        Node* prev = nullptr;

        while (current->next != nullptr) {
            prev = current;
            current = current->next;
        }
        int data = current->data;
        delete current;

        if (prev == nullptr) {
            head = nullptr;
        }
        else {
            prev->next = nullptr;
        }
        return data;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << "Данные: " << current->data << ", Приоритет: " << current->priority << std::endl;
            current = current->next;
        }
    }

    int popSpecificPriority(int targetPriority) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->priority == targetPriority) {
                int data = current->data;
                if (current == head) {
                    head = current->next;
                }
                else {
                    prev->next = current->next;
                }
                delete current;
                std::cout << "Удаленный элемент с заданным приоритетом: " << data << std::endl;
                return 1;
            }
            else {
                prev = current;
                current = current->next;
            }
        }
        std::cout << "Элемент с приоритетом " << targetPriority << " не найден.\n";
        return -1;
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    PriorityQueue pq;
    int choice;
    int data;
    int priority;

    while (true) {
        std::cout << "-------------------------------------------------\n";
        std::cout << "1. Добавить элемент\n"
            << "2. Удалить элемент с наивысшим приоритетом\n"
            << "3. Удалить элемент с наименьшим приоритетом\n"
            << "4. Удалить элемент с выбранным приоритетом\n"
            << "5. Показать очередь\n"
            << "6. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите число: ";
            std::cin >> data;
            std::cout << "Введите приоритет: ";
            std::cin >> priority;
            pq.push(data, priority);
            break;
        case 2:
            data = pq.popHighestPriority();
            if (data != -1) {
                std::cout << "Удаленный элемент с наивысшим приоритетом: " << data << std::endl;
            }
            break;
        case 3:
            data = pq.popLowestPriority();
            if (data != -1) {
                std::cout << "Удаленный элемент с наименьшим приоритетом: " << data << std::endl;
            }
            break;
        case 4:
            std::cout << "Введите приоритет: ";
            std::cin >> priority;
            pq.popSpecificPriority(priority);
            break;
        case 5:
            pq.display();
            break;
        case 6:
            return 0;
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
        }
    }

    return 0;
}