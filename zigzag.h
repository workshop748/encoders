#pragma once
#include"login.h"
class zigzag :public login
{

private:
	std::string path;
public:
	zigzag(std::string path) :login(path)
	{
		this->path = path;
	}
	void the_encrypt(char txt[], int key)
	{
		int txtLen = strlen(txt);
			int k = -1;
		int row = 0;
			int col = 0;

			std::vector<std::vector<char>> matrix(key, std::vector<char>(txtLen,'\n'));
			for (int i = 0; i < txtLen; i++)
			{
				matrix[row][col++] = txt[i];

				if (row == 0 || row == key - 1)
				{
					k *= ( - 1);
				}
				row += k;
			 }

			std::cout << "presenting the encrypted message" << std::endl;

			for (int i = 0; i < key; i++)
			{
				for (int j = 0; j < txtLen; j++)
				{
					if (matrix[i][j] != '\n')
						std::cout << matrix[i][j];
				}
			}
	}


};
