#include<iostream>

template<class  T>
class Node
{
    public:
    T Data;
    Node<T> * next=NULL;
    Node(T Data,Node<T> * next)
    {
        this->Data=Data;
        this->next=next;

    }
    ~Node(){};
};

template<class  T>
class SortLinkedList{
    public:
    SortLinkedList(T data)
    {InsertElements(data);}
    void InsertElements(T data);
    void PrintElements();
    void BubbleSort();
    void SelectionSort();
    void InsertionSort();
    void BinarySearch(int maxelement, T element);
    private:
    Node<T> * NodeSet = NULL;
    int counter=0;


};


template<class  T>
void SortLinkedList<T>::InsertionSort(){
    Node<T> * Current = NodeSet;
    Node<T> * MoveVar = Current->next;

    while(MoveVar!= NULL)
    {
        if(Current->Data >  MoveVar->Data)
        {
            int temp = MoveVar->Data;
            Current->next = MoveVar->next;
            delete MoveVar;
            if(temp < NodeSet->Data)
            {
              Node<T> * newnode = new Node<T>(temp , NodeSet);
              NodeSet = newnode ;
            }
            else
            {
                Node<T> * iterNode = NodeSet;
                while(iterNode->next->Data < temp )
                {
                    iterNode = iterNode->next;
                }
                Node<T> * newnode = new Node<T>(temp , iterNode->next);
                iterNode->next = newnode;
            }



        }
            Current = MoveVar;
            MoveVar = MoveVar->next;

    }


}


template<class  T>
void SortLinkedList<T>::SelectionSort()
{
    Node<T> * Current = NodeSet;
    while(Current->next != NULL)
    {
        Node<T> * minimum = Current;
        Node<T> * tempmove = Current->next;
        while(tempmove!= NULL)
        {
            if(tempmove->Data < minimum ->Data)
            {
                minimum = tempmove;
            }
            tempmove = tempmove->next;

        }

        if(minimum->Data !=  Current->Data)
        {
            T temp = Current->Data;
            Current->Data = minimum->Data;
            minimum->Data = temp;
        }
        Current = Current->next;
    }

}

template<class  T>
void SortLinkedList<T>::BubbleSort()
{
    T temp;
    Node<T> * current =NodeSet;
    int j=0;
    int number = counter;
    bool swapped=true;
    while(swapped)
    {
        current = NodeSet;
        swapped=false;
        j++;
    for(int i =0; i<(number - j) ; i++ )
    {
        if(current->Data > current ->next->Data)
        {
            temp =current->Data;
            current->Data=current->next->Data;
            current->next->Data= temp ;
            swapped = true;
        }
    current = current ->next;

}


}


}



template<class  T>
void SortLinkedList<T>::PrintElements()
{
     Node<T> * current = NodeSet;
      while(current!=NULL)
      {
        std::cout<<current->Data<<std::endl;
        current = current->next;
      }

}

template<class  T>
void SortLinkedList<T>::InsertElements(T data)
{
    if(NodeSet == NULL)
    {
        NodeSet = new Node<T>(data,NULL);
        counter++;
    }
    else
    {
      Node<T> * current = NodeSet;

      while(current->next!=NULL)
      {
        current = current->next;

     }
      current->next = new Node<T>(data, NULL);
      counter++;
    }

}






int main()
{
SortLinkedList<int> * lists = new SortLinkedList<int>(100);

lists->InsertElements(400);
lists->InsertElements(40);

lists->InsertElements(800);
lists->InsertElements(10);
lists->InsertElements(5);
lists->InsertElements(1);
lists->InsertElements(60);
lists->PrintElements();
//lists->BubbleSort();
lists->InsertionSort();
lists->PrintElements();

return 0;
}
