#include <iostream>

int moneti[] = {50,20,10,5,2,1};
int i; 

struct listNode
{
    int key;
    int data;
    struct listNode* next;
};

void stotinki(int sum);

int main()
{
    stotinki(100);
    return 0;
}

void stotinki(int sum)
{
    if(sum > 0)
    {
        std::cout << moneti[i] << " : " << sum / moneti[i] << std::endl;
        stotinki(sum % moneti[i++]);
    }
}
