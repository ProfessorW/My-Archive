//Corporate Renamings
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("data.txt");

	string changes[1000];	//full lines of changes to be made
	string originals[1000];	//original company names
	string news[1000];		//new company names
	int num_changes;
	
	fin >> num_changes;
	string extra_space;		//Clear the endline left in the file
	getline(fin, extra_space);

	//Read in every full line of changes and parse into original and new
	for(int i = 0; i < num_changes; i++)
	{
		getline(fin, changes[i]);
		int quote2_pos = changes[i].substr(1).find("\"");
		originals[i] = changes[i].substr(1,quote2_pos);

		news[i] = changes[i].substr(quote2_pos + 7);
		news[i] = news[i].substr(0, news[i].length()-1);
	}

	int num_lines;			//Get number of lines to process and clear the endline
	fin >> num_lines;
	getline(fin,extra_space);

	string line;
	for(int i = 1; i <= num_lines; i++)	//Process each line
	{
		getline(fin, line);
		for(int j = 0; j < num_changes; j++)	//Step through all originals
		{
			int find_pos = line.find(originals[j]);	//Look for the original in the line
			while(find_pos != string::npos)	//Keep going as long as the original is present
			{
				//erase the original and insert the new
				line.erase(find_pos, originals[j].length());
				line.insert(find_pos, news[j]);
				find_pos = line.find(originals[j]);	//Search again for original
			}
		}
		cout << line << endl;
	}

	system("pause");
	return 0;
}