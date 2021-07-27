#include"queuebad.h"
#define VN(v) (#v)
QueueBad::QueueBad(int qs) : qsize(qs),q_size(qs)
{
    //not valid, because qsize if a const var, instead, use member initializer list above
    //qsize = qs;
    front = rear = nullptr;
    items_cnt = 0;
    LOG("QueueBad(int qs)"<<" called!");
}

QueueBad::~QueueBad()
{
    Node *temp;
    while (front)
    {
        LOG(front->item.i<<" DESTORIED!");
        temp = front->next;
        delete front;
        items_cnt--;
        front = temp;
    }
    

    // if(is_empty()) return;
    // Node *p;
    // p=front->next;
    // while(p){
    //     delete front;
    //     front = p;
    //     p=p->next;
    // }
    // delete front;
}

bool QueueBad::is_empty() const{
    return items_cnt==0?true:false;
}

bool QueueBad::is_full() const{
    return items_cnt==qsize?true:false;
}

bool QueueBad::enqueue(const Item &item){
    if (is_full())
    {
        return false;
    }
    Node *node= new Node;
    node->item = item;
    node->next = nullptr;
    items_cnt++;
    if(front==nullptr){
        front = node;
    }else{
        rear->next = node;
    }
    //pointer move afterward
    rear = node;
    LOG(" "<<item.i<<" ENQUEUE");
    return true;
}

bool QueueBad::dequeue(Item &item){
    if(is_empty()){
        return false;
    }
    item = front->item;
    items_cnt--;
    Node * temp = front;
    front = front->next;
    delete temp;
    //important!!!
    if(is_empty()){
        rear = nullptr;
    }
    return true;
}