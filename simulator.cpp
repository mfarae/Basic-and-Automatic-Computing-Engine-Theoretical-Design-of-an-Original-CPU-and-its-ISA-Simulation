#include <iostream>
#include <windows.h>
using namespace std;

struct node
{
	string ins;
	int address;
	int i;
	node *next;
	int p;
};

int ram[64], ac = 0, e = 0, dr = 0, tr = 0;
string aC, dR, tR, ones;
node *pc;

char flip(char c)
{
	return (c == '0') ? '1' : '0';
}

// function to convert decimal to binary
string DecimalToBinary(unsigned int dec)
{
	char binary[19] = {0};
	int i = 0;
	int ix = 20; // subscript of current character
	do
	{
		binary[--ix] = '0' + dec % 2;
		dec /= 2;
		i++;
	} while (i < 20);

	return (binary + ix); // ix is offset into char array where answer begins
}

int BinaryToDecimal(string binary)
{
	int power = 1048576;
	int sum = 0;
	//    assert(strlen(binary) == 20);

	for (int i = 0; i < 20; ++i)
	{
		if (i == 0 && binary[i] != '0')
		{
			sum = -1048576;
		}
		else
		{
			sum += (binary[i] - '0') * power;
		}
		power /= 2;
	}
	return sum;
}

void insert(node *head)
{
	node *ptr;
	for (ptr = head; ptr->next != NULL; ptr = ptr->next)
	{
	}

	ptr->next = new node;
	ptr = ptr->next;
	cout << "\n\n\tEnter Instruction: ";
	cin >> ptr->ins;

	if (ptr->ins == "LDA")
	{
		cout << "\tEnter Address: ";
		cin >> ptr->address;
		cout << "\tI: ";
		cin >> ptr->i;

		ac = ram[ptr->address];
	}
	else if (ptr->ins == "ADD")
	{
		cout << "\tEnter Address: ";
		cin >> ptr->address;
		cout << "\tI: ";
		cin >> ptr->i;

		ac += ram[ptr->address];
	}
	else if (ptr->ins == "MUL")
	{
		cout << "\tEnter Address: ";
		cin >> ptr->address;
		cout << "\tI: ";
		cin >> ptr->i;

		ac *= ram[ptr->address];
	}
	else if (ptr->ins == "SUB")
	{
		cout << "\tEnter Address: ";
		cin >> ptr->address;
		cout << "\tI: ";
		cin >> ptr->i;

		ac -= ram[ptr->address];
	}

	else if (ptr->ins == "INC")
	{
		cout << "\tEnter Address: ";
		cin >> ptr->address;
		cout << "\tI: ";
		cin >> ptr->i;

		ac++;
	}
	else if (ptr->ins == "DEC")
	{
		cout << "\tEnter Address: ";
		cin >> ptr->address;
		cout << "\tI: ";
		cin >> ptr->i;

		ac--;
	}
	else if (ptr->ins == "EXC")
	{
		cout << "\tEnter Address: ";
		cin >> ptr->address;
		cout << "\tI: ";
		cin >> ptr->i;
		tr = ac;
		ac = ram[ptr->address];
		ram[ptr->address] = tr;
	}

	else if (ptr->ins == "OR")
	{
		cout << "\tEnter Address: ";
		cin >> ptr->address;
		cout << "\tI: ";
		cin >> ptr->i;
		tr = (ac | ram[ptr->address]);
		ac = tr;
	}
	else if (ptr->ins == "NOT")
	{
		cout << "\tEnter Address: ";
		cin >> ptr->address;
		cout << "\tI: ";
		cin >> ptr->i;
		tr = (~ram[ptr->address]);
		ac = tr;
	}

	else if (ptr->ins == "AND")
	{
		cout << "\tEnter Address: ";
		cin >> ptr->address;
		cout << "\tI: ";
		cin >> ptr->i;
		tr = (ac & ram[ptr->address]);
		ac = tr;
	}
	else if (ptr->ins == "XOR")
	{
		cout << "\tEnter Address: ";
		cin >> ptr->address;
		cout << "\tI: ";
		cin >> ptr->i;
		tr = (ac ^ ram[ptr->address]);
		ac = tr;
	}
	else if (ptr->ins == "XNOR")
	{
		cout << "\tEnter Address: ";
		cin >> ptr->address;
		cout << "\tI: ";
		cin >> ptr->i;
		tr = ~(ac ^ ram[ptr->address]);
		ac = tr;
	}
	else if (ptr->ins == "NOR")
	{
		cout << "\tEnter Address: ";
		cin >> ptr->address;
		cout << "\tI: ";
		cin >> ptr->i;
		tr = ~(ac | ram[ptr->address]);
		ac = tr;
	}
	else if (ptr->ins == "NAND")
	{
		cout << "\tEnter Address: ";
		cin >> ptr->address;
		cout << "\tI: ";
		cin >> ptr->i;
		tr = ~(ac & ram[ptr->address]);
		ac = tr;
	}
	else if (ptr->ins == "CLA")
	{
		ac = 0;
	}
	else if (ptr->ins == "CMA")
	{
		ac = ~ac;
	}
	else if (ptr->ins == "TCA")
	{
		ac = ~ac;
		ac++;
	}
	else if (ptr->ins == "CIR")
	{
	}
	else if (ptr->ins == "GTR")
	{
		cout << "\tEnter Address: ";
		cin >> ptr->address;
		cout << "\tI: ";
		cin >> ptr->i;
		if (ram[ptr->address] > ac)
		{
			ac = ram[ptr->address];
		}
	}

	else if (ptr->ins == "LES")
	{
		cout << "\tEnter Address: ";
		cin >> ptr->address;
		cout << "\tI: ";
		cin >> ptr->i;
		if (ram[ptr->address] < ac)
		{
			ac = ram[ptr->address];
		}
	}

	else if (ptr->ins == "SHL")
	{
		ac = (ac << 1);
	}
	else if (ptr->ins == "SHR")
	{
		ac = (ac >> 1);
	}

	ptr->next = NULL;
}

