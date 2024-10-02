#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <cstring>   
#include <locale>  
#include <memory>    

struct Node {
    char inf[256]; 
    std::shared_ptr<Node> next;  
};

std::shared_ptr<Node> head = nullptr;  

std::shared_ptr<Node> createNode() {
    char s[256];
    std::cout << "Введите название элемента: ";
    std::cin.getline(s, sizeof(s));

    if (strlen(s) == 0) {
        std::cout << "Элемент не добавлен\n";
        return nullptr;
    }

    auto newNode = std::make_shared<Node>();
    strcpy(newNode->inf, s);
    newNode->next = nullptr;
    return newNode;
}

void push() {
    auto newNode = createNode();
    if (newNode == nullptr) return;
    newNode->next = head;
    head = newNode;
}

void pop() {
    if (head == nullptr) {
        std::cout << "Стек пуст\n";
        return;
    }
    head = head->next;  
}

void peek() {
    if (head == nullptr) {
        std::cout << "Стек пуст\n";
        return;
    }
    std::cout << "Верхний элемент стека: " << head->inf << std::endl;
}

void review() {
    auto temp = head;
    if (head == nullptr) {
        std::cout << "Стек пуст\n";
        return;
    }
    while (temp) {
        std::cout << "Элемент стека: " << temp->inf << std::endl;
        temp = temp->next;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    int choice;

    do {
        std::cout << "-------------------------------------------------\n";
        std::cout << "1. Добавить элемент в стек \n"
            << "2. Удалить элемент из стека\n"
            << "3. Посмотреть верхний элемент стека\n"
            << "4. Просмотреть весь стек\n"
            << "5. Выйти\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            review();
            break;
        case 5:
            std::cout << "Выход\n";
            break;
        default:
            std::cout << "Неправильный выбор. Попробуйте еще раз.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}