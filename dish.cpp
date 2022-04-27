#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Ingredient
{
	public:
	Ingredient();
    
    void set_cur_names();
	void set_db_names();
	void set_db_index();
	
	void add_cur_names(string new_name);
    
    vector<string> get_cur_names();
	vector<string> get_db_names();
	vector<int> get_db_index();
    
    private:
    vector<string> cur_names;
	vector<string> db_names;
	vector<int> db_index;
};

Ingredient::Ingredient()
{
    vector<string> cur_names = {};
	vector<string> db_names = {};
	vector<int> db_index = {};
}

void Ingredient::set_cur_names()
{
	cur_names.clear();
    string name;
    ifstream infile("data.txt");
    
    while (getline(infile, name))
    {
		cur_names.push_back(name);
    }
    
	infile.close();
}

void Ingredient::set_db_names()
{
	db_names.clear();
	string name;
	ifstream infile("data2.txt");
	
	while (getline(infile, name))
	{
		db_names.push_back(name.substr(0, name.find_first_of(":")));
	}
	
	infile.close();
}

void Ingredient::set_db_index()
{
	db_index.clear();
	string index;
	ifstream infile("data2.txt");
	
	while (getline(infile, index))
	{
		int begin_pos = index.find(":",0) + 1; // index.find_first_of(":") + 1;
		db_index.push_back(stoi(index.substr(begin_pos)));
	}
	
	infile.close();
}

vector<string> Ingredient::get_cur_names()
{
    return cur_names;
}

vector<string> Ingredient::get_db_names()
{
	return db_names;
}

vector<int> Ingredient::get_db_index()
{
	return db_index;
}

void Ingredient::add_cur_names(string new_name)
{
	for (int i = 0; i < cur_names.size(); i++)
	{
		if (cur_names[i] == new_name)
		{
			cout << "Ingredient already exists" << endl;
			return;
		}
	}
	
	ofstream outfile;
	outfile.open("data.txt", ofstream::app);
	outfile << new_name << endl;
	outfile.close();
	set_cur_names();
}

int main()
{
    Ingredient in = Ingredient();
    in.set_cur_names();

    vector<string> list = in.get_cur_names();
    
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << endl;
    }
    
	cout << endl << "Testing adding function" << endl;
	in.add_cur_names("egg");
	list = in.get_cur_names();
	
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i] << endl;
	}
}