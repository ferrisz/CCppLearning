//
//  main.cpp
//  cppgaoli
//
//  Created by Ferris on 16/6/6.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class PersonID{
private:
    char *pID;
    int Year;
    int School;
    int Major;
    int Clas;
    int Num;
    void analyse(char *pID);
public:
    PersonID(char *pID);
    PersonID();
    ~PersonID();
    bool SetID(char *pID);
    bool GetYear(int &Year);
    bool GetSchool(int &School);
    bool GetMajor(int &Major);
    bool GetClas(int &Clas);
    bool GetNum(int &Num);
};

PersonID::PersonID(){
    pID=NULL;
}

PersonID::PersonID(char *pID){
    this->SetID(pID);
}

PersonID::~PersonID(){
}

bool PersonID::SetID(char *pID){
    if((pID!=NULL)&&(strlen(pID)==18)){
        if(this->pID==NULL){
            this->pID=new char[strlen(pID)+1];
        }
        strcpy(this->pID,pID);
        analyse(pID);
        return true;
    }else
        return false;
}

bool PersonID::GetYear(int& Year){
    if(pID!=NULL){
        Year=this->Year;
        return true;
    }else
        return false;
}

bool PersonID::GetSchool(int &School){
    if(pID!=NULL){
        School=this->School;
        return true;
    }else
        return false;
}

bool PersonID::GetMajor(int &Major){
    if(pID!=NULL){
        Major=this->Major;
        return true;
    }else
        return false;
}

bool PersonID::GetClas(int &Clas){
    if(pID!=NULL){
        Clas=this->Clas;
        return true;
    }else
        return false;
}

bool PersonID::GetNum(int &Num){
    if(pID!=NULL){
        Num=this->Num;
        return true;
    }else
        return false;
}

void PersonID::analyse(char *pID){
    char str[8];
    strncpy(str,pID,4);
    Year=atoi(str);
    
    strncpy(str,pID+4,2);
    str[2]='\0';
    School=atoi(str);
    
    strncpy(str,pID+6,2);
    str[2]='\0';
    Major=atoi(str);
    
    strncpy(str,pID+8,2);
    str[2]='\0';
    Clas=atoi(str);
    
    strncpy(str,pID+11,3);
    str[3]='\0';
    Num=atoi(str);
}

int main()
{
    int Year,School,Major,Clas,Num;
    bool ret;
    PersonID myID("2015060501001"),yourID;
    ret=myID.GetYear(Year);
    ret=myID.GetSchool(School);
    ret=myID.GetMajor(Major);
    ret=myID.GetClas(Clas);
    ret=myID.GetNum(Num);
    ret=yourID.SetID("2015060501002");
    ret=yourID.GetNum(Num);
    return 0;
}
