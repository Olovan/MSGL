#include <MSGL/MSGL_CORE/StringUtils.h>

#include <iostream>

using std::vector;
using std::string;


vector<string> msgl::core::splitString(string input, string delimiters)
{
	vector<string> results;
	string temp;
	for(int i = 0; input[i] != 0; i++)
	{
		char c = input[i];
		if(delimiters.find_first_of(c) != -1)
		{
			results.push_back(temp);
			temp.clear();
		}
		else
		{
			temp.push_back(c);
		}
	}

	results.push_back(temp);

	return results;
}

vector<string> msgl::core::splitString(unsigned char* input, string delimiters)
{
	vector<string> results;
	string temp;
	for(int i = 0; input[i] != 0; i++)
	{
		char c = input[i];
		if(delimiters.find_first_of(c) != -1)
		{
			results.push_back(temp);
			temp.clear();
		}
		else
		{
			temp.push_back(c);
		}
	}

	return results;
}
