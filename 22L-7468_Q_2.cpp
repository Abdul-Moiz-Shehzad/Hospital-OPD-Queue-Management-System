#include <iostream>
#include <exception>
using namespace std;
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
int checker = 0;
class Node {
public:
	Node() {}
	string name;
	int age;
	string condition;
	int priority;
	Node* next;
	Node(string name, int age, string condition, int priority) {
		this->name = name;
		this->age = age;
		this->condition = condition;
		this->priority = priority;
		next = nullptr;
	}
};
class linkedList :public Node {
public:
	Node* head;
	linkedList() {
		head = nullptr;
	}
	void insertAtEnd(string name, int age, string condition, int priority) {
		Node* n1 = new Node(name, age, condition, priority);
		if (head == nullptr) {
			head = n1;
		}
		else {
			Node* curr = head;
			while (curr->next != nullptr) {
				curr = curr->next;
			}
			curr->next = n1;
		}
	}
	void insertAtSart(string name, int age, string condition, int priority) {
		Node* n1 = new Node(name, age, condition, priority);
		if (head == nullptr) {
			head = n1;
		}
		else {
			n1->next = head;
			head = n1;
		}
	}
	void deleteFromEnd() {
		if (head == nullptr) {

		}
		else {
			Node* curr = head;
			while (curr->next->next != nullptr) {
				curr = curr->next;
			}
			curr->next = nullptr;
		}
	}
	void deleteFromStart() {
		if (head == nullptr) {

		}
		else {
			head = head->next;
		}
	}
	void display() {
		if (head == nullptr) {

		}
		else {
			int count = 1;
			Node* curr = head;
			while (curr != nullptr) {
				cout << "Patient#" << count << ": ";
				cout << "Name: " << curr->name << " Age: " << curr->age << " Condition: " << curr->condition << " Priority(0/1): " << curr->priority << endl;
				curr = curr->next;
				count++;
			}
			cout << endl;
		}
	}
	void topList() {
		if (head == nullptr) {

		}
		else {
			Node* curr = head;
			while (curr->next != nullptr) {
				curr = curr->next;
			}
			cout << curr->name << " " << curr->age << " " << curr->condition << " " << curr->priority << endl;
		}
	}
	int findKelement(string k) {//for updating the information
		Node* curr = head;
		int index = 0;
		bool found = 0;
		while (curr != nullptr) {
			index++;
			if (curr->name == k) {
				found = 1;
				break;
			}
			curr = curr->next;
		}
		if (found == 1) {
			return index;
		}
		else {
			return -1;
		}
	}
	void sortOnPriority() {
		if (head == nullptr || head->next == nullptr) {
			return;
		}
		Node* end = nullptr;
		bool swapped;
		do {
			swapped = false;
			Node* current = head;
			while (current->next != end) {
				if (current->priority < current->next->priority) {
					swap(current->name, current->next->name);
					swap(current->age, current->next->age);
					swap(current->condition, current->next->condition);
					swap(current->priority, current->next->priority);

					swapped = true;
				}
				current = current->next;
			}
			end = current;
		} while (swapped);
	}
	void shiftPatientlist(linkedList& List, Node* node, linkedList& To) {
		try {
			Node* curr = List.head;
			while (curr->next != nullptr) {
				curr = curr->next;

			}
			if (checker == 1) {
				curr->priority = curr->priority - 2;
			}
			else if (checker == 2) {
				curr->priority = curr->priority + 2;
			}
			To.insertAtEnd(curr->name, curr->age, curr->condition, curr->priority);
			List.head = nullptr;
			//To.insertAtEnd(curr->next->name, curr->next->age, curr->next->condition, curr->next->priority);
			List.sortOnPriority();
			To.sortOnPriority();
			return;
		}
		catch (exception e) {
			cout << RED << "Error found ;-;" << RESET << endl;
		}
	}
	int deleteKelement(string k) {
		Node* curr = head;
		Node* patient = nullptr;
		if (curr->next == nullptr) {
			if (curr->name == k) {
				head = nullptr;
				return 1;
			}
			else {
				return 0;
			}
		}
		while (curr->next->next != nullptr) {
			if (curr->next->name == k) {
				patient = curr->next;
				curr->next = curr->next->next;
				return 1;
			}
			curr = curr->next;
		}
		delete patient;
	}
};
class stack {
	linkedList l1;
public:
	void pushStack(string name, int age, string condition, int priority) {
		l1.insertAtEnd(name, age, condition, priority);
	}
	void popStack() {
		if (isEmptyStack()) {
			return;
		}
		l1.deleteFromEnd();
	}
	bool isEmptyStack() {
		if (l1.head == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	void displayStack() {
		l1.display();
	}
	void topStack() {
		l1.topList();
	}
};
class queue {
	linkedList l1;
public:
	void pushInQueue(string name, int age, string condition, int priority) {
		l1.insertAtEnd(name, age, condition, priority);
	}
	void popFromQueue() {
		if (isEmptyQueue()) {
			return;
		}
		else {
			l1.deleteFromStart();
		}
	}
	bool isEmptyQueue() {
		if (l1.head == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	void displayQueue() {
		l1.display();
	}
	void getRear() {
		l1.topList();
	}
	void getFront() {
		if (isEmptyQueue()) {
			return;
		}
		else {
			Node* curr = l1.head;
			cout << curr->name << " " << curr->age << " " << curr->condition << " " << curr->priority << endl;
		}
	}
	int ReplacePatientQueueToOld(string k, queue& to) {
		int choice;
		int patient = l1.findKelement(k);
		if (patient == -1) {
			cout << RED << "Patient not found normal Queue" << RESET << endl;
			return 0;
		}
		else {
			cout << GREEN << "Patient found in normal Queue" << RESET << endl;
		}
		Node* curr = l1.head;
		for (int i = 0; i < patient - 1; i++) {
			curr = curr->next;
		}
		cout << "Press 1 to update name\nPress 2 to update age ";
		cin >> choice;
		while (choice <= 0 || choice > 2) {
			cout << "Invalid option Enter again ";
			cin >> choice;
		}
		if (choice == 1) {
			cout << "Enter new name" << endl;
			cin >> curr->name;
		}
		else if (choice == 2) {
			int age;
			cout << "Enter new age" << endl;
			cin >> age;
			while (age <= 0) {
				cout << "Enter correct age ";
				cin >> age;
			}
			curr->age = age;;
		}
		checker = 2;
		if (curr->age >= 60) {
			l1.shiftPatientlist(l1, curr, to.l1);
		}
		return 1;
	}
	int ReplacePatientOldToQueue(string k, queue& to) {
		int choice;
		int patient = l1.findKelement(k);
		if (patient == -1) {
			cout << RED << "Patient not found in old age queue" << RESET << endl;
			return 0;
		}
		else {
			cout << GREEN << "Patient found in old age queue" << RESET << endl;
		}
		Node* curr = l1.head;
		for (int i = 0; i < patient - 1; i++) {
			curr = curr->next;
		}
		cout << "Press 1 to update name\nPress 2 to update age";
		cin >> choice;
		while (choice <= 0 || choice > 2) {
			cout << "Invalid option Enter again ";
			cin >> choice;
		}
		if (choice == 1) {
			cout << "Enter new name" << endl;
			cin >> curr->name;
		}
		else {
			int age;
			cout << "Enter new age" << endl;
			cin >> age;
			while (age <= 0) {
				cout << "Enter correct age ";
				cin >> age;
			}
			curr->age = age;;
		}
		checker = 1;
		if (curr->age < 60) {
			l1.shiftPatientlist(l1, curr, to.l1);
		}

		return 1;
	}
	void sortQueue() {
		l1.sortOnPriority();
	}
	void deletePatient(string k) {
		int i = l1.findKelement(k);
		if (i == -1) {
			return;
		}
		l1.deleteKelement(k);
	}
};
void check(string& name, int& age, string& condition, int& priority) {
	try {
		while (age <= 0) {
			cout << RED << "Enter correct age " << RESET;
			cin >> age;
		}
		while (condition != "normal" && condition != "critical" && condition != "intense") {
			cout << RED << "Enter correct condition (all small) " << RESET;
			cin >> condition;
		}
	}
	catch (exception e) {
		cout << RED << "Invalid input, please try again" << RESET << endl;
	}
}
void prioritizePatients(string name, string condition, int age, int& priority, queue& oldAgeQueue, int& chkOldAge) {
	if (condition == "normal") {
		priority = 1;
	}
	else if (condition == "critical") {
		priority = 2;
	}
	else if (condition == "intense") {
		priority = 3;
	}
	if (age >= 60) {
		priority += 2;
		oldAgeQueue.pushInQueue(name, age, condition, priority);
		chkOldAge = 1;
	}
	return;
}
void ServePatients(queue& Queue, queue& oldAgeQueue) {
	int serve = 0;
	while (!oldAgeQueue.isEmptyQueue() || !Queue.isEmptyQueue()) {
		if (!oldAgeQueue.isEmptyQueue()) {
			if (serve % 3 == 0) {
				cout << CYAN << "Currently serving Patient served from old age queue" << RED << endl;
				oldAgeQueue.getFront();
				oldAgeQueue.popFromQueue();
				serve++;
			}
			else {
				if (!Queue.isEmptyQueue()) {
					serve++;
					cout << CYAN << "Currently serving Patient served from normal queue" << RED << endl;
					Queue.getFront();
					Queue.popFromQueue();
				}
				else {
					serve++;
				}
			}
		}
		else {
			if (!Queue.isEmptyQueue()) {
				serve++;
				cout << CYAN << "Currently serving Patient served from normal queue" << RED << endl;
				Queue.getFront();
				Queue.popFromQueue();
			}
		}
		if (serve == 3) {
			serve = 0;
		}
		cout << RESET;
		system("pause");
	}
	cout << RED << "All patients served" << RESET << endl;
	system("pause");
	system("cls");
}

int main() {
	int choice = 1;
	string name, condition;
	int age, priority;
	queue Queue;
	queue oldAgeQueue;
	int updatePatient = 0;
	int chkOldAge = 0;
	cout << YELLOW << "Welcome to the Hospital's OPD System\n" << RESET;
	while (choice != 6) {
		cout << CYAN << "Please select an option:\n1. Enqueue Patient\n2. Update Information\n3. View Current Queue\n4. Serve Patients\n5. VIP a patient\n" << RED << "6. Exit" << RESET << endl;
		cin >> choice;
		while (choice <= 0 || choice > 6) {
			cout << RED << "Invalid choice, please try again" << RESET << endl;
			cin >> choice;
		}
		switch (choice) {
		case 1:
			chkOldAge = 0;
			cout << YELLOW << "Please enter the patient's name" << endl;
			cin >> name;
			cout << "Please enter the patient's age" << endl;
			cin >> age;
			cout << "Please enter the patient's condition" << endl;
			cin >> condition;
			cout << RESET;
			check(name, age, condition, priority);
			prioritizePatients(name, condition, age, priority, oldAgeQueue, chkOldAge);
			if (chkOldAge == 0) {
				Queue.pushInQueue(name, age, condition, priority);
			}
			Queue.sortQueue();
			oldAgeQueue.sortQueue();
			break;
		case 2:
			cout << YELLOW << "Enter name of the patient you want to make changes with " << RESET;
			cin >> name;
			updatePatient = Queue.ReplacePatientQueueToOld(name, oldAgeQueue);
			if (updatePatient == 0) {
				oldAgeQueue.ReplacePatientOldToQueue(name, Queue);
			}
			break;
		case 3:
			cout << MAGENTA << "Normal Queue" << endl << CYAN;
			Queue.displayQueue();
			cout << MAGENTA << "Old Age Queue" << endl << CYAN;
			oldAgeQueue.displayQueue();
			cout << RESET;
			break;
		case 4:
			ServePatients(Queue, oldAgeQueue);
			break;
		case 5:
			cout << YELLOW << "Enter name of the patient you want to make VIP " << RESET;
			cin >> name;
			Queue.deletePatient(name);
			oldAgeQueue.deletePatient(name);
			break;
		case 6:
			return 0;
			break;
		}
	}

}