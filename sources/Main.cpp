//////
////// Created by yarin on 3/23/2022.
//////
//#include "Notebook.hpp"
//#include <iostream>
//#include <stdexcept>
//#include <string>
//#include  <cmath>
//
//using namespace std;
//
//
//bool getNum(const string& str,int *castedNumber)
//{
//    *castedNumber = 0 ;
//    int len = str.size();
//    for (int i = 0; i < len; i++)
//    {
//        unsigned int pos = (unsigned int)(i);
//        int val = str[pos] -'0';
//        if (i==0){
//            if (val==0&&len==0){
//                *castedNumber+= 0;
//                return true;
//            }
//        }
//        if (val< 0|| val >9){
//            return false;
//        }
//        else{
//            *castedNumber+= val*pow(10,len-1);
//            len--;
//
//        }
//    }
//    return true;
//}
//
//bool valid_string(string str){
//    for (int i=0;i<str.size();i++){
//        unsigned int pos = (unsigned int)(i);
//        if (str.at(pos) < ' ' || str.at(pos)>='~') {
//            return false;
//        }
//
//    }
//    return true;
//}
//int main(){
//    cout<<"Hello mate this is gonna be your notebook"<<endl;
//    cout<<"input of page should be positive and text should be less than 100 chars and char should be valid"<<endl;
//    cout<<"please enter the things you want to write in the note book and int which page"<<endl;
//    ariel::Notebook notebook;
//    int page;
//    string text;
//    string number;
//    bool flag = true;
//    while(flag){
//        cout<<"please enter page number : \n";
//        cin>>number;
//        while (!(getNum(number,&page))) {
//            cout << "The input was not valid, Enter a valid number :  \n";
//            cin >> number;
//        }
//        cin.ignore();
//        cout<<"please enter the text for that you want to write in the notebook : \n";
//        getline(cin,text);
//        while (!valid_string(text)) {
//            cout << "The input was not valid, Enter a valid text : \n";
//            getline(cin,text);
//        }
//        try {
//            cout<<text<<"les see what we print"<<endl;
//            int j=0;
//            int k=-1;
//            string temp;
//            for (int i = 0; i < text.length(); ++i) {
//                k++;
//                if(i%100==0&&i!=0){
//                    j++;
//                    k=0;
//
//                }
//                unsigned int pos = (unsigned int)(i);
//                temp += text[pos];
//                notebook.write(page,j,k,ariel::Direction::Horizontal,temp);
//                temp="";
//
//
//            }
//            cout<<"this is your page you write on have fun reading it  \n";
//            cout<< notebook.show(page);
//            flag = false;
//
//        }
//        catch (exception ex) {
//              cout<<"please enter a valid text as you told";
//        }
//
//
//
//    }
//
//
//}
