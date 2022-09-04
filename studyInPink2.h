/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

string notebook1(string ntb1) {
    // Complete this function to gain point
    ifstream input(ntb1);
    
    string s;
    input >> s;
    string s1(s, 11, 3);
    if (s1.size() != 3) return "0000000000";
    for (int i = 0; i < 3; i++) {
        if (s1[i] < '0' || s1[i]>'9') {
            return "0000000000";
        }
    }
    int n1 = stoi(s1);
    if (n1>999||n1<1) return "0000000000";
    
    int arr[10] = { 0,0,0,0,0,0,0,0,0,0};

    for (int i = 0; i < n1; i++) {
        int val;
        input >> val;
        //cout << i << ':' << val<<endl;
        arr[val]++;
        arr[val] %= 10;
    }
    
    string result = {};
    for (int i = 0; i < 10; i++) {
        result = result + to_string(arr[i]);
    }
    return result;

}

string notebook2(string ntb2) {
    // Complete this function to gain point
    ifstream input(ntb2);
    
    string s;
    getline(input, s);
    if (s.size() != 5) return "1111111111";
    for (int i = 0; i < 5; i++) {
        if (s[i] < '0' || s[i]>'9') {
            return "1111111111";
        }
    }
    int n2 = stoi(s);
    if (n2 > 100 || n2 < 5) return "1111111111";
    
    long long cntP = 0;
    
    for (int i = 0; i < n2; i++) {
        
        string val;
        getline(input, val);
        for (int j = 0; j+3 < val.size() ; j++) {
            //cout<<i<<' '<<j<<' ' << val.size()<<' '<< (j < val.size() - 3) <<' '<< val.size() - 3 << ' ' << val[j] << endl;
            if (val[j] == 'P' || val[j] == 'p') {
                if (val[j + 1] == 'i' && val[j + 2] == 'n' && val[j + 3] == 'k') {
                    cntP++;
                    //cout << val[j] << val[j + 1] << val[j + 2] << val[j + 3] << ' ';
                }
            }
            
        }
        //cout << i << ": " << cntP << endl;
    }
    
    if (cntP < 10000) cntP = cntP * cntP;
    if (cntP != 0) {
        while (cntP < 1000000000) {
            //cout << cntP << ' ';
            cntP = cntP * 10 + 9;
        }
        return to_string(cntP);
    }
    else {
        return "0999999999";
    }
    


    
}

int returnPrime(int num) {
    if (num < 2) return 2;
    for (int i = num; true ; i++) {
        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) return i;
    }
}
int returnFibonacci(int num) {
    int f2 = 1, f1 = 1;
    while (f2 < num ) {
        f2 = f2 + f1;
        f1 = f2 - f1;
    }
    return f2;
}

string notebook3(string ntb3) {
    // Complete this function to gain point

    ifstream input(ntb3);

    int arr[10][10];
    char trash;
    string res = "";

    for (int i = 0; i < 10; i++) {
        
        for (int j = 0; j < 10; j++) {
            input >> arr[i][j];
            if (j != 9) input >> trash;
            arr[i][j] = abs(arr[i][j]);
            if (j > i) {
                arr[i][j] = returnPrime(arr[i][j]);
            }
            if (j < i) {
                arr[i][j] = returnFibonacci(arr[i][j]);
            }

            std::cout << arr[i][j] << ' ';
        }

        int maxL = arr[i][0];
        int itr = 0;
        for (int j = 1; j < 10; j++) {
            if (maxL <= arr[i][j]) {
                maxL = arr[i][j];
                if (j >= 7) itr = 9; //No need to sort since max in row at j>=7 must be 9
                else itr = j;

            }
        }
        res += to_string(itr);

        std::cout << "\n";
    }
    
    return res;
}

string g(string p1, string p2) {
    string result = "";
    int carry = 0;
    for (int i = 0; i < 10; i++) {
        
        string temp1 = "" , temp2 = "";
        temp1 += p1[i]; 
        temp2 += p2[i];
        
        int x1= stoi(temp1), x2 = stoi(temp2), x = x1+x2+carry;
        //cout << "p1[i] " << p1[i] << " p2[i] " << p2[i] <<" carry "<< carry<< " x "<<x << endl;
        if (x > 9) {
            carry = 1;
            x = x - 10;
        }
        else {
            carry = 0;
        }

        result += to_string(x);
    }
    return result;

}

