#include <cassert>
#include<iostream>
#include<string>
#include<set>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int max=0;
    int count=0;
    std::set<char> seen;
    for(char c:s)
    {
        if(isalpha(c))
	{
	    c=tolower(c);
	    if(seen.find(c)==seen.end())//not in seen
            {
                ++count;
               if(count>max)
               {
                   max=count;
  
               }
            }
            else
            {
                count=1;
            }
            seen.insert(c);
        }
    }
    return max;    
}



int main()
{
    // Test Cases
    string s1="aabcabcbb";
    string s2="bbbbb";
    string s3="pwwkew";
    string s4=" ";
    string s5="12221112345";
    string s6="!@#&&**@";
    string s7="!@#&&aabcabcbb";

    assert(lengthOfLongestSubstring(s1)==3);
    assert(lengthOfLongestSubstring(s2)==1);
    assert(lengthOfLongestSubstring(s3)==3);
    assert(lengthOfLongestSubstring(s4)==0);
    assert(lengthOfLongestSubstring(s5)==0);
    assert(lengthOfLongestSubstring(s6)==0);
    assert(lengthOfLongestSubstring(s7)==3);

    //Sample output
    cout<<"Word: "<<s1<<" Max:"<<lengthOfLongestSubstring(s1)<<endl;
    cout<<"Word: "<<s2<<" Max:"<<lengthOfLongestSubstring(s2)<<endl;
    cout<<"Word: "<<s3<<" Max:"<<lengthOfLongestSubstring(s3)<<endl;
    cout<<"Word: "<<s4<<" Max:"<<lengthOfLongestSubstring(s4)<<endl;  
    cout<<"Word: "<<s5<<" Max:"<<lengthOfLongestSubstring(s5)<<endl;
    cout<<"Word: "<<s6<<" Max:"<<lengthOfLongestSubstring(s6)<<endl;
    cout<<"Word: "<<s7<<" Max:"<<lengthOfLongestSubstring(s7)<<endl;
   

    return 0;  

};

