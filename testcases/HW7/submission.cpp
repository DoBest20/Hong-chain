#include <stdio.h>
#include <iostream>
using namespace std;


/*
	this src code is for solution or submission of assignments.
	define functions to implement your assignments on here.
	the functions defined here will be using in test driver(main.c)
*/

void print_state(my_queue a){




}

//큐에 타입으로 들어갈 정보 원소 
class element{

    public:
    string s_title; //도서명
    int npages; //페이지수
    int price; //가격

    //정보 설정하는 메서드
    void set_data(string inputTitle, int inputNPage, int inputPrice){
        s_title = inputTitle;
        npages = inputNPage;
        price = inputPrice;
    } 

};

//커스텀 큐~
class my_queue{

    element q[SIZE]; //element를 원소로 저장하는 circular queue 
    int rear; //다음 원소를 >>넣을<< 곳
    int front; //최근에 원소가 들어온 곳

    public:
    my_queue(); //초기화
    void insert_q(element x); //원소 넣기
    element delete_q(); //원소 빼기
    bool empty(); //empty 체크
    bool full(); //full 체크 

};


