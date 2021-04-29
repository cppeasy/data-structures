#include <iostream>

using namespace std;


struct stNode{
    int data;
    stNode *pNext;
};

class SingleLinkedList
{
    private:
        stNode *m_pHead;
        
    public:
        SingleLinkedList();
        
        ~SingleLinkedList();
        
        void addNodeAtBegin(int num);
        
        void removeAllNodes();
        
        void print();
};

SingleLinkedList::SingleLinkedList():m_pHead(NULL){
    
}

SingleLinkedList::~SingleLinkedList(){
    removeAllNodes();
}

void SingleLinkedList::addNodeAtBegin(int num)
{
    //create empty node and its pNext points to head;
    stNode *pNode = new stNode();
    pNode->data = num;
    pNode->pNext = m_pHead;
    
    //change head node
    m_pHead = pNode;
}

void SingleLinkedList::print()
{
    stNode *pTemp = m_pHead;
    
    while(pTemp != NULL)
    {
        cout<<pTemp->data<<endl;
        pTemp = pTemp->pNext;
    }
}

void SingleLinkedList::removeAllNodes()
{
    while(m_pHead != NULL){
        stNode *pNode = m_pHead;
        m_pHead = m_pHead->pNext;
        delete pNode;        
    }
    
    m_pHead = NULL;
}


int main()
{
    SingleLinkedList l1;
    
    l1.addNodeAtBegin(10);
    l1.addNodeAtBegin(20);
    l1.addNodeAtBegin(30);
    l1.addNodeAtBegin(40);
    l1.addNodeAtBegin(50);
    l1.addNodeAtBegin(60);
    l1.addNodeAtBegin(70);
    
    l1.print();

    l1.removeAllNodes();
    
    l1.print();
    
    return 0;
}
