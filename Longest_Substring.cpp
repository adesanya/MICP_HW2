#include <cassert>
#include<iostream>
#include<string>
#include<set>
using namespace std;

std::set<string> build_sub_string(string s)
{
    std::set<string> subs;
    int size=s.size();
    for(int wsize=1;wsize<=size;++wsize)
    {
        for(int j=0;j<=size;++j)
        { 
            subs.insert(s.substr(j,wsize));
        }
    }
    
    return subs;
}

int unique_len(string s)
{
    std::set<char> s_set;
    for(char c:s)
        s_set.insert(c);
    int s_size=s.size();
    int set_size=s_set.size();
    if(s_size==set_size)
    	return set_size;
    return 0;
}


int lengthOfLongestSubstring(string s) 
{
    int max=0;
    std::set<string> allsubs=build_sub_string(s);
    for(std::set<string>::iterator each=allsubs.begin();each!=allsubs.end();++each)
    {
        int current=unique_len(*each);
        if(current>max)
           max=current;
    }
    return max;
}

int main()
{
    // Test Cases
    string s1="aabcabcbb";
    string s2="bbbbb";
    string s3="pwwkew";
    string s4="abacde";

    assert(lengthOfLongestSubstring(s1)==3);
    assert(lengthOfLongestSubstring(s2)==1);
    assert(lengthOfLongestSubstring(s3)==3);
    assert(lengthOfLongestSubstring(s4)==5);

    //Sample output
    cout<<"Word: "<<s1<<" Max:"<<lengthOfLongestSubstring(s1)<<endl;
    cout<<"Word: "<<s2<<" Max:"<<lengthOfLongestSubstring(s2)<<endl;
    cout<<"Word: "<<s3<<" Max:"<<lengthOfLongestSubstring(s3)<<endl;
    cout<<"Word: "<<s4<<" Max:"<<lengthOfLongestSubstring(s4)<<endl;  
  
    return 0;  

};

