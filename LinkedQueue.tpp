/*
TODO list
[x] contructor
[x] back
[x] clear
[x] copy
[x] dequeue
[x] enqueue
[x] front
*/

template <typename T>
LinkedQueue<T>::LinkedQueue() {
    head = nullptr;
    last = nullptr;
    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
    if(!last){
        throw string("back: error, queue is empty, cannot access the back");
    }
    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
    if(!head){
        cout << "queue is empty" << endl;
        return;
    }
    while(head){
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    last = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
    //iterate through the copy obj and create a new list 
    // i think that we want to start from the tail of the list, and construct it backwards?
    // this is actually more tricky than I thought it would be since we need to keep track of the prev or next pnode
    // ill come back to this


    if(copyObj.head == nullptr){
        cout << "exception being thrown" << endl;
        throw string ("Copy Error: copy object is empty!");
        return;
    }

    head = new Node(copyObj.head->value);
    Node* ptr = head;
    Node* old = copyObj.head->next;

    while(old != nullptr){
        ptr->next = new Node(old->value);
        cout << "copied value: " << old->value << endl;
        ptr = ptr->next;
        old = old->next;
    }

    last = ptr;

    this->length = copyObj.length;

    cout << "copy complete!" << endl;
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO
    // remove element from the front of the list

    if(!head){
        cout << "exception being thrown" << endl;
        throw string ("front: error, queue is empty, cannot access the front");
    }

    Node* ptr = head;
    head = head->next;
    delete ptr;
    if(!head) last = nullptr;

    this->length--;

}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO

    // add an element to the end of the list
    if(!last){
        Node* add = new Node(elem);
        last = add;
        head = add;
        return;
    }
    Node* add = new Node(elem);
    last->next = add;
    last = add;

    this->length++;

    cout << "enqueued to queue of value: " << elem << endl;
}

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
    if(!head){
        throw string("Error front: queue is empty");
    }
    return head->value;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
