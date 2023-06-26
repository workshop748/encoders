#pragma once
#include"cipher.h"


class ceaser :public cipher
{
protected:
	int key;
	std::string plainText;

public:
	ceaser(std::string filename) :cipher(filename)
	{
		this->filename = filename;
		this->plainText = plainText;
	}

	


	int get_key()
	{
		return key;
	}

	

	void set_key(int key)
	{
		if (key > 0 || key < 26)
		{
			this->key = key;
		}
	}

	std::string encrypt_txt(std::string regText)
	{
		
		
	
		std::vector<char> to_encrypt;
		

		const int key = 17;
		set_key(17);
		int	cha = get_key();
		for (char c : regText)
		{
			if (isalpha(c))//this is checking to make sure that it is a letter
			{
				char encrypted_char = ((c - 'a' + cha) % 26) + 'a';
				to_encrypt.push_back(encrypted_char);
			}
			else
			{
				to_encrypt.push_back(c);
			}
		}
		return std::string(to_encrypt.begin(), to_encrypt.end());
	}

	std::string decrypt_txt(std::string encryptedText)
	{
		const int key = 17;
		set_key(key);
		int keys = get_key();
		std::vector<char> to_decrypt;

		for (char c : encryptedText)
		{
			if (isalpha(c))
			{
				char decrypted_char = ((c - 'a' - keys + 26) % 26) + 'a';
				to_decrypt.push_back(decrypted_char);
			}
			else
			{
				to_decrypt.push_back(c);
			}
		}
		return std::string(to_decrypt.begin(), to_decrypt.end());

		

		
	}


};
