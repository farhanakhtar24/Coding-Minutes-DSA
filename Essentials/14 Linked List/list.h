class LinkedList;

class Node
{
    int data;

public:
    Node *next;
    Node(int d) : data(d), next(nullptr) {} // same as data = d , next = Nullptr

    int getData()
    {
        return data;
    }

    friend class LinkedList;
    ~Node()
    {
        if (next != nullptr)
        {
            delete next;
        }
    }
};

class LinkedList
{
    Node *head;
    Node *tail;

    int helper(Node *start, int key)
    {
        // base case
        if (start == nullptr)
        {
            return -1;
        }

        if (start->data == key)
        {
            return 0;
        }

        //recursive call
        int subindex = helper(start->next, key);

        if (subindex == -1)
        {
            return -1;
        }
        return subindex + 1;
    }

public:
    LinkedList() : head(nullptr), tail(nullptr){};

    Node *begin()
    {
        return head;
    }

    void pushFront(int data)
    {
        if (head == nullptr)
        {
            Node *n = new Node(data);
            tail = head = n;
            // return;
        }
        else
        {
            Node *n = new Node(data);
            n->next = head;
            head = n;
        }
    }

    void popFront()
    {
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    void pushBack(int data)
    {
        if (head == nullptr)
        {
            Node *n = new Node(data);
            head = tail = n;
        }
        else
        {
            Node *n = new Node(data);
            tail->next = n;
            tail = n;
        }
    }

    void popBack()
    {
        Node *secondLast = head;
        for (int jump = 0; secondLast->next != tail; jump++)
        {
            secondLast = secondLast->next;
        }
        Node *temp = secondLast->next;
        secondLast->next = nullptr;
        delete temp;
    }

    void insert(int data, int pos)
    {
        if (pos == 0)
        {
            pushFront(data);
            return;
        }
        else
        {
            Node *temp = head;
            for (int jumps = 1; jumps <= pos - 1; jumps++)
            {
                temp = temp->next;
            }
            Node *n = new Node(data);
            n->next = temp->next;
            temp->next = n;
        }
    }

    void remove(int pos)
    {
        Node *temp = head;
        for (int jump = 1; jump < pos - 1; jump++)
        {
            temp = temp->next;
        }
        Node *n = temp->next;
        temp->next = n->next;
        n->next = nullptr;
        delete n;
    }

    bool search(Node *head, int key)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int recursiveSearch(int key)
    {
        int index = helper(head, key);
        return index;
    }

    ~LinkedList()
    {
        if (head != nullptr)
        {
            delete head;
            head = nullptr;
        }
    }

    void reverseList()
    {
        Node *current = head;
        Node *prev = nullptr;
        Node *temp;
        for (int jump = 0; current->next != nullptr; jump++)
        {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        }
};