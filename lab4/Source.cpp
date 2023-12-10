#include <iostream>
#include <string>
using namespace std;

// ����������� ��������� ����
struct Node 
{
    string product; // �������� ��������
    int quantity; // ���������� ��������
    Node* next; // ��������� �� ��������� ����
    Node* prev; // ��������� �� ���������� ����
};

// ����������� ������ ���������������� ������
class DoublyLinkedList {
    Node* head; // ������ ������
    Node* tail; // ����� ������

public:
    // ����������� �� ���������
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    // ������� ���������� ���� � ������
    void addNode(string product, int quantity) 
    {
        Node* newNode = new Node(); // �������� ������ ����
        newNode->product = product; // ���������� �������� �������� ������ ����
        newNode->quantity = quantity; // ���������� ���������� �������� ������ ����

        if (head == NULL) // ���� ������ ����
        { 
            head = newNode; // ����� ���� ���������� ������� ������
            tail = newNode; // ����� ���� ���������� ������� ������
            newNode->next = head; // ��������� ������� ��� ������ ���� - ������ ������ (�������� �����)
            newNode->prev = tail; // ���������� ������� ��� ������ ���� - ����� ������ (�������� �����)
        }
        else // ���� ������ �� ����
        { 
            tail->next = newNode; // ��������� ������� ��� ������ ������ - ����� ����
            newNode->prev = tail; // ���������� ������� ��� ������ ���� - ������� ����� ������
            tail = newNode; // ����� ���� ���������� ������� ������
            tail->next = head; // ��������� ������� ��� ������ ������ - ������ ������ (�������� �����)
            head->prev = tail; // ���������� ������� ��� ������ ������ - ����� ������ (�������� �����)
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

    list.display();  // ������� ���������� ������ ������
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
