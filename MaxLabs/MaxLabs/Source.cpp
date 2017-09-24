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
	void Add(AutoProp prop)
	{
		element *temp = new element;
		(*temp).prop = prop;
		(*temp).Next = Head;
		Head = temp;
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
	int size,answer = 0;
	AutoProp prop;
	cout << "������� ������� �� ������ �����: ";
	cin >> size;
	List *Auto = new List[size];
	while(answer != 5)
	{
		system("cls");
		cout << "1: ������ ������; " << endl;
		cout << "2: �������� ������� ��������; " << endl;
		cout << "3: ����� ����� ������; " << endl;
		cout << "4: �������� �������, ����� ����������; " << endl;
		cout << "5: �����. " << endl;
		cin >> answer;
		if (answer > 0 && answer <= 5) 
		{
			switch (answer)
			{
			case 1:
				system("cls");
				for (int i = 0; i < size; i++)
				{
					cout << "������� ����� ���������� ��� ������� " << i+1 << ": ";
					gets_s(prop.Brand);
					gets_s(prop.Brand);
					cout << "������� ������: ";
					gets_s(prop.Model);
					cout << "������� ��� ������: ";
					gets_s(prop.Bodystyle);
					Auto[i].Add(prop);
					system("cls");
				}
				break;
			case 2:
				break;
			case 3:
				system("cls");
				cout.setf(ios::left);
				cout << setw(10) << "�����" << setw(10) << "������" << setw(10) << "��� ������" << endl;
				for (int i = 0; i < size; i++)
				{
					Auto[i].Show();
				}
				system("pause");
				break;
			case 4:
				break;
			default:
				break;
			}
		}
		else {
			cout << "�� ����� �� ���������� ��������";
			system("pause");
		}
	}
	cout << endl;
	system("pause");
}