string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    // Complete this function to gain point

    string result="";
    result += pwd1 + ';';
    result += pwd2 + ';';
    result += pwd3 + ';';
    result += g(pwd1, pwd2) + ';';
    result += g(pwd1, pwd3) + ';';
    result += g(pwd2, pwd3) + ';';
    result += g(pwd1, g(pwd2, pwd3)) + ';';
    result += g(g(pwd1, pwd2), pwd3) + ';';
    result += g(g(pwd1, pwd2), g(pwd1, pwd3));

    //cout << g(pwd1, pwd2) << endl;
    //cout << g(pwd1, pwd3) << endl;
    //cout << g(g(pwd1, pwd2), g(pwd1, pwd3)) << endl;
    return result;
}

bool chaseTaxi(
    int arr[100][100],
    string points,
    string moves,
    string & outTimes,
    string & outCatchUps
) {
    // Complete this function to gain point
    int posX = 0, posY = 0, taxiTime = 9;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            arr[i][j] = -9;
        }
    }

    arr[0][0] = 0;
    
    for (int i = 0; i < moves.size(); i++) {
        char direct = moves[i];
        if (direct == 'L' && posY>0) {
            posY--;
            arr[posX][posY] = taxiTime + arr[posX][posY + 1];
        }
        else if (direct == 'R' && posY < 99) {
            posY++;
            arr[posX][posY] = taxiTime + arr[posX][posY - 1];
        }
        else if (direct == 'U' && posX > 0) {
            posX--;
            arr[posX][posY] = taxiTime + arr[posX + 1][posY];
        }
        else if (direct == 'D' && posX < 99) {
            posX++;
            arr[posX][posY] = taxiTime + arr[posX - 1][posY];
        }
        //cout <<i<<':'<<direct << " arr[" << posX << "][" << posY << "] = " << arr[posX][posY] << endl;
    }
    
    stringstream move;
    move << points;
    char trs;
    int currX, currY, lastX=0, lastY=0, walkTime=14, currTime = 0;
    bool isCatchUp = false;

        move >> trs >> currX >> trs >> currY >> trs;
        //cout<<trs<<" : " << currX << ',' << currY << " SAD " << endl;
        int maha = abs(currX - lastX) + abs(currY - lastY);
        currTime = walkTime * maha;
        
        outTimes += to_string(currTime);
        if (arr[currX][currY] >= currTime) {
            //cout << "catch up at "<<currX<<' '<<currY<<" : "<<arr[currX][currY]<<' '<<currTime << endl;
                isCatchUp = 1;
                outCatchUps += "Y";
        }
        else {
            outCatchUps += "N";
        }
        
        lastX = currX;
        lastY = currY;

    
    while (move >> trs) {
        move >> trs >> currX >> trs >> currY >> trs;
        int maha = abs(currX - lastX) + abs(currY - lastY);
        currTime += walkTime * maha;
        if (isCatchUp){
            outTimes += ";-";
            outCatchUps += ";-";
        }
        else {
            outTimes += ";" + to_string(currTime);
            if (arr[currX][currY]>=currTime) {
                //cout << "catch up at " << currX << ' ' << currY << " : " << arr[currX][currY] << ' ' << currTime << endl;
                isCatchUp = 1;
                outCatchUps += ";Y";
            }
            else {
                outCatchUps += ";N";
            }
        }
        lastX = currX;
        lastY = currY;

    } 

    return isCatchUp;



    return false;
}

string enterLaptop(string tag, string message) {
    // Complete this function to gain point
    string pwdL = "";
    ifstream input(tag);
    string email, address;
    getline(input, email);
    getline(input, address);
    
    string temp(email, 7);
    pwdL += temp+";";
    stringstream ss;
    ss << address;

    int time;
    ss >> temp >> time;
    
    for (int i = 0; i < time; i++) {
        pwdL += message;
    }
    return pwdL;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
