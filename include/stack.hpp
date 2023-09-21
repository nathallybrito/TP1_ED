#ifndef STACK_H
#define STACK_H

template <typename S>
class Stack {
private:
     S *p;
    int top, length;
    friend class AvaliadorExpressaoLogica;

public:
    Stack(int size =0);
    ~Stack();

    void push(S);
    S pop();
    void display();
    bool isEmpty() const;
    S topElement() const;
};

#endif
