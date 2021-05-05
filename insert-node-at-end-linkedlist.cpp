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
        
        void addNodeAtEnd(int num);
      
        void removeAllNodes();
        
        void print();
};

SingleLinkedList::SingleLinkedList():m_pHead(NULL){
    
}

SingleLinkedList::~SingleLinkedList(){
    removeAllNodes();
}


void SingleLinkedList::addNodeAtEnd(int num)
{
    
    //if the list empty
    if(m_pHead == NULL){
        m_pHead = new stNode();
        m_pHead->data = num;
        m_pHead->pNext = NULL;       
    }
    else
    {
        // store head node to temp
        stNode *pTempNode = m_pHead;
        
        while(pTempNode->pNext != NULL){
            pTempNode = pTempNode->pNext;
        }
        
        //create new node 
        stNode *pNode = new stNode();
        pNode->data = num;
        pNode->pNext = NULL;
        
        //attached new node at end
        pTempNode->pNext = pNode;     
    }
       
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
    
    l1.addNodeAtEnd(10);
    l1.addNodeAtEnd(20);
    l1.addNodeAtEnd(30);
    l1.addNodeAtEnd(40);
    l1.addNodeAtEnd(50);
    l1.addNodeAtEnd(60);
    l1.addNodeAtEnd(70);
    
    l1.print();

    //l1.removeAllNodes();
    
    //l1.print();
    
    return 0;
}
