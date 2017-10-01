#include <conio.h>
#include <iostream>
#include <iomanip>

using namespace std;

struct AutoProp
{
	char Brand[50];
	char Model[50];
	char Bodystyle[50];
};

struct element 
{
	AutoProp prop;
	element *Next; 
};

class List 
{
	element *Head; 
public:
	List()
	{ 
		Head = NULL; 
	} 
	bool Check() {
		if (Head != NULL) return true; else return false;
	}
	void Add(AutoProp prop)
	{
		element *temp = new element;
		(*temp).prop = prop;
		(*temp).Next = Head;
		Head = temp;
	}
	void DeleteNext(int del) {
		if (Head->Next != NULL) {
			element *temp = Head;
			for (int i = 0; i <= del - 1; i++) {
				temp = (*temp).Next;
			}
			for (int i = 0; i <= del - 2; i++) {
				temp = (*Head).Next;
			}
			(*Head).Next = (*temp).Next;
			delete temp;
		}
		else {
			cout << "ERROR. ���� ������ ��?" << endl;
			system("pause");
		}
	}
	void Delete() {
		if (Head == NULL) {
			
		}
		else {
			element *temp = (*Head).Next;
			delete Head;
			Head = temp;
		}
	}
	void Show()
	{
		element *temp = Head;
		while (temp != NULL)
		{
			cout << setw(10) << (*temp).prop.Brand;
			cout << setw(10) << (*temp).prop.Model;
			cout << setw(10) << (*temp).prop.Bodystyle << endl;
			temp = (*temp).Next;
		}
	}
	~List()
	{
		while (Head != NULL)
		{
			element *temp = Head->Next;
			delete Head;
			Head = temp;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "Rus");
	int size,answer = 0,del_num, cnt =0;
	AutoProp prop;
	do {
		system("cls");
		cout << "������� ������� �� ������ �����: ";
		cin >> size;
	} while (size <= 0);
	cnt = size;
	List *Auto = new List[size];
	while(answer != 5)
	{
		system("cls");
		cout << "1: ���������� ������ ��������; " << endl;
		cout << "2: �������� ������� ��������; " << endl;
		cout << "3: �������� �������, ����� ����������; " << endl;
		cout << "4: ����� ����� ������; " << endl;
		cout << "5: �����. " << endl;
		cin >> answer;
		if (answer > 0 && answer <= 5) 
		{
			switch (answer)
			{
			case 1:
				if (cnt > 0) {
					system("cls");
					cout << "������� ����� ����������: ";
					gets_s(prop.Brand);
					gets_s(prop.Brand);
					cout << "������� ������: ";
					gets_s(prop.Model);
					cout << "������� ��� ������: ";
					gets_s(prop.Bodystyle);
					Auto[0].Add(prop);
					system("cls");
					cnt--;
				}
				else {
					system("cls");
					cout << "ERROR: ���� ���� �������� ������!" << endl;
					system("pause"); system("cls");
				}
				break;
			case 2:
				Auto[0].Delete();
				cnt++;
				system("cls");
				break;
			case 3:
				system("cls");
				cout.setf(ios::left);
				cout << setw(10) << "�����" << setw(10) << "������" << setw(10) << "��� ������" << endl;
				for (int i = 0; i < size; i++)
				{
					Auto[i].Show();
				}
				cout << endl << "������� ����� ��������: ";
				cin >> del_num;
				if (del_num < size && del_num > 0) {
					Auto->DeleteNext(del_num);
					cnt++;
				}
				else {
					system("cls");
					cout << "ERROR: �� ������ �� �������!" << endl;
					system("pause"); system("cls");
				}
				break;
			case 4:
				system("cls");
				if (Auto->Check()) {
					cout.setf(ios::left);
					cout << setw(10) << "�����" << setw(10) << "������" << setw(10) << "��� ������" << endl;
					for (int i = 0; i < size; i++)
					{
						Auto[i].Show();
					}
				}
				else {
					cout << "������ ����" << endl;
				}
					system("pause");
				
				break;
			case 5:
				break;
			default:
				cout << "ERROR: �� ����� �� ���������� ��������" << endl;
				break;
			}

		}
	}
	cout << endl;
	system("pause");
}