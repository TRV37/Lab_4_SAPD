#include <iostream>
#include <string>
using namespace std;

// Определение структуры узла
struct Node 
{
    string product; // название продукта
    int quantity; // количество продукта
    Node* next; // указатель на следующий узел
    Node* prev; // указатель на предыдущий узел
};

// Определение класса двунаправленного списка
class DoublyLinkedList {
    Node* head; // голова списка
    Node* tail; // хвост списка

public:
    // Конструктор по умолчанию
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    // Функция добавления узла в список
    void addNode(string product, int quantity) 
    {
        Node* newNode = new Node(); // создание нового узла
        newNode->product = product; // присвоение названия продукта новому узлу
        newNode->quantity = quantity; // присвоение количества продукта новому узлу

        if (head == NULL) // если список пуст
        { 
            head = newNode; // новый узел становится головой списка
            tail = newNode; // новый узел становится хвостом списка
            newNode->next = head; // следующий элемент для нового узла - голова списка (создание цикла)
            newNode->prev = tail; // предыдущий элемент для нового узла - хвост списка (создание цикла)
        }
        else // если список не пуст
        { 
            tail->next = newNode; // следующий элемент для хвоста списка - новый узел
            newNode->prev = tail; // предыдущий элемент для нового узла - текущий хвост списка
            tail = newNode; // новый узел становится хвостом списка
            tail->next = head; // следующий элемент для хвоста списка - голова списка (создание цикла)
            head->prev = tail; // предыдущий элемент для головы списка - хвост списка (создание цикла)
        }
    }

    void deleteNode(string product) 
    {
        if (head == NULL) 
        {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        Node* current = head;

        do 
        {
            if (current->product == product) 
            {
                if (current == head) 
                {
                    head = head->next;
                    head->prev = tail;
                    tail->next = head;
                }
                else if (current == tail) 
                {
                    tail = tail->prev;
                    tail->next = head;
                    head->prev = tail;
                }
                else 
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        } while (current != head);
    }

    void searchNode(string product) 
    {
        if (head == NULL) 
        {
            cout << "List is empty. Cannot search.\n";
            return;
        }

        Node* current = head;

        do 
        {
            if (current->product == product) 
            {
                cout << "Product " << product << " found in the list with quantity " << current->quantity << "\n";
                return;
            }
            current = current->next;
        } while (current != head);

        cout << "Product " << product << " not found in the list\n";
    }

    void display() 
    {
        if (head == NULL) 
        {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;

        do 
        {
            cout << "Product: " << current->product << ", Quantity: " << current->quantity << "\n";
            current = current->next;
        } while (current != head);
    }

    void sortAlphabetically() 
    {
        if (head == NULL) 
        {
            cout << "List is empty. Cannot sort.\n";
            return;
        }

        Node* i, * j;
        string temp_product;
        int temp_quantity;

        for (i = head; i != tail; i = i->next) 
            for (j = i->next; j != head; j = j->next) 
                if (i->product > j->product) 
                {
                    temp_product = i->product;
                    temp_quantity = i->quantity;

                    i->product = j->product;
                    i->quantity = j->quantity;

                    j->product = temp_product;
                    j->quantity = temp_quantity;
                }
            
        
    }

    void sortByQuantity() 
    {
        if (head == NULL) 
        {
            cout << "List is empty. Cannot sort.\n";
            return;
        }

        Node* i, * j;
        string temp_product;
        int temp_quantity;

        for (i = head; i != tail; i = i->next) 
            for (j = i->next; j != head; j = j->next) 
                if (i->quantity < j->quantity) 
                {
                    temp_product = i->product;
                    temp_quantity = i->quantity;

                    i->product = j->product;
                    i->quantity = j->quantity;

                    j->product = temp_product;
                    j->quantity = temp_quantity;
                }
            
        
    }
};

int main() 
{
    DoublyLinkedList list;

    list.display();  // Попытка отобразить пустой список
    system("pause");
    system("cls");

    list.addNode("Apple", 10);
    list.addNode("Banana", 20);
    list.addNode("Cherry", 30);

    list.display();
    system("pause");
    system("cls");

    list.deleteNode("Banana");

    list.display();
    system("pause");
    system("cls");

    list.searchNode("Cherry");
    system("pause");
    system("cls");

    cout << "Sorting alphabetically:\n";
    list.sortAlphabetically();
    list.display();
    system("pause");
    system("cls");

    cout << "Sorting by quantity:\n";
    list.sortByQuantity();
    list.display();

    system("pause");
    return 0;
}
