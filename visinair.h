#pragma once
#include"cipher.h"
#include"login.h"

class visinair :public login
{
private:
	std::string path;
public:
	visinair(std::string path) :login(path)
	{
		this->path = path;
	}
	std::string prepareKey(std::string& key)
	{

		key.erase(std::remove(key.begin(), key.end(), ' '), key.end());
		return key;
	}
	std::vector<std::vector<char>> generateTable()
	{
		//in this i am creating a table to allow for a use of the visinair cipher
		std::vector<std::vector<char>> table(26, std::vector<char>(26));

		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				table[i][j] = 'A' + (i + j) % 26;
			}
		}
		return table;
	}

	std::string encrypt_text(std::string plaintext, std::string key)
	{
		std::vector<std::vector<char>> table = generateTable();
		std::string cipherText;
		int keyIndex = 0;

		for (char a : plaintext)
		{
			if (std::isalpha(a))
			{
				int row = std::toupper(key[keyIndex]) - 'A';
				int col = std::toupper(a) - 'A';

				cipherText += table[row][col];
				keyIndex = (keyIndex + 1) % key.length();
			}
			else
			{
				cipherText += a;
			}
		}
		return cipherText;
	}

	std::string decrypt(std::string cipherText, std::string key)
	{
		std::string plainText;
		std::vector<std::vector<char>> table = generateTable();
		int keyIndex = 0;

		for (char c : cipherText)
		{
			if (std::isalpha(c))
			{
				int row = std::toupper(key[keyIndex]) - 'A';

				for (int i = 0; i < 26; i++)
				{
					if (table[row][i] == std::toupper(c))
					{
						plainText += 'A' + i;
						break;
					}
				}
				keyIndex = (keyIndex + 1) % key.length();
			}
			else
			{
				plainText += c;
			}
		}


		return plainText;
	}
	void enter_newkey(std::string path)
	{
		std::ofstream write;
		std::ifstream read;
		write.open(path, std::ios::app);

		std::string key;
		std::cout << "please enter a key to be stored" << std::endl;
		std::getline(std::cin, key);

		std::string wordtostore = encrypt_txt(key);

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

	std::string get_key(std::string path)
	{
		std::ifstream read;
		std::string keys;
		std::string key_grab;
		std::vector<std::string> key_store;
		read.open(path);
		int num = get_num(path);
		if (read.is_open())
		{
			std::string line;
			for (int i = 0; i < num; i++)
			{
				std::getline(read,line);
				line = decrypt_txt(line);
				key_store.push_back(line);
			}
			read.close();
			
		}
		else
		{
			std::cout << "trouble opening file" << std::endl;
			exit(-1);
		}
		std::cout << "here is a list of all the keys stored" << std::endl;
		std::for_each(key_store.begin(), key_store.end(), [](std::string& line)
			{
				std::cout << line << ' ';
			});
		
		while (1)
		{
			std::cout << std::endl << "please enter the key you wish to use" << std::endl;
			std::getline(std::cin, key_grab);
			std::vector<std::string>::iterator find_key = std::find(key_store.begin(), key_store.end(), key_grab);
			if (find_key == key_store.end())
			{
				std::cout << "sorry the key you entered is not apart of the list look it over and please try again"<<std::endl;
			}
			else
			{
				keys = key_grab;
				return keys;
			}
		}
		
	}
	void has_key_encrypt(std::string path)
	{
		std::string text;
		std::cout << "please enter what you would like to encrypt" << std::endl;
		std::getline(std::cin, text);

		std::string theKey;
		theKey = get_key(path);
		theKey = prepareKey(theKey);
		text = encrypt_text(text, theKey);
		std::cout << "here is the encrypted text " << std::endl << text << std::endl;
	}
	void no_key_encrypt(std::string path)
	{
		std::string key;
		std::cout << "befroe we can start we are going to have you enter a new key"<<std::endl;
		enter_newkey(path);
		std::cout << "now that you have entered a new key we can then encrypt"<<std::endl;
		has_key_encrypt(path);



	}
	void key_decrypt(std::string path)
	{
		std::string cipherText;
		std::string key = get_key(path);
		key = prepareKey(key);
		std::cout << "Please enter the cipher text" << std::endl;
		std::getline(std::cin, cipherText);
		std::string text = decrypt(cipherText, key);
		std::cout << text << std::endl;

	}
	
};
