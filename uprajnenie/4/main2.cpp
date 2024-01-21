#include <iostream>
using namespace std;
typedef int data;
typedef int keyType;
struct list {
	keyType key;
	data info;
	struct list *next;
};

bool isPalindrom(struct list **L)
{
    int i = 0;
    int arr[50];
    struct list* temp = *L;
    while(temp != NULL && temp->next != NULL)
    {
        arr[i++] = temp->info;
        temp = temp->next;
    }

    int left, right;
    left = 0;
    right = i;

    while(left < right)
    {
        if(arr[left++] != arr[right--])
        {
            return false;
        }
    }

    return true;
}

void insertBegin(struct list **L, keyType key, data x)
{
	struct list *temp;
	temp = (struct list *)malloc(sizeof(*temp));
	if(NULL == temp)
	{
		cout << "Nyama dostatachno pamet za nov element! \n";
		return;
	}
	temp->next = *L;
	(*L) = temp;
	(*L)->key = key;
	(*L)->info = x;
}

void insertAfter(struct list **L, keyType key, data x)
{
	struct list *temp;
	if(NULL == *L)
	{
		insertBegin(L, key, x);
		return;
	}
	temp = (struct list *)malloc(sizeof(*temp));
	if(NULL == temp)
	{
		cout << "Nyama dostatachno pamet za noviya element! \n";
		return;
	}
	temp->key = key;
	temp->info = x;
	temp->next = (*L)->next;
	(*L)->next = temp;
}

void insertBefore(struct list **L, keyType key, data x)
{
	struct list *temp;
	if(NULL == *L)
	{
		insertBegin(L, key, x);
		return;
	}
	temp = (struct list *)malloc(sizeof(*temp));
	if(NULL == temp)
	{
		cout << "Nyama dostatachno pamet za noviya element! \n";
		return;
	}
	*temp = **L;
	(*L)->next = temp;
	(*L)->key = key;
	(*L)->info = x;
}

void deleteNode(struct list **L, keyType key)
{
	struct list *current = *L;
	struct list *save;
	if((*L)->key == key)
	{
		current = (*L)->next;
		free(*L);
		(*L) = current;
		return;
	}
	while(current->next != NULL && current->next->key != key)
	{
		current = current->next;
	}
	if(NULL == current->next)
	{
		cout << "Greshka: Elementat za iztrivane ne e nameren!\n";
		return;
	}
	else
	{
		save = current->next;
		current->next = current->next->next;
		free(save);
	}
}

void print(struct list *L)
{
	while(NULL != L)
	{
		cout << L->key << "(" << L->info << ") ";
		L = L->next;
	}cout << "\n";
}
struct list* search(struct list *L, keyType key)
{
	while(L != NULL)
	{
		if(L->key == key)
			return L;
		L = L->next;
	}
	return NULL;
}
int main()
{
	struct list *L = NULL;
	int i, edata;
	insertBegin(&L, 0, 42);
	for(i=1; i<6; i++)
	{
		edata = rand()%100;
		cout << "Vmakvane predi: " << i << "(" << edata << ")" << "\n";
		insertBefore(&L, i, edata);
	}
	for(i=6; i<10; i++)
	{
		edata = rand()%100;
		cout << "Vmakvane sled: " << i << "(" << edata << ")" << "\n";
		insertAfter(&L, i, edata);
	}
	print(L);
	deleteNode(&L, 9);
	print(L);
	deleteNode(&L, 0);
	print(L);
	deleteNode(&L, 3);
	print(L);
	deleteNode(&L, 5);
	print(L);
	deleteNode(&L, 5);
 	return 0;
}
