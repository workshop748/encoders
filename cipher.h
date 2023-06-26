#pragma once
#include<iostream>
#include<string>
#include<set>
#include<fstream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<functional>


class cipher
{
protected:
	std::string filename;
	
	cipher(std::string filename)
	{
		this->filename = filename;
	}
public:
	std::string get_filename()
	{
		return filename;
	}
	std::vector<char> create_char_array(std::string plain_text)
	{
		std::vector<char> c_array(plain_text.begin(), plain_text.end());

		return c_array;
	}
	

};

