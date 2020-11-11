//
//  Header.h
//  RecommendationAlgo
//
//  Created by 顾孟瀚 on 11/10/20.
//  Copyright © 2020 顾孟瀚. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <iostream>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <set>
#include "eigen-3.3.8/Eigen/Dense"
#include <boost/tokenizer.hpp>
#include <sstream>
#include <boost/algorithm/string.hpp>
//#include "python3.7m/Python.h"
#include <typeinfo>

using namespace std;
extern std::unordered_map<std::string,std::unordered_set<std::string>> M;
extern std::unordered_map<std::string,std::string> V;


std::unordered_map<std::string,int> preProcess(std::string & S)
{
    boost::tokenizer<> tok(S);
    std::unordered_map<std::string,int> M;
    for (boost::tokenizer<>::iterator beg = tok.begin(); beg != tok.end(); ++ beg)
    {
        M[*beg]++;
    }
    return M;
}


void update (std::string & S, std::unordered_set<std::string>& SET){
    std::unordered_map<std::string,int> M=preProcess(S);
    std::unordered_map<std::string,int>::iterator itr;
    for (itr=M.begin();itr!=M.end();itr++){
        if (itr->second>=2) {
            SET.insert(itr->first);
        }
    }
}
std::unordered_set<std::string> build(std::string & S){
    std::unordered_map<std::string,int> M=preProcess(S);
    std::unordered_set<std::string> SET;
    std::unordered_map<std::string,int>::iterator itr;
    for (itr=M.begin();itr!=M.end();itr++){
        if (itr->second>=2) {
            SET.insert(itr->first);
        }
    }
    return SET;
}

int LCSubStr(std::string & X, std::string & Y)
{
    
    size_t m=X.length();
    size_t n=Y.length();
    int LCSuff[m+1][n+1];
    int result = 0;
    //std::string S="";
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
            
            else if (X[i-1] == Y[j-1]||(X[i-1]-'a'+'A'==Y[i-1]||X[i-1]+'a'-'A'==Y[i-1]))
            {
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
                if (LCSuff[i][j]>result){
                    result = LCSuff[i][j];
                    //S=X.substr(i-result+1,result);
                }
            }
            else LCSuff[i][j] = 0;
        }
    }
    return result;
}
std::string Recomm (std::string & S){
    std::unordered_map<std::string,std::string>::iterator itr;
    int count=0;
    std::string result;
    for (itr=V.begin();itr!=V.end();itr++){
        std::string tmp=itr->second;
        int I=LCSubStr(S,tmp);
        if (I>count){
            count=I;
            result=itr->first;
        }
    }
    return result;
    
}

#endif /* Header_h */
