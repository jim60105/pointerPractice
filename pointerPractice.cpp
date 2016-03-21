/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年03月19日 04時13分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jim (), jim60105@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Node{
    int value;
    Node* next;
}Node;

int a[] = {4,8,7,6,3};
Node* b[4];

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  makeQueue
 *  Description: 初始串列 
 * =====================================================================================
 */
    Node* 
makeQueue ()
{
    Node* head = new Node;

    for(int i=sizeof(a)/sizeof(*a)-1;i>=0;i--){
        Node* tmp = new Node;
        tmp->value = a[i];
        tmp->next = b[i];
        if(i!=0){
           b[i-1] = tmp;
        }else{
            head = tmp;
        }
    }

    return head;
}		/* -----  end of function makeQueue  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  listQuene
 *  Description: 印出串列內容 
 * =====================================================================================
 */
    void
listQuene ( Node* head )
{
    cout<<"現在已存在之元素:"<<endl;
    Node* cur=head;
    while(cur!=NULL){
         cout<<cur->value<<",";
         cur=cur->next;
    }
}		/* -----  end of function listQuene  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  addToQuene
 *  Description: 指定位置插入元素 
 * =====================================================================================
 */

    Node*    
addToQuene ( Node* head, int position, int value )
{
    Node* tmp = new Node;
    tmp->value = value;
    tmp->next = NULL;
    
    Node* cur,* pre;
    cur = pre = head; 
    for(int i=0;1;i++){
        if(cur==NULL){
            pre->next = tmp;
            break;
        }
        if(i==position){
            tmp->next = cur;
            if(i!=0){
                pre->next = tmp;
            }else{
                head = tmp;
            }
            break;
        }
        cur=cur->next;
        if(i!=0){
            pre=pre->next;
        }
    }
    return head;
}		/* -----  end of function addToQuene  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  delFromQuene
 *  Description:  
 * =====================================================================================
 */
    Node*
delFromQuene( Node* head, int position )
{
    Node* cur,* pre;
    cur = pre = head; 
    for(int i=0;1;i++){
        if(cur==NULL){
            pre->next = NULL;
            break;
        }
        if(i==position){
            if(i==0){
                head = head->next;
            }else{
                pre->next = cur->next;
            }
            break;
        }
        cur=cur->next;
        if(i!=0){
            pre=pre->next;
        }
    }
    return head;
}		/* -----  end of function delFromQuene  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  sortQuene
 *  Description:  
 * =====================================================================================
 */
    void
sortQuene ( Node* head )
{
    Node* pre,* cur;
    bool exit = false;
    while(1){
        pre = head;
        cur = head->next;
        while(cur->value >= pre->value){
            pre = cur;
            cur = cur->next;
            if(cur==NULL){
                exit = true;
                break;
            }
        }
        if(exit){
            break;
        }else{
            int tmp;
            tmp = pre->value;
            pre->value = cur->value;
            cur->value = tmp;
        }
    }
}		/* -----  end of function sortQuene  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    Node* head = makeQueue();

    bool exit = false;
    while(!exit){
        listQuene(head);
        cout<<"要執行的指令:"<<endl;
        cout<<"1)指定位置插入元素\n2)指定位置刪除元素\n3)排序元素\n4)結束"<<endl;
        
        int select;
        cin>>select;
        int position;
        
        switch (select){
            case 1:
                cout<<"位置?(0 base)"<<endl;
                cin>>position;
                cout<<"請輸入元素(限定數字)：";
                int value;
                cin>>value;
                head = addToQuene(head,position,value);
                break;
            case 2:
                cout<<"位置?(0 base)"<<endl;
                cin>>position;
                head = delFromQuene(head,position);
                break;
            case 3:
                sortQuene(head);
                break;
            case 4:
                exit = true;
                break;
        }
    }

    return 0;
}
    /* ----------  end of function main  ---------- */