void displayMemory()
{
	cout << endl
		 << "_________________________________________________________ MEMORY _______________________________________________________\n\n";
	for (int i = 0; i < 64; i++)
	{
		if (ram[i] != -9999)
			cout << ram[i] << "\t";

		else
			cout << "_\t";
	}
	cout << endl
		 << endl
		 << "________________________________________________________________________________________________________________________\n\n";
}

void displayRegisters()
{
	aC = DecimalToBinary(ac);
	dR = DecimalToBinary(dr);
	tR = DecimalToBinary(tr);

	cout << "\n_________________________________________________________ Registers ____________________________________________________\n\n";
	cout << "   | AC = " << ac << " , " << aC << " |	| DR = " << dr << " , " << dR << " |	| TR = " << tr << " , " << tR << " |";
	cout << endl
		 << endl
		 << "________________________________________________________________________________________________________________________\n\n";
}

void display(node *head)
{
	node *ptr = head->next;
	cout << endl
		 << endl
		 << "_________________________________________________________ INSTRUCTIONS _________________________________________________\n\n\n";
	if (head->next == NULL)
	{
		cout << "You haven't written any instruction!!!";
	}
	else
	{
		for (; ptr != NULL; ptr = ptr->next)
		{
			if (ptr->ins == "AND" || ptr->ins == "ADD" || ptr->ins == "LDA" || ptr->ins == "STA" || ptr->ins == "BUN" || ptr->ins == "BSA" || ptr->ins == "ISZ" || ptr->ins == "NOR" || ptr->ins == "NAND" || ptr->ins == "SWP" || ptr->ins == "MUL" || ptr->ins == "SUB" || ptr->ins == "GTB" || ptr->ins == "BTG")
			{
				cout << "\t" << ptr->i << " " << ptr->ins << " " << ptr->address << endl;
			}
			else
			{
				cout << "\t  " << ptr->ins << endl;
			}
		}
	}

	cout << "________________________________________________________________________________________________________________________\n";
	cout << endl;
}

void ramvalinit(int address, int value)
{

	ram[address] = value;
}

void clearRam()
{
	for (int i = 0; i < 64; i++)
	{
		ram[i] = 0;
	}
}

int main()
{
	node *head = new node;
	head->next = NULL;

	char opt = 'y';
	int choice = 0;

	for (int i = 0; i < 64; i++)
	{
		ram[i] = -9999;
	}

	ram[0] = 6;
	ram[1] = 5;
	ram[2] = -15;
	ram[3] = 19;
	ram[4] = -10;
	ram[5] = 2;
	ram[6] = 111;
	ram[7] = -26;
	ram[8] = 5;
	ram[9] = 63;

	do
	{
		displayMemory();
		displayRegisters();
		system("color f4");
		cout << "_________________________________________________________ MENU _________________________________________________________\n"
			 << "\n	1. Write Program"
			 << "\n	2. Enter a value in the ram: "
			 << "\n	3. Clear ram:"
			 << "\n	4. Display Memory"
			 << "\n	5. Exit"
			 << "\n________________________________________________________________________________________________________________________"
			 << "\n\n	SELECT OPERATION: ";

		cin >> choice;

		if (choice == 1)
		{
			opt = 'y';
			while (opt != 'n')
			{
				insert(head);
				cout << "\n\tDo you want to write more instructions(y/n)? ";
				cin >> opt;
			}
			system("cls");
		}
		else if (choice == 2)
		{
			int value, address;
			cout << "Enter the address at which you want to store value:";
			cin >> address;
			cout << "Enter the value: ";
			cin >> value;
			ramvalinit(address, value);
		}
		else if (choice == 3)
		{
			clearRam();
		}
		else if (choice == 4)
		{
			displayMemory();
		}

	} while (choice != 5);
	return 0;
}
