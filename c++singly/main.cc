#include "singly_manager.h"

int main()
{
    SinglyManager<int> manager;
    manager.Insert(1);
    manager.Insert(2);
    manager.Insert(3);
    manager.Insert(4);
    manager.DisplayList();
    manager.DeleteNode(2);
    manager.DisplayList();
    manager.DeleteNode(4);
    manager.DisplayList();
    manager.DeleteNode(1);
    manager.DisplayList();
    return 0;
}
