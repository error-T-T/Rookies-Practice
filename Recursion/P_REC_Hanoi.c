/*
Author: RookieT
Date: 2026/04/20
Repository: https://github.com/error-T-T/Rookies-Practice
Email: RookieT@e.gzhu.edu.cn
Type: Practice
Knowledge: Recursive Algorithm
Skill: Recursion, Linked-List
Abstract: 
    Recursive solution to Tower of Hanoi.
    Prints each move, records per-disk move counts using a linked list,
    and measures running time.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

static int count = 0;

typedef struct node{
    int count;
    struct node* next;
}node_t;


node_t* head = NULL;

node_t* build_node(int n); // this function could build a link to record every disk`s step 
void count_disk(int n);
void hanoi(int n, char start, char trans, char end);
void print_count(node_t* head);


node_t* build_node(int n){
    if(n == 1){
        node_t* node = (node_t*) malloc (sizeof(node_t));
        node->count = 0;
        node->next = NULL;
        return node;
    }

    node_t* node = (node_t*) malloc (sizeof(node_t));
    node->count = 0;
    node->next = build_node(n-1);
    return node;
}

void count_disk(int n){
    node_t* temp_head = head;
    for(int i = 0; i < n - 1; i++) // counting from 1~n, so "i < n-1"
        temp_head = temp_head->next;
    temp_head->count++;
}

void hanoi(int n, char start, char trans, char end){
    if( n == 1 ){
        count++;
        count_disk(1);
        printf("step:%7d move disk  1 from %c to %c.\n", count, start, end);
        return;
    } 
    else {
        hanoi(n - 1, start, end, trans);
        count++;
        count_disk(n);
        printf("step:%7d move disk %2d from %c to %c.\n", count, n, start, end);
        hanoi(n - 1, trans, start, end);
   }
    
}

void print_count(node_t* head){
    int i = 1;
    while(head != NULL){
    printf("disk %2d has moved %7d steps.\n", i, head->count);
    head = head->next;
    i++;
    }
    printf("----------------------------------------");
}

int main(){
    clock_t start, end;
    double cost;
    int n;
    printf("the count of disk is:");
    scanf("%d", &n);

    printf("----------------------------------------");
    head = build_node(n);

    start = clock();
    hanoi(n, 'A', 'B', 'C');
    end = clock();

    cost = (double)(end - start) / CLOCKS_PER_SEC;
    printf("----------------------------------------\n"
            "Running time: %.4f s\n"
           "----------------------------------------\n",cost);
    print_count(head);

    return 0;
}
/*
input:
    the count of disk is:22

output:
    ----------------------------------------
    step:      1 move disk  1 from A to C.
    step:      2 move disk  2 from A to B.
    step:      3 move disk  1 from C to B.
    step:      4 move disk  3 from A to C.
    step:      5 move disk  1 from B to A.

    ...

    step:4194299 move disk  1 from C to A.
    step:4194300 move disk  3 from B to C.
    step:4194301 move disk  1 from A to B.
    step:4194302 move disk  2 from A to C.
    step:4194303 move disk  1 from B to C.
    ----------------------------------------
    Running time: 107.1480 s
    ----------------------------------------
    disk  1 has moved 2097152 steps.
    disk  2 has moved 1048576 steps.
    disk  3 has moved  524288 steps.
    disk  4 has moved  262144 steps.
    disk  5 has moved  131072 steps.
    disk  6 has moved   65536 steps.
    disk  7 has moved   32768 steps.
    disk  8 has moved   16384 steps.
    disk  9 has moved    8192 steps.
    disk 10 has moved    4096 steps.
    disk 11 has moved    2048 steps.
    disk 12 has moved    1024 steps.
    disk 13 has moved     512 steps.
    disk 14 has moved     256 steps.
    disk 15 has moved     128 steps.
    disk 16 has moved      64 steps.
    disk 17 has moved      32 steps.
    disk 18 has moved      16 steps.
    disk 19 has moved       8 steps.
    disk 20 has moved       4 steps.
    disk 21 has moved       2 steps.
    disk 22 has moved       1 steps.
    ----------------------------------------
*/

/*
构造递归函数的方法：
    1.递归的本质是从结果出发，把复杂任务拆分为简单情况进行处理
    2.递归和迭代的主要区别在于出发点、时空复杂度和代码可读性
        2.1迭代的出发点是简单情况：
            int function(int n){
                int sum = 0;
                for(int i = 0; i < n; i++){
                    if(n < 0) return -1;
                    
                }
            }
        它第一步的数值是可知的

        2.2递归的切入点往往是要求的 "n"：
            void recursion(int n){
                if(n < 0) return -1;
                if(n = 1) return  1;
                return n*recursion(n-1);
            }
    3.构造递归的 skill：
        3.1打开冰箱
        3.2把大象放进去
        3.3合上冰箱
    
*/