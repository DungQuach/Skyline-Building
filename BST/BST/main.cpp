#include<iostream>
#include "Node.h"
#include "BST.h"

void main()
{
	BST* control = new BST();
	int select = 1;
	bool flag = true;
	while (flag)
	{
		std::cout << "Your option: \n";
		std::cout << "0. Exit\n";
		std::cout << "1. Insert node\n";
		std::cout << "2. Print value\n";
		std::cout << "3. Delete value\n";
		std::cout << "4. Search for value\n";
		std::cout << "5. Find the successor\n";
		std::cout << "6. Find the predecessor\n";
		std::cout << "7. Return root\n";
		std::cout << "8. The height of tree\n";
		std::cout << "9. Clear the tree\n";
		std::cout << "Your choice: ";
		std::cin >> select;
		std::cout << std::endl;
		switch (select)
		{
		case 0:
		{
			flag = false;
			break;
		}
		case 1:
		{
			int value;
			std::cout << "Value of new node: ";
			std::cin >> value;
			control->Insert(value);
			break;
		}
		case 2:
		{
			control->Travel();
			break;
		}
		
		case 4:
		{
			int value;
			std::cout << "Value for searching: ";
			std::cin >> value;
			control->Search(value);
			break;
		}
		case 5:
		{
			int value;
			std::cout << "Value for finding: ";
			std::cin >> value;
			control->Successor(value);
			break;
		}
		case 6:
		{
			int value;
			std::cout << "Value for finding: ";
			std::cin >> value;
			control->Predecessor(value);
			break;
		}
		case 7:
		{
			Node* result = control->ReturnRoot();
			if (!result)
				std::cout << "The tree has not been init\n";
			else
				std::cout << "Root is " << result->key << std::endl;
			break;
		}
		case 3:
		{
			if (control->IsEmpty())
				std::cout << "No element for deletion\n";
			else
			{
				int value;
				std::cout << "Value for deleting: ";
				std::cin >> value;
				{
					Node* ref = control->Search(value);
					if (ref == control->NIL)
						std::cout << "No found matched\n";
					else
						control->Delete(ref);
					std::cout << "Deletion Done\n";
				}
			}
			break;
		}
		case 9:
		{
			control->ClearTree();
			if (control->IsEmpty())
				std::cout << "Cleared" << std::endl;
			break;
		}
		case 8:
		{
			control->HeightofTree();
			break;
		}

		default:
			break;
		}
		std::cout << std::endl;
	}


}