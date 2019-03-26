namespace ariel{

    class node{
        public:
        node* left;
        node* right;
        node* parent;
        int value;
    };


class Tree{
public:
    Tree();
    ~Tree();

    Tree& insert(int data);
    void remove(int i);
    int size();
    bool contains(int i);
    int root();
    int parent(int i);
    int left(int i);
    int right(int i);
    void print();

private:
    void insert(int data, node* t);
    node* contains(int data, node* t);
    void remove(int data, node* t);
    int root(node* t);
	int parent(int i, node* t);
	int left(int i, node* t);
	int right(int i, node* t);
	void print(node* t);


	node* _root;
	int _size;

};

}
