namespace ariel{

class Node{
    private:
      int _data;
      Node* left;
      Node* right;
      Node* parent;

    public:
      Node(int data); //constructor
      Node* getLeft(); 
      Node* getRight(); 
      Node* getParent(); 
      void setLeft(Node* l);
      void setRight(Node* r);
      void setParent(Node* p);
      int getData();
      void setData(int data);

  };


class Tree{
public:

    Tree();
    ~Tree();

    Tree& insert(int i);
    void remove(int i);
    int size();
    bool contains(int i);
    int root();
    int parent(int i);
    int left(int i);
    int right(int i);
    void print();
    Node* findMin(Node* N);


private:

    Node* find(int i);

    void insert(int i, Node* node);
    void print(Node* x);
    void Destroy(Node* x);

	int _size;
    Node* _root;

};

}
