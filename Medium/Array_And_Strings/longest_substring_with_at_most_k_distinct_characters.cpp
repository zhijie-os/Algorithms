// brute force O(n^2)
// algorithm should take it down to O(n)
//
#include <iostream>
#include <cstring>
#define MAX_CHARS 26

bool isValid(int count[], int k)
{
    int val = 0;
    for (int i=0; i<MAX_CHARS; i++)
        if (count[i] > 0)
            val++;
 
    // Return true if k is greater than or equal to val
    return (k >= val);
}

std::string KUniques(std::string s, int k)
{
	int unique = 0; // current unique characters
	int n = s.lengt();

	int count[MAX_CHARS];
	memset(count, 0, sizeof(count));

	for(int i=0; i<n; ++i)
	{
		if(count[s[i]-'a']==0)
			unique++;
		count[s[i]-'a']++;
	}

	// if entire string does not contain k unique characters
	if(unique<k)
	{
		return s;
	}

	int curr_start = 0, curr_end = 0;
	int max_window_size = 1, max_window_start = 0;

	memset(count, 0, sizeof(count));
	count[s[0]-'a']++;

	for(int i=1;i<n;i++)
	{
		// count if unique 
		count[s[i]-'a']++;
		// extend the window?
		curr_end++;

		// If there are more than k unique characters in
        // current window, remove from left side
		while(!isValid(count,k))
		{
			count[s[curr_start]-'a']--;
			curr_start++;
		}

		// update the max window size if necessary
		if(curr_end - curr_start +1 > max_window_size)
		{
			max_window_size = curr_end - curr_start + 1;
			max_window_start = curr_start;
		}
	}

	return s.substr(max_window_start, max_window_size);
}
