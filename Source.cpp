#include"ceaser.h"
#include"cipher.h"
#include"login.h"
#include"visinair.h"
#include "fairplay.h"
#include"zigzag.h"

int main()
{
	std::string choice_str,key_str,str_str;
	std::string path = "holder_of_login.txt";
	std::string path2 = "visinair_keys.txt";
	login a(path);
	visinair b(path2);
	fairplay c(path2);
	zigzag d(path);
	std::cout << "hello and welcome to this wonderful website that i have not created a name for." <<
		std::endl << "before I can let you play around I want to know if your a frist time user or have used in the past" << std::endl
		<< "i am just going to have you login real quick" << std::endl
		<< "[1] to enter a new password" << std::endl <<
		"[2] to log in"<<std::endl;
	std::getline(std::cin, choice_str);
	int choice = std::stoi(choice_str);
	switch (choice)
	{
	case(1):
	{
		a.enter_newPassword(path);
		exit(-1);
	
	}
	case(2):
	{
		bool test_pass;
		test_pass=a.authentication(path);
		if (test_pass == true)
		{
			std::cout << "welcome you are free to play around as you will" << std::endl;
			break;
		}
		else if( test_pass ==false)
		{
			std::cout << "as a computer i do not feel remorse in the fact you failed to enter a password" << std::endl << "however the programer is sorry and say come try again someother time";
			exit(-1);
		}
		break;
	}
	default:
	{
		std::cout << "invalid imput";
		exit(-1);
	}
	}
	while (1)
	{
		std::cout << std::endl << "Please enter what you want to do" << std::endl
			<< "[1] to decrypt/encrypt in visinair" << std::endl <<
			"[2] to encrypt using Playfair cipher" << std::endl <<
			"[3] to encrypt using a rail post cipher" << std::endl <<
			"[4] to log out" << std::endl;
		std::getline(std::cin, choice_str);
		int choice2 = std::stoi(choice_str);
		switch (choice2)
		{
		case(1):
		{
			std::cout << "would you like to encrypt or decrypt" << std::endl
				<< "[1] to encrypt" << std::endl
				<< "[2] to decrypt";
			std::getline(std::cin, choice_str);
			int choice3 = std::stoi(choice_str);

			if (choice3 == 1)
			{
				std::cout << "welcome to encryption" << std::endl
					<< "[1] if you have a key" << std::endl <<
					"[2] if you would like to store and encrypt" << std::endl;
				std::getline(std::cin, choice_str);
				int choice4 = std::stoi(choice_str);
				switch (choice4)
				{
				case(1):
				{
					b.has_key_encrypt(path2);
					break;
				}
				case(2):
				{
					b.no_key_encrypt(path2);
					break;
				}
				default:
				{
					std::cout << "invalid imput" << std::endl;
					exit(-1);
				}
				}
			}
			else if (choice3 == 2)
			{
				std::cout << "welcome to decryption" << std::endl;
				b.key_decrypt(path2);

			}
			else
			{
				std::cout << "invalid imput" << std::endl;
				exit(-1);
			}

			break;
		}
		case(2):
		{
			std::cout << "welcome to encryption with fair play cipher" << std::endl
				<< "please eneter a key"<<std::endl;
			std::getline(std::cin, key_str);

			std::cout << "Please enter a phrase you wish to encrypt" << std::endl;
			std::getline(std::cin, str_str);
			c.work_encrypt(str_str, key_str);
			break;

		}
		case(3):
		{
			char txt[100];
			std::cout << "thanks for choosing rail fences cipher" << std::endl
			<< "please enter a key." << std::endl;
		std::getline(std::cin, key_str);
		int key = std::stoi(key_str);
		std::cout << "please enter a phrase you would like to encrypt" << std::endl;
		std::getline(std::cin, str_str);
		strcpy_s(txt,str_str.c_str());
		d.the_encrypt(txt, key);

			break;
		}
		case(4):
		{
			std::cout << "the programer would like to thank you for using his program " << std::endl
				<< "thank you come again" << std::endl;
			return 0;
		}
		}

	}
	
	}