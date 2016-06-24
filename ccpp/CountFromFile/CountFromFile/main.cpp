//
//  main.cpp
//  CountFromFile
//
//  Created by Ferris on 16/6/24.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp (const pair<string ,int> & a, const pair<string, int> & b)
{
    if (a.second > b.second) return true;
    if (a.second == b.second) return (a.first< b.first);
    return false;
}
// 去掉标点符号
string erase_sgin(char * s)
{
    string str;
    int len =strlen(s);
    for (int i = 0 ; i < len ;i++)
        if (isalpha(s[i]))
            str+=tolower(s[i]);
    return str;
}
int main()
{
    FILE *fpin,*fpout;
    fpin = fopen("/Users/iam24/Documents/hello/hello/test/test/in.txt","r");
    fpout = fopen("/Users/iam24/Documents/hello/hello/test/test/out.txt","w");
    char s[30];
    string str;
    map <string, int> num_map;
    map <string, int>::iterator l_it;
    vector<pair<string, int>> my_vec;
    vector<pair<string ,int>>::iterator vec_it;
    while (!feof(fpin))
    {
        fscanf(fpin,"%s",s);
        str = erase_sgin(s);
        num_map[str]++;
    }
    for (l_it = num_map.begin(); l_it!=num_map.end(); l_it++)
    {
        my_vec.push_back(make_pair(l_it->first, l_it->second));
    }
    sort(my_vec.begin(), my_vec.end(), cmp);
    int tot = 0;
    for (vec_it = my_vec.begin() ; vec_it !=my_vec.end() ;vec_it++)
    {
        tot++;
        fprintf(fpout,"%s %d\n",vec_it->first.c_str(), vec_it->second);
        if (tot >= 100) break;
    }
    fclose(fpin);
    fclose(fpout);
    return 0;
}
