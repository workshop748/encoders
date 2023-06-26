#pragma once
#include"login.h"
#define SIZE 30
class fairplay :public login
{
private:
	std::string path;
public:
	fairplay(std::string path) :login(path)
	{
		this->path = path;
	}

	void to_lower(char plain[], int ps)
	{
		for (int i = 0; i < ps; i++)
		{
			if (plain[i] > 64 && plain[i] < 91)
			{
				plain[i] += 32;
			}
		}
	}
	int removeSpace(char* plain, int ps)
	{
		int count = 0;
		for (int i = 0; i < ps; i++)
		{
			if (plain[i] != isalpha(i))
			{
				plain[count++] = plain[i];
			}
			
		}
		plain[count] = '\0';
		return count;
		
	}
	void generateTable(char key[], int size, char key_table[5][5])
	{
		int flag = 0;

		int array[26] = { 0 };
		for (int i = 0; i < size; i++)
		{
			if (key[i] != 'j')
			{
				array[key[i] - 97] = 2;
			}
		}

		array['j' - 97] = 1;
		int k = 0;
		int j = 0;

		for (int i = 0; i < size; i++)
		{
			if (array[key[i] - 97] == 2)
			{
				array[key[i] - 97] -= 1;
				key_table[k][j] = key[i];
				j++;
					if (j == 5)
					{
						i++;
							j = 0;
					}
			}
		}
	}
	void search(char key_table[5][5], char a, char b, int arr[])
	{
		if (a == 'j')
		{
			a = 'i';
		}
		else if (b == 'j')
		{
			b = 'i';
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (key_table[i][j] == a)
				{
					arr[0] = i;
					arr[1] = j;
				}
				else if (key_table[i][j] == b)
				{
					arr[2] = i;
					arr[3] = j;
				}
			}
		}
	}

	int mod5(int a) { return (a % 5); }

	int prepare(char str[], int ptrs)
	{
		if (ptrs % 2 != 0)
		{
			str[ptrs++] = 'z';
			str[ptrs] = '\0';
		}
		return ptrs;
	}
	void encrypt(char str[], char key_table[5][5], int nums)
	{
		int a[4];
		for (int i = 0; i < nums; i++)
		{
			search(key_table, str[i], str[i + 1], a);

			if (a[0] == a[2])
			{
				str[i] = key_table[a[0]][mod5(a[1] + 1)];
				str[i + 1] = key_table[a[0]][mod5(a[3]+1)];
			}
			else if(a[1]==a[3])
			{
				str[i] = key_table[mod5(a[0] + 1)][a[1]];
				str[i + 1] = key_table[mod5(a[2] + 1)][a[1]];
			}
			else
			{
				str[i] = key_table[a[0]][a[3]];
				str[i + 1] = key_table[a[2]][a[1]];
			}
		}
	}
	void encrypt_by_playfair_cipher(char str[], char key[])
	{
		//just sotring the key and the str as a char to get ready for the  encryption
		char str_length, ks, key_tabel[5][5];
		//preparing them to comences with incription
		ks = strlen(key);
		ks = removeSpace(key, ks);
		to_lower(key, ks);

		str_length = strlen(str);
		to_lower(str, str_length);
		str_length = removeSpace(str, str_length);
		str_length = prepare(str, str_length);

		generateTable(key, ks, key_tabel);

		encrypt(str, key_tabel, str_length);
	}

	void work_encrypt(std::string str_str, std::string key_str)
	{
		char str[SIZE], key[SIZE];

		strcpy_s(key, key_str.c_str());
		strcpy_s(str, str_str.c_str());

		encrypt_by_playfair_cipher(str, key);

		std::cout << "your encrypted text is " << std::endl
			<<str;
	}
};
