#pragma once
#include"ceaser.h"

class login :public ceaser
{
	private:

public:
	login(std::string path) :ceaser(path)
	{

	}
	int get_num(std::string path)
	{
		std::ifstream read;
		read.open(path);
		int count = 0;
		if (read.is_open())
		{
			std::string line;
			while (std::getline(read, line))
			{
				count++;
			}
			
			read.close();
		}
		return count;
	}
	void enter_newPassword(std::string path )
	{
		std::ofstream write;
		std::ifstream read;
		write.open(path, std::ios::app);
		
		std::string newpasswrd;
		std::cout << "please enter a pasword to be stored" << std::endl;
		std::getline(std::cin, newpasswrd);
		
	std::string wordtostore=encrypt_txt(newpasswrd);

	if (write.is_open())
	{
		std::string line;
		read.open(path);
		while (std::getline(read, line))
		{

		}
		read.close();
		write << wordtostore << std::endl;
		write.close();
	}
	else
	{
		std::cout << "error in opening file";
		exit(-1);
	}

	}
	std::vector<std::string> set_vect(std::string path)
	{
		std::ifstream read;
		int num = get_num(path);
		std::vector<std::string> vects;
		read.open(path);
		if (read.is_open())
		{
			for (int i = 0; i < num; i++)
			{
				std::string line;
				std::getline(read, line);
				vects.push_back(line);
			}
			read.close();
		}
		return vects;
	}
	bool authentication(std::string path)
	{
		std::ifstream read;
		int counter = 0;
		std::vector<std::string> authenticat;
		std::string password;


		read.open(path);
		//this will store and decrypted the passwords into a vector to be used with the find comand.
		if (read.is_open())
		{
			std::string line;
			while (std::getline(read, line))
			{

				line = decrypt_txt(line);
				
				authenticat.push_back(line);
			}
			read.close();
		}
		
		
		
		while (1)
		{
			std::cout << "please enter your password" << std::endl;
			std::getline(std::cin, password);
			std::vector<std::string>::iterator has_pass = std::find(authenticat.begin(), authenticat.end(), password);
			if (has_pass == authenticat.end())
			{
				counter++;
				std::cout << "that is the incorect output please try again"<<std::endl;
				if (counter == 3)
				{
					
					return false;
				}
			}
			else
			{
				std::cout << "corret pasword" << std::endl;
				return true;
			}
		}
	}
};