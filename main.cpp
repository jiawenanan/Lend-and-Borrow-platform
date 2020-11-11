//
//  main.cpp
//  RecommendationAlgo
//
//  Created by 顾孟瀚 on 11/9/20.
//  Copyright © 2020 顾孟瀚. All rights reserved.
//


#include "Header.h"


using namespace std;
using namespace boost::algorithm;


unordered_map<string,unordered_set<string>> M;
unordered_map<string,string> V;

int main(int argc, const char * argv[]) {
     //insert code here...
    
    ifstream fin("/Users/gumenghan/Desktop/C++ Projects/RecommendationAlgo/RecommendationAlgo/sampleData.csv");
    if (fin.fail()) {
        std::cerr << "error" << std::endl;
        exit(1);
    }
    string line;
    
    while (getline(fin, line)) {

        vector<string> parts;
        split(parts, line, boost::is_any_of("\t"));
        V[parts[0]]=parts[1];
        unordered_map<string,unordered_set<string>>::iterator itr=M.find(parts[0]);
        if (itr==M.end()){
            M[parts[0]]=build(parts[1]);
        }
        else{
            update(parts[1],itr->second);
        }
    }
    fin.close();
    cout<<M.size()<<endl;
    //unordered_map<string,string>::iterator itr;
//    for (itr=V.begin();itr!=V.end();itr++){
//        cout<<itr->first<<" : "<<itr->second;
//
//        cout<<endl;
//    }
    string newS;
    cin>>newS;
    string S1=Recomm(newS);
    cout<<S1<<endl;
    
    return 0;
}
