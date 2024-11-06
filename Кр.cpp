// Сформировать линейный однонаправленный стек. Сформировать новую очередь из элементов этого списка, которые присутствуют в нем по одному разу.
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

struct stacknode {
    int data;
    stacknode* next;
};

struct queuenode {
    int data;
    queuenode* next;
};

stacknode* node_stack(int value) {
    stacknode* newNode = new stacknode;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

queuenode* queue_node(int value) {
    queuenode* newNode = new queuenode;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void put(stacknode*& top, int value) {
    stacknode* newNode = node_stack(value);
    newNode->next = top;
    top = newNode;
}

stacknode* read_file(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Unable to open file " << filename << " for reading" << endl;
        return nullptr;
    }

    // Проверка на пустоту файла, не уверена нужно ли
    if (file.peek() == ifstream::traits_type::eof()) {
        cout << "Input file is empty" << endl;
        return nullptr;
    }

    stacknode* top = nullptr;
    int value;
    while (file >> value) {
        put(top, value);
    }
    file.close();
    return top;
}

void enqueue(queuenode*& front, queuenode*& rear, int value) {
    queuenode* newNode = queue_node(value);
    if (!rear) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}


queuenode* queue_create(stacknode* top) {
    int MAX_VALUE = numeric_limits<int>::max();

    int* freq = new int[MAX_VALUE / 100]();

    stacknode* current = top;
    while (current) {
        freq[current->data]++;
        current = current->next;
    }

    queuenode* front = nullptr;
    queuenode* rear = nullptr;
    current = top;
    while (current) {
        if (freq[current->data] == 1) {
            enqueue(front, rear, current->data);
        }
        current = current->next;
    }

    return front;
}

void stack_print(stacknode* top, ostream& output) {
    stacknode* current = top;
    while (current) {
        output << current->data << " ";
        current = current->next;
    }
    output << endl;
}

void queue_print(queuenode* front, ostream& output) {
    queuenode* current = front;
    while (current) {
        output << current->data << " ";
        current = current->next;
    }
    output << endl;
}

void free_stack(stacknode* top) {
    while (top) {
        stacknode* temp = top;
        top = top->next;
        delete temp;
    }
}

void free_queue(queuenode* front) {
    while (front) {
        queuenode* temp = front;
        front = front->next;
        delete temp;
    }
}

bool compare_stack_queue(stacknode* stack, queuenode* queue) {
    stacknode* currentStack = stack;
    queuenode* currentQueue = queue;

    while (currentStack && currentQueue) {
        if (currentStack->data != currentQueue->data) {
            return false;
        }
        currentStack = currentStack->next;
        currentQueue = currentQueue->next;
    }

    return currentStack == nullptr && currentQueue == nullptr;
}

int main() {
    cout << "Petrunina Maria BIV235" << endl;
    string file_input, file_output;
    cout << "Name of input file: ";
    cin >> file_input;
    cout << "Name of output file: ";
    cin >> file_output;

    stacknode* stack = read_file(file_input);
    if (!stack) {
        return 1;
    }

    ofstream new_file(file_output);
    if (!new_file.is_open()) {
        cout << "Unable to open file " << file_output << " for writing" << endl;
        return 1;
    }

    cout << "entered stack: ";
    stack_print(stack, cout);
    new_file << "entered stack: ";
    stack_print(stack, new_file);

    queuenode* queue_un = queue_create(stack);


    if (!queue_un) {
        cout << "All elements repeat. The queue is empty" << endl;
    } else {
        cout << "result queue: ";
        queue_print(queue_un, cout);
        new_file << "result queue: ";
        queue_print(queue_un, new_file);
    }

    if (compare_stack_queue(stack, queue_un)) {
        cout << "The stack and queue are same" << endl;
        new_file << "The stack and queue are same" << endl;
    }

    new_file.close();

    free_stack(stack);
    free_queue(queue_un);

    return 0;
}
