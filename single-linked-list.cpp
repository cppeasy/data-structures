
#include <iostream>

using namespace std;

// node of the linked list
struct stNode{
    int data;
    stNode *m_pNext;
};

class SingleLinkedList{
private:
    stNode *m_pHead;  
    
public:
    
    SingleLinkedList():m_pHead(NULL){ }
    ~SingleLinkedList();
    
    void insert(int data);
    void addAtBegin(int data);
    void addAtPos(int data, int pos);       
    void deleteFirstNode();
    void deleteLastNode(); 
    void deleteAtPos(int pos);      
    void deleteAll();   
    void print(); 
};

void SingleLinkedList::insert(int data){
    
    //if list empty
    if(m_pHead == NULL){
        m_pHead = new stNode();
        m_pHead->data = data;
        m_pHead->m_pNext = NULL;        
    }
    else
    {
        // store head node to temp
        stNode *pTempNode = m_pHead;
        
        while(pTempNode->m_pNext != NULL){
            pTempNode = pTempNode->m_pNext;
        }
        
        //create new node 
        stNode *pNode = new stNode();
        pNode->data = data;
        pNode->m_pNext = NULL;
        
        //attached new node at end
        pTempNode->m_pNext = pNode;                    
    }    
}

void SingleLinkedList::addAtBegin(int data)
{
    // create node and attach to head
    stNode *pNode = new stNode();
    pNode->data = data;
    pNode->m_pNext = m_pHead;
    
    //reset head
    m_pHead = pNode;           
}

void SingleLinkedList::addAtPos(int data, int pos)
{
    //if pos < 0 
    if(pos <= 0)
    {
        cout<<"invalid position"<<endl;
    }
    else if((m_pHead == NULL) || (pos == 1))
    {
        // create node and attach to head
        stNode *pNode = new stNode();
        pNode->data = data;
        pNode->m_pNext = m_pHead;
    
        //reset head
        m_pHead = pNode;
    }
    else
    {
        stNode *pTemp = m_pHead;
        stNode *pPrev = NULL;
        int counter = 1;
        
        // iterate till specific position and maintain prev. node
        while((pTemp != NULL) && (counter <= (pos - 1)))
        {
            //maintain prev. node
            pPrev = pTemp;
            pTemp = pTemp->m_pNext;
            counter++;
        }
        // if position beyound the list or not found
        if(pTemp == NULL)
        {
            cout<<"Position doesn't exist adding at last position"<<endl;
            stNode *p = new stNode();
            p->data = data;
            p->m_pNext = NULL;
            
            pPrev->m_pNext = p;
        }
        else
        {
            //create node
            stNode *p = new stNode();
            p->data = data;
            p->m_pNext = pTemp;
            
            pPrev->m_pNext = p;
        } 
    }
}

void SingleLinkedList::deleteFirstNode()
{
    if(m_pHead != NULL)
    {
        stNode *pNext = m_pHead;
        m_pHead = m_pHead->m_pNext;        
        delete pNext;        
    }
    else
    {
        cout<<"list is empty"<<endl;
    }
}

void SingleLinkedList::deleteLastNode()
{
    // if list is empty
    if(m_pHead == NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else
    {
        // if the list has only one element
        if(m_pHead->m_pNext == NULL)
        {
            delete m_pHead;
            m_pHead = NULL;
        }
        else
        {
            stNode *pTemp = m_pHead;
            stNode *pPrev = NULL;
            
            //iterate list till end and maintain previous node
            while(pTemp->m_pNext != NULL)
            {
                //maintain previous node
                pPrev = pTemp;
                pTemp = pTemp->m_pNext;
            }            
            //update previous node link to NULL
            pPrev->m_pNext = NULL;            
            //delete last node
            delete pTemp;
        }
    } 
}

void SingleLinkedList::deleteAtPos(int pos)
{
    // if the list is empty
    if(m_pHead == NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else
    {
        //if pos < 0 
        if(pos <= 0)
        {
            cout<<"invalid position"<<endl;
        }
        else if(pos == 1) // if first node
        {
            //deleteFirstNode();
            stNode *pNext = m_pHead;
            m_pHead = m_pHead->m_pNext;        
            delete pNext;
        }
        else
        {
            stNode *pTemp = m_pHead;
            stNode *pPrev = NULL;
            int counter = 1;
            // iterate till specific position and maintain prev. node
            while((pTemp != NULL) && (counter <= (pos - 1)))
            {
                //maintain prev. node
                pPrev = pTemp;
                pTemp = pTemp->m_pNext;
                counter++;
            }
            // if position beyound the list or not found
            if(pTemp == NULL)
            {
                cout<<"Position doesn't exist"<<endl;
            }
            else
            {
                //link prev. node to the next node which we want to delete
                pPrev->m_pNext = pTemp->m_pNext;
                //delete node
                delete pTemp;
            }        
        }
    }
}

void SingleLinkedList::deleteAll()
{
    while(m_pHead != NULL){
        stNode *pNode = m_pHead;
        m_pHead = m_pHead->m_pNext;
        delete pNode;        
    }
}

SingleLinkedList::~SingleLinkedList(){    
    deleteAll();
}

void SingleLinkedList::print()
{
    stNode *pNode = m_pHead;
    
    while(pNode != NULL){
        cout<<pNode->data<<endl;
        pNode = pNode->m_pNext;
    }
}

int main(int argc, char** argv) {
    
    SingleLinkedList l1;
    l1.insert(10);
    l1.insert(20);
    l1.insert(30);
    l1.insert(40);
    l1.insert(50);
    l1.addAtBegin(0);
    l1.addAtPos(25,7);    
    l1.print();    
    cout<<"===================="<<endl;    
    //l1.deleteAll();    
    //l1.deleteFirstNode();
    //l1.deleteLastNode();
    //l1.deleteAtPos(2);
    l1.print();
    
    return 0;
}
