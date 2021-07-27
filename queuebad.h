//queuebad.h -- flaw string defination
#ifndef QUEUEBAD_H_
#define QUEUEBAD_H_
#endif
#include<iostream>
#include<string>
#define LOG(str) std::cout<<"["<<__FUNCTION__ <<" at line "<<__LINE__<<"]: "<<str<<std::endl

typedef struct {
    int i;
}Item;

class QueueBad
{
    
private:
    enum{Q_SIZE=10};
    struct Node{Item item; Node *next;};
    Node *front;
    Node *rear;
    int items_cnt;

    //const and reference variable must use member initializer list 
    const int qsize;
    int &q_size;
public:
    QueueBad(int qs=Q_SIZE);
    ~QueueBad();

    bool is_empty() const;
    bool is_full() const;
    int queue_count() const;
    bool enqueue(const Item &item);
    bool dequeue(Item &item);
};

