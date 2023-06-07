#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_NAME_LEN 20
#define MAX_EMAIL_LEN 20

typedef struct Node {
    int id;
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    int next_id;
    int next_name; 
    int next_email; 
} Node;

typedef struct List {
    Node* buffer;
    unsigned int length;
    unsigned int capacity;
    // Invalid value is -1
    int head_id;
    int head_name;
    int head_email;
} List;

int init_list(List* list);
int push_node(List* list, Node n);
void init_node(Node* n);
void print_list(List* list);
void print_node(Node* n);

int main() {
    List list;
    init_list(&list);
    Node n1, n2, n3, n4, n5, n6;
    init_node(&n1);
    init_node(&n2);
    init_node(&n3);
    init_node(&n4);
    init_node(&n5);
    init_node(&n6);
    n1.id = 5;
    n2.id = 4;
    n3.id = 10;
    n4.id = 2;
    n5.id = 7;
    n6.id = 11;

    strncpy(n1.name, "Dusan", MAX_NAME_LEN);
    strncpy(n2.name, "Nemanja", MAX_NAME_LEN);
    strncpy(n3.name, "Jovana", MAX_NAME_LEN);
    strncpy(n4.name, "Ana", MAX_NAME_LEN);
    strncpy(n5.name, "Maja", MAX_NAME_LEN);
    strncpy(n6.name, "Aleksa", MAX_NAME_LEN);
    strncpy(n1.email, "dusan@dusan.com", MAX_EMAIL_LEN);
    strncpy(n2.email, "cone@cone.com", MAX_EMAIL_LEN);
    strncpy(n3.email, "jvn@jvn.com", MAX_EMAIL_LEN);
    strncpy(n4.email, "ana@ana.com", MAX_EMAIL_LEN);
    strncpy(n5.email, "maja@maja.com", MAX_EMAIL_LEN);
    strncpy(n6.email, "aleksa@aleksa.com", MAX_EMAIL_LEN);

    push_node(&list, n1);
    push_node(&list, n2);
    push_node(&list, n3);
    push_node(&list, n4);
    push_node(&list, n5);
    push_node(&list, n6);

    print_list(&list);

    return 0;

}

void print_node(Node* n) {
    printf("ID: %d NAME: %s EMAIL: %s NEXT_ID: %d\n", n->id, n->name, n->email, n->next_id);
}

void init_node(Node* n) {
    n->next_id = -1;
    n->next_name = -1;
    n->next_email = -1;
}

void print_list(List* list) {
    if (list == NULL || list->head_id == -1) {
        printf("List is empty\n");
        return;
    }
    
    int tmp_index = list->head_id;
    while(tmp_index != -1) {
        print_node(list->buffer + tmp_index);
        tmp_index = list->buffer[tmp_index].next_id;
    }
}

int init_list(List* list) {
    if (list == NULL) {
        return 1;
    } 

    list->length = 0;
    list->capacity = 16;
    list->head_id = -1;
    list->head_name = -1;
    list->head_email = -1;

    list->buffer = (Node*)malloc(sizeof(Node) * list->capacity);
    
    if (list->buffer == NULL) {
        return 1;
    }

    return 0;
}

int push_node(List* list, Node n) { 
    if (list->length == list->capacity) {
        list->capacity *= 2;
        Node* new_buffer = realloc(list->buffer, sizeof(Node) * list->capacity);

        if (new_buffer == NULL) {
            return 1;
        }

        list->buffer = new_buffer;
    }


    if (list->head_id == -1) {
        list->head_id = 0;
        list->head_name = 0;
        list->head_email = 0;
        n.next_id = -1;
        list->buffer[list->head_id] = n;
        list->length += 1;
        return 0;
    }
    
    // If new node should go at the start
    Node head_node = list->buffer[list->head_id];
    if (n.id > head_node.id) {
        n.next_id = list->head_id;
        list->buffer[list->length] = n;
        list->head_id = list->length;
        list->length += 1;
        return 0;
    }
    
    // Find last node sorted by id
    int last_index = list->head_id;
    Node tmp = list->buffer[last_index];


    while(tmp.next_id != -1 && list->buffer[tmp.next_id].id > n.id) {
        last_index = tmp.next_id;
        tmp = list->buffer[tmp.next_id];
    }

    n.next_id = tmp.next_id;
    list->buffer[list->length] = n;

    tmp.next_id = list->length;

    list->buffer[last_index] = tmp;

    list->length += 1;

    return 0; 
}
