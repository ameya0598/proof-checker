#include "helpers.h"

using namespace std;

string string_separate(string in)
{
	
	string temp;
	int i = 0;
	while (in[i] != '/')
	{
		temp.push_back(in[i]);
		i++;
	}
	return temp;
}

void tr_input(vector<string> &tr, string in)
{ 
	string temp = string_separate(in);
	string pf_temp;
	generate(temp, pf_temp); 
	tr.push_back(pf_temp);
}

/**bool and_introduction_check(vector<string> &tr, string in, int pos)
{			 
	int pos; 
	string temp = string_separate(in);
	string pf_temp;
	generate(temp, pf_temp); 
	int l1 = (in[pos] - '0') - 1, l2 = (in[pos + 2] - '0') - 1;
	if (pf_temp.back() == '^')
	{ 
		if (is_substring(tr[l1], pf_temp) && is_substring(tr[l2], pf_temp))
		{
			
			tr.push_back(pf_temp); 
			return true;
		}
	}
	return false;
}

bool and_elimination_check(vector<string> &tr, string in, int pos)
{
	string temp = string_separate(in);
	string pf_temp;
	int l = pf_temp.length(), l1 = (in[pos] - '0') - 1, l2 = (in[pos + 2] - '0') - 1;
	generate(temp, pf_temp);
	if (is_substring(pf_temp, tr[l1]))
	{
		tr.push_back(pf_temp);
		return true;
	}
	return false;
}

bool or_introduction_check(vector<string> &tr, string in, int pos)
{
	string temp = string_separate(in);
	string pf_temp;
	int l = pf_temp.length(), l1 = (in[pos] - '0') - 1, l2 = (in[pos + 2] - '0') - 1;
	generate(temp, pf_temp);
	if (pf_temp.back() == 'V')
	{
		if (is_substring(tr[l1], pf_temp))
		{
			tr.push_back(pf_temp);
			return true;
		}
	}
	return false;
}

bool impl_elimination_check(vector<string> &tr, string in, int k)
{
	int pos = in[k] - '0';
	string temp = string_separate(in);
	string pf_temp;
	generate(temp, pf_temp);

	if (pf_temp.back() == '>')
	{
	
		//  * if p is substring of p > q and
		//  * first element of postfixes of p and p>q are same and
		//  * q is a substring of p>q
		//  * then true
		//  
		int l = pf_temp.length(), l1 = (in[pos] - '0') - 1, l2 = (in[pos + 2] - '0') - 1;
		if ((is_substring(tr[l2], tr[l1])) && is_substring(pf_temp, tr[l1]))
		{
			int prlength = tr[l2].length();
			if (check_impl_left(tr[l2], tr[l1]))
			{
				if (check_impl_right(pf_temp, tr[l1], prlength))
				{
					tr.push_back(pf_temp);
					return true;
				}
			}
		}
	}
	return false;
}

bool mt_check(vector<string> &tr, string in, int pos)
{
	string temp = string_separate(in);
	string pf_temp;
	generate(temp, pf_temp);
	pf_temp.pop_back();
	int l = pf_temp.length(), l1 = (in[pos]-'0') - 1, l2 = (in[pos+2]-'0') - 1;
	string pro = tr[l2];
	pro.pop_back();

	if(is_substring(pf_temp, tr[l1]) && is_substring(pro, tr[l1]))
	{
		if(check_impl_right(pro, tr[l1], l))
		{
			if(check_impl_left(pf_temp, tr[l1]))
			{
				tr.push_back(pf_temp);
					return true;
			}
		}
	}
	return false;
}



bool check_impl_left(string part, string whole)
{
	int l = part.length(), l2 = whole.length(), i, j;
	for(i = 0, j = 0; i < l && j < l2; i++, j++)
	{
		if(part[i] != whole[j])
			break;
	}

	if(i == l)
		return true;
	else
		return false;
}

bool check_impl_right(string part, string whole, int start)
{
	int l = part.length(), l2 = whole.length(), i , j;
	for (i = 0, j = start; i < l && j < l2; i++, j++)
	{
		if (part[i] != whole[j])
			break;
	}

	if (i == l)
		return true;
	else
		return false;
}*/

bool is_substring(string sub, string str)
{
	int l = str.length(), i, j = 0;
	for (i = 0; i < l; i++)
	{
		if (str[i] == sub[j])
		{
			while (str[i] == sub[j] && j < sub.length())
			{
				i++;
				j++;
			}
		}
		if (j == sub.length())
			return true;

		i -= j;

		j = 0;
	}
	return false;
}